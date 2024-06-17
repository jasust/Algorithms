#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

string S;
char ch[100];

int main()
{
    cin >> S; // do razmaka
    scanf("%s", ch); // do razmaka
    cin >> S;
    cout << S << " " << S.length() <<endl;
    printf("%s %d", ch, strlen(ch));
    return 0;
}
