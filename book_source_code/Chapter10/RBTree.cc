#include <stdlib.h>
#include <stdio.h>
#include "RBTree.h"

RBTree::RBTree()
{
  root = NULL;
}

void Destroy(TreeNode*& tree);

RBTree::~RBTree()
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

TreeNode* Parent(TreeNode* N)
{
  return N->parent;
}

TreeNode* GrandParent(TreeNode* N)
{
  TreeNode* P = Parent(N);
  if (P == NULL) return NULL;
  else return Parent(P);
}

TreeNode* Uncle(TreeNode* N)
{
  TreeNode* G = GrandParent(N);
  if (G == NULL) return NULL;
  else if (Parent(N) == G->left) return G->right;
  else return G->left;
}

Color GetColor(TreeNode* N)
{
  if (N == NULL) return BLACK;
  else return N->color;
}

void SetColor(TreeNode* N, Color color)
{
  if (N != NULL) N->color = color;
}

void ReStructure(TreeNode* N)
{
  // Left as an exercise.
}

void ReColor(TreeNode* N)
{
  if (N == NULL) return; // do nothing if N is NULL
  TreeNode* P = Parent(N);
  TreeNode* G = GrandParent(N);
  TreeNode* U = Uncle(N);
  if (P == NULL) N->color = BLACK; // N is the root node
  else if (P != NULL || GetColor(P) != BLACK) {
    if (GetColor(U) == RED) {
      SetColor(P, BLACK);
      SetColor(U, BLACK);
      SetColor(G, RED);
      ReColor(G);
    }
    else
      ReStructure(N);
  }
}

void Insert(TreeNode*& tree, TreeNode* parent, ItemType item)
// Inserts item into tree.
// Post:  item is in tree; search property is maintained.
{
  if (tree == NULL)
  {// Insertion place found.
    printf("new node for %d\n", item);
    tree = new TreeNode;
    tree->right = NULL;
    tree->left = NULL;
    tree->parent = parent;
    tree->info = item;
    ReColor(tree);
  }
  else if (item < tree->info)
    Insert(tree->left, tree, item);     // Insert in left subtree.
  else
    Insert(tree->right, tree, item);    // Insert in right subtree.
}

void RBTree::PutItem(ItemType item)
// Calls recursive function Insert to insert item into tree.
{
  Insert(root, NULL, item);
}

void RBTree::DeleteItem(ItemType item)
// Deletes the element whose key matches item's key.
{
  // Left as an exercise.
}
