/*
  Dat je spil sastavljen od n karata sa brojevima
  od 1 do n. Na pocetku se jedna karta sa vrha stavlja
  na dno, pa se izvlaci karta koja je trenutno na vrhu
  i na njoj je broj 1. Nakon toga se dve karte sa vrha
  stavljaju na dno i izvlaci se jos jedna karta sa vrha
  i na njoj je broj 2. Procedura se nastavlja sve do
  broja n. Za dato n ispisati kako treba da stoje
  karte na pocetku.
*/

#include <cstdio>

const int MaxN = 20002;
const int offset = 0x8000;

int tsts, n, prev, niz[ MaxN ];

struct segment_tree
{
  int tree[ 2 * offset ];
  void reset( int idx, int l, int r )
  {
    if ( l == r )
    {
      tree[ idx ] = 1;
      return;
    }
    int mid = ( l + r ) / 2;
    reset( 2 * idx, l, mid );
    reset( 2 * idx + 1, mid + 1, r );
    tree[ idx ] = tree[ 2 * idx ] + tree[ 2 * idx + 1 ];
  }
  void update( int idx, int l, int r, int pos )
  {
    if ( l == r )
    {
      tree[ idx ] = 0;
      return;
    }
    int mid = ( l + r ) / 2;
    if ( pos <= mid ) update( 2 * idx, l, mid, pos );
    else update( 2 * idx + 1, mid + 1, r, pos );
    tree[ idx ] = tree[ 2 * idx ] + tree[ 2 * idx + 1 ];
  }
  int find( int idx, int l, int r, int tar )
  {
    if ( l == r ) return l;
    int mid = ( l + r ) / 2;
    if ( tar <= tree[ 2 * idx ] ) return find( 2 * idx, l, mid, tar );
    else return find( 2 * idx + 1, mid + 1, r, tar - tree[ 2 * idx ] );
  }
} spiel;

int main()
{
  scanf( "%d", &tsts );
  while ( tsts-- )
  {
    scanf( "%d", &n );
    prev = 0;
    spiel.reset( 1, 0, n - 1 );
    for ( int i = 1; i <= n; i++ )
    {
      int idx = spiel.find( 1, 0, n - 1, ( prev = ( prev + i ) % spiel.tree[ 1 ] ) + 1 );
      spiel.update( 1, 0, n - 1, idx );
      niz[ idx ] = i;
    }
    for ( int i = 0; i < n; i++ ) printf( "%d ", niz[ i ] );
    printf( "\n" );
  }
  return 0;
}
