#include <bits/stdc++.h>
#define MAXN 305
#define ff(i, a, b) for(int i=a; i<=b; i++)
#define fr(i, a, b) for(int i=a; i>=b; i--)
#define par pair<int, int>
#define mid (l+r)/2

using namespace std;

int n, m;
int a[MAXN][MAXN];
vector<int> cols[MAXN];
vector<int> rows[MAXN];
int best;
int now, curr, it;
int firstmy;

// we can easily prove that we need only integers
// so we fix our potential throne O(n^2)
// and we traverse (double pointer) his row and his column
// each element of his row/column is a valid candidate for the so-called FIX
// FIX = value of the throne
// all in-between/higher/lower values are equivalent to those
// since we have sorted the row/col elements we can do that in two passes O(n)
// and calculate number of changes that should be done
// NOTE : we calc our potential throne once if he's different than FIX (which is OK)
// and zero times if he's equal to FIX (which is OK)
// overall complexity is O(n^3) which pwns for n<=300
// literally pwns

int main()
{
    //freopen("presto2.in","r",stdin);
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%d", &a[i][j]);
            rows[i].push_back(a[i][j]);
            cols[j].push_back(a[i][j]);
        }
    }
    best = n + m; //it can always be smaller than this

    for(int i=1; i<=n; i++)
        sort(rows[i].begin(), rows[i].end()); //n rows sort
    for(int j=1; j<=m; j++)
        sort(cols[j].begin(), cols[j].end()); //j cols sort

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            //throne @ a[i][j]
            //all from rows[i] GreaterOrEqual
            //all from cols[j] LessOrEqual
            //chase a fix

            //fix from a row
            it = -1; //it is for cols, last LOE, last untouched
            for(int fx=0; fx<=m-1; fx++) //each row has m values
            {
                if(fx == 0) firstmy = 0;
                else if(rows[i][fx] > rows[i][fx-1]) firstmy = fx;

                curr = rows[i][fx]; //curr is our FIX
                                        //FIX grows so it grows
                if(it==-1 && cols[j][0] > curr){} //last untouched is still -1
                else
                {
                    if(it==-1) it = 0; //at least one is touched
                    while(it<n && cols[j][it] <= curr) //check if it is untouched
                        it++;   //if it is get next
                    it--; //go back one step to last untouched
                }
                now = firstmy + n - it - 1; //calc swaps, firstmy for rows and (n-it-1) for cols
                //if(a[i][j] != curr) now++; //we have to adjust for the throne ?!
                best = min(best, now); //update best
            }

            //fix from a col
            it = -1; //it is for rows, last LESS, last touched
            for(int fx=0; fx<=n-1; fx++) // each col has n values
            {
                if(fx<n-1 && rows[i][fx+1]==rows[i][fx]) continue;
                //last of each kind

                curr = cols[j][fx]; //curr is our FIX
                if(it==-1 && rows[i][0] >= curr){} //last touched is still -1
                else
                {
                    if(it==-1) it = 0; //we should touch at least one
                    while(it<m && rows[i][it] < curr) //check if it should be touched
                        it++;
                    it--; //go back one step to last touched
                }
                int now = it + 1 + n - fx - 1; //calc now, it+1 for rows and n-firstmy-1 for cols
                //if(a[i][j] != curr) now++;
                best = min(best, now);
            }
            //same values are OK
        }
    }
    printf("%d\n", best); //always an int
    return 0;
}
