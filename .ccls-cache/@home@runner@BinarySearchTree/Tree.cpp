#include <iostream>
#include "Tree.h"

using namespace std;

Tree::Tree()
{
  root = NULL;
}

void Tree::insert(int number)
{
  insert_impl(root, number); 
}

void Tree::insert_impl(Node* current, int number)
{
  if(root == NULL)
  {
    Node* newRoot = new Node();
    newRoot->number = number;
    root = newRoot;
    return;
  }
  if(current != NULL)
    {
      if(number > current->number)
      {
        if(current->right != NULL)
        {
          insert_impl(current->right, number);
        }
        else
        {
          Node* newNode = new Node();
          newNode->number = number;
          current->right = newNode;
        }
      }
      else //number is less than or equal to current
      {
        if(current->left != NULL)
        {
          insert_impl(current->left, number);
        }
        else
        {
          Node* newNode = new Node();
          newNode->number = number;
          current->left = newNode;
        }
      }
    }
}

bool Tree::search(int number)
{
  return search_impl(root, number);
}

bool Tree::search_impl(Node* current, int number)
{
  if(current->number == 2) return true;
  else
  {
    search_impl(current->right, number);
    search_impl(current->left, number);
  }
  return false;
}

void Tree::display()
{
  display_impl(root, 0);
}

void Tree::display_impl(Node* current, int level)
{
  if(current == NULL && level == 0)
  {
    cout << "Tree is empty :(" << endl;
    return;
  }
  if(current != NULL)
  {
    display_impl(current->right, level + 1);
    printTabs(level);
    cout << current->number << endl;
    display_impl(current->left, level + 1);
  }
  else return;
}

//prints tabs according to level of tree that value is at
void Tree::printTabs(int level)
{
  for(int i = 0; i < level; i++)
  {
    cout << "     ";    
  }
}