#include<cstdio>
#include<cmath>
using namespace std;
typedef long long lld;

lld n, c, l, skidaj, putuj;
float n1;
int x;

int main()
{
    scanf("%f%lld%lld%d", &n1, &c, &l, &x);
    x++;
    if (n1/x>c) n1=c*x; else x=ceil(n1/c);
    n = lld(n1);
    while (x)
    {
        skidaj = n % c;
        if (skidaj==0) skidaj = c;
        putuj = skidaj / x;
        if (putuj*x<skidaj) putuj++;
        if (putuj>=l)
        {
            n -= l*x;
            printf("%lld", n);
            return 0;
        }
        n -= putuj*x;
        n1 = n;
        l -= putuj;
        x = ceil(n1/c);
    }
    printf("0");
    return 0;
}
