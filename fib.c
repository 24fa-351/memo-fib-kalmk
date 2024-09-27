#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long fib_i_core(int index);
unsigned long long fib_r_core(int index);
unsigned long long fib_i(int index);
unsigned long long fib_r(int index);

typedef unsigned long long (*FibFuncPtr)(int index);

int main(int argc, char *argv[]) {
    int index = atoi(argv[1]);
    char fib_method = argv[2][0];

    FibFuncPtr fib_ptr;

    if (fib_method == 'i') {
        fib_ptr = fib_i;
        printf("%llu\n", fib_ptr(index));
    } else if (fib_method == 'r') {
        fib_ptr = fib_r;
        printf("%llu\n", fib_ptr(index));
    }

    return 0;
}

unsigned long long fib_i_core(int index) {
    if (index == 1) {
        return 0;
    }

    if (index == 2) {
        return 1;
    }

    --index;

    unsigned long long t1 = 0;
    unsigned long long t2 = 1;
    unsigned long long next_term = t1 + t2;

    for (int ix = 3; ix <= index; ++ix) {
        t1 = t2;
        t2 = next_term;
        next_term = t1 + t2;
    }

    return next_term;
}

unsigned long long fib_r_core(int index) {
    if (index == 1) {
        return 0;
    }

    if (index == 2) {
        return 1;
    }

    return fib_r(index - 1) + fib_r(index - 2);
}

unsigned long long fib_i(int index) {
    static unsigned long long memo[1000] = {0};

    if (memo[index] != 0) {
        return memo[index];
    }

    memo[index] = fib_i_core(index);

    return memo[index];
}

unsigned long long fib_r(int index) {
    static unsigned long long memo[1000] = {0};

    if (memo[index] != 0) {
        return memo[index];
    }

    memo[index] = fib_r_core(index);

    return memo[index];
}