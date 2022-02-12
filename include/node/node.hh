#ifndef __INCLUDE_NODE_NODE_HH__
#define __INCLUDE_NODE_NODE_HH__

#include "inode.hh"


struct IntNode : public INode
{
public:
  int num;

  IntNode(int number);
  std::string stringify() const override;
  char typeID() const override;
};

struct FloatNode : public INode
{
public:
  float num;

  FloatNode(float number);
  std::string stringify() const override;
  char typeID() const override;
};

struct StrNode : public INode
{
public:
  std::string str;

  StrNode(const std::string &string);
  std::string stringify() const override;
  char typeID() const override;
};

#endif // __INCLUDE_NODE_NODE_HH__
