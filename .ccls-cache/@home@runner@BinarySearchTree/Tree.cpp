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

void Tree::remove(int number)
{
  Node* removeThis = search_impl(root, number);
  if(removeThis == NULL)
  {
    cout << "That number isn't in the tree!" << endl;
    return;
  }
  //if it only has one child
  if(removeThis->left == NULL)
  {
    removeThis->right // need the previous one...
  }
  //find next largest number - right once, then left until end
  Node* current = removeThis;
  Node* previous;
  current = removeThis->right;
  while(current->left != NULL) 
  {
    previous = current;
    current = current->left;
  }
  removeThis->number = current->number; //replacing the number were removing with the next larges number in tree
  if(current->right != NULL)
  {
    previous->left = current->right;
  }
  previous->right = NULL;
  delete current;
}

Node* Tree::search(int number)
{
  return search_impl(root, number);
}

//searches tree for certain number. if number is there, returns it's node. if not, returns null
Node* Tree::search_impl(Node* current, int number)
{
  if(current == NULL) return NULL;
  if(current->number == number) return current;
  if(number > current->number) return search_impl(current->right, number);
  return search_impl(current->left, number);
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
  else if(current != NULL)
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