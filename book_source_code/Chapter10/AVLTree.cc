#include <cstdlib>
#include "AVLTree.h"

AVLTreeADT::AVLTreeADT()
{
  root = NULL;
}

void Destroy(TreeNode*& tree);

AVLTreeADT::~AVLTreeADT()
// Calls recursive function Destroy to destroy the tree.
{
  Destroy(root);
}

void Destroy(TreeNode*& tree)
// Post: tree is empty; nodes have been deallocated.
{
  if (tree != NULL)
  {
    Destroy(tree->left);
    Destroy(tree->right);
    delete tree;
  }
}

TreeNode* RotateRight(TreeNode* T)
// Returns the tree node resulting from a right rotation.
{
  TreeNode* S = T->left;
  TreeNode* B = S->right;
  S->right = T;
  T->left = B;
  return S;
}

TreeNode* RotateLeft(TreeNode* T)
// Returns the tree node resulting from a left rotation.
{
  TreeNode* S = T->right;
  TreeNode* B = S->left;
  S->left = T;
  T->right = B;
  return S;
}

TreeNode* RotateRightLeft(TreeNode* T)
// Returns the tree node resulting from a right-left rotation.
{
  TreeNode* S = T->right;
  T->right = RotateRight(S);
  return RotateLeft(T);
}

TreeNode* RotateLeftRight(TreeNode* T)
// Returns the tree node resulting from a left-right rotation.
{
  TreeNode* S = T->left;
  T->left = RotateLeft(S);
  return RotateRight(T);
}

int Height(TreeNode* T)
// Returns the height of a tree T.
{
  if (T == NULL)
    return 0;
  else {
    int heightLeft  = Height(T->left);
    int heightRight = Height(T->right);
    if (heightLeft > heightRight)
      return heightLeft + 1;
    else
      return heightRight + 1;
  }
}

int Difference(TreeNode* T)
// Returns the difference between the heights of the left and right subtree T.
// Assumes the given TreeNode* T is not null.
{
  return Height(T->left) - Height(T->right);
}

TreeNode* Balance(TreeNode* T)
// Checks and balances the subtree T.
{
  int balanceFactor = Difference(T);
  if (balanceFactor > 1) {
    if (Difference(T->left) > 1)
      return RotateRight(T);
    else
      return RotateLeftRight(T);
  }
  else if (balanceFactor < -1) {
    if (Difference(T->right) < 0)
      return RotateLeft(T);
    else
      return RotateRightLeft(T);
  }
  else
    return T;
}

void Insert(TreeNode*& tree, ItemType item)
// Inserts item into tree.
// Post:  item is in tree; search property is maintained.
{
  if (tree == NULL)
  {// Insertion place found.
    tree = new TreeNode;
    tree->right = NULL;
    tree->left = NULL;
    tree->info = item;
  }
  else if (item < tree->info) {
    Insert(tree->left, item);    // Insert in left subtree.
    tree->left = Balance(tree->left);
  }
  else {
    Insert(tree->right, item);   // Insert in right subtree.
    tree->right = Balance(tree->right);
  }
}

void AVLTreeADT::PutItem(ItemType item)
// Calls recursive function Insert to insert item into tree.
{
  Insert(root, item);
  root = Balance(root);
}

void AVLTreeADT::DeleteItem(ItemType item)
// Deletes the element whose key matches item's key.
{
  // Left as an exercise.
}
