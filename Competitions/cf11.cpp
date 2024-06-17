#include <cstdio>
#include <algorithm>

int n, br5, br0, x;

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &x);
        if (x==0) br0++; else br5++;
    }
    br5 = br5 - (br5 % 9);

    if ((br5 !=0) and (br0 != 0))
    {
        for (int i=1; i<=br5; i++) printf("5");
        for (int i=1; i<=br0; i++) printf("0");
    }
    else if (br0 > 0) printf("0"); else if (br0 == 0) printf("-1");
    return 0;
}
