#include <sys/types.h>

#include <cassert>
#include <string>
#include <vector>

namespace token {
enum TokenType {
  PRINT,
  EXPR,

  NUMBER,
  SEMICOLON,

  PLUS,
  MINUS,
  MULTIPLY,
  DIVIDE,
  EXPONENT,
  MODULUS,

  END_OF_FILE,
  ILLEGAL
};

struct Token {
  TokenType type;
  std::string literal;
};

// MAYBE
struct Line {
  std::vector<Token> tokens;
  uint line_start;
  uint line_end;
};

}  // namespace token
