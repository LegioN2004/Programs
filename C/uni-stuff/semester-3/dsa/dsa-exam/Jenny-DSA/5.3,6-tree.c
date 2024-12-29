// // NOTE: the root node with a memory address is not a header in the case of a
// // tree, it's the mem address of the root node and it is used to point to the
// // root node of the tree
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node {
//   int data;
//   struct node *left, *right;
// } Node;

// // since it'll return pointer to the node, so we'll use the data type of the
// // Node*
// Node *createTree() {
//   int x = 0;
//   Node *newnode = (Node *)malloc(sizeof(Node));
//   printf("enter the data(-1 for no node)");
//   scanf("%d", &x);
//   if (x == -1) {
//     return NULL;
//   } else {
//     newnode->data = x;
//     // newnode -> left =
//     printf("enter the left child of %d", x);
//     // calling the createTree in the left because we want to create a node in
//     // the left child of the parent, and that will return the address of the new
//     // node, and everything will happen recursively. We can also do that for the
//     // right, and note that newnode doesn't lose the old pointer that started
//     // from the root to the parent and the children, it is created as a copy.
//     newnode->left = createTree();
//     printf("Enter the right child of %d", x);
//     newnode->right = createTree();
//     return newnode;
//   }
// }

// /*
// the tree traversal will be like:
// inorder: 7 5 8 4 10 1
// preorder: 4 5 7 8 10 1
// postorder: 7 8 5 1 10 4
// */

// void preorderTree(Node *root) {
//   Node *newnode = root;
//   // root ka data because it is pointed to the a single parent only so directly
//   printf("%d", root->data);
//   if (root == NULL) {
//     return;
//   }
//   // but after that parent we need to go left because preorder, but we cannot
//   // directly print it cause it is the root for the children and not the left
//   // node of the parent only. So we need to go to the left of the parents until
//   // we reach the leaf node and so call the tree again recursively
//   preorderTree(root->left);
//   preorderTree(root->right);
//   // we need to stop it as well so we'll need to stop it as well, so we can
//   // return if
// }

// void inorderTree(Node *root) {
//   Node *newnode = root;
//   if (root == NULL) {
//     return;
//   }
//   inorderTree(root->left);
//   printf("%d", root->data);
//   inorderTree(root->right);
// }

// void postorderTree(Node *root) {
//   Node *newnode = root;
//   if (root == NULL) {
//     return;
//   }
//   postorderTree(root->left);
//   postorderTree(root->right);
//   printf("%d", root->data);
// }

// void main() {
//   Node *root = NULL;
//   // this createTree function will return the created nodes of the tree so we'll
//   // assign the root to it.
//   root = createTree();

//   printf("preorder is: ");
//   preorderTree(root);  // it is going to pass the root pointer to the root node
// }

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node *createTree() {
    int x;
    printf("Enter the data (-1 for no node): ");
    scanf("%d", &x);

    if (x == -1) {
        return NULL; // No node
    }

    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = x;

    printf("Enter the left child of %d\n", x);
    newnode->left = createTree();

    printf("Enter the right child of %d\n", x);
    newnode->right = createTree();

    return newnode;
}

void preorderTree(Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);  // Print root
    preorderTree(root->left);  // Traverse left subtree
    preorderTree(root->right); // Traverse right subtree
}

void inorderTree(Node *root) {
    if (root == NULL) {
        return;
    }
    inorderTree(root->left);   // Traverse left subtree
    printf("%d ", root->data); // Print root
    inorderTree(root->right);  // Traverse right subtree
}

void postorderTree(Node *root) {
    if (root == NULL) {
        return;
    }
    postorderTree(root->left);  // Traverse left subtree
    postorderTree(root->right); // Traverse right subtree
    printf("%d ", root->data);  // Print root
}

int main() {
    Node *root = NULL;

    printf("Create the tree:\n");
    root = createTree();

    printf("\nPreorder traversal: ");
    preorderTree(root);

    printf("\nInorder traversal: ");
    inorderTree(root);

    printf("\nPostorder traversal: ");
    postorderTree(root);

    return 0;
}
