#include <iostream>

#include "node/inode.hh"
#include "node/node.hh"

#include "tree/tree.hh"

int main()
{
  INode *root = new IntNode{3};
  root->children.push_back(new FloatNode{2.5});
  root->children.push_back(new StrNode{"\"[text]\""});

  auto *fnode = root->children[0];
  fnode->children.push_back(new StrNode{"text"});

  Tree tree{root};
  std::cout << tree.dump();

  std::cout << Tree::serialize(tree) << std::endl;

  return 0;
}
