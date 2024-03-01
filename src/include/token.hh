#include <sys/types.h>

#include <cassert>
#include <string>
#include <vector>

namespace token {
enum TokenType {
  EXPR,

  NUMBER,
  SEMICOLON,

  PLUS,
  MINUS,
  MULTIPLY,
  DIVIDE,

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

Token NewToken(TokenType type, char ch) {
  Token token;
  token.type = type;
  token.literal = ch;

  return token;
};

}  // namespace token
