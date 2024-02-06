#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue
{
    int items[MAX_SIZE];
    int front;
    int rear;
};

struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(struct Queue *queue)
{
    return queue->rear == -1;
}

int isFull(struct Queue *queue)
{
    return queue->rear == MAX_SIZE - 1;
}

void enqueue(struct Queue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue is full, cannot enqueue!\n");
        return;
    }
    if (isEmpty(queue))
    {
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = value;
}

int dequeue(struct Queue *queue)
{
    int item;
    if (isEmpty(queue))
    {
        printf("Queue is empty, cannot dequeue!\n");
        return -1;
    }
    item = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    return item;
}

double averageQueueLength(struct Queue *queue, int totalTime)
{
    if (isEmpty(queue))
    {
        return 0.0;
    }
    return (double)(queue->rear - queue->front + 1) / totalTime;
}

double averageWaitingTime(struct Queue *queue, int totalTime)
{
    if (isEmpty(queue))
    {
        return 0.0;
    }
    int totalItems = queue->rear - queue->front + 1;
    return (double)totalItems / totalTime;
}

double utilization(struct Queue *queue, int totalTime)
{
    if (isEmpty(queue))
    {
        return 0.0;
    }
    return (double)totalTime / (queue->rear - queue->front + 1);
}

int main()
{
    struct Queue *queue = createQueue();

    int totalTime = 20; // Total time units

    // Enqueueing some items into the queue
    enqueue(queue, 10);
    enqueue(queue, 15);
    enqueue(queue, 20);

    // Dequeueing an item from the queue
    dequeue(queue);

    printf("Average queue length: %.2f\n", averageQueueLength(queue, totalTime));
    printf("Average waiting time: %.2f\n", averageWaitingTime(queue, totalTime));
    printf("Utilization: %.2f\n", utilization(queue, totalTime));

    return 0;
}
