#ifndef LIST_UTILS_H
#define LIST_UTILS_H

#include "list.h"

bool list_insert_all(list *dest, size_t index, const list *src);

list *list_split_at(list *t, size_t index);

#endif 