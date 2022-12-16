#ifndef TREE_H
#define TREE_H
#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode TreeNode;

struct TreeNode {
  int isRoot;
  int value;
  TreeNode *parent;
  TreeNode *left;
  TreeNode *right;
};

typedef struct {
  TreeNode *root;
  int depth;
} Tree;

void searchIntoNode(TreeNode *node, int value);
TreeNode* insertIntoLeftNode(TreeNode *node, int value);
TreeNode* insertIntoRightNode(TreeNode *node, int value);

Tree createBinarySearchTree() {
  Tree t;

  t.root = malloc(sizeof(TreeNode));
  t.depth = 0;

  return t;
}

void insertTreeNode(Tree *tree, int value) {
  TreeNode *node = malloc(sizeof(TreeNode));
  if (tree->depth == 0) {
    node->left = NULL;
    node->right = NULL;
    node->isRoot = 1;
    node->value = value;
    tree->root = node;
  } else {
    searchIntoNode(tree->root, value);
  }
  tree->depth++;
}

TreeNode *searchForTreeNode(TreeNode *node, int value) {
  if (node->value == value) {
    return node;
  } else {
    if (node->value > value && node->left != NULL) {
      return searchForTreeNode(node->left, value);
    }

    if (node->value <= value && node->right != NULL) {
      return searchForTreeNode(node->right, value);
    }

    return NULL;
  }
}

static int isNodeAtLeft(TreeNode *node) {
  // 1 = left, 0 = right
  return node->parent->value > node->value;
}

static void removeChildlessNode(TreeNode *node) {
    if (isNodeAtLeft(node)) {
      node->parent->left = NULL;
    } else {
      node->parent->right = NULL;
    }
}

static TreeNode* removeNodeWithOneChild(TreeNode *node) {
    TreeNode *aux;
    if (node->left != NULL) {
      aux = node->left;
    } else {
      aux = node->right;
    }

    if (isNodeAtLeft(node)) {
      node->parent->left = NULL;
    } else {
      node->parent->right = NULL;
    }

    return aux;
}

static void removeNodeWithBothChilds(TreeNode *node) {
}

TreeNode* removeNodeFromTree(Tree *tree, int value) {
  TreeNode *findedNode = searchForTreeNode(tree->root, value);
  TreeNode *aux = findedNode;

  if (findedNode == NULL) {
    return NULL;
  }

  int noLeftChild = findedNode->left == NULL;
  int noRightChild = findedNode->right == NULL;
  int hasBothChilds = !noLeftChild && !noRightChild;

  if (noLeftChild && noRightChild) {
    removeChildlessNode(findedNode);
  } else if (hasBothChilds) {
    removeNodeWithBothChilds(findedNode);
  } else {
    TreeNode *childNode = removeNodeWithOneChild(findedNode);
    if (findedNode->parent->value > childNode->value) {
      findedNode->parent->left = childNode;
    } else {
      findedNode->parent->right = childNode;
    }
  }
  // why?
  free(findedNode);
  return aux;
}

void searchIntoNode(TreeNode *node, int value) {
  TreeNode *insertedNode;
  if (node->value > value) {
    if (node->left == NULL) {
      insertedNode = insertIntoLeftNode(node, value);
      insertedNode->parent = node;
    } else {
      searchIntoNode(node->left, value);
    }
  } else {
    if (node->right == NULL) {
      insertedNode = insertIntoRightNode(node, value);
      insertedNode->parent = node;
    } else {
      searchIntoNode(node->right, value);
    }
  }
  return;
}

TreeNode* insertIntoRightNode(TreeNode *node, int value) {
  node->right = malloc(sizeof(TreeNode));
  node->right->value = value;
  node->right->right = NULL;
  node->right->left = NULL;
  return node->right;
}

TreeNode *insertIntoLeftNode(TreeNode *node, int value) {
  node->left = malloc(sizeof(TreeNode));
  node->left->value = value;
  node->left->left = NULL;
  node->left->right = NULL;
  return node->left;
}

void preOrder(TreeNode *node) {
  printf("%d ", node->value);
  if (node->left != NULL) {
    preOrder(node->left);
  } 

  if (node->right != NULL) {
    preOrder(node->right);
  }
  return;
}

void posOrder(TreeNode *node) {
  if (node->left != NULL) {
    posOrder(node->left);
  } 

  if (node->right != NULL) {
    posOrder(node->right);
  }
  printf("%d ", node->value);
  return;
}

void showTreeOrder(TreeNode *node) {
  if (node->left != NULL) {
    showTreeOrder(node->left);
  } 

  printf("%d ", node->value);

  if (node->right != NULL) {
    showTreeOrder(node->right);
  }
  return;
}

#endif
