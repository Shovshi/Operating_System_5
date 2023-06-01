#include "activeObject.h"
#include <stdlib.h>
#include <pthread.h>


void* activeObjectThread(void *object)
{
    activeObject* AO = (activeObject*)(object);

    void *task;
    while(task = dequeue(AO->queue))
    {
        AO->func(AO->next,task);
    }
}

activeObject * createActiveObject(activeObject * next, void (*otherFunc)(activeObject * AO ,  void* item))
{
    activeObject* AO = (activeObject*)(malloc(sizeof(activeObject)));
    
    if (AO == NULL)
    {
        return NULL;
    }

    AO->func = otherFunc;
    AO->next = next;
    Queue* q = (Queue*)malloc(sizeof(Queue));
    initializeQueue(q,10);
    AO->queue=q;
    pthread_create(&(AO->thread) , NULL , activeObjectThread , (void*)AO);
    return AO;
}

pqueue getQueue(activeObject* AO)
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


