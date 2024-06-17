#include <cstdio>
using namespace std;
typedef long long lld;

int a, i;
lld rest, br;
char ch[100005];

int main()
{
    scanf("%d", &a);
    scanf("%s", ch);

    while (ch[i]>0)
    {
        rest = (rest * 10 + (ch[i]-48)) % a;
        i++;
    }
    printf("%s", ch);
    if (rest)
    {
        br = 10;
        rest = rest*10 % a;
        while ((a-rest)%a >= br)
        {
            rest = rest*10 % a;
            br *= 10;
        }
        rest = (a - rest) % a;
        br = br / 10;
        while (br>rest) { printf("0"); br = br / 10; }
        if (rest) printf("%d", rest);
    }
    return 0;
}
