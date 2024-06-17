/*
  Dat je niz n bitova. Operacija prvog tipa
  oznacava da treba invertovati sve bitove od
  l do r. Operacija drugog tipa oznacava da
  treba odrediti koliko ima ukljucenih bitova
  od l do r.
*/

#include <cstdio>

const int MaxN = 1e5;
const int offset = 131072;

struct segment_tree
{
  struct node
  {
    int cnt, add;
  } tree[ offset * 2 ];
  void update( int idx, int l, int r, int levo, int desno )
  {
    if ( levo <= l && r <= desno )
    {
      tree[ idx ].cnt = r - l + 1 - tree[ idx ].cnt;
      tree[ idx ].add ^= 1;
      return;
    }
    int mid = ( l + r ) / 2;
    if ( levo <= mid ) update( 2 * idx, l, mid, levo, desno );
    if ( desno > mid ) update( 2 * idx + 1, mid + 1, r, levo, desno );
    tree[ idx ].cnt = tree[ idx ].add ? r - l + 1 - tree[ 2 * idx ].cnt - tree[ 2 * idx + 1 ].cnt : tree[ 2 * idx ].cnt + tree[ 2 * idx + 1 ].cnt;
  }
  int query( int idx, int l, int r, int levo, int desno, int state )
  {
    if ( levo <= l && r <= desno ) return state ? r - l + 1 - tree[ idx ].cnt : tree[ idx ].cnt;
    int mid = ( l + r ) / 2;
    int tempL = levo <= mid ? query( 2 * idx, l, mid, levo, desno, state ^ tree[ idx ].add ) : 0;
    int tempR = desno > mid ? query( 2 * idx + 1, mid + 1, r, levo, desno, state ^ tree[ idx ].add ) : 0;
    return tempL + tempR;
  }
} stale;

int main()
{
  int n, q, t, a, b;
  scanf( "%d %d", &n, &q );
  while ( q-- )
  {
    scanf( "%d %d %d", &t, &a, &b );
    if ( t ) printf( "%d\n", stale.query( 1, 0, n - 1, --a, --b, 0 ) );
    else stale.update( 1, 0, n - 1, --a, --b );
  }
  return 0;
}
