#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

int t, n, m, lp[31700];
vector <int> pr;
set<int> notprime;

int main()
{
    for (int i=2; i<31654; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j=0; j<pr.size() && pr[j]<=lp[i] && i*pr[j]<=31654; j++) lp[i * pr[j]] = pr[j];
    }

    scanf("%d", &t);

    while (t--)
    {
        scanf("%d%d", &m, &n);
        if (!(m-1)) m = 2;
        int cap = sqrt(n) + 1;

        notprime.clear();

        vector<int>::iterator p;
        for (p = pr.begin(); p != pr.end(); p++)
        {
            if (*p >= cap) break;
            int start;

            if (*p >= m) start = (*p)*2;
            else start = m + ((*p - m % *p) % *p);

            for (int j = start; j <= n; j += *p) {
                notprime.insert(j);
            }
        }

        for (int i = m; i <= n; i++)
            if (notprime.count(i) == 0) printf("%d\n", i);
        if (t>1) printf("\n");
    }
    return 0;
}
