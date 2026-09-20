#include "Chapter6.h"

int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; ++i)
    {
        res *= i;
    }
    return res;
}

int fact_interact()
{
    int n;
    std::cin >> n;
    int res = 1;
    for (int i = 2; i <= n; ++i)
        res *= i;
    return res;
}

int getAbs(int val)
{
    return val >= 0 ? val : -val;
}