#include <cstdio>
#include <algorithm>
using namespace std;

int sum = 0, sol = 0, a[9];

int main()
{
    for (int i=0; i<8; i++) scanf("%d", a+i), sum += a[i];

    for (int i=0; i<4; i++)
    {
        int cur = 0;
        for (int j=0; j<4; j++) cur += a[i+j];
        sol = max(sol, max(cur, sum-cur));
    }

    printf("%d", sol);

    return 0;
}
