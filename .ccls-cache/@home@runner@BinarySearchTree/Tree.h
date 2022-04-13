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
  void insert_impl(Node* current, int number);
  Node* search(int number);
  Node* search_impl(Node* current, int number);
  void remove(int number);
  void display();
  void display_impl(Node* current, int level);
  void printTabs(int level);
  private: 
  Node* root;
};

#endif