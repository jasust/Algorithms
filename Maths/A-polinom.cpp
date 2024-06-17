#include <cstdio>
using namespace std;

int N;
double a, b, c;

int main ( )
{
    scanf("%d%lf%lf%lf", &N, &a, &b, &c );
    printf("%.2lf\n",(b*b)/(a*a)-2.00*c/a);
    return 0;
}
