#include "queue.h"

typedef struct activeObject
{
    void(*func)(void* item); 
    Queue *queue;                 
    pthread_t thread;             
} activeObject;

void* activeObjectThread(void *object);
void createActiveObject(void (*otherFunc)(void* item));
Queue *getQueue(activeObject* AO);
void stop();