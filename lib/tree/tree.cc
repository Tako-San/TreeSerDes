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
