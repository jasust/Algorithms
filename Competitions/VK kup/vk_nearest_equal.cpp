#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, i, br, br1, first, l, r, mid, secnd, tree_size;
int a[500005], b[500005], c[500005], last[500005], tree[1050000];
struct interval { int x, y; } pairs[500005], nezabusavaj[500005];

bool cmp1(interval _a, interval _b) { return _a.y<_b.y; }

int min_tree(int _l, int _r, int _idl, int _idr, int _idx)
{
    if (_l==_idl && _r==_idr) return tree[_idx];
    int _mid = (_idl+_idr)>>1;
    if (_r<=_mid) return min_tree(_l, _r, _idl, _mid, 2*_idx);
    else if (_l>_mid) return min_tree(_l, _r, _mid+1, _idr, 2*_idx+1);
    else return min(min_tree(_l, _mid, _idl, _mid, 2*_idx), min_tree(_mid+1, _r, _mid+1, _idr, 2*_idx+1));
}

int main()
{
    scanf("%d%d", &n, &m);
    for (i=1; i<=n; i++) { scanf("%d", a+i); b[i] = a[i]; }

    // spustanje brojeva
    sort(b+1, b+n+1);
    c[1] = 1;
    for (i=2; i<=n; i++) if (b[i]==b[i-1]) c[i]=c[i-1]; else c[i]=c[i-1]+1;
    for (i=1; i<=n; i++)
    {
        l = 1; r = n;
        while (l<=r)
        {
              mid = (l+r)>>1;
              if (a[i]==b[mid]) { a[i]=c[mid]; break; }
              if (a[i]>b[mid]) l = mid+1; else r = mid - 1;
        }
    }

    // biranje intervala
    br = 0;
    for (i=0; i<=500001; i++) last[i] = 0;
    for (i=1; i<=n; i++)
    {
        if (last[a[i]])
        {
            pairs[br].x = last[a[i]];
            pairs[br].y = i;
            br++;
        }
        last[a[i]] = i;
    }

    // eliminacija
    if (br)
    {
        sort(pairs, pairs+br, cmp1);
        nezabusavaj[0].x = pairs[0].x;
        nezabusavaj[0].y = pairs[0].y;
        br1 = 1;
        for (i=1; i<br; i++)
            if (pairs[i].x>nezabusavaj[br1-1].x)
            {
                nezabusavaj[br1].x = pairs[i].x;
                nezabusavaj[br1].y = pairs[i].y;
                br1++;
            }
    } else br1 = 0;

    // pravljenje stabla
    if (br1)
    {
        for (tree_size=1; tree_size<br1; tree_size<<=1);
        for (i=0; i<tree_size; i++)
            if (i<br1) tree[tree_size+i] = nezabusavaj[i].y - nezabusavaj[i].x;
                else tree[tree_size+i] = 500005;
        for (i=tree_size-1; i; i--) tree[i] = min(tree[2*i], tree[2*i+1]);
    }

    // upiti
    for (i=0; i<m; i++)
    {
    scanf("%d%d", &first, &secnd);
    if (br1)
    {
        l = 0; r = br1-1;
        int leftie = -1;
        while (l<=r)
        {
              mid = (l+r)>>1;
              if (first==nezabusavaj[mid].x) { leftie = mid; break; }
              if (first>nezabusavaj[mid].x) l = mid+1; else r = mid - 1;
        }
        if (leftie==-1) leftie = l;

        l = 0; r = br1-1;
        int rightie = -1;
        while (l<=r)
        {
              mid = (l+r)>>1;
              if (secnd==nezabusavaj[mid].y) { rightie = mid; break; }
              if (secnd>nezabusavaj[mid].y) l = mid+1; else r = mid - 1;
        }
        if (rightie==-1) rightie = l-1;

        if (leftie>rightie) printf("-1\n");
        else printf("%d\n", min_tree(leftie, rightie, 0, tree_size-1, 1));
    } else printf("-1\n");
    }

    return 0;
}
