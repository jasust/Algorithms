#include <cstdio>
#include <cmath>
using namespace std;

int t, l, r, i, low, up;
long long int ans;

void new_three(int a, int b, int c)
{
    int treci1 = 2*a - 2*b + 3*c;
    if (treci1<=r) {
    int prvi1 = a - 2*b + 2*c;
    int drugi1 = 2*a - b + 2*c;
    up = (r/treci1);
    if (drugi1>prvi1) low = ((l+prvi1-1)/prvi1); else low = ((l+drugi1-1)/drugi1);
    if (up>=low) ans += up-low+1;
    new_three(prvi1,drugi1,treci1);
    }

    int treci2 = 2*a + 2*b + 3*c;
    if (treci2<=r) {
    int prvi2 = a + 2*b + 2*c;
    int drugi2 = 2*a + b + 2*c;
    up = (r/treci2);
    if (drugi2>prvi2) low = ((l+prvi2-1)/(prvi2)); else low = ((l+drugi2-1)/(drugi2));
    if (up>=low) ans += up-low+1;
    new_three(prvi2,drugi2,treci2);
    }

    int treci3 = -2*a + 2*b + 3*c;
    if (treci3<=r) {
    int prvi3 =  -a + 2*b + 2*c;
    int drugi3 = -2*a + b + 2*c;
    up = (r/treci3);
    if (drugi3>prvi3) low = ((l+prvi3-1)/prvi3); else low = ((l+drugi3-1)/drugi3);
    if (up>=low) ans += up-low+1;
    new_three(prvi3,drugi3,treci3);
    }

    return;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &l, &r);
        ans = 0;
        up = (r/5);
        low = ((l+2)/3);
        if (low == 0) low = 1;
        if (up>=low) ans += up-low+1;
        new_three(3,4,5);
        printf("%I64d\n", ans);
    }
}
