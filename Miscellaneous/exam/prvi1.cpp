#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int p, n, H[100], P[100], sol, k;
char s[100];

int _hash(int i, int j )
{
    int ret = H[j];
    if (i) ret -= H[i-1] * P[j-i+1];
    return ret;
}

int bin(int x, int y)
{
    int l=0, r=y;
    while (l<r)
    {
        int m = (l+r)/2;
        if (_hash(x-m,x-1) == _hash(x+1,x+m)) l = m+1;
        else r = m-1;
    }
    return l;
}

int main()
{
    int i=1;
    char c;
    s[0] = ' ';
    while (c != '\n')
    {
        scanf("%c", &c);
        s[i] = c;
        i++;
        s[i] = ' ';
        i++;
    }
    n = i-1;

    P[0] = 1;
    H[0] = s[0];
    p = 10007;

    for (int i=1; i<n; i++)
    {
        P[i] = P[i-1] * p;
        H[i] = H[i-1] * p + s[i];
    }

    for (int i=0; i<n; i++)
    {
        if (bin(i, min(i, n-i-1))>sol)
        {
            sol = bin(i,min(i, n-i-1));
            k = i;
        }
    }
    printf("%d", sol);
    return 0;
}
