#include <iostream>
using namespace std;

class BinaryTreeNode: Node {
  private:
    BinaryTreeNode *left;
    BinaryTreeNode *right;
  public:
    BinaryTreeNode(int v = 0) {value = v; left = nullptr; right = nullptr;}

    void print() {
      cout << "The value is: " << this->value << endl;
      if (this->left != nullptr) {
        cout << "The left child is: " << this->left->value << endl;
      }

      if (this->right != nullptr) {
        cout << "The right child is: " << this->right->value << endl;
      }

      if (this->right == nullptr && this->left == nullptr) {
        cout << "This node is a leaf." << endl;
      }
    }
};

