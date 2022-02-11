#ifndef __INCLUDE_NODE_NODE_HH__
#define __INCLUDE_NODE_NODE_HH__

#include "inode.hh"

struct IntNode : public INode
{
public:
  int num;

public:
  IntNode(int number);
  std::string stringify() const override;
};

struct FloatNode : public INode
{
public:
  float num;

public:
  FloatNode(float number);
  std::string stringify() const override;
};

struct StrNode : public INode
{
public:
  std::string str;

public:
  StrNode(const std::string &string);
  std::string stringify() const override;
};

#endif // __INCLUDE_NODE_NODE_HH__
