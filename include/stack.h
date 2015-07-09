#ifndef __STACK_H__
#define __STACK_H__

typedef enum SR {
  STACK_OK = 0,
  STACK_ERROR = -1
} STACK_RETURN;


typedef int StackItem;


struct StackStruct {
  int capacity;
  int top;
  StackItem* stack;
};

typedef struct StackStruct StackType;


STACK_RETURN init_stack(StackType* sp, int max_size);
STACK_RETURN destroy_stack(StackType* sp);
STACK_RETURN push(StackType* sp, StackItem si);
StackItem pop(StackType* sp);

#endif