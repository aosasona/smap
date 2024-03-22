#include "include/token.hh"

namespace token {
Token NewToken(TokenType type, std::string ch) {
  Token token;
  token.type = type;
  token.literal = ch;

  return token;
};
}  // namespace token
