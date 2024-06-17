#include <cstdio>
using namespace std;
int baza, eksponenet;
long long sol = 1;

void stepen(int x, int k)
{
    if (k == 0) return;
    else
    {
        stepen(x, k>>1);
        sol *= sol;
        if (k&1) sol *= x;
    }
    return;
}

int main()
{
    scanf("%d %d", &baza, &eksponenet);
    stepen(baza, eksponenet);
    printf("%lld", sol);
    return 0;
}
