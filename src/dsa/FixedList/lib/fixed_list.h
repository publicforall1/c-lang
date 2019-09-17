#ifndef FIXED_LIST_H
#define FIXED_LIST_H

#include <stdbool.h>

#define capacity 10

typedef int ElementType;
typedef int Position;
typedef struct {
    ElementType Element[capacity];
    int length;
} List;

bool is_empty_list(const List);
ElementType retrieve(const Position, const List);
void show_all(const List);
void makenull_list(List*);
void insert_list(const ElementType, const Position, List*);
void delete_list(const Position, List*);
Position first_list(const List);
Position end_list(const List);
Position previous(const Position, const List);
Position next(const Position, const List);
Position locate(const ElementType, const List);

#endif
