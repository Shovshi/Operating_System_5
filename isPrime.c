#include <math.h>
#include <stdio.h>

int isPrime(unsigned int num)
{
    int isPrime = 1;
    if (num == 1)
    {
        isPrime = 1;
    }
    if (num == 0 || num == 2)
    {
        isPrime = 0;
    }
    // Check divisibility from 2 to square root of num
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            isPrime = 0; 
            break;
        }
    }
}

