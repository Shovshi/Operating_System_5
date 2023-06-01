#include "queue.h"
#include <stdlib.h>

void initializeQueue(Queue* queue, int capacity)
{
    queue->items = (void*)malloc(capacity * sizeof(void));
    queue->capacity = capacity;
    queue->size = 0;
    queue->head = 0;
    queue->tail = -1;
    pthread_mutex_init(&(queue->mutex), NULL);
    pthread_cond_init(&(queue->cond), NULL);
}

void enqueue(Queue *queue , void *item)
{
    pthread_mutex_lock(&(queue->mutex)); // with this function if the mutex is locked
                                         // then the thread is put into a waiting state
                                         // otherwise we acquire the lock
    while (queue->size == queue->capacity)
    {
        pthread_cond_wait(&(queue->cond), &(queue->mutex));
    }

    if (queue->size == queue->capacity)
    {
        int newCapacity = queue->capacity * 2;
        queue->items = realloc(queue->items, newCapacity * sizeof(void*));
        queue->capacity = newCapacity;
    }
    
    queue->tail = (queue->tail + 1) % queue->capacity; // we do this for the circular implementation
    queue->items[queue->tail] = item;
    queue->size++;

    pthread_cond_signal(&(queue->cond));
    pthread_mutex_unlock(&(queue->mutex));
}

void* dequeue(Queue* queue)
{
    pthread_mutex_lock(&(queue->mutex));

    while (queue->size == 0) 
    {
        pthread_cond_wait(&(queue->cond), &(queue->mutex));
    }

    void* item = queue->items[queue->head];
    queue->head = (queue->head + 1) % queue->capacity;
    queue->size--;

    pthread_cond_signal(&(queue->cond));
    pthread_mutex_unlock(&(queue->mutex));

    return item;
}