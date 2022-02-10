#ifndef __INCLUDE_NODE_NODE_HH__
#define __INCLUDE_NODE_NODE_HH__

#include <string>

#include "inode.hh"

struct IntNode : public INode
{
public:
  int num;

public:
  IntNode(int number);
  void dump() override;
};

struct FloatNode : public INode
{
public:
  float num;

public:
  FloatNode(float number);
  void dump() override;
};

struct StrNode : public INode
{
public:
  std::string str;

public:
  StrNode(const std::string &string);
  void dump() override;
};

#endif // __INCLUDE_NODE_NODE_HH__
