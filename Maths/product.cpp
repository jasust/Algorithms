#include <iostream>
using namespace std;

int n, p=1;

int main() {
    cin >> n;
    for (int i=1; i<=n; ++i) {
        p = p*i;
        while (!(p%10)) p /= 10;
        p %= 100000;
    }
    cout << p%10;
    return 0;
}
