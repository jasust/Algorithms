#include <cstdio>
#include <cstring>
using namespace std;

int n, i, j, sol, b[205];
char a[205][30], s[30];

bool is_equal(char *ch1, char *ch2)
{
    int br = 0;
    while (ch1[br]==ch2[br]) { if (ch1[br]=='\0') return true; br++; }
    return false;
}

int main()
{
    scanf("%d", &n);
    a[0][0] = 'p'; a[0][1] = 'o'; a[0][2] = 'l'; a[0][3] = 'y';
    a[0][4] = 'c'; a[0][5] = 'a'; a[0][6] = 'r'; a[0][7] = 'p';
    a[0][8] = '\0';
    b[0] = 1;
    sol = 1;

    for (i=1; i<=n; i++)
    {
        scanf("%s %*s %s", a[i], s);
        for (j=0; j<strlen(a[i]); j++) if (a[i][j]>64 && a[i][j]<91) a[i][j]+=32;
        for (j=0; j<strlen(s); j++) if (s[j]>64 && s[j]<91) s[j]+=32;
        j=0;
        while (j<i && !is_equal(a[j],s)) j++;
        b[i] = b[j] + 1;
        if (b[i]>sol) sol = b[i];
    }

    printf("%d", sol);

    return 0;
}
