#ifndef __INCLUDE_LEXER_LEXER_HH__
#define __INCLUDE_LEXER_LEXER_HH__

#include <istream>
#include <string>

// The lexer returns tokens [0-255] if it is an unknown character, otherwise one
// of these for known things.
enum class Token : int
{
  eof = -1,
  error = -2,

  typeID = -3,
  integer = -4,
  floating = -5,
  character = -6
};

class Lexer final
{
private:
  char typeID_{};    // Filled in if Token::typeID
  int intVal_{};     // Filled in if Token::integer
  char charVal_{};   // Filled in if Token::string
  float floatVal_{}; // Filled in if Token::floating

  std::istream *istream_;

public:
  Lexer(std::istream &istream);

  char typeID();
  int intVal();
  char charVal();
  float floatVal();

  int getTok();

private:
  int getChar();
};

#endif // __INCLUDE_LEXER_LEXER_HH__
