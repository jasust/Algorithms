#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, x, mina = 200, minb = 200, maxa = 0;

int main()
{
    scanf("%d%d", &n, &m);

    for (int i=0; i<n; i++)
    {
        scanf("%d", &x);
        if (x < mina) mina = x;
        if (x > maxa) maxa = x;
    }
    for (int i=0; i<m; i++)
    {
        scanf("%d", &x);
        if (x < minb) minb = x;
    }
    if (mina * 2 >= maxa) maxa= 2 * mina;
    if (maxa < minb) printf("%d", maxa);
     else printf("-1");

    return 0;
}
