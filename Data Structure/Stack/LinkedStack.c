#include "Stack.h"

struct node
{
    stack_data_t data;
    struct node *next;
};

struct stack
{
    int count;
    struct node *top;
};

/*******************************
Helper functions implementation.
*******************************/

/*******************************
Interface functions implementation.
*******************************/

stack_t *Stack_Create(void)
{
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
    if (stack == NULL)
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }

    stack->top = NULL;
    stack->count = 0;

    return stack;
}

void Stack_Destroy(stack_t *stack)
{
    while (stack->top)
    {
        struct node *current = stack->top->next;
        free(stack->top);
        stack->top = current;
    }
    free(stack);
}

int Stack_Size(const stack_t *stack)
{
    return stack->count;
}

bool Stack_IsEmpty(const stack_t *stack)
{
    return stack->count == 0;
}

void Stack_Push(stack_t *stack, stack_data_t data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    if (node == NULL)
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }
    node->data = data;
    node->next = stack->top;
    stack->top = node;

    stack->count++;
}

stack_data_t Stack_Pop(stack_t *stack)
{
    if (Stack_IsEmpty(stack))
    {
        fprintf(stderr, "The stack is empty.\n");
        exit(EXIT_FAILURE);
    }

    struct node *node = stack->top;
    stack->top = node->next;
    stack_data_t data = node->data;
    free(node);

    stack->count--;

    return data;
}

stack_data_t Stack_Top(const stack_t *stack)
{
    if (Stack_IsEmpty(stack))
    {
        fprintf(stderr, "The stack is empty.\n");
        exit(EXIT_FAILURE);
    }

    return stack->top->data;
}