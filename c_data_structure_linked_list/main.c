#include <stdio.h>
#include <stdlib.h>

/*
  //////////////////////////////////[LINKED LIST]//////////////////////////////////
  ////////////////////{node}/////////////////{node}//////////////////{node}////////
  //||||||||-----||||||||||||||||||-----||||||||||||||||||-----||||||||||||||||||//
  //||list|| --> ||value||pointer|| --> ||value||pointer|| --> |||value|||NULL|||//
  //||||||||-----||||||||||||||||||-----||||||||||||||||||-----||||||||||||||||||//
  /////////////////////////////////////////////////////////////////////////////////
*/

typedef struct node {
  int number;
  struct node *next;
}node;

int main(void) {
  node *list = NULL;

  node *n = malloc(sizeof(node));
  if (n == NULL) {
    return 1;
  }
  n->number = 1;
  n->next = NULL;
  list = n;

  n = malloc(sizeof(node));
  if (n == NULL) {
    free(list);
    return 1;
  }
  n->number = 2;
  n->next = NULL;
  list->next = n;

  n = malloc(sizeof(node));
  if (n == NULL) {
    free(list->next);
    free(list);
    return 1;
  }
  n->number = 3;
  n->next = NULL;
  list->next->next = n;

  while (list != NULL) {
    printf("%i\n", list->number);
    list = list->next;
  }

  return 0;
}