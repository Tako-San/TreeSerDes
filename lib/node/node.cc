#include <iostream>

#include "node.hh"

IntNode::IntNode(int number) : INode::INode(), num(number)
{
}

void IntNode::dump()
{
  std::cout << num << std::endl;
}

FloatNode::FloatNode(float number) : INode::INode(), num(number)
{
}

void FloatNode::dump()
{
  std::cout << num << std::endl;
}

StrNode::StrNode(const std::string &string) : INode::INode(), str(string)
{
}

void StrNode::dump()
{
  std::cout << str << std::endl;
}
