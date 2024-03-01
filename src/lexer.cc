#include "include/lexer.hh"

namespace lexer {
Lexer new_lexer(std::string input) {
  Lexer l = lexer::Lexer(input, 0, 0, 0);
  l.read_char();
  return l;
}
}  // namespace lexer
