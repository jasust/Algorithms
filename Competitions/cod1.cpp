#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
using namespace std;
typedef long long lld;

char ch[200];
int le, re, sum, dif, i;

int main()
{
    while (1)
    {
        scanf("%c", ch+i);
        if (ch[i] == "|") break;
        i++;
        le++;
    }
    while (1)
    {
        getc(ch[i]);
        if (ch[i] == "\n") break;
        i++; re++;
    }
    while (1)
    {
        getc(ch[i]);
        if (ch[i] == "\n") break;
        i++; sum++;
    }
    i=0; dif = abs(le-re);
    if (dif>sum || (dif%2 != sum%2)) printf("Impossible"), return 0;
    if (le>re)
    {
        while (i<le) printf("%c", ch[i]), i++;
        for (i=le+re; i<le+re-1+(sum-dif)/2; i++) printf("%c", ch[i]);
        printf("|");
        for (i=le; i<re; i++) printf("%c", ch[i]);
        for (i=le+re+(sum-dif)/2; i<le+re+sum; i++) printf("%c", ch[i]);
        return 0;
    }
    if (re>le)
    {
        for (i=le; i<re; i++) printf("%c", ch[i]);
        for (i=le+re; i<le+re-1+(sum+dif)/2; i++) printf("%c", ch[i]);
        printf("|");
        for (i=le; i<re; i++) printf("%c", ch[i]);
        for (i=le+re+(sum+dif)/2; i<le+re+sum; i++) printf("%c", ch[i]);
        return 0;
    }
}
