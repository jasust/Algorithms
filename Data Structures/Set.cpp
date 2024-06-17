#include <cstdio>
#include <set>
using namespace std;

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs>rhs;}
};
int n, q, x;
set <int, classcomp> s;
multiset <int> ms;
// =, begin, end, rbegin, rend, empty, size, max_size, insert, erase, clear, swap,
// find, count, upper_bound, lower_bound, equal_range
// multiset moze da ima i vise elemenata - sve kao set i - emplace, emplace_hint, key_comp, value_comp,

int main()
{
    printf("%d", s.max_size());
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &x);
        s.insert(x);
        ms.insert(x);
    }
    printf("%d %d %d\n", s.count(1), s.count(2), ms.count(3));
    scanf("%d", &q);
    for (int i=0; i<q; i++)
    {
        scanf("%d", &x);
        if (s.upper_bound(x)==s.end()) printf("kraj "); else printf("%d ", *s.upper_bound(x));
        if (ms.upper_bound(x)==ms.end()) printf("kraj "); else printf("%d ", *ms.upper_bound(x));
    }
    return 0;
}

