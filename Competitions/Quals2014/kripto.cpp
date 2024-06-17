#include<cstdio>
using namespace std;
typedef long long lld;

lld divisor;
unsigned long long remainder;
char dividend[100005];

void division(char dividend[], lld divisor)
{
    int i=0;
    while(dividend[i])
    {
         remainder = remainder*10 + (dividend[i]-48);
         if (remainder>=divisor) remainder = remainder % divisor;
         i++;
    }
}

int main()
{
    scanf("%s", dividend);
    scanf("%lld", &divisor);
    division(dividend, divisor);
    printf ("%lld", remainder);
    return 0;
}
