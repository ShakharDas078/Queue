#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initialize(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool isEmpty(Queue *queue) {
    return (queue->front == -1);
}

bool isFull(Queue *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = value;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int value = queue->data[queue->front];
    if (queue->front == queue->rear)
        initialize(queue);
    else
        queue->front = (queue->front + 1) % MAX_SIZE;

    return value;
}

int peek(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot peek.\n");
        return -1;
    }

    return queue->data[queue->front];
}

int main() {
    Queue myQueue;
    initialize(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    printf("Front of the queue: %d\n", peek(&myQueue));
    printf("Dequeued: %d\n", dequeue(&myQueue));
    printf("Front of the queue after dequeue: %d\n", peek(&myQueue));

    return 0;
}
