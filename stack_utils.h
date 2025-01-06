#ifndef STACK_UTILS_H
#define STACK_UTILS_H

#include <stdbool.h>
#include "stack.h"  

typedef bool (*stack_leq_func)(const void *, const void *);

bool double_less_than(const void *val1, const void *val2);

stack *stack_split_at(stack *s, size_t index);

bool stack_is_sorted(const stack *s, stack_leq_func leq);

#endif 