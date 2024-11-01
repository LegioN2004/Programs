#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left, *right;
};

struct node *newNode(int item) {
  struct node *temporary = (struct node *)malloc(sizeof(struct node));
  temporary->data = item;
  temporary->left = temporary->right = NULL;
  return temporary;
}

void createPostOrder(struct node *root) {
  if (root != NULL) {
    createPostOrder(root->left);
    createPostOrder(root->right);
    printf("%d ", root->data);
  }
}

void createPreOrder(struct node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    createPreOrder(root->left);
    createPreOrder(root->right);
  }
}

struct node *insertNode(struct node *node, int data) {
  if (node == NULL) return newNode(data);

  if (data < node->data)
    node->left = insertNode(node->left, data);
  else if (data > node->data)
    node->right = insertNode(node->right, data);

  return node;
}

int main() {
  struct node *root = NULL;
  root = insertNode(root, 9);
  insertNode(root, 7);
  insertNode(root, 5);
  insertNode(root, 8);
  insertNode(root, 14);
  insertNode(root, 11);
  insertNode(root, 16);

  printf("The postorder is :\n");
  createPostOrder(root);

  printf("\nThe preorder is :\n");
  createPreOrder(root);

  return 0;
}
