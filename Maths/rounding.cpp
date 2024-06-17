//Codeforces 351 - Problem A.Jeff and Rounding
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

double s = 0.0, x;
int n, ub, lb;

int main()
{
    scanf("%d", &n);
    for (int i=0; i<2*n; i++)
    {
        scanf("%lf", &x);
        x = x - floor(x);
        if (x > 0) ub++;
        s = s + x;
    }

    if (ub<n) lb = 0; else { lb = ub - n; ub = n; }
    while ((lb < ub) and (s - lb - 1>=0)) lb++;
    if ((1 - s + lb<s - lb) and (lb<ub)) lb++;

    printf("%.3lf", abs(lb - s));

    return 0;
}
