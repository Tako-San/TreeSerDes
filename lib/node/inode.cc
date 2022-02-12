#include <sstream>

#include "inode.hh"

std::string INode::serialize() const
{
  std::stringstream res{};

  res << typeID() << ":" << stringify();

  for (auto child : children)
  {
    if (nullptr == child)
      continue;

    res << "[" << child->serialize() << "]";
  }

  return res.str();
}
