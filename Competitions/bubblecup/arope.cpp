#include <iostream>
#include <cstdio>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

int q, t, l, r, n;
string s;
rope<char> nor, obr;

int main() {

    cin >> s;
    n = s.length();
    for (int i=0; i<n; ++i) {
        nor.push_back(s[i]);
        obr.push_back(s[n-i-1]);
    }

    scanf("%d", &q);scanf("%d", &r);
    while (q--) {
        scanf("%d %d", &t, &l);
        if (t!=3) {
            scanf("%d", &r);
            rope<char> curn = nor.substr(l, ++r-l);
            rope<char> curo = obr.substr(n-r, r-l);
            nor.erase(l, r-l);
            obr.erase(n-r, r-l);
            if (t==1) {
                curo.append(nor);
                swap(curo,nor);
                obr.append(curn);
            } else {
                nor.append(curo);
     			curn.append(obr);
     			swap(curn,obr);
            }
        } else printf("%c\n", nor[l]);
    }
    return 0;
}
