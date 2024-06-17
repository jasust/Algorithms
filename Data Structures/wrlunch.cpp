#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int inf = 1e8;
int NH, NV, H, V, t, n, size, i, sol, br;
set <int> priv[1003], npriv[1003];

struct jbg
{
    int poc, kraj;
} row[10004], col[10004];

struct segment_tree
{
  int tree[2050][2];
  void reset(int idx, int l, int r)
  {
    tree[idx][0] = inf;
    tree[idx][1] = inf;
    if (l==r) return;
    int mid = (l+r)>>1;
    reset(2*idx, l, mid);
    reset(2*idx+1, mid+1, r);
  }
  void update(int idx, int l, int r, int pos, int val, int type)
  {
    if (l==r)
    {
      tree[idx][type] = val;
      return;
    }
    int mid = (l+r)>>1;
    if (pos<=mid) update(2*idx, l, mid, pos, val, type);
    else update(2*idx+1, mid+1, r, pos, val, type);
    tree[idx][type] = tree[2*idx][type]<tree[2*idx+1][type]?tree[2*idx][type]:tree[2*idx+1][type];
  }
  int get(int idx, int l, int r, int levi, int desni, int type)
  {
    if (l==levi && r==desni) return tree[idx][type];
    int mid = (l+r)>>1;
    if (desni<=mid) return get(2*idx, l, mid, levi, desni, type);
    else if (levi>mid) return get(2*idx+1, mid+1, r, levi, desni, type);
    else
    {
        int p1 = get(2*idx, l, mid, levi, mid, type);
        int p2 = get(2*idx+1, mid+1, r, mid+1, desni, type);
        return (p1<p2?p1:p2);
    }
  }
} stree;

