#include "ArrayQueue.h"
#include "LinkedQueue.h"

#include <assert.h>
#include <stdio.h>

void TestArrayQueue(void)
{
    queue_t *queue = ArrayQueue_Create();
    assert(ArrayQueue_Size(queue) == 0);
    assert(ArrayQueue_IsEmpty(queue) == true);

    queue_data_t arr[] = {1, 2, 3, 4};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < arrSize; i++)
    {
        ArrayQueue_Enqueue(queue, arr[i]);
    }
    assert(ArrayQueue_Size(queue) == 4);
    assert(ArrayQueue_IsEmpty(queue) == false);

    for (int i = 0; i < arrSize; i++)
    {
        assert(ArrayQueue_Dequeue(queue) == i + 1);
    }
    assert(ArrayQueue_Size(queue) == 0);
    assert(ArrayQueue_IsEmpty(queue) == true);

    ArrayQueue_Destroy(queue);

    printf("Array Queue Test OK.\n");
}

void TestLinkedQueue(void)
{
    queue_t *queue = LinkedQueue_Create();
    assert(LinkedQueue_Size(queue) == 0);
    assert(LinkedQueue_IsEmpty(queue) == true);

    queue_data_t arr[] = {1, 2, 3, 4};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < arrSize; i++)
    {
        LinkedQueue_Enqueue(queue, arr[i]);
    }
    assert(LinkedQueue_Size(queue) == 4);
    assert(LinkedQueue_IsEmpty(queue) == false);

    for (int i = 0; i < arrSize; i++)
    {
        assert(LinkedQueue_Dequeue(queue) == i + 1);
    }
    assert(LinkedQueue_Size(queue) == 0);
    assert(LinkedQueue_IsEmpty(queue) == true);

    LinkedQueue_Destroy(queue);

    printf("Linked Queue Test OK.\n");
}

int main(void)
{
    TestArrayQueue();
    TestLinkedQueue();

    return 0;
}
