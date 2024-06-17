#include<cstdio>
using namespace std;
char s[4];
int main()
{
    while (true)
    {
        scanf("%s", s);
        if ((s[0]=='4' && s[1]=='2' && s[3]==0) || s[0]==0) break;
        printf("%s\n", s);
        s[0]==0; s[1]==0; s[2]==0;
    }
    return 0;
}
