#include <cstdio>
#include <queue>
using namespace std;
typedef long long lld;

struct zbg
{
    int x;
    bool operator < (const zbg &b) const { return x>b.x; }
    zbg( int _x ) { x = _x; }
};
struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};
/*struct classcomp1 {
  bool operator() (const zbg& lhs, const zbg& rhs) const
  {return lhs.x>rhs.x;}
}; */

priority_queue < zbg , vector <zbg>, less<zbg> > heap;  // less daje max
priority_queue < int , vector <int>, classcomp > heap1;
int n, x;
// pop, push, top, size, empty, swap

int main()
{
    scanf("%d", &n);
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &x);
        heap.push(zbg(x));
        heap1.push(x);
    }
    while (!heap1.empty()) { printf("%d\n", heap1.top()); heap1.pop(); }

    return 0;
}
