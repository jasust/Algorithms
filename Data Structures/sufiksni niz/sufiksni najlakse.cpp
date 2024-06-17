#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

char ch[100];
int a[100], len;

bool cmp(int a, int b)
{
    while (ch[a]==ch[b])
    {
        if (a==len) return 1;
        if (b==len) return 0;
        a++; b++;
    }
    return (ch[a]<ch[b]);
}

int main()
{
    scanf("%s", ch);
    len = strlen(ch);
    for (int i = 0; i<len; i++) a[i] = i;
    sort(a, a+len, cmp);
    for (int i = 0; i<len; i++) printf("%d ", a[i]);
    return 0;
}
