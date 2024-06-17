#include <cstdio>
#include <algorithm>
using namespace std;

int N, i, j, sol, a[1003];

int main()
{
    for (i=0; i<3; i++)
    {
        scanf("%d", &N);
        sol = 1;
        for (j=0; j<N; j++) scanf("%d", a+j);
        sort(a, a+N);
        for (j=1; j<N; j++)
            if (a[j]!=a[j-1]) sol++;
        printf("%d\n", 2-sol%2);
    }

    return 0;
}
