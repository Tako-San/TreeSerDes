#ifndef __INCLUDE_NODE_INODE_HH__
#define __INCLUDE_NODE_INODE_HH__

#include <string>
#include <vector>

struct INode
{
public:
  /**
   * @brief Pointer to parent node
   */
  INode *parent;

  /**
   * @brief Vector of pointers to children nodes
   */
  std::vector<INode *> children;

protected:
  INode() : parent(nullptr)
  {
  }

public:
  /**
   * @brief Returns node dump in dot format
   *
   * @return std::string
   */
  std::string dump() const;

  /**
   * @brief Returns node value as string
   *
   * @return std::string
   */
  virtual std::string stringify() const = 0;

  /**
   * @brief Destroy the INode object recursively.
   */
  virtual ~INode()
  {
    for (auto child : children)
      delete child;
  }
};

#endif // __INCLUDE_NODE_INODE_HH__
