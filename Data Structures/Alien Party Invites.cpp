/* Z-trening Problem Alien Party Invites */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;

int n, m, br;
string ime;
queue <string> Q;
map <string, int> mapa1, mapa2;

int main ()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        cin >> ime;
        mapa1[ime]++;
    }

    scanf ("%d", &m);
    int ans = m;
    for (int i=0; i<m; i++)
    {
        cin >> ime;
        Q.push(ime);
        if (mapa1[ime])
        {
            if (!mapa2[ime]) br++;
            mapa2[ime]++;
        }
        while ((!Q.empty()) && ((!mapa1[Q.front()]) || (mapa2[Q.front()]>1)))
        {
            mapa2[Q.front()]--;
            Q.pop();
        }
        if ((Q.size()<ans) && (br==n)) ans=Q.size();
    }

    printf ("%d", ans);
    return 0;
}
