/*
  Dat je ciklican niz od n brojeva. U svakom koraku,
  svaki clan niza se menja bitovnim AND sebe, elementa
  levo od njega i elementa desno od njega. Operacije
  u svakom koraku se desavaju istovremeno. Ispisati
  izgled niza nakon k ovakvih koraka.
*/

#include <cstdio>

const int MaxN = 6e4 + 100;
const int offset = 65536 + 200;

int niz[ MaxN ];

struct binarno_drvece
{
  int tree[ offset * 2 ];
  void update( int idx, int l, int r, int pos, int val )
  {
    if ( l == r )
    {
      tree[ idx ] = val;
      return;
    }
    int mid = ( l + r ) / 2;
    if ( pos <= mid ) update( 2 * idx, l, mid, pos, val );
    else update( 2 * idx + 1, mid + 1, r, pos, val );
    tree[ idx ] = tree[ 2 * idx ] & tree[ 2 * idx + 1 ];
  }
  int query( int idx, int l, int r, int levo, int desno )
  {
    if ( levo <= l && r <= desno ) return tree[ idx ];
    int mid = ( l + r ) / 2;
    if ( desno <= mid )
      return query( 2 * idx, l, mid, levo, desno );
    if ( levo > mid )
      return query( 2 * idx + 1, mid + 1, r, levo, desno );
    int tempL = query( 2 * idx, l, mid, levo, desno );
    int tempR = query( 2 * idx + 1, mid + 1, r, levo, desno );
    int ret = tempL & tempR;
    return ret;
  }
} segment_tree;

int main()
{
  int n, k, q;
  scanf( "%d", &q );
  while ( q-- )
  {
    scanf( "%d %d", &n, &k );
    if ( k > n ) k = n;
    for ( int i = 0; i < n; i++ )
    {
      int x;
      scanf( "%d", &x );
      segment_tree.update( 1, 0, 3 * n - 1, i, x );
      segment_tree.update( 1, 0, 3 * n - 1, i + n, x );
      segment_tree.update( 1, 0, 3 * n - 1, i + 2 * n, x );
    }
    for ( int i = 0; i < n; i++ )
      printf( "%d ", segment_tree.query( 1, 0, 3 * n - 1, i + n - k, i + n + k ) );
    printf( "\n" );
  }
  return 0;
}
