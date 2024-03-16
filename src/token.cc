#include "include/token.hh"

namespace token {
Token NewToken(TokenType type, char ch) {
  Token token;
  token.type = type;
  token.literal = ch;

  return token;
};
}  // namespace token
