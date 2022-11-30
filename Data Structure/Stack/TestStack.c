#include "ArrayStack.h"
#include "LinkedStack.h"

#include <assert.h>
#include <stdio.h>

void TestArrayStack(void)
{
    stack_t *stack = ArrayStack_Create();
    assert(ArrayStack_Size(stack) == 0);
    assert(ArrayStack_IsEmpty(stack) == true);

    stack_data_t arr[] = {1, 2, 3, 4, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < arrSize; i++)
    {
        ArrayStack_Push(stack, arr[i]);
    }
    assert(ArrayStack_Size(stack) == 5);
    assert(ArrayStack_IsEmpty(stack) == false);
    assert(ArrayStack_Top(stack) == 5);

    for (int i = 0; i < arrSize; i++)
    {
        assert(ArrayStack_Pop(stack) == arr[arrSize - i - 1]);
    }
    assert(ArrayStack_IsEmpty(stack) == true);

    ArrayStack_Push(stack, 233);
    assert(ArrayStack_Size(stack) == 1);
    assert(ArrayStack_IsEmpty(stack) == false);
    assert(ArrayStack_Top(stack) == 233);

    ArrayStack_Destroy(stack);

    printf("Array Stack Test OK.\n");
}

void TestLinkedStack(void)
{
    stack_t *stack = LinkedStack_Create();
    assert(LinkedStack_Size(stack) == 0);
    assert(LinkedStack_IsEmpty(stack) == true);

    stack_data_t arr[] = {1, 2, 3, 4, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < arrSize; i++)
    {
        LinkedStack_Push(stack, arr[i]);
    }
    assert(LinkedStack_Size(stack) == 5);
    assert(LinkedStack_IsEmpty(stack) == false);
    assert(LinkedStack_Top(stack) == 5);

    for (int i = 0; i < arrSize; i++)
    {
        assert(LinkedStack_Pop(stack) == arr[arrSize - i - 1]);
    }
    assert(LinkedStack_IsEmpty(stack) == true);

    LinkedStack_Push(stack, 233);
    assert(LinkedStack_Size(stack) == 1);
    assert(LinkedStack_IsEmpty(stack) == false);
    assert(LinkedStack_Top(stack) == 233);

    LinkedStack_Destroy(stack);

    printf("Linked Stack Test OK.\n");
}

int main(void)
{
    TestArrayStack();
    TestLinkedStack();

    return 0;
}