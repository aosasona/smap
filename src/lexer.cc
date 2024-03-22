#include "include/lexer.hh"

#include <cassert>
#include <vector>

namespace lexer {
using namespace token;

bool is_number(char c) { return c >= '0' && c <= '9'; }

bool is_letter(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

Lexer new_lexer(std::string input) {
  Lexer l = Lexer(input);
  l.read_char();
  return l;
}

Token Lexer::next() {
  Token tk;

  this->eat_whitespace();

  switch (this->current_char) {
    case '+':
      tk = Token{token::PLUS, "+"};
      break;

    case '-':
      if (is_number(this->peek())) {
        std::string num = "-";
        num += this->read_number();
        tk = Token{token::NUMBER, num};
      } else {
        tk = Token{token::MINUS, "-"};
      }
      break;

    case '*':
      tk = Token{token::MULTIPLY, "*"};
      break;

    case '/':
      tk = Token{token::DIVIDE, "/"};
      break;

    case '^':
      tk = Token{token::EXPONENT, "^"};
      break;

    case '%':
      tk = Token{token::MODULUS, "%"};
      break;

    case ';':
      tk = Token{token::SEMICOLON, ";"};
      break;

    case '=':
      tk = Token{token::EQUALS, "="};
      break;
  }

  this->read_char();
  return tk;
}

char Lexer::peek() {
  if (this->read_pos >= this->input.length()) {
    return 0;
  } else {
    return this->input[this->read_pos];
  }
}

void Lexer::read_char() {
  assert(this != NULL);

  if (this->read_pos >= this->input.length()) {
    this->current_char = 0;
  } else {
    this->current_char = this->input[this->read_pos];
  }

  this->current_pos = this->read_pos;
  this->read_pos++;
}

void Lexer::eat_whitespace() {
  while (this->current_char == '\n' || this->current_char == '\t' ||
         this->current_char == ' ') {
    this->read_char();
  }
}

std::string Lexer::read_identifier() {
  int start = this->current_pos;

  while (is_letter(this->current_char)) {
    this->read_char();
  }

  return this->input.substr(start, this->current_pos - start);
}

std::string Lexer::read_number() {
  int start = this->current_pos;

  while (is_number(this->current_char)) {
    this->read_char();
  }

  return this->input.substr(start, this->current_pos - start);
}

}  // namespace lexer
