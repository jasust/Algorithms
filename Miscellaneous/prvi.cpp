/* Ispisati realan broj u binarnom sistemu na k decimala */
#include <cstdio>
using namespace std;
float n;
int k;

void bin( int br )
{
    if (br == 0) return;
    bin(br/2);
    printf("%d", br%2);
}

void binreal( float real)
{
    if (!k) return;
    k--;
    real *= 2;
    printf("%d",int(real));
    binreal(real - int(real));
}

int main()
{
    scanf("%f %d", &n, &k);
    bin(int(n));
    putchar('.');
    binreal(n - int(n));
    return 0;
}
