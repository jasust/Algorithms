/*Za zadati broj duzine n<=10^5 i levu i desnu granicu l,r<=10^9 naci najvecu sumu brojeva na koje ga treba
  podeliti tako da svi pripadaju datom intervalu. Vremensko ogranicenje je 0,5s, a memorijsko 64MB
 */
#include <stdio.h>

using namespace std;

int N, l, r, tr, gr, st;
int A[100005],Dp[100005];
char Ch;

int main()
{
    scanf("%d%d%d\n",&N,&l,&r);
    A[0]=-1;
    for (int i=0; i<=N; i++) Dp[i] = 0;
    for (int i=1; i<=N; i++)
    {
        Ch = getchar();
        tr = A[i] = (int)Ch-(int)'0';
        gr = i;
        st = 1;
        while ((gr > 0) && (tr <= r))
        {
           if ((tr >= l) && (Dp[i]<tr + Dp[gr-1])) Dp[i] = tr + Dp[gr-1];
           st *= 10;
           gr -= 1;
           tr += A[gr]*st;
        }
    }
    printf("%d", Dp[N]);

    return 0;
}
