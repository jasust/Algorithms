/* Izracunati besnu sumu */
#include <cstdio>
using namespace std;
int n;

float rek( int k )
{
    if (k > n) return 0;
    return (1/(2*k + rek(k+1)));
}

int main()
{
    scanf("%d", &n);
    printf("%f", rek(1));
}
