/* DONE */ #include<bits/stdc++.h>
/* DONE */ #define maxA 131072
/* DONE */ #define maxn 200005
/* DONE */ using namespace std;
/* DONE */
/* DONE */ long long mod = 1000000007;
/* DONE */
/* DONE */ long long step(long long a,long long b) {
/* DONE */     if(b==0ll) return 1ll;
/* DONE */     if(b&1ll) return (a*step(a,b-1ll))%mod;
/* DONE */     else return step((a*a)%mod,b>>1ll);
/* DONE */ }
/* DONE */
/* DONE */ long long inverse(long long a) {
/* DONE */     return step(a,mod-2);
/* DONE */ }
/* DONE */
/* DONE */ bool vis[maxn];
/* DONE */ pair<int,int> p[maxn];
/* DONE */ long long cur[maxA];
/* DONE */ int disc[maxn];
/* DONE */ int t=0;
/* DONE */ vector<pair<int,int> > a[maxn];
/* DONE */ int total_xor = 0;
/* DONE */ int n,m;
/* DONE */ int cc = 0;
/* DONE */ long long invmaxA;
/* DONE */ long long cur_cycle[maxA];
/* DONE */
/* DONE */ void fwht(long long* x,bool inv) {
/* DONE */     for(int l=2;l<=maxA;l<<=1) {
/* DONE */         for(int i=0;i+l<=maxA;i+=l) {
/* DONE */             int u,v;
/* DONE */             for(int j=0;j<(l>>1);j++) {
/* DONE */                 u=x[i+j];
/* DONE */                 v=x[i+(l>>1)+j];
/* DONE */                 x[i+j] = u + v;
/* DONE */                 if(x[i+j]>=mod) x[i+j]-=mod;
/* DONE */                 x[i+(l>>1)+j] = u + mod - v;
/* DONE */                 if(x[i+(l>>1)+j]>=mod) x[i+(l>>1)+j]-=mod;
/* DONE */             }
/* DONE */         }
/* DONE */     }
/* DONE */     if(inv) {
/* DONE */         for(int i=0;i<maxA;i++) {
/* DONE */             x[i] = (x[i]*invmaxA)%mod;
/* DONE */         }
/* DONE */     }
/* DONE */ }
/* DONE */
void dfs(int u) {
    vis[u]=true;
/* DONE */     disc[u] = t;
/* DONE */     t++;
    for(auto v: a[u]) {
        if(p[u].first!=v.first) {
            if(vis[v.first] && disc[v.first]<disc[u]) { //We found a cycle
                for(int i=0;i<maxA;i++) cur_cycle[i]=0;
                cur_cycle[v.second]++;
                int w = u;
/* DONE */                 cc ++ ;
                while(w != v.first) {
                    cur_cycle[p[w].second]++;
                    w = p[w].first;
                }
                fwht(cur_cycle,false);
                for(int i=0;i<maxA;i++) {
                    cur[i]=(1ll*cur[i]*cur_cycle[i])%mod;
                }
/* DONE */                 int tc = 0;
/* DONE */                 for(int i=0;i<maxA;i++) {
/* DONE */                     if(cur[i]!=0) tc++;
/* DONE */                 }
/* DONE */             }
/* DONE */             else {
/* DONE */                 if(!vis[v.first]) {
/* DONE */                     p[v.first]={u,v.second};
/* DONE */                     dfs(v.first);
/* DONE */                 }
/* DONE */             }
/* DONE */         }
/* DONE */     }
/* DONE */ }
/* DONE */
/* DONE */ int main() {
/* DONE */     invmaxA = inverse(maxA);
/* DONE */    scanf("%d %d",&n,&m);
/* DONE */    int u,v,w;
/* DONE */     cur[0] = 1;
/* DONE */     fwht(cur,false);
/* DONE */     for(int i=0;i<m;i++) {
/* DONE */         scanf("%d %d %d",&u,&v,&w);
/* DONE */         total_xor ^= w;
/* DONE */         a[u].push_back({v,w});
/* DONE */         a[v].push_back({u,w});
/* DONE */     }
/* DONE */     dfs(1);
/* DONE */     fwht(cur,true);
/* DONE */     int ans = maxA;
/* DONE */     for(int i=0;i<maxA;i++) {
/* DONE */         if(cur[i]!=0 && (total_xor^i)<ans) {
/* DONE */             ans = total_xor^i;
/* DONE */         }
/* DONE */     }
/* DONE */     printf("%d %d",ans,cur[ans^total_xor]);
/* DONE */     return 0;
/* DONE */ }
