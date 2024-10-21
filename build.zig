const std = @import("std");

// Although this function looks imperative, note that its job is to
// declaratively construct a build graph that will be executed by an external
// runner.
pub fn build(b: *std.Build) !void {
    // Standard target options allows the person running `zig build` to choose
    // what target to build for. Here we do not override the defaults, which
    // means any target is allowed, and the default is native. Other options
    // for restricting supported target set are available.
    const target = b.standardTargetOptions(.{});

    // Standard optimization options allow the person running `zig build` to select
    // between Debug, ReleaseSafe, ReleaseFast, and ReleaseSmall. Here we do not
    // set a preferred release mode, allowing the user to decide how to optimize.
    const optimize = b.standardOptimizeOption(.{});

    // walk the src directory for all cc and cpp files
    var sources = std.ArrayList([]const u8).init(b.allocator);
    {
        var dir = try std.fs.cwd().openIterableDir("src", .{});
        var walker = try dir.walk(b.allocator);
        defer walker.deinit();

        const allowedExtensions = [_][]const u8{ ".cc", ".c", ".cpp" };
        while (try walker.next()) |entry| {
            const ext = std.fs.path.extension(entry.basename);
            const includeFile = for (allowedExtensions) |allowedExt| {
                if (std.mem.eql(u8, ext, allowedExt)) {
                    break true;
                }
            } else false;

            if (includeFile) {
                var path = [_][]const u8{ "src", entry.path };
                const fullPath = try std.fs.path.join(b.allocator, &path);
                // std.debug.print("Adding source file: {s}\n", .{fullPath});
                try sources.append(fullPath);
            }
        }
    }

    const exe = b.addExecutable(.{
        .name = "smap",
        .target = target,
        .optimize = optimize,
    });

    exe.addIncludePath(.{ .path = "src/include" });
    exe.linkLibCpp();

    const argv = [_][]const u8{ "git", "rev-parse", "HEAD" };
    var commitHashProcess = try std.ChildProcess.exec(.{
        .allocator = b.allocator,
        .argv = &argv,
    });

    var commitHash = commitHashProcess.stdout;
    commitHash = commitHash[0..7];

    const commitHashFlag = try std.fmt.allocPrint(b.allocator, "-DCOMMIT_HASH=\"{s}\"", .{commitHash});

    exe.addCSourceFiles(sources.items, &.{
        "-pedantic",
        "-Wall",
        "-W",
        "-Wno-unused-parameter",
        "-Wno-unused-variable",
        "-Wno-unused-function",
        "-Wno-unused-but-set-variable",
        "-Wno-missing-field-initializers",
        "-Wno-missing-braces",
        "-Werror=switch",
        "-std=c++17",
        commitHashFlag,
    });

    b.installArtifact(exe);
}
