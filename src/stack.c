#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

#define MAX_STACK_SIZE 10

int main(void) {

  int i=0;
  StackType my_stack;

  if (init_stack(&my_stack, MAX_STACK_SIZE) != STACK_OK) {
    printf("ERROR: Unable to create stack.\n");
    exit(-1);
  } else {
    printf("Stack created.\n");
  }

  push(&my_stack, 5);
  push(&my_stack, 10);
  push(&my_stack, 15);
  push(&my_stack, 20);
  push(&my_stack, 25);
  push(&my_stack, 30);
  push(&my_stack, 35);
  push(&my_stack, 40);
  push(&my_stack, 45);
  push(&my_stack, 50);

  for (i=0; i<MAX_STACK_SIZE; i++) {
    printf("pop:%2d\n", pop(&my_stack));
  }


  if (destroy_stack(&my_stack) != STACK_OK) {
    printf("ERROR: Unable to delete stack.\n");
    exit(-1);
  } else {
    printf("Stack deleted.\n");
  }

  return 0;
}


STACK_RETURN init_stack(StackType* sp, int max_size) {
  printf("Creating a stack with size %d\n", max_size);

  if (max_size <= 0) {
    printf("errant size passed to init_stack: %d\n", max_size);
    return -1;
  }

  sp->stack = NULL;

  // allocate space for the array
  sp->stack = malloc(sizeof(StackItem) * max_size);
  if (sp->stack == NULL) {
    printf("malloc error on array\n");
    return -1; 
  }

  sp->capacity = max_size;
  sp->top = 0;
  memset(sp->stack, 0, sizeof(StackItem) * max_size);

  return STACK_OK;
}


STACK_RETURN destroy_stack(StackType* sp) {
  // free the array
  free(sp->stack);
  return STACK_OK;
}

STACK_RETURN push(StackType* sp, StackItem si) {
  if (sp->top >= (sp->capacity)) {
    printf("Push error.  Stack full.\n");
    return STACK_ERROR;
  }

  // add item
  sp->stack[sp->top] = si;
  // move top up one
  sp->top = sp->top + 1;

  return STACK_OK;
}

StackItem pop(StackType* sp) {
  StackItem si = 0;

  if (sp->top == 0) {
    printf("Pop error.  Stack empty.\n");
    return STACK_ERROR; 
  }
  // remove item
  si = sp->stack[sp->top-1];
  // move top down one
  sp->top = sp->top - 1;
  return si;
}


