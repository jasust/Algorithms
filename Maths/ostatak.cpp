/* Calculate the following expression for a given number N: (1^N + 2^N + 3^N + 4^N) mod 5.
   Number N can be rather large so it is given as a string.
*/
#include<iostream>
#include<string>
using namespace std;

string n;

int calc(string n)
{
    int a=10*(n[n.size()-2]-'0')+n[n.size()-1]-'0';
    if (a%4) return 4;
        else return 0;
}

int main()
{
    cin>>n;
    cout<<calc(n);
}
