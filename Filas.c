#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->size == 0;
}

int isFull(Queue* queue) {
    return queue->size == MAX_SIZE;
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = item;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;
    return item;
}

int main() {
    Queue* queue = createQueue();
    
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    
    printf("Dequeued item: %d\n", dequeue(queue));
    
    enqueue(queue, 40);
    enqueue(queue, 50);
    
    printf("Is queue empty? %s\n", isEmpty(queue) ? "Yes" : "No");
    printf("Is queue full? %s\n", isFull(queue) ? "Yes" : "No");
    
    return 0;
}
