/*
  Dato je n zadataka i za svaki od njih je
  poznato vreme za koje se on izvrsava (sekunde).
  Svaki zadatak se obavlja jednu sekundu i nakon toga
  se prelazi na sledeci. Kada se dodje do poslednjeg
  opet se izvrsava prvi. Odrediti za svaki zadatak
  koliko je vremena proslo od pocetka do njegovog
  potpunog izvrsavanja.
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MaxN = 5e4 + 45;

struct Fenwick
{
  int tree[ MaxN ];
  void update( int idx, int val )
  {
    for ( ; idx < MaxN; idx += idx & -idx ) tree[ idx ] += val;
  }
  int query( int idx )
  {
    int ret = 0;
    for ( ; idx; idx -= idx & -idx ) ret += tree[ idx ];
    return ret;
  }
} BIT;

int n, x;
long long time; //ago in a galaxy far, far away... ^^
long long ans[ MaxN ];
vector< pair< int, int > > niz;

int main()
{
  scanf( "%d", &n );
  for ( int i = 1; i <= n; i++ ) BIT.update( i, 1 );
  for ( int i = 0; i < n; i++ ) scanf( "%d", &x ), niz.push_back( make_pair( x, i + 1 ) );
  sort( niz.begin(), niz.end() );
  int prev = 1, idx = 0;
  for ( int i = 0; i < n; i++ )
  {
    if ( niz[ i ].first - prev >= 1 )
    {
      time += 1LL * ( niz[ i ].first - prev - 1 ) * BIT.query( n );
      time += BIT.query( niz[ i ].second ) + BIT.query( n ) - BIT.query( idx );
    }
    else time += BIT.query( niz[ i ].second ) - BIT.query( idx );
    BIT.update( niz[ i ].second, -1 );
    ans[ niz[ i ].second - 1 ] = time;
    prev = niz[ i ].first;
    idx = niz[ i ].second;
  }
  for ( int i = 0; i < n; i++ ) printf( "%lld\n", ans[ i ] );
  return 0;
}
