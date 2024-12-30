#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left, *right;
} Node;

Node *createTree() {
  int x = 0;
  printf("enter the data(-1 for no node): ");
  scanf("%d", &x);

  if (x == -1) {
    return NULL;
  }

  Node *newnode = (Node *)malloc(sizeof(Node));
  newnode->data = x;

  printf("enter the left child of %d\n", x);
  newnode->left = createTree();

  printf("enter the right child of %d\n", x);
  newnode->right = createTree();

  return newnode;
}

void preorderTree(Node *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);  // Print root
  preorderTree(root->left);   // Traverse left subtree
  preorderTree(root->right);  // Traverse right subtree
}

void inorderTree(Node *root) {
  if (root == NULL) {
    return;
  }
  inorderTree(root->left);    // Traverse left subtree
  printf("%d ", root->data);  // Print root
  inorderTree(root->right);   // Traverse right subtree
}

void postorderTree(Node *root) {
  if (root == NULL) {
    return;
  }
  postorderTree(root->left);   // Traverse left subtree
  postorderTree(root->right);  // Traverse right subtree
  printf("%d ", root->data);   // Print root
}

int main() {
  Node *root = NULL;

  printf("create the table\n");
  root = createTree();

  printf("\nPreorder traversal");
  preorderTree(root);

  printf("\nInorder traversal");
  inorderTree(root);

  printf("\nPostorder traversal");
  postorderTree(root);
  return 0;
}
