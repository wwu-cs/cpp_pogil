#include <iostream>

class TreeNode {
public:
  int value;
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;
};

void insert(int d, TreeNode **tptr);
TreeNode *newTreeNode(int d);
void insertR(int d, TreeNode **tptr);
TreeNode *createTree(int a[], int size);
int size(TreeNode *t);

/* insert
 * inserts data item d into tree; note that this is a BST so it is ordered
 */
void insert(int d, TreeNode **tptr) {
  // create new node for data
  TreeNode *toInsert = newTreeNode(d);
  TreeNode *curr = *tptr;
  if (curr == nullptr) {
    *tptr = toInsert; // make this the tree
    return;
  }
  // check value of t to see if new node should be to the right or left of curr
  while (curr != nullptr) {
    if (d < curr->value) { // goes to left
      if (curr->left == nullptr) {
        curr->left = toInsert;
        return;
      }
      // keep going left
      curr = curr->left;
    } else { // goes to right
      if (curr->right == nullptr) {
        curr->right = toInsert;
        return;
      }
      // keep going right
      curr = curr->right;
    }
  }
}

/* newTreeNode
 * helper function, creates a new tree node with value d
 * returns the address of the new node
 */
TreeNode *newTreeNode(int d) {
  TreeNode *toReturn = new TreeNode();
  toReturn->value = d;
  toReturn->left = nullptr;
  toReturn->right = nullptr;
  return toReturn;
}

/* insertR
 * inserts data item d into tree; note that this is a BST so it is ordered
 * note: this function is written recursively
 */
void insertR(int d, TreeNode **tptr) {
  if (*tptr == nullptr) {
    *tptr = newTreeNode(d);
  } else if (d < (*tptr)->value) {
    insertR(d, &(*tptr)->left);
  } else {
    insertR(d, &(*tptr)->right);
  }
}

/* createTree
 * creates a binary search tree with data stored in array a
 */
TreeNode *createTree(int a[], int size) {
  if (size <= 0) {
    return nullptr;
  }
  TreeNode *toReturn = newTreeNode(a[0]); // insert first item from list
  int i;
  for (i = 1; i < size; i++) {
    insert(a[i], &toReturn);
  }
  return toReturn;
}

/* size
 * returns the number of nodes in the tree
 */
int size(TreeNode *t) {
  if (t == nullptr) {
    return 0;
  }
  return 1 + size(t->left) + size(t->right);
}

int main() {
  TreeNode *tree = nullptr;
  insert(1, &tree);
  insert(3, &tree);
  insert(4, &tree);
  insert(6, &tree);
  insert(7, &tree);
  insert(8, &tree);
  insert(9, &tree);
  std::cout << size(tree) << std::endl;

  return 0;
}