#ifndef __cplusplus
typedef char bool;
#define true 1
#define false 0
#endif

struct node
{
  struct node * next;
};
typedef struct node node;

typedef struct
{
  node * first;
  node * last;
} list;

void list_init(list * container)
{
  container->first = 0;
  container->last = 0;
}

bool empty(list * container)
{
  return 0 == container->first;
}

node * first(list * container)
{
  return container->first;
}

node * next(node * current)
{
  return current->next;
}

void push(list * container, node * element)
{
  if (empty(container)) {
    container->first = element;
    container->last = element;
  } else {
    container->last->next = element;
    container->last = element;
  }

  element->next = 0;
}

node * shift(list * container)
{
  node * element = container->first;
  container->first = container->first->next;
  return element;
}

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
  node header;
  int value;
} item;

int main()
{
  list items;
  item * item_one = (item *) malloc(sizeof(item));
  item * item_two = (item *) malloc(sizeof(item));
  item * item_three = (item *) malloc(sizeof(item));

  item_one->value = 1;
  item_two->value = 2;
  item_three->value = 3;

  list_init(&items);

  push(&items, &item_one->header);
  push(&items, &item_two->header);
  push(&items, &item_three->header);

  for (item_one = (item *) first(&items); item_one; item_one = (item *) next(&item_one->header)) {
    printf("%d\n", item_one->value);
  }

  while (!empty(&items)) {
    item_one = (item *) shift(&items);
    free(item_one);
  }

  return 0;
}
