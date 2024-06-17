#include <cstdio>
using namespace std;

int n, s;

int brz_step (int _n, int _s)
{
    if (_s==0) return 1;
    int sol = brz_step(_n, _s>>1);
    sol *= sol;
    if (_s&1) sol *= _n;
    return sol;
}

int main()
{
    scanf("%d%d", &n, &s);
    printf("%d", brz_step(n, s));
    return 0;
}
