#include <cstdio>
#include <algorithm>
using namespace std;
const int MaxN = 2147483646;

int n, i, j, k, l, sum, a[20], b[20], ksma = 0, nmi=MaxN;
struct node
{
    int mi, ma, last;       
} dp[20][8200];

void uradi (int br, int bi, int it, int tib, int zb)
{
      while (bi<n && !(br&(1<<bi))) bi++;
      if (bi==n) 
      {
         if ((dp[it][br].ma-dp[it][br].mi)>max(dp[it-1][br-tib].ma,zb)-min(dp[it-1][br-tib].mi,zb))
         {
            dp[it][br].ma = max(dp[it-1][br-tib].ma,zb);
            dp[it][br].mi = min(dp[it-1][br-tib].mi,zb);
            dp[it][br].last = tib;                                                                                             
         }                    
      }
      else
      {
          uradi(br, bi+1, it, tib+(1<<bi), zb+a[bi+1]);
          uradi(br, bi+1, it, tib, zb);
      }
      return;
}

void rekonst(int _k, int _bit, int _br)
{
     if (_k>0) {
      for (int i=0; i<n; i++) if (dp[_k][_bit].last&(1<<i)) b[i+1] = _br;
      rekonst(_k-1, _bit-dp[_k][_bit].last, _br+1);
      }
      return;           
}

int main()
{
    scanf("%d%d", &n, &k);
    for (i=1; i<=n; i++) { scanf("%d", a+i); if (a[i]>ksma) ksma = a[i]; if (a[i]<nmi) nmi = a[i]; }
    if (k>n) { printf("%d\n", ksma); for (i=1; i<=n; i++) printf("%d ", i); return 0; }
    if (k==n) { printf("%d\n", ksma-nmi); for (i=1; i<=n; i++) printf("%d ", i); return 0; }
    
    for (i=2; i<=k; i++)
    for (j=1; j<(1<<n); j++) { dp[i][j].mi = 0; dp[i][j].ma = MaxN; dp[i][j].last = 0; }
    
    for (j=1; j<(1<<n); j++) 
    {
        sum = 0;
        for (l=0; l<n; l++) if (j&(1<<l)) sum += a[l+1];
        dp[1][j].mi = sum;
        dp[1][j].ma = sum;
        dp[1][j].last = j;
    }
    for (i=2; i<=k; i++)
    for (j=1; j<(1<<n); j++) uradi(j,0,i,0,0);
    
    printf("%d\n", dp[k][(1<<n)-1].ma-dp[k][(1<<n)-1].mi);
    rekonst(k,(1<<n)-1,1);
    for (i=1; i<=n; i++) printf("%d ", b[i]);
    
    return 0;   
}
