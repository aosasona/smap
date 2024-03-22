#include <cassert>
#include <string>
#include <vector>

#include "token.hh"

namespace lexer {
struct Lexer {
  std::string input;
  int current_pos;
  int read_pos;
  char current_char;

  Lexer(std::string input)
      : input(input), current_pos(0), read_pos(0), current_char(0) {}

  token::Token next();

  char peek();

  void read_char();

  void eat_whitespace();

  std::string read_identifier();

  std::string read_number();
};

Lexer new_lexer(std::string input);
}  // namespace lexer
