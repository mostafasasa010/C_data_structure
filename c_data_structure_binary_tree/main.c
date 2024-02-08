#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int number;
  struct node *left;
  struct node *right;
} node;

int search_tree(node *root, int num) {
  if (root == NULL) {
    printf("Number Not Found\n");
    return 1;
  } else if (num < root->number) {
    printf("Number Left: %i\n", num);
    return search_tree(root->left, num);
  } else if (num > root->number) {
    printf("Number Right: %i\n", num);
    return search_tree(root->right, num);
  } else {
    printf("Number Found\n");
  }
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
    free(tree);
    return 1;
  }
  n->number = 1;
  n->left = NULL;
  n->right = NULL;
  tree->left = n;

  n = malloc(sizeof(node));
  if (n == NULL) {
    free(tree->left);
    free(tree);
    return 1;
  }
  n->number = 3;
  n->left = NULL;
  n->right = NULL;
  tree->right = n;
  search_tree(tree, 2);
}
