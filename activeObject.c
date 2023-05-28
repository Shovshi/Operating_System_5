#include "activeObject.h"
#include <pthread.h>


void* activeObjectThread(void *object)
{
    activeObject* AO = (activeObject*)(object);

    void *task;
    while(task = dequeue(AO->queue))
    {
        AO->func(task);
    }
}

void createActiveObject(void (*otherFunc)(void* item))
{
    activeObject* AO = (activeObject*)(malloc(sizeof(activeObject)));
    
    if (AO == NULL)
    {
        return;
    }

    AO->func = otherFunc;
    Queue* q = (Queue*)malloc(sizeof(Queue));
    initializeQueue(q,10);
    AO->queue=q;
    pthread_create(&(AO->thread) , NULL , activeObjectThread , (void*)AO);   
}

Queue *getQueue(activeObject* AO)
{
    return AO->queue;
}

void stop(activeObject* AO)
{
    pthread_cancel(AO->thread);

    // Cleanup and free memory
    free(AO->queue);
    free(AO);
}


