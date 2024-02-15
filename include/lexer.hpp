#include <cassert>
#include <string>

namespace lexer {
struct Lexer {
  std::string input;
  int current_pos;
  int read_pos;
  char current_char;

  Lexer(std::string input, int current_pos, int read_pos, char current_char)
      : input(input),
        current_pos(current_pos),
        read_pos(read_pos),
        current_char(current_char) {}

  char read_char() {
    if (read_pos >= input.length()) {
      current_char = 0;
    } else {
      assert(read_pos < input.length() && read_pos >= 0);

      current_char = input[read_pos];
    }

    current_pos = read_pos;
    read_pos += 1;

    return current_char;
  }

  void skip_whitespace() {
    while (current_char == ' ' || current_char == '\t' ||
           current_char == '\n' || current_char == '\r') {
      read_char();
    }
  }
};

Lexer new_lexer(std::string input);
}  // namespace lexer
