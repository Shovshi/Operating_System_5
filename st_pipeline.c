#include "activeObject.h"
#include "queue.h"
#include "isPrime.c"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

void first_ao(activeObject *next, void *otherSeed)
{
    int min = 100000;
    int max = 999999;
    int rand_num;
    rand_num = (rand() % (max - min + 1)) + min;
    void *task = &rand_num;
    sleep(1);
    enqueue(getQueue(next), task);
}

void second_ao(activeObject *next, void *item)
{
    int num = *(int *)(item);
    printf("%d\n", num);
    if (isPrime(num))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    num += 11;
    int* numPoint = malloc(sizeof(int));
    *numPoint = num;
    enqueue(getQueue(next), numPoint);
}


void third_ao(activeObject *next, void *item)
{
    int num = *(int *)(item);
    printf("%d\n", num);
    if (isPrime(num))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    num -= 13;
    int* numPoint = malloc(sizeof(int));
    *numPoint = num;
    enqueue(getQueue(next), numPoint);
    free(item);
}

void fourth_ao(activeObject *next, void *item)
{
    int num = *(int *)(item);
    printf("%d\n", num);
    num += 2;
    printf("%d\n", num);
    free(item);
}

int main(int argc, char *argv[])
{
    int randomSeed = 0;
    if (argc > 3)
    {
        printf("Too many arguments\n");
        exit(0);
    }

    else if (argc == 2)
    {
        srand(time(NULL));
        randomSeed = (rand() % (10));
    }
    else if(argc == 3)
    {
        randomSeed = atoi(argv[2]);
    }

    activeObject *fourthAO = createActiveObject(NULL, fourth_ao);
    activeObject *thirdAO = createActiveObject(fourthAO, third_ao);
    activeObject *secondAO = createActiveObject(thirdAO, second_ao);
    activeObject *firstAO = createActiveObject(secondAO, first_ao);

    void *task = &randomSeed;

    for (int i = 0; i <= atoi(argv[1]); i++)
    {
        int rand_seed = *(int *)task;
        enqueue(getQueue(firstAO), &rand_seed);
    }


    while (firstAO->queue->size > 0)
    {
    }
    sleep(1);
    stop(firstAO);

    while (secondAO->queue->size > 0)
    {
    }
    stop(secondAO);

    while (thirdAO->queue->size > 0)
    {
    }
    stop(thirdAO);

    while (fourthAO->queue->size > 0)
    {
    }
    stop(fourthAO);

    return 0;
}
