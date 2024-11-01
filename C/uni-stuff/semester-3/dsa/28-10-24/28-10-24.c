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
  struct node *rootNode = NULL;
  rootNode = insertNode(rootNode, 9);
  insertNode(rootNode, 7);
  insertNode(rootNode, 5);
  insertNode(rootNode, 8);
  insertNode(rootNode, 14);
  insertNode(rootNode, 11);
  insertNode(rootNode, 16);

  printf("The postorder is :\n");
  createPostOrder(rootNode);

  printf("\nThe preorder is :\n");
  createPreOrder(rootNode);

  return 0;
}
