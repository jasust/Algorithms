//  Codeforces Problem 369D - Valera and Fools
#include <cstdio>
#include <algorithm>
using namespace std;

int S[3003][3003], maxi[3003], p[3003], n, K, sol=0;

void comp(int a, int b, int k)
{
  if (S[a][b]) return;
  S[a][b] = true;
  sol++;
  if(!k || b>n) return;
  if(maxi[b] && p[a]) comp(b+1,b+2,k-1);
  if(maxi[b] && p[a]!=100) comp(b,b+1,k-1);
  if(maxi[b]!=100 && p[a]) comp(a,b+1,k-1);
}

int main()
{
  scanf("%d%d", &n, &K);
  for (int i=1; i<=n; i++) scanf("%d", p + i);

  maxi[n]=p[n];
  for(int i=n-1; i>=1; i--) maxi[i]=max(maxi[i+1],p[i]);

  comp(1,2,K);

  printf("%d", sol);
  return 0;
}