int main()
{
    scanf("%d%d%d%d", &NH, &NV, &H, &V);
    if (NV) size = max(H,V); else size = H;

    stree.reset(1, 0, size-1);
    stree.update(1, 0, size-1, H-1, 1, 0);
    if (NV && V!=H) stree.update(1, 0, size-1, V-1, H, 0);
    for (i=0; i<NH; i++)
    {
        priv[H-1].insert(1+i*(H+V-2));
        row[i].poc = 1+i*(H+V-2);
        row[i].kraj = H+i*(H+V-2);
    }
    for (i=0; i<NV; i++)
    {
        priv[V-1].insert(H+i*(H+V-2));
        col[i].poc = H+i*(H+V-2);
        col[i].kraj = 1+(i+1)*(H+V-2);
    } // samo redni brojevi stolova su stvarni, ostalo je -1

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        if (n>size) { printf("no\n"); continue; }
        sol = stree.get(1, 0, size-1, n-1, size-1, 0);
        if (sol==(NH*(H-1)+NV*(V-1)+1))
        {
            printf("%d\n", sol);
            if (NH>NV) row[NH-1].kraj = sol-2; else col[NV-1].kraj = sol-2;
            priv[0].erase(sol);
            stree.update(1, 0, size-1, 0, inf, 0);
            npriv[1].erase(sol-1);
            if (npriv[1].empty()) stree.update(1, 0, size-1, 1, inf, 1); else stree.update(1, 0, size-1, 1, *npriv[1].begin(), 1);
            npriv[0].insert(sol-1);
            stree.update(1, 0, size-1, 0, *npriv[0].begin(), 1);
            continue;
        }
        if (sol<inf)
        {
            printf("%d\n", sol);

            if (sol%(H+V-2)>0 && sol%(H+V-2)<H)  // red
            {
                br = sol/(H+V-2);
                if (sol == 1+br*(H+V-2))
                {
                    if (br)
                    {
                        priv[col[br-1].kraj-col[br-1].poc].erase(col[br-1].poc);
                        if (priv[col[br-1].kraj-col[br-1].poc].empty()) stree.update(1, 0, size-1, col[br-1].kraj-col[br-1].poc, inf, 0); else stree.update(1, 0, size-1, col[br-1].kraj-col[br-1].poc, *priv[col[br-1].kraj-col[br-1].poc].begin(), 0);
                        if (col[br-1].poc<sol-1)
                        {
                            priv[sol-col[br-1].poc-2].insert(col[br-1].poc);
                            stree.update(1, 0, size-1, sol-col[br-1].poc-2, *priv[sol-col[br-1].poc-2].begin(), 0);
                        }
                        if (col[br-1].poc>sol-V+1)
                        {
                            npriv[col[br-1].kraj-col[br-1].poc+1].erase(col[br-1].poc-1);
                            if (npriv[col[br-1].kraj-col[br-1].poc+1].empty()) stree.update(1, 0, size-1, col[br-1].kraj-col[br-1].poc+1, inf, 1); else stree.update(1, 0, size-1, col[br-1].kraj-col[br-1].poc+1, *npriv[col[br-1].kraj-col[br-1].poc+1].begin(), 1);
                            npriv[col[br-1].kraj-col[br-1].poc].insert(col[br-1].poc-1);
                            stree.update(1, 0, size-1, col[br-1].kraj-col[br-1].poc, *npriv[col[br-1].kraj-col[br-1].poc].begin(), 1);
                        } else
                        {
                            npriv[col[br-1].kraj-col[br-1].poc-1].insert(col[br-1].poc);
                            stree.update(1, 0, size-1, col[br-1].kraj-col[br-1].poc-1, *npriv[col[br-1].kraj-col[br-1].poc-1].begin(), 1);
                        }
                        col[br-1].kraj = sol-2;
                    }
                } else
                {
                    npriv[0].insert(row[br].poc-1); // dobijes keca na pocetku, uvek, pokazano
                    stree.update(1, 0, size-1, 0, *npriv[0].begin(), 1);
                }
                if (sol+n-1==H+br*(H+V-2))
                {
                    if (sol+n-1!=(NH*(H-1)+NV*(V-1)+1)) // prekrati sledecu, pazi na poslednju
                    {
                        col[br].poc = sol+n+1;
                        priv[col[br].kraj-sol-n+1].erase(sol+n-1);
                        if (priv[col[br].kraj-sol-n+1].empty()) stree.update(1, 0, size-1, col[br].kraj-sol-n+1, inf, 0); else stree.update(1, 0, size-1, col[br].kraj-sol-n+1, *priv[col[br].kraj-sol-n+1].begin(), 0);
                        if (col[br].kraj<sol+n-2+V)
                        {
                            npriv[col[br].kraj-sol-n+2].erase(sol+n-1);
                            if (npriv[col[br].kraj-sol-n+2].empty()) stree.update(1, 0, size-1, col[br].kraj-sol-n+2, inf, 1); else stree.update(1, 0, size-1, col[br].kraj-sol-n+2, *npriv[col[br].kraj-sol-n+2].begin(), 1);
                            npriv[col[br].kraj-col[br].poc+2].insert(col[br].poc-1);
                            stree.update(1, 0, size-1, col[br].kraj-col[br].poc+2, *npriv[col[br].kraj-col[br].poc+2].begin(), 1);
                        } else
                        {
                            npriv[col[br].kraj-col[br].poc+1].insert(col[br].poc-1);
                            stree.update(1, 0, size-1, col[br].kraj-col[br].poc+1, *npriv[col[br].kraj-col[br].poc+1].begin(), 1);
                        }
                        if (col[br].kraj>=col[br].poc)
                        {
                            priv[col[br].kraj-col[br].poc].insert(col[br].poc);
                            stree.update(1, 0, size-1, col[br].kraj-col[br].poc, *priv[col[br].kraj-col[br].poc].begin(), 0);
                        }
                    }
                    priv[n-1].erase(row[br].poc);
                    if (priv[n-1].empty()) stree.update(1, 0, size-1, n-1, inf, 0); else stree.update(1, 0, size-1, n-1, *priv[n-1].begin(), 0);
                    if (sol>1+br*(H+V-2))
                    {
                        npriv[n].erase(sol-1);
                        if (npriv[n].empty()) stree.update(1, 0, size-1, n, inf, 1); else stree.update(1, 0, size-1, n, *npriv[n].begin(), 1);
                    }
                    row[br].poc = sol+n+1;
                } else if (sol+n==H+br*(H+V-2))
                {
                    if (sol+n<(NH*(H-1)+NV*(V-1)+1))
                    {
                        priv[col[br].kraj-col[br].poc].erase(col[br].poc);
                        if (priv[col[br].kraj-col[br].poc].empty()) stree.update(1, 0, size-1, col[br].kraj-col[br].poc, inf, 0); else stree.update(1, 0, size-1, col[br].kraj-col[br].poc, *priv[col[br].kraj-col[br].poc].begin(), 0);
                        if (col[br].kraj==1+(br+1)*(H+V-2))
                        {
                            npriv[V-1].insert(col[br].poc);
                            stree.update(1, 0, size-1, V-1, *npriv[V-1].begin(), 1);
                        }
                        col[br].poc = sol+n+1;
                        if (col[br].poc<=col[br].kraj)
                        {
                            priv[col[br].kraj-col[br].poc].insert(col[br].poc);
                            stree.update(1, 0, size-1, col[br].kraj-col[br].poc, *priv[col[br].kraj-col[br].poc].begin(), 0);
                        }
                    } else
                    {
                        npriv[0].insert(sol+n);
                        stree.update(1, 0, size-1, 0, *npriv[0].begin(), 1);
                    }
                    priv[n].erase(row[br].poc);
                    if (priv[n].empty()) stree.update(1, 0, size-1, n, inf, 0); else stree.update(1, 0, size-1, n, *priv[n].begin(), 0);
                    if (sol>1+br*(H+V-2))
                    {
                        npriv[n+1].erase(sol-1);
                        if (npriv[n+1].empty()) stree.update(1, 0, size-1, n+1, inf, 1); else stree.update(1, 0, size-1, n+1, *npriv[n+1].begin(), 1);
                    }
                    row[br].poc = sol+n+1;
                } else
                {
                    priv[row[br].kraj-row[br].poc].erase(row[br].poc);
                    if (priv[row[br].kraj-row[br].poc].empty()) stree.update(1, 0, size-1, row[br].kraj-row[br].poc, inf, 0); else stree.update(1, 0, size-1, row[br].kraj-row[br].poc, *priv[row[br].kraj-row[br].poc].begin(), 0);
                    if (sol>1+br*(H+V-2))
                    {
                        if (row[br].kraj<H+br*(H+V-2))
                        {
                            npriv[row[br].kraj-row[br].poc+2].erase(sol-1);
                            if (npriv[row[br].kraj-row[br].poc+2].empty()) stree.update(1, 0, size-1, row[br].kraj-row[br].poc+2, inf, 1); else stree.update(1, 0, size-1, row[br].kraj-row[br].poc+2, *npriv[row[br].kraj-row[br].poc+2].begin(), 1);
                            if (sol+n+1 <= row[br].kraj)
                            {
                                priv[row[br].kraj-sol-n-1].insert(sol+n+1);
                                stree.update(1, 0, size-1, row[br].kraj-sol-n-1, *priv[row[br].kraj-sol-n-1].begin(), 0);
                            }
                            npriv[row[br].kraj-sol-n+1].insert(sol+n);
                            stree.update(1, 0, size-1, row[br].kraj-sol-n+1, *npriv[row[br].kraj-sol-n+1].begin(), 1);
                        } else
                        {
                            npriv[row[br].kraj-row[br].poc+1].erase(sol-1);
                            if (npriv[row[br].kraj-row[br].poc+1].empty()) stree.update(1, 0, size-1, row[br].kraj-row[br].poc+1, inf, 1); else stree.update(1, 0, size-1, row[br].kraj-row[br].poc+1, *npriv[row[br].kraj-row[br].poc+1].begin(), 1);
                            if (sol+n+1 < row[br].kraj || row[br].kraj==(NH*(H-1)+NV*(V-1)+1))
                            {
                                priv[row[br].kraj-sol-n-1].insert(sol+n+1);
                                stree.update(1, 0, size-1, row[br].kraj-sol-n-1, *priv[row[br].kraj-sol-n-1].begin(), 0);
                            }
                            npriv[row[br].kraj-sol-n].insert(sol+n);
                            stree.update(1, 0, size-1, row[br].kraj-sol-n, *npriv[row[br].kraj-sol-n].begin(), 1);
                        }
                    } else
                    {
                        if (row[br].kraj<H+br*(H+V-2))
                        {
                            npriv[row[br].kraj-row[br].poc+1].erase(sol);
                            if (npriv[row[br].kraj-row[br].poc+1].empty()) stree.update(1, 0, size-1, row[br].kraj-row[br].poc+1, inf, 1); else stree.update(1, 0, size-1, row[br].kraj-row[br].poc+1, *npriv[row[br].kraj-row[br].poc+1].begin(), 1);
                            if (sol+n+1 <= row[br].kraj)
                            {
                                priv[row[br].kraj-sol-n-1].insert(sol+n+1);
                                stree.update(1, 0, size-1, row[br].kraj-sol-n-1, *priv[row[br].kraj-sol-n-1].begin(), 0);
                            }
                            npriv[row[br].kraj-sol-n+1].insert(sol+n);
                            stree.update(1, 0, size-1, row[br].kraj-sol-n+1, *npriv[row[br].kraj-sol-n+1].begin(), 1);
                        } else // ovo nzm dal treba uopste
                        {
                            if (sol+n+1<row[br].kraj || row[br].kraj==(NH*(H-1)+NV*(V-1)+1))
                            {
                                priv[row[br].kraj-sol-n-1].insert(sol+n+1);
                                stree.update(1, 0, size-1, row[br].kraj-sol-n-1, *priv[row[br].kraj-sol-n-1].begin(), 0);
                            }
                            npriv[row[br].kraj-sol-n].insert(sol+n);
                            stree.update(1, 0, size-1, row[br].kraj-sol-n, *npriv[row[br].kraj-sol-n].begin(), 1);
                        }
                    }
                    row[br].poc = sol+n+1;
                }

            } else //kolona
            {
                br = (sol-1)/(H+V-2);
                if (sol == H+br*(H+V-2))
                {
                    priv[row[br].kraj-row[br].poc].erase(row[br].poc);
                    if (priv[row[br].kraj-row[br].poc].empty()) stree.update(1, 0, size-1, row[br].kraj-row[br].poc, inf, 0); else stree.update(1, 0, size-1, row[br].kraj-row[br].poc, *priv[row[br].kraj-row[br].poc].begin(), 0);
                    if (row[br].poc<sol-1)
                    {
                        priv[sol-row[br].poc-2].insert(row[br].poc);
                        stree.update(1, 0, size-1, sol-row[br].poc-2, *priv[sol-row[br].poc-2].begin(), 0);
                    }
                    if (row[br].poc>sol-H+1)
                    {
                        npriv[sol-row[br].poc+1].erase(row[br].poc-1);
                        if (npriv[sol-row[br].poc+1].empty()) stree.update(1, 0, size-1, sol-row[br].poc+1, inf, 1); else stree.update(1, 0, size-1, sol-row[br].poc+1, *npriv[sol-row[br].poc+1].begin(), 1);
                        npriv[row[br].kraj-row[br].poc].insert(row[br].poc-1);
                        stree.update(1, 0, size-1, row[br].kraj-row[br].poc, *npriv[row[br].kraj-row[br].poc].begin(), 1);
                    } else
                    {
                        npriv[row[br].kraj-row[br].poc-1].insert(row[br].poc);
                        stree.update(1, 0, size-1, row[br].kraj-row[br].poc-1, *npriv[row[br].kraj-row[br].poc-1].begin(), 1);
                    }
                    row[br].kraj = sol-2;
                } else
                {
                    npriv[0].insert(col[br].poc-1); // dobijes keca na pocetku, uvek, pokazano
                    stree.update(1, 0, size-1, 0, *npriv[0].begin(), 1);
                }
                if (sol+n-1==1+(br+1)*(H+V-2))
                {
                    if (sol+n-1!=(NH*(H-1)+NV*(V-1)+1)) // prekrati sledecu, pazi na poslednju
                    {
                        row[br+1].poc = sol+n+1;
                        priv[row[br+1].kraj-sol-n+1].erase(sol+n-1);
                        if (priv[row[br+1].kraj-sol-n+1].empty()) stree.update(1, 0, size-1, row[br+1].kraj-sol-n+1, inf, 0); else stree.update(1, 0, size-1, row[br+1].kraj-sol-n+1, *priv[row[br+1].kraj-sol-n+1].begin(), 0);
                        if (row[br+1].kraj<sol+n-2+H)
                        {
                            npriv[row[br+1].kraj-sol-n+2].erase(sol+n-1);
                            if (npriv[row[br+1].kraj-sol-n+2].empty()) stree.update(1, 0, size-1, row[br+1].kraj-sol-n+2, inf, 1); else stree.update(1, 0, size-1, row[br+1].kraj-sol-n+2, *npriv[row[br+1].kraj-sol-n+2].begin(), 1);
                            npriv[row[br+1].kraj-row[br+1].poc+2].insert(row[br+1].poc-1);
                            stree.update(1, 0, size-1, row[br+1].kraj-row[br+1].poc+2, *npriv[row[br+1].kraj-row[br+1].poc+2].begin(), 1);
                        } else
                        {
                            npriv[row[br+1].kraj-row[br+1].poc+1].insert(row[br+1].poc-1);
                            stree.update(1, 0, size-1, row[br+1].kraj-row[br+1].poc+1, *npriv[row[br+1].kraj-row[br+1].poc+1].begin(), 1);
                        }
                        if (row[br+1].kraj>=row[br+1].poc)
                        {
                            priv[row[br+1].kraj-row[br+1].poc].insert(row[br+1].poc);
                            stree.update(1, 0, size-1, row[br+1].kraj-row[br+1].poc, *priv[row[br+1].kraj-row[br+1].poc].begin(), 0);
                        }
                    }
                    priv[n-1].erase(col[br].poc);
                    if (priv[n-1].empty()) stree.update(1, 0, size-1, n-1, inf, 0); else stree.update(1, 0, size-1, n-1, *priv[n-1].begin(), 0);
                    if (sol>H+br*(H+V-2))
                    {
                        npriv[n].erase(sol-1);
                        if (npriv[n].empty()) stree.update(1, 0, size-1, n, inf, 1); else stree.update(1, 0, size-1, n, *npriv[n].begin(), 1);
                    }
                    col[br].poc = sol+n+1;
                } else if (sol+n==1+(br+1)*(H+V-2))
                {
                    if (sol+n<(NH*(H-1)+NV*(V-1)+1))
                    {
                        priv[row[br+1].kraj-row[br+1].poc].erase(row[br+1].poc);
                        if (priv[row[br+1].kraj-row[br+1].poc].empty()) stree.update(1, 0, size-1, row[br+1].kraj-row[br+1].poc, inf, 0); else stree.update(1, 0, size-1, row[br+1].kraj-row[br+1].poc, *priv[row[br+1].kraj-row[br+1].poc].begin(), 0);
                        if (row[br+1].kraj==H+(br+1)*(H+V-2))
                        {
                            npriv[H-1].insert(row[br+1].poc);
                            stree.update(1, 0, size-1, H-1, *npriv[H-1].begin(), 1);
                        }
                        row[br+1].poc = sol+n+1;
                        if (row[br+1].poc<=row[br+1].kraj)
                        {
                            priv[row[br+1].kraj-row[br+1].poc].insert(row[br+1].poc);
                            stree.update(1, 0, size-1, row[br+1].kraj-row[br+1].poc, *priv[row[br+1].kraj-row[br+1].poc].begin(), 0);
                        }
                    } else
                    {
                        npriv[0].insert(sol+n);
                        stree.update(1, 0, size-1, 0, *npriv[0].begin(), 1);
                    }
                    priv[n].erase(col[br].poc);
                    if (priv[n].empty()) stree.update(1, 0, size-1, n, inf, 0); else stree.update(1, 0, size-1, n, *priv[n].begin(), 0);
                    if (sol>H+br*(H+V-2))
                    {
                        npriv[n+1].erase(sol-1);
                        if (npriv[n+1].empty()) stree.update(1, 0, size-1, n+1, inf, 1); else stree.update(1, 0, size-1, n+1, *npriv[n+1].begin(), 1);
                    }
                    col[br].poc = sol+n+1;
                } else
                {
                    priv[col[br].kraj-col[br].poc].erase(col[br].poc);
                    if (priv[col[br].kraj-col[br].poc].empty()) stree.update(1, 0, size-1, col[br].kraj-col[br].poc, inf, 0); else stree.update(1, 0, size-1, col[br].kraj-col[br].poc, *priv[col[br].kraj-col[br].poc].begin(), 0);
                    if (sol>H+br*(H+V-2))
                    {
                        if (col[br].kraj<1+(br+1)*(H+V-2))
                        {
                            npriv[col[br].kraj-col[br].poc+2].erase(sol-1);
                            if (npriv[col[br].kraj-col[br].poc+2].empty()) stree.update(1, 0, size-1, col[br].kraj-col[br].poc+2, inf, 1); else stree.update(1, 0, size-1, col[br].kraj-col[br].poc+2, *npriv[col[br].kraj-col[br].poc+2].begin(), 1);
                            if (sol+n+1 <= col[br].kraj)
                            {
                                priv[col[br].kraj-sol-n-1].insert(sol+n+1);
                                stree.update(1, 0, size-1, col[br].kraj-sol-n-1, *priv[col[br].kraj-sol-n-1].begin(), 0);
                            }
                            npriv[col[br].kraj-sol-n+1].insert(sol+n);
                            stree.update(1, 0, size-1, col[br].kraj-sol-n+1, *npriv[col[br].kraj-sol-n+1].begin(), 1);
                        } else
                        {
                            npriv[col[br].kraj-col[br].poc+1].erase(sol-1);
                            if (npriv[col[br].kraj-col[br].poc+1].empty()) stree.update(1, 0, size-1, col[br].kraj-col[br].poc+1, inf, 1); else stree.update(1, 0, size-1, col[br].kraj-col[br].poc+1, *npriv[col[br].kraj-col[br].poc+1].begin(), 1);
                            if (sol+n+1 < col[br].kraj || col[br].kraj==(NH*(H-1)+NV*(V-1)+1))
                            {
                                priv[col[br].kraj-sol-n-1].insert(sol+n+1);
                                stree.update(1, 0, size-1, col[br].kraj-sol-n-1, *priv[col[br].kraj-sol-n-1].begin(), 0);
                            }
                            npriv[col[br].kraj-sol-n].insert(sol+n);
                            stree.update(1, 0, size-1, col[br].kraj-sol-n, *npriv[col[br].kraj-sol-n].begin(), 1);
                        }
                    } else
                    {
                        if (col[br].kraj<1+(br+1)*(H+V-2))
                        {
                            npriv[col[br].kraj-col[br].poc+1].erase(sol);
                            if (npriv[col[br].kraj-col[br].poc+1].empty()) stree.update(1, 0, size-1, col[br].kraj-col[br].poc+1, inf, 1); else stree.update(1, 0, size-1, col[br].kraj-col[br].poc+1, *npriv[col[br].kraj-col[br].poc+1].begin(), 1);
                            if (sol+n+1 <= col[br].kraj)
                            {
                                priv[col[br].kraj-sol-n-1].insert(sol+n+1);
                                stree.update(1, 0, size-1, col[br].kraj-sol-n-1, *priv[col[br].kraj-sol-n-1].begin(), 0);
                            }
                            npriv[col[br].kraj-sol-n+1].insert(sol+n);
                            stree.update(1, 0, size-1, col[br].kraj-sol-n+1, *npriv[col[br].kraj-sol-n+1].begin(), 1);
                        } else
                        {
                            if (sol+n+1<col[br].kraj || col[br].kraj==(NH*(H-1)+NV*(V-1)+1))
                            {
                                priv[col[br].kraj-sol-n-1].insert(sol+n+1);
                                stree.update(1, 0, size-1, col[br].kraj-sol-n-1, *priv[col[br].kraj-sol-n-1].begin(), 0);
                            }
                            npriv[col[br].kraj-sol-n].insert(sol+n);
                            stree.update(1, 0, size-1, col[br].kraj-sol-n, *npriv[col[br].kraj-sol-n].begin(), 1);
                        }
                    }
                    col[br].poc = sol+n+1;
                }
            }

        } else  // npriv
        {
            sol = stree.get(1, 0, size-1, n-1, size-1, 1);
            if (sol==(NH*(H-1)+NV*(V-1)+1))
            {
                printf("%d\n", sol);
                npriv[0].erase(sol);
                stree.update(1, 0, size-1, 0, inf, 1);
                continue;
            }
            if (sol<inf)
            {
                printf("%d\n", sol);
                if (sol%(H+V-2)>0 && sol%(H+V-2)<H)  // red
                {
                    br = sol/(H+V-2);
                    if (n==1 && ((sol<row[br].poc-1)) || (row[br].poc>row[br].kraj+1))
                    {
                        npriv[0].erase(sol);
                        if (npriv[0].empty()) stree.update(1, 0, size-1, 0, inf, 1); else stree.update(1, 0, size-1, 0, *npriv[0].begin(), 1);
                    } else if (sol==row[br].poc)
                    {
                        if (br && col[br-1].poc<=sol)
                        {
                            priv[col[br-1].kraj-col[br-1].poc].erase(col[br-1].poc);
                            if (priv[col[br-1].kraj-col[br-1].poc].empty()) stree.update(1, 0, size-1, col[br-1].kraj-col[br-1].poc, inf, 0); else stree.update(1, 0, size-1, col[br-1].kraj-col[br-1].poc, *priv[col[br-1].kraj-col[br-1].poc].begin(), 0);
                            if (col[br-1].poc<sol-1)
                            {
                                priv[sol-col[br-1].poc-2].insert(col[br-1].poc);
                                stree.update(1, 0, size-1, sol-col[br-1].poc-2, *priv[sol-col[br-1].poc-2].begin(), 0);
                            }
                            if (col[br-1].poc>sol-V+1)
                            {
                                npriv[col[br-1].kraj-col[br-1].poc+1].erase(col[br-1].poc-1);
                                if (npriv[col[br-1].kraj-col[br-1].poc+1].empty()) stree.update(1, 0, size-1, col[br-1].kraj-col[br-1].poc+1, inf, 1); else stree.update(1, 0, size-1, col[br-1].kraj-col[br-1].poc+1, *npriv[col[br-1].kraj-col[br-1].poc+1].begin(), 1);
                                npriv[col[br-1].kraj-col[br-1].poc].insert(col[br-1].poc-1);
                                stree.update(1, 0, size-1, col[br-1].kraj-col[br-1].poc, *npriv[col[br-1].kraj-col[br-1].poc].begin(), 1);
                            } else
                            {
                                npriv[col[br-1].kraj-col[br-1].poc-1].insert(col[br-1].poc);
                                stree.update(1, 0, size-1, col[br-1].kraj-col[br-1].poc-1, *npriv[col[br-1].kraj-col[br-1].poc-1].begin(), 1);
                            }
                            col[br-1].kraj = sol-2;
                        }
                        priv[row[br].kraj-row[br].poc].erase(row[br].poc);
                        if (priv[row[br].kraj-row[br].poc].empty()) stree.update(1, 0, size-1, row[br].kraj-row[br].poc, inf, 0); else stree.update(1, 0, size-1, row[br].kraj-row[br].poc, *priv[row[br].kraj-row[br].poc].begin(), 0);
                        npriv[row[br].kraj-row[br].poc+1].erase(row[br].poc);
                        if (npriv[row[br].kraj-row[br].poc+1].empty()) stree.update(1, 0, size-1, row[br].kraj-row[br].poc+1, inf, 1); else stree.update(1, 0, size-1, row[br].kraj-row[br].poc+1, *npriv[row[br].kraj-row[br].poc+1].begin(), 1);
                    } else
                    {
                        if (sol+n-1==row[br].kraj && row[br].kraj==H+br*(H+V-2))
                        {
                            if (sol+n-1!=(NH*(H-1)+NV*(V-1)+1))
                            {
                                col[br].poc = sol+n+1;
                                priv[col[br].kraj-sol-n+1].erase(sol+n-1);
                                if (priv[col[br].kraj-sol-n+1].empty()) stree.update(1, 0, size-1, col[br].kraj-sol-n+1, inf, 0); else stree.update(1, 0, size-1, col[br].kraj-sol-n+1, *priv[col[br].kraj-sol-n+1].begin(), 0);
                                if (col[br].kraj<sol+n-2+V)
                                {
                                    npriv[col[br].kraj-sol-n+2].erase(sol+n-1);
                                    if (npriv[col[br].kraj-sol-n+2].empty()) stree.update(1, 0, size-1, col[br].kraj-sol-n+2, inf, 1); else stree.update(1, 0, size-1, col[br].kraj-sol-n+2, *npriv[col[br].kraj-sol-n+2].begin(), 1);
                                    npriv[col[br].kraj-col[br].poc+2].insert(col[br].poc-1);
                                    stree.update(1, 0, size-1, col[br].kraj-col[br].poc+2, *npriv[col[br].kraj-col[br].poc+2].begin(), 1);
                                } else
                                {
                                    npriv[col[br].kraj-col[br].poc+1].insert(col[br].poc-1);
                                    stree.update(1, 0, size-1, col[br].kraj-col[br].poc+1, *npriv[col[br].kraj-col[br].poc+1].begin(), 1);
                                }
                                if (col[br].kraj>=col[br].poc)
                                {
                                    priv[col[br].kraj-col[br].poc].insert(col[br].poc);
                                    stree.update(1, 0, size-1, col[br].kraj-col[br].poc, *priv[col[br].kraj-col[br].poc].begin(), 0);
                                }
                            }
                            priv[n-2].erase(row[br].poc);
                            if (priv[n-2].empty()) stree.update(1, 0, size-1, n-2, inf, 0); else stree.update(1, 0, size-1, n-2, *priv[n-2].begin(), 0);
                            npriv[n-1].erase(sol);
                            if (npriv[n-1].empty()) stree.update(1, 0, size-1, n-1, inf, 1); else stree.update(1, 0, size-1, n-1, *npriv[n-1].begin(), 1);
                            row[br].poc = sol+n+1;
                        } else
                        {
                            if (row[br].poc<=row[br].kraj)
                            {
                                priv[row[br].kraj-row[br].poc].erase(row[br].poc);
                                if (priv[row[br].kraj-row[br].poc].empty()) stree.update(1, 0, size-1, row[br].kraj-row[br].poc, inf, 0); else stree.update(1, 0, size-1, row[br].kraj-row[br].poc, *priv[row[br].kraj-row[br].poc].begin(), 0);
                            }
                            npriv[row[br].kraj-row[br].poc+2].erase(row[br].poc-1);
                            if (npriv[row[br].kraj-row[br].poc+2].empty()) stree.update(1, 0, size-1, row[br].kraj-row[br].poc+2, inf, 1); else stree.update(1, 0, size-1, row[br].kraj-row[br].poc+2, *npriv[row[br].kraj-row[br].poc+2].begin(), 1);
                            if (sol+n-1==row[br].kraj)
                            {
                                npriv[0].insert(sol+n);
                                stree.update(1, 0, size-1, 0, *npriv[0].begin(), 1);
                            }
                            row[br].poc = sol+n+1;
                        }
                    }

                } else //kolona
                {
                    br = (sol-1)/(H+V-2);
                    if (n==1 && ((sol<col[br].poc-1)) || (col[br].poc>col[br].kraj+1))
                    {
                        npriv[0].erase(sol);
                        if (npriv[0].empty()) stree.update(1, 0, size-1, 0, inf, 1); else stree.update(1, 0, size-1, 0, *npriv[0].begin(), 1);
                    } else if (sol==col[br].poc)
                    {
                        if (br && row[br].poc<=sol)
                        {
                            priv[row[br].kraj-row[br].poc].erase(row[br].poc);
                            if (priv[row[br].kraj-row[br].poc].empty()) stree.update(1, 0, size-1, row[br].kraj-row[br].poc, inf, 0); else stree.update(1, 0, size-1, row[br].kraj-row[br].poc, *priv[row[br].kraj-row[br].poc].begin(), 0);
                            if (row[br].poc<sol-1)
                            {
                                priv[sol-row[br].poc-2].insert(row[br].poc);
                                stree.update(1, 0, size-1, sol-row[br].poc-2, *priv[sol-row[br].poc-2].begin(), 0);
                            }
                            if (row[br].poc>sol-H+1)
                            {
                                npriv[row[br].kraj-row[br].poc+1].erase(row[br].poc-1);
                                if (npriv[row[br].kraj-row[br].poc+1].empty()) stree.update(1, 0, size-1, row[br].kraj-row[br].poc+1, inf, 1); else stree.update(1, 0, size-1, row[br].kraj-row[br].poc+1, *npriv[row[br].kraj-row[br].poc+1].begin(), 1);
                                npriv[row[br].kraj-row[br].poc].insert(row[br].poc-1);
                                stree.update(1, 0, size-1, row[br].kraj-row[br].poc, *npriv[row[br].kraj-row[br].poc].begin(), 1);
                            } else
                            {
                                npriv[row[br].kraj-row[br].poc-1].insert(row[br].poc);
                                stree.update(1, 0, size-1, row[br].kraj-row[br].poc-1, *npriv[row[br].kraj-row[br].poc-1].begin(), 1);
                            }
                            row[br].kraj = sol-2;
                        }
                        priv[col[br].kraj-col[br].poc].erase(col[br].poc);
                        if (priv[col[br].kraj-col[br].poc].empty()) stree.update(1, 0, size-1, col[br].kraj-col[br].poc, inf, 0); else stree.update(1, 0, size-1, col[br].kraj-col[br].poc, *priv[col[br].kraj-col[br].poc].begin(), 0);
                        npriv[col[br].kraj-col[br].poc+1].erase(col[br].poc);
                        if (npriv[col[br].kraj-col[br].poc+1].empty()) stree.update(1, 0, size-1, col[br].kraj-col[br].poc+1, inf, 1); else stree.update(1, 0, size-1, col[br].kraj-col[br].poc+1, *npriv[col[br].kraj-col[br].poc+1].begin(), 1);
                    } else
                    {
                        if (sol+n-1==col[br].kraj && col[br].kraj==1+(br+1)*(H+V-2))
                        {
                            if (sol+n-1!=(NH*(H-1)+NV*(V-1)+1))
                            {
                                row[br+1].poc = sol+n+1;
                                priv[row[br+1].kraj-sol-n+1].erase(sol+n-1);
                                if (priv[row[br+1].kraj-sol-n+1].empty()) stree.update(1, 0, size-1, row[br+1].kraj-sol-n+1, inf, 0); else stree.update(1, 0, size-1, row[br+1].kraj-sol-n+1, *priv[row[br+1].kraj-sol-n+1].begin(), 0);
                                if (row[br+1].kraj<sol+n-2+H)
                                {
                                    npriv[row[br+1].kraj-sol-n+2].erase(sol+n-1);
                                    if (npriv[row[br+1].kraj-sol-n+2].empty()) stree.update(1, 0, size-1, row[br+1].kraj-sol-n+2, inf, 1); else stree.update(1, 0, size-1, row[br+1].kraj-sol-n+2, *npriv[row[br+1].kraj-sol-n+2].begin(), 1);
                                    npriv[row[br+1].kraj-row[br+1].poc+2].insert(row[br+1].poc-1);
                                    stree.update(1, 0, size-1, row[br+1].kraj-row[br+1].poc+2, *npriv[row[br+1].kraj-row[br+1].poc+2].begin(), 1);
                                } else
                                {
                                    npriv[row[br+1].kraj-row[br+1].poc+1].insert(row[br+1].poc-1);
                                    stree.update(1, 0, size-1, row[br+1].kraj-row[br+1].poc+1, *npriv[row[br+1].kraj-row[br+1].poc+1].begin(), 1);
                                }
                                if (row[br+1].kraj>=row[br+1].poc)
                                {
                                    priv[row[br+1].kraj-row[br+1].poc].insert(row[br+1].poc);
                                    stree.update(1, 0, size-1, row[br+1].kraj-row[br+1].poc, *priv[row[br+1].kraj-row[br+1].poc].begin(), 0);
                                }
                            }
                            priv[n-2].erase(col[br].poc);
                            if (priv[n-2].empty()) stree.update(1, 0, size-1, n-2, inf, 0); else stree.update(1, 0, size-1, n-2, *priv[n-2].begin(), 0);
                            npriv[n-1].erase(sol);
                            if (npriv[n-1].empty()) stree.update(1, 0, size-1, n-1, inf, 1); else stree.update(1, 0, size-1, n-1, *npriv[n-1].begin(), 1);
                            col[br].poc = sol+n+1;
                        } else
                        {
                            if (col[br].poc<=col[br].kraj)
                            {
                                priv[col[br].kraj-col[br].poc].erase(col[br].poc);
                                if (priv[col[br].kraj-col[br].poc].empty()) stree.update(1, 0, size-1, col[br].kraj-col[br].poc, inf, 0); else stree.update(1, 0, size-1, col[br].kraj-col[br].poc, *priv[col[br].kraj-col[br].poc].begin(), 0);
                            }
                            npriv[col[br].kraj-col[br].poc+2].erase(col[br].poc-1);
                            if (npriv[col[br].kraj-col[br].poc+2].empty()) stree.update(1, 0, size-1, col[br].kraj-col[br].poc+2, inf, 1); else stree.update(1, 0, size-1, col[br].kraj-col[br].poc+2, *npriv[col[br].kraj-col[br].poc+2].begin(), 1);
                            if (sol+n-1==col[br].kraj)
                            {
                                npriv[0].insert(sol+n);
                                stree.update(1, 0, size-1, 0, *npriv[0].begin(), 1);
                            }
                            col[br].poc = sol+n+1;
                        }
                    }
                }
            } else { printf("no\n"); continue; }
        }
    }
    return 0;
}
