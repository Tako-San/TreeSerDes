#include <string_view>

#include "node.hh"

//==============================================================//

IntNode::IntNode(int number) : INode::INode(), num(number)
{
}

std::string IntNode::stringify() const
{
  return std::to_string(num);
}

char IntNode::typeID() const
{
  return 'i';
}

//==============================================================//

FloatNode::FloatNode(float number) : INode::INode(), num(number)
{
}

std::string FloatNode::stringify() const
{
  return std::to_string(num);
}

char FloatNode::typeID() const
{
  return 'f';
}

//==============================================================//

CharNode::CharNode(char character) : INode::INode(), ch(character)
{
}

std::string CharNode::stringify() const
{
  return {ch};
}

char CharNode::typeID() const
{
  return 'c';
}
