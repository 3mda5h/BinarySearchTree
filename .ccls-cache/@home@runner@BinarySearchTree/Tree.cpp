#include <iostream>
#include "Tree.h"

using namespace std;

Tree::Tree()
{
  root = NULL;
}

void Tree::insert(int number)
{
  
}

bool Tree::search(int number)
{
  return search_impl(number, root);
}

bool Tree::search_impl(int number, Node* current)
{
  if(current->number == 2) return true;
  else
  {
    search_impl(number, current->right);
    search_impl(number, current->left);
  }
  return false;
}

void Tree::display(Node* current, int level)
{
  if(current == NULL && level == 0)
  {
    cout << "Tree is empty :(" << endl;
    return;
  }
  if(current != NULL)
  {
    display(current->left, level + 1);
    printTabs(level);
    cout << current->number << endl;
    display(current->right, level + 1);
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