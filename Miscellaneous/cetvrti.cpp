/* Koliko clanova Fibonacijevog niza treba sabrati da bi suma bila veca od k */
#include <cstdio>
using namespace std;

int k, suma, br, a[3] = {1, 0, 0};

int main()
{
    scanf("%d", &k);
    suma = 1, br = 1;
    while (suma <= k)
    {
        a[2]=a[1], a[1]=a[0];
        a[0]=a[1]+a[2];
        br++;
        suma+=a[0];
    }
    printf("%d", br);
    return 0;
}
