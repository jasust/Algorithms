#include <cstdio>
using namespace std;

int i = 1, j, par;
char n[1003];

int main()
{
    scanf("%s", &n);
    par = (n[0]-'0')&1;
    while (((n[i]-'0')&1)^par) i++, par=1-par;
    if (n[i]=='0')
    {
        for (int j=i; n[j]; j++) n[j]='1'-((j-i)&1);
        printf("%s", n);
        return 0;
    } else
    if (n[i]=='9')
    {
        for (int j=i; n[j]; j++) n[j]='8'+((j-i)&1);
        printf("%s", n);
        return 0;
    } else
    {
        for (j=i+1; n[j] && (n[j]==('5'-((j-i)&1)^par)); j++);
        if (n[j] && (n[j]>('5'-((j-i)&1)^par)))
        {
            n[i] = n[i] + 1;
            for (int j=i+1; n[j]; j++) n[j]='1'-(((j-i)&1)^par);
            printf("%s", n);
            return 0;
        } else
        if (n[j] && (n[j]<('5'-((j-i)&1)^par)))
        {
            n[i] = n[i] - 1;
            for (int j=i+1; n[j]; j++) n[j]='9'-(((j-i)&1)^par);
            printf("%s", n);
            return 0;
        } else
        {
            n[i] = n[i] - 1;
            for (int j=i+1; n[j]; j++) n[j]='9'-(((j-i)&1)^par);
            printf("%s ", n);
            n[i] = n[i] + 2;
            for (int j=i+1; n[j]; j++) n[j]='1'-(((j-i)&1)^par);
            printf("%s", n);
            return 0;
        }
    }
}
