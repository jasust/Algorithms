#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, i, idx;
struct tocka { int x,y; } point[100005];
vector <int> hull_mc, hull_gs;

int levo(tocka _a, tocka _b, tocka _c)
{
    return ((_b.x-_a.x)*(_c.y-_a.y)-(_b.y-_a.y)*(_c.x-_a.x));
}

bool cmp_mc(tocka _a, tocka _b) { if (_a.x==_b.x) return _a.y<_b.y; return _a.x<_b.x; }
bool cmp_gs(tocka _a, tocka _b)
{
    if ((_a.y-point[idx].y)*(_b.x-point[idx].x)==(_a.x-point[idx].x)*(_b.y-point[idx].y))
    {   if (_a.x==_b.x) return _a.y<_b.y; else return _a.x<_b.x;    }
    return (_a.y-point[idx].y)*(_b.x-point[idx].x)<(_a.x-point[idx].x)*(_b.y-point[idx].y);
}

void monotone_chain(void)
{
    sort(point, point+n, cmp_mc);
    hull_mc.push_back(0);
    hull_mc.push_back(1);
    for (i=2; i<n; i++)
    {
        while (hull_mc.size()>1 && levo(point[hull_mc[hull_mc.size()-2]],point[hull_mc[hull_mc.size()-1]], point[i])<0)
            hull_mc.pop_back();
        hull_mc.push_back(i);
    }
    for (i=n-2; i>=0; i--)
    {
        while (levo(point[hull_mc[hull_mc.size()-2]],point[hull_mc[hull_mc.size()-1]], point[i])<0)
            hull_mc.pop_back();
        hull_mc.push_back(i);
    }
    hull_mc.pop_back();
    return;
}

void graham_scan(void) // ima poblem kad se vise tacaka nalaze na poslednjoj ivici
{
    idx = 0;
    for (i=1; i<n; i++) if ((point[i].x==point[idx].x && point[i].y<point[idx].y) || (point[i].x<point[idx].x)) idx = i;
    swap(point[0], point[idx]);
    sort(point+1, point+n, cmp_gs);
    hull_gs.push_back(0);
    hull_gs.push_back(1);
    for (i=2; i<n; i++)
    {
        while (hull_gs.size()>1 && levo(point[hull_gs[hull_gs.size()-2]],point[hull_gs[hull_gs.size()-1]], point[i])<0)
            hull_gs.pop_back();
        hull_gs.push_back(i);
    }
    while (hull_gs.size()>1 && levo(point[hull_gs[hull_gs.size()-2]],point[hull_mc[hull_gs.size()-1]], point[0])<0) hull_gs.pop_back();
    return;
}

int main()
{
    scanf("%d", &n);
    for (i=0; i<n; i++) scanf("%d %d", &point[i].x, &point[i].y);

    monotone_chain();
    printf("\n");
    for(i=0; i<hull_mc.size(); i++) printf("%d %d\n", point[hull_mc[i]].x, point[hull_mc[i]].y);

    graham_scan();
    printf("\n");
    for(i=0; i<hull_gs.size(); i++) printf("%d %d\n", point[hull_gs[i]].x, point[hull_gs[i]].y);

    return 0;
}
