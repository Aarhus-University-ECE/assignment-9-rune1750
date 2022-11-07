#include "search.h"
#include <stdbool.h>

// 3) function to binary search an array using recursion
bool search(int a[], int n, int x)
{
    if (n > 0 && a[n - 1] == x)
    {
        return true;
    }
    else if (n == 0)
    {
        return false;
    }
    else
    {
        return search(a, n - 1, x);
    }
}