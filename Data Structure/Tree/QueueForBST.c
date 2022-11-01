#include "QueueForBST.h"
#include "BinarySearchTree.h"

#define QUEUE_CAPACITY 100

struct queue
{
    queue_data_t data[QUEUE_CAPACITY + 1]; // 循环队列，数组容量为队列有效容量加一
    int front;
    int rear;
};

/*******************************
Helper functions implementation.
*******************************/

/*******************************
Interface functions implementation.
*******************************/

queue_t *Queue_Create(void)
{
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    if (queue == NULL)
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }

    queue->front = -1;
    queue->rear = -1;

    return queue;
}

void Queue_Destroy(queue_t *queue)
{
    free(queue);
}

int Queue_Size(const queue_t *queue)
{
    return (queue->rear - queue->front + (QUEUE_CAPACITY + 1)) % (QUEUE_CAPACITY + 1);
}

bool Queue_IsEmpty(const queue_t *queue)
{
    return Queue_Size(queue) == 0;
}

void Queue_Enqueue(queue_t *queue, queue_data_t data)
{
    if (Queue_Size(queue) == QUEUE_CAPACITY)
    {
        fprintf(stderr, "The queue is full.\n");
        return;
    }

    queue->rear = (queue->rear + 1) % QUEUE_CAPACITY;
    queue->data[queue->rear] = data;
}

queue_data_t Queue_Dequeue(queue_t *queue)
{
    if (Queue_IsEmpty(queue))
    {
        fprintf(stderr, "The queue is empty.\n");
        exit(EXIT_FAILURE);
    }

    queue->front = (queue->front + 1) % QUEUE_CAPACITY;

    return queue->data[queue->front];
}