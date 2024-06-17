#include <cstdio>
using namespace std;

int n, m, r, c, r1, c1, sol, k;
bool a[10][10];

int DFS( int red, int kol )
{
    int re = red - 4, ko = kol - 4;
    if (r+re>2 && c+ko>1) a[red-2][kol-1] = true;
    if (r+re>2 && c1-ko>1) a[red-2][kol+1] = true;
    if (r+re>1 && c+ko>2) a[red-1][kol-2] = true;
    if (r+re>1 && c1-ko>2) a[red-1][kol+2] = true;
    if (r1-re>2 && c+ko>1) a[red+2][kol-1] = true;
    if (r1-re>2 && c1-ko>1) a[red+2][kol+1] = true;
    if (r1-re>1 && c+ko>2) a[red+1][kol-2] = true;
    if (r1-re>1 && c1-ko>2) a[red+1][kol+2] = true;
}

int main()
{
    scanf("%d %d %d %d %d", &n, &m, &r, &c, &k);

    k--; c1 = m - c + 1; r1 = n - r + 1;
    if (r>2 && c>1) if (k) DFS(2,3); else sol++;
    if (r>2 && c1>1) if (k) DFS(2,5); else sol++;
    if (r>1 && c>2) if (k) DFS(3,2); else sol++;
    if (r>1 && c1>2) if (k) DFS(3,6); else sol++;
    if (r1>2 && c>1) if (k) DFS(6,3); else sol++;
    if (r1>2 && c1>1) if (k) DFS(6,5); else sol++;
    if (r1>1 && c>2) if (k) DFS(5,2); else sol++;
    if (r1>1 && c1>2) if (k) DFS(5,6); else sol++;

    if (k)
        for (int i=0; i<9; i++)
            for (int j=0; j<9; j++)
                if (a[i][j]) sol++;

    printf("%d", sol);
    return 0;
}
