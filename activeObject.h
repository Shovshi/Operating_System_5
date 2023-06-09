#include "queue.h"

typedef struct activeObject
{
    void(*func)(struct activeObject * AO, void* item); 
    Queue *queue;                 
    pthread_t thread; 
    struct activeObject * next;
}activeObject;

void* activeObjectThread(void *object);
activeObject * createActiveObject(activeObject * next, void (*otherFunc)(activeObject * AO ,  void* item));
void stop(activeObject *AO);
Queue *getQueue(activeObject *AO);