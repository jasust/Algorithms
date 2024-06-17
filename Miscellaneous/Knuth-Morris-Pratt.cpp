/*Knuth-Morris-Pratt algoritam za string matching
            slozenost: O(N + M)                  */
#include <cstdio>
#include <vector>
#include <string>
#define MAX_N 1000001
using namespace std;
typedef long long lld;

int n, m, j;
string needle, haystack;
int P[MAX_N];
vector<int> matches;

inline void KMP()
{
    P[0] = P[1] = 0;
    for(int i=2, j; i<=m; i++)
    {
        j = P[i-1];
        for( ; ; )
        {
            if (needle[j] == needle[i - 1])
            {
                P[i] = j + 1;
                break;
            }
            if (j == 0)
            {
                P[i] = 0;
                break;
            }
            j = P[j];
        }
    }
    for(int i=0, j=0; j < n;)
    {
        if (haystack[j] == needle[i])
        {
            i++;
            j++;
            if (i == m) matches.push_back(j - m);
        }
        else if (i) i = P[i];
         else j++;
  }
}

int main()
{
    n = 7, m = 2;
    haystack = "abcacbc";
    needle = "bc";
    KMP();
    for (int i=0; i<matches.size(); i++) printf("%d ",matches[i]);
    return 0;
}
