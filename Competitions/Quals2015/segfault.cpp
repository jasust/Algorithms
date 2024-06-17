#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e9;

int n, m, i, j, k, br, sz, pom, x[500005], y[500005], uslov[1003][1003], mat[1003][1003], redx[1000006], redy[1000006];
char d[500005], ram[1003][1003];

int main()
{
    scanf("%d%d", &n, &m);
    for (i=0; i<n; i++) scanf("%s", ram+i);
    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
            {
                if (ram[i][j]=='S') { redx[0] = i; redy[0] = j; }
                mat[i][j] = maxn;
                uslov[i][j]=0;
            }

    scanf("%d", &k);
    for (i=0; i<k; i++)
    {
        scanf("%d %d %c", x+i, y+i, d+i);
        mat[--x[i]][--y[i]] = 1;
        if (d[i]=='D') uslov[x[i]][y[i]] |= 1;
        if (d[i]=='U') uslov[x[i]][y[i]] |= 2;
        if (d[i]=='L') uslov[x[i]][y[i]] |= 4;
        if (d[i]=='R') uslov[x[i]][y[i]] |= 8;
    }
    for (i=0; i<k; i++)
    {
        br = 2;
        if (d[i]=='D')
        {
            pom = ++x[i];
            while (x[i]<n && ram[x[i]][y[i]]=='.' && !(uslov[x[i]][y[i]]&1))
            {
                mat[x[i]][y[i]] = min(mat[x[i]][y[i]], br);
                br++; x[i]++;
            }
            if (pom<n) uslov[pom][y[i]] |= 1;
        }
        if (d[i]=='U')
        {
            pom = --x[i];
            while (x[i]>=0 && ram[x[i]][y[i]]=='.' && !(uslov[x[i]][y[i]]&2))
            {
                mat[x[i]][y[i]] = min(mat[x[i]][y[i]], br);
                br++; x[i]--;
            }
            if (pom>=0) uslov[pom][y[i]] |= 2;
        }
        if (d[i]=='L')
        {
            pom = --y[i];
            while (y[i]>=0 && ram[x[i]][y[i]]=='.' && !(uslov[x[i]][y[i]]&4))
            {
                mat[x[i]][y[i]] = min(mat[x[i]][y[i]], br);
                br++; y[i]--;
            }
            if (pom>=0) uslov[x[i]][pom] |= 4;
        }
        if (d[i]=='R')
        {
            pom = ++y[i];
            while (y[i]<m && ram[x[i]][y[i]]=='.' && !(uslov[x[i]][y[i]]&8))
            {
                mat[x[i]][y[i]] = min(mat[x[i]][y[i]], br);
                br++; y[i]++;
            }
            if (pom<m) uslov[x[i]][pom] |= 8;
        }
    }

    mat[redx[0]][redy[0]] = 0;
    br = 0; sz = 1;
    while (br<sz)
    {
        if (redx[br]<n-1 && ram[redx[br]+1][redy[br]]=='.' && (mat[redx[br]+1][redy[br]]>mat[redx[br]][redy[br]]+1))
        {
            mat[redx[br]+1][redy[br]] = mat[redx[br]][redy[br]] + 1;
            redx[sz] = redx[br]+1;
            redy[sz] = redy[br];
            sz++;
        }
        if (redx[br]>0 && ram[redx[br]-1][redy[br]]=='.' && (mat[redx[br]-1][redy[br]]>mat[redx[br]][redy[br]]+1))
        {
            mat[redx[br]-1][redy[br]] = mat[redx[br]][redy[br]] + 1;
            redx[sz] = redx[br]-1;
            redy[sz] = redy[br];
            sz++;
        }
        if (redy[br]>0 && ram[redx[br]][redy[br]-1]=='.' && (mat[redx[br]][redy[br]-1]>mat[redx[br]][redy[br]]+1))
        {
            mat[redx[br]][redy[br]-1] = mat[redx[br]][redy[br]] + 1;
            redx[sz] = redx[br];
            redy[sz] = redy[br]-1;
            sz++;
        }
        if (redy[br]<m-1 && ram[redx[br]][redy[br]+1]=='.' && (mat[redx[br]][redy[br]+1]>mat[redx[br]][redy[br]]+1))
        {
            mat[redx[br]][redy[br]+1] = mat[redx[br]][redy[br]] + 1;
            redx[sz] = redx[br];
            redy[sz] = redy[br]+1;
            sz++;
        }
        br++;
    }

    printf("%d", sz);

    return 0;
}
