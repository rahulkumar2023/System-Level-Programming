#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "stack_utils.h"

stack* stack_split_at(stack* s, size_t index) 
{
    
    if (s == NULL)
    {
        return NULL;
    }
    if (index > s->size)
    {
        return NULL;
    }

    if (index == s->size) 
    {
        stack* new_stack = (stack*)malloc(sizeof(stack));
        if (new_stack == NULL) 
        {
            return NULL;  
        }

        new_stack->top = NULL;
        new_stack->size = 0;
        return new_stack;
    }

    
    node* current = s->top;
    size_t i = 0;
    while (i < index - 1)
    {
        current = current->next;
        i++;
    }

    stack* new_stack = (stack*)malloc(sizeof(stack));
    if (new_stack == NULL) {
        return NULL;  
    }
    new_stack->top = current->next;
    new_stack->size = s->size - index;
    current->next = NULL;
    s->size = index;
    return new_stack;
}

bool double_less_than(const void* val1, const void* val2) 
{
    const double* double_val1 = (const double*)val1;
    const double* double_val2 = (const double*)val2;
    return (*double_val1) <= (*double_val2);
}

bool stack_is_sorted(const stack* s, stack_leq_func eq) 
{
    if (s == NULL || eq == NULL) 
    {
        return false;
    }

    if (s->size == 0) 
    {
        return true;
    }

    const node* current = s->top;

    while (current->next != NULL) 
    {
        if (!eq(current->data, current->next->data)) 
        {
            return false;
        }

        current = current->next;
    }

    return true;
}
