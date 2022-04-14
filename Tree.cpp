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
  /*using nonrecursive search. I'm not using my already made search function because I 
  need both the parent and its child (function can't really return 2 things :(  ) */
  Node* removeThis = root;
  Node* parent;
  while(removeThis != NULL && removeThis->number != number) //for now removethis is the current node
  {
    parent = removeThis; 
    if(number > removeThis->number) removeThis = removeThis->right;
    else removeThis = removeThis->left;
  }
  if(removeThis == NULL)
  {
    cout << "That number isn't in the tree!" << endl;
    return;
  }
  //if removeThis only has one child remove it and connect its child with parent of removeThis
  if(removeThis->left == NULL ^ removeThis->right == NULL) //^ = exclusive or - returns true if only one of the statements is true (so if one child is null but not both)
  {
    if(removeThis->number > parent->number) //removeThis is the right child of parent
    {
      if(removeThis->right != NULL) parent->right = removeThis->right; //removeThis has a right child, connect this child with parent of Remove this
      else parent->right = removeThis->left;
    }
    else //removeThis is the left child of parent
    {
      if(removeThis->right != NULL) parent->left = removeThis->right; 
      else parent->left = removeThis->left;
    }
    delete removeThis;
    return;
  }
  if(removeThis->left == NULL && removeThis->right == NULL) //removeThis has no children 
  {
    if(removeThis->number > parent->number) parent->right = NULL;
    else parent->left = NULL;
    delete removeThis;
    return;
  }
  
  //removeThis has two children: find next largest number - right once, then left until end
  Node* previous;
  Node* nextLargest = removeThis->right;
  while(nextLargest->left != NULL) 
  {
    previous = nextLargest;
    nextLargest = nextLargest->left;
  }
  removeThis->number = nextLargest->number; //replacing the number were removing with the next largest number in tree
  if(nextLargest->right != NULL)
  {
    previous->left = nextLargest->right;
  }
  previous->right = NULL;
  delete nextLargest;
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