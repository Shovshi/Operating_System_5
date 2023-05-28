#include <math.h>
#include <stdio.h>

int isPrime(unsigned int num)
{
    if (num == 1)
    {
        return 1;
    }
    if (num == 0 || num == 2)
    {
        return 0;
    }
    for (int i = 3; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    printf("2: %d\n",isPrime(2));
    printf("3: %d\n",isPrime(3));
    printf("17: %d\n",isPrime(17));
}