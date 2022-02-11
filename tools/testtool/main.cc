#include <iostream>

#include "node/inode.hh"
#include "node/node.hh"

int main()
{
  INode *root = new IntNode{3};
  root->children.push_back(new FloatNode{2.5});
  root->children.push_back(new StrNode{"\"[text]\""});

  std::cout << "digraph a {" << std::endl << root->dump() << "}" << std::endl;

  delete root;
  return 0;
}
