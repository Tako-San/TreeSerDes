#ifndef __INCLUDE_NODE_INODE_HH__
#define __INCLUDE_NODE_INODE_HH__

#include <string>
#include <vector>

struct INode
{
public:
  INode *parent{nullptr};
  std::vector<INode *> children;

public:
  std::string serialize() const;
  virtual char typeID() const = 0;
  virtual std::string stringify() const = 0;
  virtual ~INode()
  {
    for (auto child : children)
      delete child;
  }
};

#endif // __INCLUDE_NODE_INODE_HH__
