#ifndef __INCLUDE_TREE_TREE_VIEW_HH__
#define __INCLUDE_TREE_TREE_VIEW_HH__

#include "node/inode.hh"

class TreeView
{
private:
  INode *curNode_{nullptr};

public:
  TreeView(INode * nodePtr) : curNode_(nodePtr)
  {}
};

#endif // __INCLUDE_TREE_TREE_VIEW_HH__
