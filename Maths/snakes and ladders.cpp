#include <cstdio>
#include <vector>
using namespace std;
const double ver = (double(1))/(double(6));

int l, s, i, j, next[103], x1, x2, k, n, m;
double a[103][103], niz[103], niz1[103], sol;
vector <int> v[103];

int main()
{
    while (scanf("%d %d %d %d", &n, &m, &s, &l)!=-1)
    {
        for (i=0; i<102; i++) next[i] = i;
        for (i=0; i<102; i++) niz[i] = niz1[i] = 0.0;
        niz[0] = 1.0;
        for (i=0; i<102; i++) for (j=0; j<102; j++) a[i][j] = 0.000;
        for (i=0; i<s; i++) { scanf("%d %d", &x1, &x2); next[x1]=x2; }
        for (i=0; i<l; i++) { scanf("%d %d", &x1, &x2); next[x1]=x2; }
        for (i=1; i<n*m; i++)
        	while (next[i]!=next[next[i]]) next[i]=next[next[i]];
        for (i=0; i<n*m; i++)
        if (next[i]==i)
        {
            for (j=1; j<7; j++)
            {
                if (i+j>n*m) { if (a[i][i] == 0.0) v[i].push_back(i); a[i][i] += double(7-j)*ver; break; }
                 else {
                        if (a[i][next[i+j]] == 0.0) v[i].push_back(next[i+j]);
                        a[i][next[i+j]] += ver;
                      }
            }
        }
        sol = 0.0;
        for (i=1; i<=5000; i++)
        {
            for (j=0; j<=n*m; j++)
            for (k=0; k<v[j].size(); k++) niz1[v[j][k]] += a[j][v[j][k]]*niz[j];
            for (j=0; j<=n*m; j++) { niz[j] = niz1[j]; niz1[j] = 0.0; }
            sol += niz[n*m]*double(i);
        }
        for (i=0; i<=n*m; i++) v[i].clear();
        printf("%.3lf\n", sol);
    }
    return 0;
}
