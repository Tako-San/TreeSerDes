#include <sstream>

#include "lexer/lexer.hh"
#include "node/node.hh"
#include "tree.hh"

/* TODO: make recursion on stack */
std::string Tree::dump() const
{
  std::stringstream ss{};
  ss << "digraph a {" << std::endl << root_->dump() << "}" << std::endl;
  return ss.str();
}

std::string Tree::serialize(const Tree &tree)
{
  return tree.root_->serialize();
}

static INode *handleNode(Lexer &lex)
{
  auto typeID = lex.typeID();
  lex.getTok(); // store node value

  switch (typeID)
  {
  case 'i':
    return new IntNode{lex.intVal()};
  case 'f':
    return new FloatNode{lex.floatVal()};
  case 'c':
    return new CharNode{lex.charVal()};
  default:
    return nullptr;
  }
}

Tree Tree::deserialize(std::istream &is)
{
  Lexer lex{is};
  INode *root{};
  int tok{};

  bool inChild = false;

  do
  {
    tok = lex.getTok();

    if (tok == static_cast<int>(Token::typeID))
    {
      lex.getTok(); // colon

      auto node = handleNode(lex);
      if (inChild)
      {
        root->children.push_back(node);
        node->parent = root;
        root = node;
      }
      else
        root = node;
    }

    if (tok == '[')
    {
      if (root == nullptr)
        throw std::runtime_error{"Current node is nullptr\n"};

      inChild = true;
    }

    if (tok == ']')
    {
      if (root == nullptr)
        throw std::runtime_error{"Current node is null\n"};
      if (root->parent == nullptr)
        throw std::runtime_error{"Current node parent is null\n"};

      root = root->parent;
    }

    if (tok == static_cast<int>(Token::error))
      throw std::runtime_error{"Lexer error\n"};
  } while (tok != static_cast<int>(Token::eof));

  return Tree{root};
}
