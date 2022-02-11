#ifndef __INCLUDE_NODE_INODE_HH__
#define __INCLUDE_NODE_INODE_HH__

#include <string>
#include <vector>

struct INode
{
public:
  INode *parent;
  std::vector<INode *> children;

protected:
  INode() : parent(nullptr)
  {
  }

public:
  /* dump in dot format */
  std::string dump();

  virtual std::string stringify() = 0;

  /* recursive - not really good */
  virtual ~INode()
  {
    for (auto child : children)
      delete child;
  }
};

#endif // __INCLUDE_NODE_INODE_HH__
