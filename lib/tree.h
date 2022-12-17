#ifndef TREE_H
#define TREE_H
#include <stdlib.h>
#include <stdio.h>

/**
 * TreeNode creation, see that it is different from a Node used in Stack or Queue, since it has parent, left and right pointers, instead of just next
 */
typedef struct TreeNode TreeNode;
typedef struct Tree Tree;

struct TreeNode {
  int isRoot;
  int value;
  Tree *tree;
  TreeNode *parent;
  TreeNode *left;
  TreeNode *right;
};

struct Tree {
  TreeNode *root;
  int depth;
};

/**
 * TreeNode constructor
 */

TreeNode* createTreeNode(int value) {
  TreeNode *node = malloc(sizeof(TreeNode));
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

/**
 * Functions declarations
 */

void searchIntoNode(TreeNode *node, int value);
TreeNode* insertIntoLeftNode(TreeNode *node, int value);
TreeNode* insertIntoRightNode(TreeNode *node, int value);

/**
 * Binary search tree constructor
 */

Tree* createBinarySearchTree() {
  Tree *t = malloc(sizeof(Tree));

  t->depth = 0;
  return t;
}

/**
 * Insert a new node using an existing tree
 */

void insertTreeNode(Tree *tree, int value) {
  TreeNode *node = createTreeNode(value);
  if (tree->depth == 0) {
    node->left = NULL;
    node->right = NULL;
    node->tree = tree;
    node->isRoot = 1;
    node->value = value;
    tree->root = node;
  } else {
    // will search starting the the root to check where it can be inserted
    searchIntoNode(tree->root, value);
  }
  // increase number of nodes in the tree
  tree->depth++;
}

/*
 * Searches for a specific value inside the tree
 */

TreeNode *searchSpecificValue(TreeNode *node, int value) {
  // current node has value equal to the provided one
  if (node->value == value) {
    return node;
  } else {
    // node is possibly in the left child of current node
    if (node->value > value && node->left != NULL) {
      return searchSpecificValue(node->left, value);
    }

    // node is possible in the right child of current node
    if (node->value <= value && node->right != NULL) {
      return searchSpecificValue(node->right, value);
    }

    // if no node was found with provided value
    return NULL;
  }
}

static int isNodeAtLeft(TreeNode *node) {
  // 1 = left, 0 = right
  return node->parent->value > node->value;
}

static void removeLeaf(TreeNode *node) {
    if (isNodeAtLeft(node)) {
      node->parent->left = NULL;
    } else {
      node->parent->right = NULL;
    }
}

static void eraseNodeFromParent(TreeNode *node) {
  if (isNodeAtLeft(node)) {
    node->parent->left = NULL;
  } else {
    node->parent->right = NULL;
  }
}


static void removeNodeWithOneChild(TreeNode *node) {
    TreeNode *aux;
    // checking if node to be removed has a child in left or right and then saving it in the temporary variable
    printf("here");
    if (node->left != NULL) {
      aux = node->left;
      node->parent->left = aux;
    } else {
      aux = node->right;
      node->parent->right = aux;
    }
}

static void assignNewParent(TreeNode *toBeRemoved, TreeNode *node) {
  if (isNodeAtLeft(toBeRemoved)) {
    toBeRemoved->parent->left = node;
  } else {
    toBeRemoved->parent->right = node;
  }
}

static void swapRemovedNode(TreeNode *toBeRemoved, TreeNode *node) {
  eraseNodeFromParent(node);
  assignNewParent(toBeRemoved, node);

  // assign old node's left and right to new one
  node->left = toBeRemoved->left;
  node->right = toBeRemoved->right;

  if (toBeRemoved->isRoot) {
    toBeRemoved->tree->root = node;
  }
}

static TreeNode* findInorderSuccessor(TreeNode *node) {
  if (node->right != NULL) {
    node = node->right;
    while (node->left != NULL) {
      node = node->left;
    }
    return node;
  }
  return NULL;
}

static void findInorderPredecessor(TreeNode *node) {
}

static void removeNodeWithBothChilds(TreeNode *node) {
  TreeNode *successor = findInorderSuccessor(node);

  if (successor != NULL) {
    swapRemovedNode(node, successor);
  }

  //TreeNode *predecessor = findInorderPredecessor(node);
}

static TreeNode* removeSingleNode(Tree *tree) {
  // root has no child
  TreeNode *aux = tree->root;
  tree->root = NULL;
  free(tree->root);
  tree->depth--;
  return aux;
}

/**
 * Will remove a specific node with the value provided, and return the removed node
 */

TreeNode* removeNodeFromTree(Tree *tree, int value) {
  // find node with the value we want
  TreeNode *findedNode = searchSpecificValue(tree->root, value);
  TreeNode *aux = findedNode;

  // if node is root, then we will need another approach
  if (tree->depth == 1) {
    return removeSingleNode(tree);
  }

  // if no node was found with this value
  if (findedNode == NULL) {
    return NULL;
  }

  // using this 3 flags we will decide the removal method we will call
  int noLeftChild = findedNode->left == NULL;
  int noRightChild = findedNode->right == NULL;
  int hasBothChilds = !noLeftChild && !noRightChild;

  if (noLeftChild && noRightChild) {
    removeLeaf(findedNode);
  } else if (hasBothChilds) {
    removeNodeWithBothChilds(findedNode);
  } else {
    removeNodeWithOneChild(findedNode);
  }
  free(findedNode);
  tree->depth--;
  return aux;
}

/*
 * Search for where the node can be inserted
 */
void searchIntoNode(TreeNode *node, int value) {
  if (node->value > value) {
    // provided node is less than the currentNode
    // check if this node is empty, if it is, then we can insert the new node in the left pointer of the current node in the function call
    if (node->left == NULL) {
      TreeNode *insertedNode = insertIntoLeftNode(node, value);
      insertedNode->parent = node;
    } else {
      // if not NULL, then keep searching
      searchIntoNode(node->left, value);
    }
  } else {
    // same as above, but for the right side
    if (node->right == NULL) {
      TreeNode *insertedNode = insertIntoRightNode(node, value);
      insertedNode->parent = node;
    } else {
      searchIntoNode(node->right, value);
    }
  }
  return;
}

TreeNode* insertIntoRightNode(TreeNode *node, int value) {
  node->right = createTreeNode(value);
  node->right->right = NULL;
  node->right->left = NULL;
  return node->right;
}

TreeNode *insertIntoLeftNode(TreeNode *node, int value) {
  node->left = createTreeNode(value);
  node->left->left = NULL;
  node->left->right = NULL;
  return node->left;
}

void eraseAllNodesFromTree(Tree *tree) {

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
