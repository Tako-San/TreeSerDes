#ifndef __INCLUDE_NODE_INODE_HH__
#define __INCLUDE_NODE_INODE_HH__

#include <vector>

struct INode
{
public:
  INode *parent;
  std::vector<INode *> children;

protected:
  INode(/* args */);

public:
  virtual void dump();
  virtual ~INode() = default;
};

#endif // __INCLUDE_NODE_INODE_HH__
