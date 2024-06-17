/*program police*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MaxM = 1e5 + 5;
const int MaxN = 1e2 + 5;

int n , m ;
int dp1[MaxN][MaxN], dp2[MaxN], Sol[MaxN][MaxM], price[MaxN];

int main()
{
    cin >> n >> m ;

    for (int i=0 ; i<n ; i++)
    {
        int k;
        cin >> k;

        memset(price , 0 , sizeof ( price ) );
        for (int j=0 ; j<k ; j++) cin >> price[j] ;

        memset( dp1 , 0 , sizeof ( dp1 ) );
        for (int cnt = 0 ; cnt < k ; cnt ++)
        for (int left = 0 ; left <= k && left <= cnt ; left ++ )
        {
            int right = cnt - left ;
            dp1[left + 1][right] = max ( dp1[left + 1][right] , dp1[left][right] + price[left] );
            dp1[left][right + 1] = max ( dp1[left][right + 1] , dp1[left][right] + price[k - 1 - right] );
        }

        memset( dp2 , 0 , sizeof ( dp2 ) );
        for (int cnt = 0; cnt <= k ; cnt ++ )
        for (int left = 0; left <= k && left <= cnt; left ++ )
        {
            int right = cnt - left ;
            dp2[cnt] = max ( dp2[cnt] , dp1[left][right] );
        }

        for (int uzeo = 0 ; uzeo <= m ; uzeo ++ )
        for (int novi = 0 ; (novi + uzeo <= m) && ( novi <= k ); novi ++ )
        {
            Sol[i + 1][uzeo + novi] = max ( Sol[i + 1][uzeo + novi] , Sol[i][uzeo] + dp2[novi] );
        }
    }
    cout << Sol[n][m] ;
    return 0;
}
