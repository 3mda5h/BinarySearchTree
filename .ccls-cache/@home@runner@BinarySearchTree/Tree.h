#ifndef TREE_H
#define TREE_H

#include <iostream>

using namespace std;

struct Node
{
  Node* left;
  Node* right;
  int number;
};

class Tree
{
  public:
  Tree();
  void insert(int number);
  bool search(int number);
  bool search_impl(int number, Node* current);
  void display(Node* current, int level);
  void printTabs(int level);
  private: 
  Node* root;
};

#endif