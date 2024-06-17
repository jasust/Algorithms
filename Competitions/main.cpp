//
//  main.cpp
//  heshcode_test
//
//  Created by Tamara Sekularac on 3/1/18.
//  Copyright © 2018 Tamara Sekularac. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;


string inputFile[]={"example","small","medium","big"};
int main(int argc, const char * argv[]) {
    int n, m, l, h;
    string a[1003];
    int used[1000][1000];
    for (int kk = 0; kk < 4; ++kk){
        string name = "" + inputFile[kk] + ".in";
        string outname = "" + inputFile[kk] + ".out";
        ifstream in(name, ifstream::in);
        ofstream out(outname, ofstream::out);
        stringstream ss;
        int br=0;
        in>>n>>m>>l>>h;
        for(int i=0; i<n; i++)
            in>>a[i];
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                used[i][j]=false;
        for(int x=h; x>0; x--)
            for(int y=h/x; y>0; y--)
                if(x*y>=2*l){
                    
                    for(int i=0; i<=n-x; i++)
                        for(int j=0; j<=m-y; j++){
                            bool ok=true;
                            int tt=0, mm=0;
                            for(int ii=0; ii<x;ii++)
                                for(int jj=0; jj<y;jj++)
                                {
                                    if(used[i+ii][j+jj])
                                        ok=false;
                                    if(a[i+ii][j+jj]=='M')
                                        mm++;
                                    if(a[i+ii][j+jj]=='T')
                                        tt++;
                                }
                            if(ok && tt>=l && mm>=l)
                            {
                                for(int ii=0; ii<x;ii++)
                                    for(int jj=0; jj<y;jj++)
                                        used[i+ii][j+jj]=true;
                                ss<<i<<" "<<j<<" "<<i+x-1<<" "<<j+y-1<<endl;
                                br++;
                            }
                                
                        }
                    
                }
        out<<br<<endl;
        out<<ss.str();
        
    }
    return 0;
}
