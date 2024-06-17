#include<cstdio>
#include<set>
using namespace std;

int n, q, pom1, pom2, x, i, j;
char ch[100005][55], ch1[55], ch2[55], upit;
set <int> s;

int main()
{
    scanf("%d%d", &n, &q);
    scanf("%s", ch[1]);
    s.insert(1);
    s.insert(n+1);
    for (i=1; i<=q; i++)
    {
        scanf("\n%c%*c%*c%*c%*c", &upit);
        if (upit=='S')
        {
            scanf("%d %s %s", &x, ch1, ch2);
            pom1 = *--s.upper_bound(x);
            pom2 = *s.upper_bound(x);
            if (x>pom1)
            {
                for (j=0; j<51; j++) ch[x][j] = ch[pom1][j];
                for (j=0; j<51; j++) ch[pom1][j] = ch1[j];
                s.insert(x);
            }
            if (x+1<pom2)
            {
                for (j=0; j<51; j++) ch[x+1][j] = ch2[j];
                s.insert(x+1);
            }
        }
        else
        {
            scanf("%d", &x);
            printf("%s\n", ch[*--s.upper_bound(x)]);
        }
    }
    return 0;
}
