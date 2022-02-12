#include <sstream>

#include "tree.hh"

/* TODO: make recursion on stack */
std::string Tree::dump() const
{
  std::stringstream ss{};
  ss << "digraph a {" << std::endl << root_->dump() << "}" << std::endl;
  return ss.str();
}

std::string Tree::serialize(const Tree &tree)
{
  return tree.root_->serialize();
}

// auto thisPtrDec = reinterpret_cast<uint64_t>(this);

// std::stringstream res{};
// res << thisPtrDec << " [label=\"" << stringify() << "\"];" << std::endl;

// for (auto child : children)
// {
//   auto childPtrDec = reinterpret_cast<uint64_t>(child);
//   res << thisPtrDec << " -> " << childPtrDec << ";" << std::endl;
//   if (child != nullptr)
//     res << child->dump();
// }

// return res.str();