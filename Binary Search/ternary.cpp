#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
#define EPS 0.00000001

int n;
double x[102], y[102], z[102];
double solx, soly, solz;

double dist (double _x, double _y, double _z) {
    double distsol = 0, curr;
    for (int i=0; i<n; i++) {
        curr = (_x-x[i])*(_x-x[i])+(_y-y[i])*(_y-y[i])+(_z-z[i])*(_z-z[i]);
        if (distsol<curr) distsol = curr;
    }
    return distsol;
}

double ternary2(double _x, double _y) {

    double l = -1e4, r = 1e4;
    while (r-l>EPS) {
        double m1 = l+(r-l)/3, m2=r-(r-l)/3;
        if (dist(_x,_y,m1)>dist(_x,_y,m2)) l = m1;
            else r = m2;
    }
    return (l+r)/2;
}

pair<double,double> ternary1(double _x) {

    double l = -1e4, r = 1e4;
    while (r-l>EPS) {
        double m1 = l+(r-l)/3, m2=r-(r-l)/3;
        double z1 = ternary2(_x,m1), z2 = ternary2(_x,m2);
        if (dist(_x,m1,z1)>dist(_x,m2,z2)) l = m1;
            else r = m2;
    }
    return make_pair((l+r)/2,ternary2(_x,(l+r)/2));
}

void ternary() {

    double l = -1e4, r = 1e4;
    while (r-l>EPS) {
        double m1 = l+(r-l)/3, m2=r-(r-l)/3;
        pair<double,double> s1 = ternary1(m1), s2 = ternary1(m2);
        if (dist(m1,s1.first,s1.second)>dist(m2,s2.first,s2.second)) l = m1;
            else r = m2;
    }
    solx = (l+r)/2;
    pair<double,double> sol = ternary1(solx);
    soly = sol.first;
    solz = sol.second;
}

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%lf%lf%lf", x+i, y+i, z+i);
    ternary();
    printf("%.6lf %.6lf %.6lf", solx, soly, solz);
    return 0;
}
