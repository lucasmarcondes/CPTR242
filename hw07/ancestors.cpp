/****************************************************************************
 *
 * Howemork.06: Implement a three functions for printing tree ancestors.
 *
 * File Name:  ancestors.cpp
 * Name:       Lucas Marcondes
 * Course:     CPTR 242
 * Date:       6/6/18
 * Time Taken: ?
 *
 */
#include "TreeType.h"

void TreeType::AncestorsIterative(ItemType value, std::ofstream& outFile) {
    TreeNode* node = root;
    while(value != node->info && node != NULL){
        if(value < node->info){
            outFile << node->info;
            node = node->left;
        }
        else if (value > node->info){
            outFile << node->info;
            node = node->right;
        }
    }

}

void PrintAncestorsRecursive(TreeNode* tree, ItemType value, std::ofstream& outFile) {
    if (tree == NULL){
        return;
    }else if (tree->info > value){
        outFile << tree->info;
        PrintAncestorsRecursive(tree->left, value, outFile);
    }else if (tree->info < value){
        outFile << tree->info;
        PrintAncestorsRecursive(tree->right, value, outFile);
    }
}

void PrintAncestorsReverse(TreeNode* tree, ItemType value, std::ofstream& outFile) {
    if (tree == NULL){
        return;
    }else if (tree->info > value){
        PrintAncestorsReverse(tree->left, value, outFile);
        outFile << tree->info;
    }else if (tree->info < value){
        PrintAncestorsReverse(tree->right, value, outFile);
        outFile << tree->info;
    }
}