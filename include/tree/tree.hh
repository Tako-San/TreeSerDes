#ifndef __INCLUDE_TREE_TREE_HH__
#define __INCLUDE_TREE_TREE_HH__

#include <string>

#include "node/inode.hh"
#include "tree_view.hh"

class Tree
{
private:
  INode *root_{nullptr};

public:
  Tree(const Tree &) = delete;
  Tree &operator=(const Tree &) = delete;

  Tree(INode *root) : root_(root)
  {
  }

  std::string dump() const;

  ~Tree()
  {
    delete root_;
  }

  static TreeView makeTreeView(const Tree &tree)
  {
    return TreeView{tree.root_};
  }

  static std::string serialize(const Tree &tree);
  static Tree deserialize();
};

#endif // __INCLUDE_TREE_TREE_HH__
