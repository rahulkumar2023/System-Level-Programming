#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "list_utils.h"


bool list_insert_all(list *dest, size_t index, const list *src) 
{
    if (dest == NULL || src == NULL || dest == src || index > dest->size)
    {
        return false;
    }

    if (index == dest->size) 
    {
        for (size_t i = 0; i < src->size; ++i) 
        {
            if (!list_add(dest, src->arr[i])) 
            {
                return false;  
            }
        }
        return true;
    }

    size_t new_size = dest->size + src->size;

    if (new_size > dest->capacity)
    {
        size_t new_capacity = new_size * 2;  
        int *new_arr = realloc(dest->arr, new_capacity * sizeof(int));

        if (new_arr == NULL) 
        {
            return false;  
        }

        dest->arr = new_arr;
        dest->capacity = new_capacity;
    }

    memmove(&dest->arr[index + src->size], &dest->arr[index], (dest->size - index) * sizeof(int));

    memcpy(&dest->arr[index], src->arr, src->size * sizeof(int));
    dest->size = new_size;
    return true;
}

list *list_split_at(list *t, size_t index) 
{

    if (t == NULL || index > t->size) 
    {
        return NULL;
    }

    if (index == t->size) {
        return list_init_empty();
    }

    size_t new_size = t->size - index;

    list *new_list = (list *)malloc(sizeof(list));
    if (new_list == NULL) {
        return NULL;  
    }

    new_list->arr = (int *)malloc(new_size * sizeof(int));
    if (new_list->arr == NULL) 
    {
        free(new_list);
        return NULL;  
    }

    memcpy(new_list->arr, &t->arr[index], new_size * sizeof(int));
    t->size = index;
    t->capacity = t->size;
    return new_list;
}