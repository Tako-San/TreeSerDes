#include <istream>
#include <string>

#include "lexer.hh"

Lexer::Lexer(std::istream &istream) : istream_(&istream)
{
}

char Lexer::typeID()
{
  return typeID_;
}

int Lexer::intVal()
{
  return intVal_;
}

char Lexer::charVal()
{
  return charVal_;
}

float Lexer::floatVal()
{
  return floatVal_;
}

/* getTok - Return the next token from standard istream. */
int Lexer::getTok()
{
  static int lastChar = ' ';

  /* Skip any whitespace. */
  while (std::isspace(lastChar))
    lastChar = getChar();

  if (std::isalpha(lastChar))
  {
    char letter = lastChar;
    if (lastChar = getChar(); ':' == lastChar)
    {
      typeID_ = letter;
      return static_cast<int>(Token::typeID);
    }
    if ('[' == lastChar || ']' == lastChar)
    {
      charVal_ = letter;
      return static_cast<int>(Token::character);
    }
    return static_cast<int>(Token::error);
  }

  if (std::isdigit(lastChar) || lastChar == '.')
  {
    std::string numStr{};
    do
    {
      numStr += lastChar;
      lastChar = getChar();
    } while (std::isdigit(lastChar) || lastChar == '.');

    if (auto it = numStr.find('.'); it == std::string::npos)
    {
      intVal_ = std::stoi(numStr);
      return static_cast<int>(Token::integer);
    }

    floatVal_ = std::stof(numStr);
    return static_cast<int>(Token::floating);
  }

  /* Check for end of file. Don't eat the EOF. */
  if (lastChar == EOF)
    return static_cast<int>(Token::eof);

  /* Otherwise, just return the character as its ascii value. */
  int ThisChar = lastChar;
  lastChar = getChar();
  return ThisChar;
}

int Lexer::getChar()
{
  auto ch = istream_->get();
  if (std::char_traits<char>::not_eof(ch))
    return ch;
  return EOF;
}
