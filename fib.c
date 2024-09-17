#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

unsigned long long fib_i(int times);
unsigned long long fib_r(int times);
unsigned long long fib_i_provider(int times);
unsigned long long fib_r_provider(int times);

unsigned long long memo[MAX_SIZE];

unsigned long long fib_i(int times)
{
    if (memo[times] != 0)
    {
        return memo[times];
    }
    
    memo[times] = fib_i_provider(times);

    return memo[times];
}

unsigned long long fib_r(int times)
{
    if (memo[times] != 0)
    {
        return memo[times];
    }

    memo[times] = fib_r_provider(times);

    return memo[times];
}

int main(int argc, char *argv[])
{
    // First argument is an integer
    int first_arg = atoi(argv[1]);

    // Second argument is "r" or "i"
    char *temp = malloc(sizeof(argv[2]));
    strcpy(temp, argv[2]);
    char second_arg = temp[0];
    free(temp);
    
    // Add two numbers together
    int N = first_arg;
    
    // Compute the Nth Fibonacci number according to "i" or "r"
    // Fibonacci sequence starts with 0 and 1
    if (second_arg == 'i') 
        printf("%llu\n", fib_i(N));
    else if (second_arg == 'r')
        printf("%llu\n", fib_r(N));

    return 0;
}

unsigned long long fib_i_provider(int times)
{
    if (times == 1)
        return 0;

    if (times == 2)
        return 1;

    --times;

    unsigned long long t1 = 0;
    unsigned long long t2 = 1;
    unsigned long long next_term = t1 + t2;

    for (int i = 3; i <= times; ++i)
    {
        t1 = t2;
        t2 = next_term;
        next_term = t1 + t2;
    }

    return next_term;
}

unsigned long long fib_r_provider(int times)
{
    if (times == 1)
        return 0;

    if (times == 2)
        return 1;

    return fib_i(times - 1) + fib_i(times - 2);
} 
