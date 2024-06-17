#include <vector>
#include <cstdio>
using namespace std;
const int N = 10000000;

int lp[N+1];
vector <int> pr;

int main()
{
    for (int i=2; i<=N; i++)
    {
        if (lp[i] == 0)
        {
            printf ("%d",i);
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; j++) lp[i * pr[j]] = pr[j];
    }
    return 0;
}
