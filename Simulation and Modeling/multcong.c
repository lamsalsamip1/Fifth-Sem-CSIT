#include <stdio.h>

#define a 1103515245
#define m 2147483648 // 2^31

unsigned int seed = 32423234; // Initial seed

double lcg_random()
{
    seed = (a * seed) % m;
    return (double)seed / m;
}

int main()
{
    printf("10 random numbers between 0 and 1:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%0.2f\n", lcg_random());
    }
    return 0;
}