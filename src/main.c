#include <stdlib.h>
#include <stdio.h>
#include "sum.c"

// File for sandboxing and trying out code
int main(int argc, char **argv)
{
    int test[1] = {5};
    int n = 1;
    int summation = sum(test, n);

    printf("\n %d is the summation\n", summation);

    return 0; 
}