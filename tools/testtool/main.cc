#include <iostream>

#include "lexer/lexer.hh"
#include "node/inode.hh"
#include "node/node.hh"
#include "tree/tree.hh"

int main()
{
  INode *root = new IntNode{3};
  root->children.push_back(new FloatNode{2.5});
  root->children.push_back(new CharNode{'a'});

  auto *fnode = root->children[0];
  fnode->children.push_back(new CharNode{'b'});

  Tree tree{root};
  // std::cout << tree.dump();

  std::cout << Tree::serialize(tree) << std::endl;

  Lexer lexer{std::cin};

  int tok{};
  do
  {
    tok = lexer.getTok();

    if (tok < 0)
      std::cout << tok << std::endl;
    else
    {
      auto ch = static_cast<char>(tok);
      std::cout << ch << std::endl;
    }
  } while (tok != static_cast<int>(Token::eof));

  return 0;
}
