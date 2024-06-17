#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int i;
vector <int> V;

int main()
{
    for (i=1; i<5; i++) V.push_back(i);
    do
    {
        for (i=0; i<4; i++) printf("%d ", V[i]);
        printf("\n");
    } while ( next_permutation(V.begin(),V.end()) );
}
