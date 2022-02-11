#include "node.hh"

//==============================================================//

IntNode::IntNode(int number) : INode::INode(), num(number)
{
}

std::string IntNode::stringify()
{
  return std::to_string(num);
}

//==============================================================//

FloatNode::FloatNode(float number) : INode::INode(), num(number)
{
}

std::string FloatNode::stringify()
{
  return std::to_string(num);
}

//==============================================================//

StrNode::StrNode(const std::string &string) : INode::INode(), str(string)
{
}

std::string StrNode::stringify()
{
  return str;
}
