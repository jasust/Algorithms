#include <cstdio>
using namespace std;
int x,y;

int fastMax()
{
    return (((y-x)>>31)&(x^y))^y;
}

int main()
{
    scanf("%d%d", &x, &y);
    printf("%d", fastMax());
    return 0;
}


