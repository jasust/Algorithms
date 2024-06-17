#include<stdio.h>

int dp[100][100];
int n,p,q,x,y;

int min(int a,int b)
{
    return((a<b)? a:b);
}

void resi(int x,int y)
{
    int k;
    if(dp[x][y]==-1)
    {
        if(x<=y) dp[x][y]=x;
        k=y;
        while((k>0)&&(dp[x][y]==-1))
        {
            resi(x-k,min(k+q,p));
            if (dp[x-k][min(k+q,p)]==0) dp[x][y]=k;
            k--;
        }
        if(dp[x][y]==-1) dp[x][y]=0;
    }
}

int main()
{
    scanf("%d%d%d",&n,&p,&q);

    for(x=0;x<=n;x++)
        for(y=0;y<=p;y++) dp[x][y]=-1;

    resi(n,p);

    printf("%d",dp[n][p]);

    return 0;
}
