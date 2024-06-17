/*              Sneguljica - Hrvatska Informaticka Olimpijada 2013
Snezana zivi sa 2<=N<=200000 patuljaka visina 1, 2,..., N (ne postoje dva patuljka iste visine).
Svakog dana, Snezana natera patuljke da stanu u vrstu po visini. Kako patuljci ne umeju sami da se poređaju,
Snežana im pomaže postavljajući upite:
1 x y (1<=x,y<=N, x ≠ y) – patuljci na pozicijama x i y treba da zamene mesta
2 a b (1<=a<=b<=N) – da li se patuljci sa visinama a,a+1,...,b nalaze na uzastopnim mestima u vrsti (u bilo kojem poretku)
Odgovoriti na svaki upit tipa 2 sa „YES“ za da, odnosno „NO“ za ne.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 2e5 + 5;
const int tree_size = 1 << 19;
int n, m, x[ maxn ], pos[ maxn ], a, b, type;
pair < int, int > tree[ tree_size ];

void init_tree( int idx, int left, int right )
{
    if ( left == right )
    {
        tree[ idx ] = make_pair( pos[ left ], pos[ left ] );
        return;
    }
    int mid = ( left + right ) / 2;
    init_tree( 2 * idx, left, mid );
    init_tree( 2 * idx + 1, mid + 1, right );
    tree[ idx ].first = max( tree[ 2 * idx ].first, tree[ 2 * idx + 1 ].first );
    tree[ idx ].second = min( tree[ 2 * idx ].second, tree[ 2 * idx + 1 ].second );
}

void update_tree( int idx, int left, int right, int k )
{
    if ( left == right )
    {
        tree[ idx ] = make_pair( pos[ left ], pos[ left ] );
        return;
    }
    int mid = ( left + right ) / 2;
    if ( k <= mid ) update_tree( 2 * idx, left, mid, k );
        else update_tree( 2 * idx + 1, mid + 1, right, k );
    tree[ idx ].first = max( tree[ 2 * idx ].first, tree[ 2 * idx + 1 ].first );
    tree[ idx ].second = min( tree[ 2 * idx ].second, tree[ 2 * idx + 1 ].second );
}

pair < int, int > get_tree( int idx, int left, int right, int L, int R )
{
    if ( left == L && right == R ) return tree[ idx ];
    int mid = ( left + right ) / 2;
    if ( R <= mid ) return get_tree( 2 * idx, left, mid, L, R );
     else if ( L > mid ) return get_tree( 2 * idx + 1, mid + 1, right, L, R );
      else
      {
        pair < int, int > ret1 = get_tree( 2 * idx, left, mid, L, mid );
        pair < int, int > ret2 = get_tree( 2 * idx + 1, mid + 1, right, mid + 1, R );
        return make_pair( max( ret1.first, ret2.first ), min( ret1.second, ret2.second ) );
      }
}

int main()
{
    scanf( "%d %d", &n, &m );
    for ( int i = 0; i < n; i++ )
    {
        scanf( "%d", &x[ i ] );
        x[ i ]--;
        pos[ x[ i ] ] = i;
    }
    init_tree( 1, 0, n - 1 );
    while ( m-- )
    {
        scanf( "%d %d %d", &type, &a, &b );
        a--; b--;
        if ( type == 1 )
        {
            swap( pos[ x[ a ] ], pos[ x[ b ] ] );
            swap( x[ a ], x[ b ] );
            update_tree( 1, 0, n - 1, x[ a ] );
            update_tree( 1, 0, n - 1, x[ b ] );
        }
        else
        {
            pair < int, int > curr = get_tree( 1, 0, n - 1, a, b );
            if ( curr.first - curr.second == b - a ) printf( "YES\n" );
             else printf( "NO\n" );
        }
    }
    return 0;
}
