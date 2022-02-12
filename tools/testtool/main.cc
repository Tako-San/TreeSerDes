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

  // std::cout << Tree::serialize(tree) << std::endl;

  Lexer lexer{std::cin};

  auto desTree = Tree::deserialize(std::cin);
  std::cout << desTree.dump();
  return 0;
}
