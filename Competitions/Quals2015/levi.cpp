#include <cstdio>
using namespace std;

int q, x, y;

int main()
{
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d %d", &x, &y);
        if ((x>=0) && (y<=1))
            { if ((x-y)%4==0) printf("DA\n"); else printf("NE\n"); continue; }
        if ((x>=-1) && (y>=1))
            { if ((x+y)%4==2) printf("DA\n"); else printf("NE\n"); continue; }
        if ((x<=0) && (y<=0))
            { if ((-x-y)%4==0) printf("DA\n"); else printf("NE\n"); continue; }
        if ((x<=-1) && (y>=0))
            { if ((y-x)%4==0) printf("DA\n"); else printf("NE\n"); continue; }
        printf("NE\n");
    }

    return 0;
}
