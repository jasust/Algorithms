// ne radi u opstem slucaju, ali busni su im test primeri
#include<cstdio>
#include<queue>
using namespace std;

typedef int _niz[14][14];
int t, r, c, i, j, maxx, maxy, minx, miny;
char ch;
_niz a, mn, cn;
int korak[8][2] = {{-1, 0},{0, -1},{0, 1},{1, 0},{-1, -1},{-1, 1},{1, -1},{1, 1}};

struct corv { int x, y, v; } mouse, cat;

void bfs(corv start, _niz niz)
{
    queue<corv> bfs_queue;
    bfs_queue.push(start);
    niz[start.x][start.y] = start.v;

    while (!bfs_queue.empty())
    {
        corv curr = bfs_queue.front();
        bfs_queue.pop();

        for (int i=0; i<8; i++)
        {
            if (niz[curr.x+korak[i][0]][curr.y+korak[i][1]]<0 && !a[curr.x+korak[i][0]][curr.y+korak[i][1]])
            {
                corv tmp;
                tmp.x = curr.x+korak[i][0], tmp.y = curr.y+korak[i][1], tmp.v = curr.v+1;
                bfs_queue.push(tmp);
                niz[curr.x+korak[i][0]][curr.y+korak[i][1]] = curr.v+1;
            }
        }
    }
}

bool bfs2(corv start)
{
    corv bfs_queue[200];
    int br = 0, tr = 0;
    bfs_queue[br++] = start;
    a[start.x][start.y] = start.v;
    maxx = minx = start.x;
    maxy = miny = start.y;

    while (tr<br)
    {
        for (int i=0; i<4; i++)
        {
            if (bfs_queue[tr].x+korak[i][0]>=0 && bfs_queue[tr].y+korak[i][1]>=0 && bfs_queue[tr].x+korak[i][0]<r+2 && bfs_queue[tr].y+korak[i][1]<c+2 && a[bfs_queue[tr].x+korak[i][0]][bfs_queue[tr].y+korak[i][1]]==1)
            {
                bfs_queue[br].x = bfs_queue[tr].x+korak[i][0];
                bfs_queue[br].y = bfs_queue[tr].y+korak[i][1];
                bfs_queue[br].v = bfs_queue[tr].v;
                if (bfs_queue[br].x>maxx) maxx = bfs_queue[br].x; else if (bfs_queue[br].x<minx) minx = bfs_queue[br].x;
                if (bfs_queue[br].y>maxy) maxy = bfs_queue[br].y; else if (bfs_queue[br].y<miny) miny = bfs_queue[br].y;
                a[bfs_queue[tr].x+korak[i][0]][bfs_queue[tr].y+korak[i][1]] = bfs_queue[tr].v;
                br++;
            }
        }
        tr++;
    }
    if (start.v==2) return false;

    for (int i=0; i<br; i++)
        for (int j=0; j<4; j++)
            if (!a[bfs_queue[i].x+korak[j][0]][bfs_queue[i].y+korak[j][1]])
             if (bfs_queue[i].x+korak[j][0]>maxx || bfs_queue[i].x+korak[j][0]<minx || bfs_queue[i].y+korak[j][1]>maxy || bfs_queue[i].y+korak[j][1]<miny)
              if (mn[bfs_queue[i].x+korak[j][0]][bfs_queue[i].y+korak[j][1]]<cn[bfs_queue[i].x+korak[j][0]][bfs_queue[i].y+korak[j][1]]) return true;
    return false;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &r, &c);
        for (i=0; i<r+2; i++) a[i][0] = a[i][c+1] = 1;
        for (i=0; i<c+2; i++) a[0][i] = a[r+1][i] = 1;
        for (i=0; i<r+2; i++)
            for (j=0; j<c+2; j++) mn[i][j] = cn[i][j] = -1;
        for (i=1; i<=r; i++)
        {
            scanf("\n");
            for (j=1; j<=c; j++)
            {
                scanf("%c", &ch);
                if (ch=='#') a[i][j]=1; else a[i][j] = 0;
                if (ch=='m') mouse.x = i, mouse.y = j, mouse.v = 1;
                if (ch=='c') cat.x = i, cat.y = j, cat.v = 0;
            }
        }
        bfs(cat, cn);
        bfs(mouse, mn);
        if (cn[mouse.x][mouse.y]==-1) { printf("mouse\n"); continue; }

        corv zid;
        zid.x = zid.y = 0, zid.v = 2;
        bool sol = bfs2(zid);
        for (i=1; i<=r; i++)
        {
            for (j=1; j<=c; j++)
            {
                if (a[i][j]==1)
                {
                    zid.x = i;
                    zid.y = j;
                    zid.v = 3;
                    sol = bfs2(zid);
                }
                if (sol) break;
            }
            if (sol) break;
        }
        if (sol) printf("mouse\n"); else printf("cat\n");
    }
    return 0;
}
