#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int number;
  struct node *left;
  struct node *right;
} node;

void tree_print(node *root) {
  if (root == NULL) {
    return;
  }
  tree_print(root->left);
  printf("%i\n", root->number);
  tree_print(root->right);

  free(root);
}

int main(void) {
  node *tree = NULL;
  node *n = malloc(sizeof(node));
  if (n == NULL) {
    return 1;
  }
  n->number = 2;
  n->left = NULL;
  n->right = NULL;
  tree = n;

  n = malloc(sizeof(node));
  if (n == NULL) {
    return 1;
  }
  n->number = 1;
  n->left = NULL;
  n->right = NULL;
  tree->left = n;

  n = malloc(sizeof(node));
  if (n == NULL) {
    return 1;
  }
  n->number = 3;
  n->left = NULL;
  n->right = NULL;
  tree->right = n;

  tree_print(tree);
}
