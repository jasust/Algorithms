#include<cstdio>
using namespace std;

int n, k, a[1000006], i, j, tmp, br;

int main()
{
    scanf("%d %d", &n, &k);
    for (i=0; i<n; i++) scanf("%d", a+i);

    for (i=30; i>=0; i--)
    {
        tmp += 1<<i;
        br = 0;
        for (j=0; j<n; j++)
            if ((a[j]&tmp)==tmp) br++;
        if (br<k) tmp -= 1<<i;
    }

    br = 0;
    for (i=0; i<n; i++)
    {
        if ((a[i]&tmp)==tmp) { printf("%d ", a[i]); br++; }
        if (br==k) break;
    }
    return 0;
}
