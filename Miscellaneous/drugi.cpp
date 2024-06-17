/* Ispisati binomne koeficijente prirodnog broja N */
#include <cstdio>
using namespace std;

int n;

int calc(int n, int k)
{
    if (!k || k==n) return 1;
    return (calc( n-1, k-1 ) + calc( n-1, k ));
}

int main()
{
    scanf("%d", &n);
    for (int i=0; i<=n; i++) printf("%d ", calc( n, i ));
    return 0;
}
