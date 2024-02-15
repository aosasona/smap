#include <cassert>
#include <string>

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

Token NewToken(TokenType type, char ch) {
  Token token;
  token.type = type;
  token.literal = ch;

  return token;
};

}  // namespace token
