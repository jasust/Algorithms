/* Resiti rebus ow + ow = vov u sistemima manjim od 11*/
#include <cstdio>
using namespace std;
int a, b, x, y, z, c;

int main()
{
    for (int i=2; i<11; i++)
     for (int o=0; o<i; o++)
      for (int w=0; w<i; w++)
       {
            a = 10*o+w;
            b = 101+o*10;
            x = 2*w % i;
            y = (2*w/i)+ (2*o);
            z = y/i;
            y %= i;
            c = z*100 + y*10 + x;
            if (c==b && o!=w) printf("U osnovi %d: %d + %d = %d\n", i, a, a, b);
        }
        return 0;
}
