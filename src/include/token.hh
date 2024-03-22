#include <sys/types.h>

#include <cassert>
#include <string>
#include <vector>

namespace token {
enum TokenType {
  PRINT,
  LET,

  NUMBER,  // floats, negative numbers, etc
  SEMICOLON,

  PLUS,
  MINUS,
  MULTIPLY,
  DIVIDE,
  EXPONENT,
  MODULUS,
  EQUALS,

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

Token NewToken(TokenType type, std::string literal);

}  // namespace token
