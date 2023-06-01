#include "activeObject.h"
#include "queue.h"
#include "isPrime.c"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

void first_ao(activeObject *next, void *otherSeed)
{
    int seed = *(int *)otherSeed;
    srand(seed);
    int randomNum = rand() % 900000 + 100000;
    void *item = &randomNum;
    sleep(1);
    enqueue(getQueue(next), item);
    printf("First Active Object Number: %d\n", *(int *)item);
}

void second_ao(activeObject *next, void *item)
{
    int num = *(int *)(item);
    printf("Second Active Object Number: %d\n", num);
    if (isPrime(num))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    num += 11;
    void *numPoint = &num;
    printf("TESTING: %d\n", *(int *)numPoint);
    enqueue(getQueue(next), numPoint);
    printf("Second Active Object Number After Adding 11: %d\n", num);
}

void third_ao(activeObject *next, void *item)
{
    printf("Third Active Object: %d\n", *(int *)(item));
    int num = *(int *)(item);
    printf("Third Active Object: %d\n", num);
    if (isPrime(num))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    num -= 13;
    void *numPoint = &num;
    enqueue(getQueue(next), numPoint);
}

void fourth_ao(activeObject *null, void *item)
{
    int num = *(int *)(item);
    printf("Num is: %d\n", num);
    num += 2;
    printf("Num is: %d\n", num);
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
        randomSeed = rand();
    }

    activeObject *fourthAO = createActiveObject(NULL, fourth_ao);
    activeObject *thirdAO = createActiveObject(fourthAO, third_ao);
    activeObject *secondAO = createActiveObject(thirdAO, second_ao);
    activeObject *firstAO = createActiveObject(secondAO, first_ao);

    void *task = &randomSeed;

    for (int i = 0; i < atoi(argv[1]); i++)
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
