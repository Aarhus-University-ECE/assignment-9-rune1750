#include "sum.h"
#include <assert.h>

// 2) Function to sum an array using recursion
int sum(int a[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return a[n - 1] + sum(a, n - 1);
    }
}