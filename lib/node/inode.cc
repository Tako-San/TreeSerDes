#include <sstream>

#include "inode.hh"

std::string INode::dump() const
{
  auto thisPtrDec = reinterpret_cast<uint64_t>(this);

  std::stringstream res{};
  res << thisPtrDec << " [label=\"" << stringify() << "\"];" << std::endl;

  for (auto child : children)
  {
    auto childPtrDec = reinterpret_cast<uint64_t>(child);
    res << thisPtrDec << " -> " << childPtrDec << ";" << std::endl;
    if (child != nullptr)
      res << child->dump();
  }

  return res.str();
}
