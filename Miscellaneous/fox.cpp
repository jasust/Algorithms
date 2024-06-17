#include <cstdio>
using namespace std;

int t, n, m, i, j, br;
char tmp, ch1[105], ch2[105];
bool brisanje[105], dp0[105][105], dp1[105][105];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        for (i=0; i<=101; i++) ch1[i] = ch2[i] = brisanje[i] = 0;
        for (i=0; i<=101; i++)
            for (j=0; j<=101; j++) dp0[i][j] = dp1[i][j] = false;
        scanf("%d", &n);
        scanf("%s", ch2);
        scanf("%d", &m);
        scanf("%s", ch1);
        /*
        scanf("%d\n", &n);
        gets(ch2);
        scanf("%d\n", &m);
        gets(ch1);
        */
        br = 0;
        for (i=0; i<m; i++)
        {
            if (ch1[i]=='n') { brisanje[br-1] = true; ch1[i] = 0; }
            else { ch1[br] = ch1[i]; if (br<i) ch1[i] = 0; br++; }
        }
        m = br;
        dp0[0][0] = true;
        dp1[0][1] = true;
        br = 0;
        while (brisanje[br]) { dp0[br+1][0] = true; br++;}
        if (br<m) dp1[br+1][0] = true; br++;
        while (brisanje[br]) { dp0[br+1][0] = true; br++;}
        for (i=0; i<m; i++)
            for (j=0; j<n; j++)
            {
                if (!brisanje[i])
                {
                    if (ch1[i]==ch2[j] && dp0[i][j]) dp0[i+1][j+1] = true;
                    if ((ch1[i]==ch2[j] && dp1[i][j]) || dp0[i][j+1] || dp0[i+1][j] || dp0[i][j]) dp1[i+1][j+1] = true;
                        br = j;
                        while (ch1[i]==ch2[br])
                            {
                                if (dp0[i][br]) dp1[i+1][j+1] = true;
                                br--;
                                if (br<0) break;
                            }
                    if (i && !brisanje[i-1])
                    {
                        br = j;
                        if (dp0[i-1][br+1]) dp1[i+1][j+1] = true;
                        while (ch1[i-1]==ch2[br])
                        {
                            if (dp0[i-1][br]) dp1[i+1][j+1] = true;
                            br--;
                            if (br<0) break;
                        }
                    }
                } else
                {
                    br = j;
                    if (dp0[i][br+1]) dp0[i+1][j+1] = true;
                    if (dp1[i][br+1]) dp1[i+1][j+1] = true;
                    while (ch1[i]==ch2[br])
                    {
                        if (dp0[i][br]) dp0[i+1][j+1] = true;
                        if (dp1[i][br]) dp1[i+1][j+1] = true;
                        br--;
                        if (br<0) break;
                    }
                    br = j; tmp = ch2[j];
                    while (tmp==ch2[br])
                    {
                        if (dp0[i][br]) dp1[i+1][j+1] = true;
                        br--;
                        if (br<0) break;
                    }
                    if (i && !brisanje[i-1])
                    {
                        br = j;
                        if (dp0[i-1][br+1]) dp1[i+1][j+1] = true;
                        while (ch1[i-1]==ch2[br])
                        {
                            if (dp0[i-1][br]) dp1[i+1][j+1] = true;
                            br--;
                            if (br<0) break;
                        }
                    }
                    if (dp0[i+1][j]) dp1[i+1][j+1] = true;
                    br = j; tmp = ch2[j];
                    if (ch1[i]!=tmp)
                    {
                        if (br) while (tmp==ch2[br] && ch2[br-1]==tmp) { br--; if (!br) break; }
                        if (br && ch1[i]==ch2[br-1] && dp0[i][br-1]) dp1[i+1][j+1] = true;
                    }
                }
            }
        if (dp1[m][n] || dp0[m][n]) printf("Yes"); else printf("No");
        if (t) printf("\n");
    }
    return 0;
}
