/*  November Rain
	Dato je N duzi, 1 <= N <= 40000, koje su zadate krajevima 0 <= xL, yL, xR, yR <= 1000000, yL != yR.	Kisa pada po
	celobrojnim x koordinatama i pada na najvisu duz (ili na zemlju ako x koordinata ne pripada nijednoj duzi). Sa duzi voda
	se sliva na druge duzi ili na zemlju. Za svaku duz	odrediti koliko vode pada na nju (ili sa neba ili sa druge duzi)
 */
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int lld;

const int maxn = 4e4 + 5;
const int size = 1e6 + 5;

struct node
{
    int xL, yL, xR, yR;
} roof[ maxn ];

struct dot
{
    int x, y, idx, type;
    dot( int _x, int _y, int _idx, int _type )
    {
        x = _x;
        y = _y;
        idx = _idx;
        type = _type;
    }
    bool operator < ( const dot & curr ) const
    {
        if ( x != curr.x ) return x < curr.x;
        if ( type != curr.type ) return type < curr.type;
        if ( type == 1 ) return y < curr.y;
        else return y > curr.y;
    }
};

vector < dot > ends;
vector < int > part;

int cases, n, water[ maxn ], sky[ maxn ], next[ maxn ], pos[ maxn ], prev[ maxn ];

int find( int x, int y )
{
    lld up = -1, down = 1;
    int ret = 0;
    for ( vector < int > :: iterator it = part.begin(); it != part.end(); it++ )
    {
        lld tempDown = lld( roof[ *it ].xR - roof[ *it ].xL );
        lld tempUp = lld( x - roof[ *it ].xL ) * lld( roof[ *it ].yR - roof[ *it ].yL ) + tempDown * roof[ *it ].yL;
        if ( tempUp < y * tempDown && tempUp * down > up * tempDown )
        {
            up = tempUp;
            down = tempDown;
            ret = *it;
        }
    }
    return ret;
}

void add( int idx )
{
    if ( roof[ idx ].yL < roof[ idx ].yR ) next[ idx ] = find( roof[ idx ].xL, roof[ idx ].yL );
    part.push_back( idx );
    pos[ idx ] = part.size() - 1;
}

void remove( int idx )
{
    if ( roof[ idx ].yR < roof[ idx ].yL ) next[ idx ] = find( roof[ idx ].xR, roof[ idx ].yR );
    part[ pos[ idx ] ] = part.back();
    pos[ part.back() ] = pos[ idx ];
    part.pop_back();
}

void solveSky()
{
    ends.clear();
    for ( int i = 1; i <= n; i++ )
    {
        ends.push_back( dot( roof[ i ].xL, roof[ i ].yL, i, 1 ) );
        ends.push_back( dot( roof[ i ].xR, roof[ i ].yR, i, 2 ) );
    }
    sort( ends.begin(), ends.end() );
    part.clear();
    for ( int i = 0; i < ends.size(); i++ )
    {
        if ( ends[ i ].type == 1 ) add( ends[ i ].idx );
        else remove( ends[ i ].idx );
        if ( ! part.empty() ) sky[ find( ends[ i ].x, size ) ] += ends[ i + 1 ].x - ends[ i ].x;
    }
}

void addWater( int idx, int val )
{
    water[ idx ] += val;
    prev[ idx ]--;
    if ( ! prev[ idx ] ) addWater( next[ idx ], water[ idx ] );
}

void solveFall()
{
    prev[ 0 ] = maxn;
    for ( int i = 1; i <= n; i++ ) prev[ i ] = 1;
    for ( int i = 1; i <= n; i++ ) prev[ next[ i ] ]++;
    for ( int i = 1; i <= n; i++ ) addWater( i, sky[ i ] );
}

int main()
{
    scanf( "%d", &cases );

    while ( cases-- )
    {
        scanf( "%d", &n );
        for ( int i = 1; i <= n; i++ )
        {
            scanf( "%d %d %d %d", &roof[ i ].xL, &roof[ i ].yL, &roof[ i ].xR, &roof[ i ].yR );
            water[ i ] = 0;
            sky[ i ] = 0;
        }

        solveSky();
        solveFall();

        for ( int i = 1; i <= n; i++ ) printf( "%d\n", water[ i ] );
    }
}
