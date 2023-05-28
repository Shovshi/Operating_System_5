#include <pthread.h>
#include <stdio.h>

typedef struct Queue
{
    void **items;
    int capacity;
    int size;
    int head;
    int tail;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
}Queue;

void initializeQueue(Queue* queue, int capacity);
void enqueue(Queue *queue , void *item);
void* dequeue(Queue* queue);
