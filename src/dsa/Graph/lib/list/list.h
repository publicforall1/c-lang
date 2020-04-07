#ifndef LIST_H
#define LIST_H

#define LIST_CAPACITY 100
typedef int Type;

typedef struct {
    Type arr[LIST_CAPACITY];
    int length;
} List;

void init_list(List* l); // O(1)
void append(List* l, Type value); // O(1)
int is_exist(List l, Type value); // O(n)
int length(List l); // O(1)
Type value_at(List l, int position); // O(1)
void print_list(List l); // O(n)

#endif
