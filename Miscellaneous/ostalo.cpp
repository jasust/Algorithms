/* datoteke, greedy, 2sat,
   stringovi, knut-moris-prat, Boyer Moore, Z algorithm, Rabin Karpa, algoritmi sa stringovima,
   hash, map,
   vektor, stack, queue, deque, struct, pointer.

   Prime numbers: 107, 1009, 3137, 10009, 31337, 100003, 1000003, 11111117, 100000007, 1000000007
*/
// #include <bits/stdc++.h> // inkluduje sve
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <string>
using namespace std;

struct dot
{
    int x, y;
    dot( int _x, int _y )
    {
        x = _x;
        y = _y;
    }
    bool operator < ( const dot & curr ) const
    {
        if ( x != curr.x ) return x < curr.x;
        else return y > curr.y;
    }
} *b;

struct dot2
{
    int x, y;
    bool operator < ( const dot2 & curr ) const
    {
        if ( x != curr.x ) return x < curr.x;
        else return y > curr.y;
    }
} a;

int main(void)
{
    // vector
    printf("\n---VEKTOR---\n");
    vector <int> v, ve, vek;
    vector <int> :: iterator it;
    for (int i=0; i<10; i++) v.push_back(i);
    v.pop_back();
    printf("%d %d %d\n", v.size(), v.capacity(), v.max_size());
    printf("%d %d %d\n", v.size(), v.capacity(), v.max_size());
    ve = v;
    vek.reserve(10);
    v.resize(4);
    ve.resize(15);
    printf("%d %d\n", v.front(), v.back());
    ve.swap(v);
    if (vek.empty()) printf("PRAZAN\n");
    for (it = v.begin(); it<v.end(); it++) printf("%d ", *it);
    for (vector <int> :: reverse_iterator rit = ve.rbegin(); rit<ve.rend(); rit++) printf("%d ", *rit);

    //stack - push, pop, empty, size, top, swap
    printf("\n---STEK---\n");
    stack <int> s;
    for (int i=0; i<10; i++) s.push(i);
    while (!s.empty()) printf("%d ", s.top()), s.pop();

    //queue - push, pop, empty, size, front, back, swap
    printf("\n---RED---\n");
    queue <int> q;
    for (int i=0; i<10; i++) q.push(i);
    while (!q.empty()) printf("%d%d ", q.front(), q.back()), q.pop();

    //deque - sve kao vektor, samo ima jos push_front i pop_front

    //struct
    printf("\n---STRUCT---\n");
    vector <dot> tocke;
    for ( int i = 1; i <= 10; i++ ) tocke.push_back(dot(i,i));
    sort(tocke.begin(), tocke.end());
    for (vector <dot>::iterator it = tocke.begin(); it<tocke.end(); it++) printf("%d%d ", it->x, it->y);

    //pointer *vrednost, &adresa, a->x je (*a).x, NULL, new,

    //map - ima sve kao set, radi u log(n), postoji i multimap i unordered_map
    printf("\n---MAP---\n");
    map <string, int> Hash;
    Hash["Janko"] = 5;
    Hash["Mirko"] = 3;
    Hash["Slavko"] = 0;
    printf("%d %d", Hash["Janko"], Hash["Slavko"]);

    // realni brojevi - u scanf - f za float, lf za double Lf za long double- max float 1e37
    printf("\n---REAL---\n");
    float f = 3.1415926535897932384626433832795028841971693993751;
    double d = 3.1415926535897932384626433832795028841971693993751;
    printf("%.7f %.15f %g %e", f, d, d, d);
    return 0;
}
