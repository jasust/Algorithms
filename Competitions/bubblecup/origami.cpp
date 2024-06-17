#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define DEBUG 0
using namespace std;
typedef long long ll;

int n, i, num, id1, id2, idu, idl, idr;
ll a1, b1, c1;
long double a, b, c;
bool in_hull[100005];
long double area, width, height, den;
struct tocka { ll x,y; } point[100005];
vector <int> hull;

long double aps(long double a) { return (a>0)?a:-a; }
long double numer(int id) { return aps(a*(long double)point[hull[id]].x+b*(long double)point[hull[id]].y+c); }
long double dist(long double x1, long double y1, long double x2, long double y2) { return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));}
ll levo(tocka _a, tocka _b, tocka _c) { return ((_b.x-_a.x)*(_c.y-_a.y)-(_b.y-_a.y)*(_c.x-_a.x)); }
bool btw(long double ax, long double ay, long double bx, long double by, long double x, long double y) {
    return ((x<ax)&&(x>bx))||((x>ax)&&(x<bx))||((y<ay)&&(y>by))||((y>ay)&&(y<by));
}

bool cmp_mc(tocka _a, tocka _b) { if (_a.x==_b.x) return _a.y>_b.y; return _a.x<_b.x; }

int nextID (int id) { if (id==num-1) return 0; return id+1; }
int prevID (int id) { if (id==0) return num-1; return id-1; }

void monotone_chain() {
    sort(point, point+n, cmp_mc);
    hull.push_back(0);
    hull.push_back(1);
    in_hull[0] = true;
    in_hull[1] = true;
    for (i=2; i<n; i++)
    {
        while (hull.size()>1 && levo(point[hull[hull.size()-2]],point[hull[hull.size()-1]], point[i])<=0) {
            in_hull[hull[hull.size()-1]] = false;
            hull.pop_back();
        }
        hull.push_back(i);
        in_hull[i] = true;
    }
    for (i=n-1; i>=0; i--)
        if (!in_hull[i])
    {
        while (levo(point[hull[hull.size()-2]],point[hull[hull.size()-1]], point[i])<=0) {
            in_hull[hull[hull.size()-1]] = false;
            hull.pop_back();
        }
        hull.push_back(i);
        in_hull[i] = true;
    }
    while (levo(point[hull[hull.size()-2]],point[hull[hull.size()-1]], point[0])<=0) {
            in_hull[hull[hull.size()-1]] = false;
            hull.pop_back();
        }
    // hull.pop_back();
    return;
}

int main()
{
    if (DEBUG)
        freopen("test.txt", "r", stdin);

    scanf("%d", &n);
    for (i=0; i<n; ++i) scanf("%lld%lld", &point[i].x, &point[i].y);

    monotone_chain();
    num = hull.size();
    if (DEBUG) {
        printf("Tacke na konveksnom:\n");
        for (i=0; i<num; i++) printf("(%lld,%lld) ", point[hull[i]].x, point[hull[i]].y);
        printf("\n   Visina     Sirina     Povrsina:\n");
    }
    long double area = 1e19;
    id1 = 0;
    id2 = idu = idr = 1;
    idl = 2;

    for (i=0; i<num; ++i)
    {
        height = 0;
        a1 = point[hull[id2]].y - point[hull[id1]].y;
        b1 = point[hull[id1]].x - point[hull[id2]].x;
        c1 = point[hull[id2]].x*point[hull[id1]].y - point[hull[id1]].x*point[hull[id2]].y;
        den = sqrtl((long double)(a1*a1+b1*b1));
        a = (long double)a1/(long double)den;
        b = (long double)b1/(long double)den;
        c = (long double)c1/den;
        while (idu != id1) {
            long double h = (long double)numer(idu);
            if (h>=height) {
                height = h;
                idu = nextID(idu);
            } else {
                break;
            }
        }
        idu = prevID(idu);

        if (idr==id1) idr = nextID(idr);
        long double currx;
        long double curry;
        if (idr==id2) {
            currx = point[hull[idr]].x;
            curry = point[hull[idr]].y;
        } else {
            currx = (long double)(b*(b*point[hull[idr]].x-a*point[hull[idr]].y)-a*c)/(long double)(a*a+b*b);
            curry = (long double)(a*(-b*point[hull[idr]].x+a*point[hull[idr]].y)-b*c)/(long double)(a*a+b*b);
        }

        while (idr != id1) {
            long double pomx;
            long double pomy;
            if (idr==id2) {
                pomx = point[hull[idr]].x;
                pomy = point[hull[idr]].y;
            } else {
                pomx = (long double)(b*(b*point[hull[idr]].x-a*point[hull[idr]].y)-a*c)/(long double)(a*a+b*b);
                pomy = (long double)(a*(-b*point[hull[idr]].x+a*point[hull[idr]].y)-b*c)/(long double)(a*a+b*b);
            }
            if (dist(pomx,pomy,point[hull[id2]].x,point[hull[id2]].y)<dist(pomx,pomy,point[hull[id1]].x,point[hull[id1]].y)
                && dist(pomx,pomy,point[hull[id2]].x,point[hull[id2]].y)>=dist(currx,curry,point[hull[id2]].x,point[hull[id2]].y)
                && !btw(point[hull[id1]].x,point[hull[id1]].y,point[hull[id2]].x,point[hull[id2]].y,pomx,pomy))  {
                currx = pomx;
                curry = pomy;
                idr = nextID(idr);
            } else {
                break;
            }
        }
        idr = prevID(idr);

        while (idl != id1) {
            long double pomx = (long double)(b*(b*point[hull[idl]].x-a*point[hull[idl]].y)-a*c)/(long double)(a*a+b*b);
            long double pomy = (long double)(a*(-b*point[hull[idl]].x+a*point[hull[idl]].y)-b*c)/(long double)(a*a+b*b);
            if (dist(pomx,pomy,point[hull[id2]].x,point[hull[id2]].y)<dist(pomx,pomy,point[hull[id1]].x,point[hull[id1]].y)
                || btw(point[hull[id1]].x,point[hull[id1]].y,point[hull[id2]].x,point[hull[id2]].y,pomx,pomy)) {
                idl = nextID(idl);
            } else {
                break;
            }
        }

        long double curlx = (long double)(b*(b*point[hull[idl]].x-a*point[hull[idl]].y)-a*c)/(long double)(a*a+b*b);
        long double curly = (long double)(a*(-b*point[hull[idl]].x+a*point[hull[idl]].y)-b*c)/(long double)(a*a+b*b);
        while (idl != id2) {
            long double pomx = (long double)(b*(b*point[hull[idl]].x-a*point[hull[idl]].y)-a*c)/(long double)(a*a+b*b);
            long double pomy = (long double)(a*(-b*point[hull[idl]].x+a*point[hull[idl]].y)-b*c)/(long double)(a*a+b*b);
            if (dist(pomx,pomy,point[hull[id1]].x,point[hull[id1]].y)>=dist(curlx,curly,point[hull[id1]].x,point[hull[id1]].y)) {
                curlx = pomx;
                curly = pomy;
                idl = nextID(idl);
            } else {
                break;
            }
        }
        idl = prevID(idl);
        if (DEBUG)
            printf("%d\n", idr);

        width = sqrtl(dist(currx, curry, curlx, curly));
        if (DEBUG) {
            printf("%lf %lf %lf\n", double(height), double(width), double(height*width));
        }
        if (height*width<=area) area = height*width;

        id1 = id2;
        id2 = nextID(id2);
    }
    printf("%lld", llroundl(area));
    if (DEBUG)
        fclose(stdout);

    return 0;
}
