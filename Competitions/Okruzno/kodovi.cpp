#include <cstdio>
using namespace std;
typedef long long lld;
int n, x, i, idx = 0, p[100005], h[100005]; 
// zasto nemam code::blocks na racunaru?!

int main()
{
    scanf("%d%d", &n, &x);
    for (i=1; i<=n; i++) 
    {
        scanf("%d%d", p+i, h+i);
        if (x>p[i]) idx = i;
    }
    int left = idx, right = idx+1, dir = 1;
    lld vreme = p[right]*1LL - x*1LL;
    lld sol = 1LL;
    h[right]--;
    while ((right<n+1) && (left>0))
    {
          if (dir)
          {
                  if (h[left]>h[right]) 
                  { 
                    dir = 0; 
                    sol += 2LL*h[right]+1LL; 
                    h[left] -= h[right]+1; 
                    vreme = vreme + (2LL*h[right]+1LL)*(p[right]-p[left])*1LL;
                    right++; 
                  } else
                  {
                    dir = 1; 
                    sol += 2LL*h[left]; 
                    h[right] -= h[left]; 
                    vreme = vreme + (2LL*h[left])*(p[right]-p[left])*1LL;
                    left--;      
                  }
          } else
          {
                if (h[right]>h[left]) 
                  { 
                    dir = 1; 
                    sol += 2LL*h[left]+1LL;  
                    h[right] -= h[left]+1; 
                    vreme = vreme + (2LL*h[left]+1LL)*(p[right]-p[left])*1LL;
                    left--;
                  } else
                  {
                    dir = 0; 
                    sol += 2LL*h[right];  
                    h[left] -= h[right]; 
                    vreme = vreme + (2LL*h[right])*(p[right]-p[left])*1LL;      
                    right++;                  
                  }
          }          
    }    
    // mrzi me bignum za vreme, dovoljno mi je 75pt na ovom zadatku
    printf("%lld\n%lld", sol, vreme);
    
    return 0;   
}    
