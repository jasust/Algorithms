/*Codeforces Problem-311B Cats Transport */
#include<cstdio>
#include<algorithm>
#define MaxN 100005
#define INF 0xffffffffffffLL
using namespace std ;

typedef long long ll;

int N, M, P, br, sz, x, hull[MaxN];
ll a[MaxN], dis[MaxN], dp[MaxN], sum[MaxN], X[MaxN];

int main()
{
    scanf("%d%d%d", &N, &M, &P);
    for(int i=2; i<=N; i++)
    {
        scanf("%I64d", &dis[i]);       //ucitavanje razdaljine izmedju susednih brda i preracunavanje dinamicke sume
        dis[i] += dis[i-1];
    }
    for(int i=1; i<=M; i++)
    {
        scanf("%d%I64d", &x, &a[i]);   //-a[i] govori koliko i-ta macka mora da ceka ako covek krene u trenutku 0
        a[i] -= dis[x] ;
    }
    sort(a + 1, a + M + 1);            //taj niz, kada je sortiran, nam daje podatak kojim redom ljudi skupljaju macke
    for(int i=0; i<=M; i++)
    {
        dp[i] = INF;
        sum[i] = sum[i-1] + a[i];      //radi kasnijeg racunanja potrebna nam je dinamicka suma i ovog niza
    }

    dp[0] = 0 ;
    for(int j=1; j<=P; j++)                        //pravljenje konveksnog omotaca
    {
        br = 1, sz = 1, hull[br] = 0;
        for(int i=1; i<=M; i++)
        {
            while(br < sz && X[hull[br+1]]-X[hull[br]] <= a[i]*(hull[br+1]-hull[br])) br++;
            X[i] = dp[i]+sum[i];
            dp[i] = X[hull[br]]+a[i]*(i-hull[br])-sum[i];
            while(br < sz && (X[hull[sz]]-X[hull[sz-1]])*(i-hull[sz]) >= (X[i]-X[hull[sz]])*(hull[sz]-hull[sz-1])) sz--;
            hull[++sz] = i;
        }
    }

    printf("%I64d\n", dp[M]);

    return 0;
}
