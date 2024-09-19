#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long fib_i_core(int index);
unsigned long long fib_r_core(int index);
unsigned long long fib_i(int index);
unsigned long long fib_r(int index);

int main(int argc, char *argv[])
{
    int first_arg = atoi(argv[1]);

    char *temp = malloc(sizeof(argv[2]));
    strcpy(temp, argv[2]);
    char second_arg = temp[0];
    free(temp);
    
    int N = first_arg;
    
    if (second_arg == 'i') 
        printf("%llu\n", fib_i(N));
    else if (second_arg == 'r')
        printf("%llu\n", fib_r(N));

    return 0;
}

unsigned long long fib_i_core(int index)
{
    if (index == 1)
        return 0;

    if (index == 2)
        return 1;

    --index;

    unsigned long long t1 = 0;
    unsigned long long t2 = 1;
    unsigned long long next_term = t1 + t2;

    for (int i = 3; i <= index; ++i)
    {
        t1 = t2;
        t2 = next_term;
        next_term = t1 + t2;
    }

    return next_term;
}

unsigned long long fib_r_core(int index)
{
    if (index == 1)
        return 0;

    if (index == 2)
        return 1;

    return fib_r(index - 1) + fib_r(index - 2);
} 

unsigned long long fib_i(int index)
{
    static unsigned long long memo[1000] = {0};

    if (memo[index] != 0)
    {
        return memo[index];
    }
    
    memo[index] = fib_i_core(index);

    return memo[index];
}

unsigned long long fib_r(int index)
{
    static unsigned long long memo[1000] = {0};

    if (memo[index] != 0)
    {
        return memo[index];
    }
    
    memo[index] = fib_r_core(index);

    return memo[index];
}