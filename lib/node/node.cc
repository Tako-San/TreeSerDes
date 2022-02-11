#include <string_view>

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

static std::size_t replace_all(std::string &inout, std::string_view what,
                               std::string_view with)
{
  std::size_t count{};
  for (std::string::size_type pos{};
       inout.npos != (pos = inout.find(what.data(), pos, what.length()));
       pos += with.length(), ++count)
  {
    inout.replace(pos, what.length(), with.data(), with.length());
  }
  return count;
}

std::string StrNode::stringify()
{
  auto res = str;
  replace_all(res, "\\", "\\\\");
  replace_all(res, "\"", "\\\"");
  replace_all(res, "[", "\\[");
  replace_all(res, "]", "\\]");
  return res;
}
