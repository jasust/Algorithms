#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
#include <queue>
#include <iterator>
using namespace std;

struct whilePetlja{
    string cond;
    vector<string> inst;
    whilePetlja(string s):cond(s){}
    bool active=false;
    int nextLine=0;
};
struct variables
{
    string name;
    int vr=0;
    int nextVr=0;
    variables(string n):name(n){}
};

vector <whilePetlja> whileP;
vector<int> activeList;
vector<variables> variable;

string findVariables(string s)
{
    smatch m;
    string sRez=s;
    while (regex_search (s,m,regex("\\$([^\\$]+)\\$")))
    {
        string pom=regex_replace(m[0].str(), regex(" "), "_");
        pom=regex_replace (pom,regex("_+"),"_");
        int poz=-1;
        for(int i=0; i<variable.size();i++)
            if(!variable[i].name.compare(pom))
                poz=i;
        if(poz==-1)
        {
            variable.push_back(variables(pom));
            poz=variable.size()-1;
        }
        sRez=regex_replace (sRez,regex(m[1].str()),to_string(poz));
        s = m.suffix().str();
    }
    return regex_replace(sRez, regex("\\ "),"");
}
int retVal(string s)
{
    if(s[0]=='$')
        return variable[stoi(s.substr(1,s.size()-2))].vr;
    return stoi(s);
}
int check(string s)
{
    smatch m;
    int op1=0,op2=0;
    string oper;
    if(regex_match ( s.cbegin(), s.cend(), m, regex("\\((.+)\\)(\\+|\\-|<|and|or|xor)\\((.+)\\)")))
    {
        op1=check(m[1]);
        op2=check(m[3]);
        oper=m[2];
    }
    else
        if(regex_match ( s.cbegin(), s.cend(), m, regex("\\((.+)\\)(\\+|\\-|<|and|or|xor)(\\$?[0-9]+\\$?)")))
        {
            op1=check(m[1]);
            op2=retVal(m[3]);
            oper=m[2];
        }
        else
            if(regex_match ( s.cbegin(), s.cend(), m, regex("(\\$?[0-9]+\\$?)(\\+|\\-|<|and|or|xor)\\((.+)\\)")))
            {
                op1=retVal(m[1]);
                op2=check(m[3]);
                oper=m[2];
            }
            else
                if(regex_match ( s.cbegin(), s.cend(), m, regex("(\\$?[0-9]+\\$?)(\\+|\\-|<|and|or|xor)(\\$?[0-9]+\\$?)")))
                {
                    op1=retVal(m[1]);
                    op2=retVal(m[3]);
                    oper=m[2];
                }
                else
                    return retVal(s);
    if(oper=="+")
        return op1+op2;
    else
        if(oper=="-")
            return op1-op2;
        else
            if(oper=="<")
                return (op1<op2)?1:0;
            else
                if(oper=="and")
                    return op1&op2;
                else
                    if(oper=="or")
                        return op1|op2;
                    else
                        if(oper=="xor")
                            return op1^op2;

   // cout<<m[0]<<endl<<m[1]<<endl<<m[2]<<endl<<m[3]<<endl;

    return 0;
}

void checkActiveList ()
{
    for(int i=0; i<whileP.size(); i++)
        if(!whileP[i].active)
        {
            bool b=check(whileP[i].cond);
            if(b)
            {
                whileP[i].active=true;
                activeList.push_back(i);
            }
        }
}

void printL(string s)
{
    smatch m;
    s=s.substr(5,s.size()-5);
    while (regex_search (s,m,regex("([^,]+),")))
    {
        string izr=m[1];
        if(izr[0]=='(')
            cout<<check(izr.substr(1,izr.size()-2))<<",";
        else
            cout<<check(izr)<<",";
        s = m.suffix().str();
    }
    if(s[0]=='(')
        cout<<check(s.substr(1,s.size()-2))<<endl;
    else
        cout<<check(s)<<endl;
}

void setL(string s)
{
    smatch m;
    smatch m1;
    s=s.substr(3,s.size()-3);
    while (regex_search (s,m,regex("([^,]+),")))
    {
        string izr=m[1];
        regex_match ( izr.cbegin(), izr.cend(), m1,regex("(.+)=(.+)"));
        string izr1=m1[2];
        string v1=m1[1].str().substr(1,m1[1].str().size()-2);
        int vr;
        if(izr1[0]=='(')
            vr=check(izr1.substr(1,izr1.size()-2));
        else
            vr=check(izr1);
        variable[stoi(v1)].nextVr=vr;
        s = m.suffix().str();
    }
    regex_match ( s.cbegin(), s.cend(), m1,regex("(.+)=(.+)"));
    int vr;
    string izr1=m1[2];
    if(izr1[0]=='(')
        vr=check(izr1.substr(1,izr1.size()-2));
    else
        vr=check(izr1);
    string v1=m1[1].str().substr(1,m1[1].str().size()-2);
    variable[stoi(v1)].nextVr=vr;
    for(int i=0; i<variable.size(); i++)
    {
        variable[i].vr=variable[i].nextVr;
        //cout<<variable[i].name<<" "<<variable[i].vr<<endl;
    }
}
int main(int argc, const char * argv[]) {

    string s;
    smatch sm;
    while(getline(cin,s))
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if(regex_match ( s.cbegin(), s.cend(), sm, regex("when \\((.*)\\)")))
            whileP.push_back(whilePetlja(findVariables(sm[1])));
        else
            if(!regex_match (s.cbegin(), s.cend(), sm, regex("end when")))
                whileP.back().inst.push_back(findVariables(s));
    }
    /*
     for(whilePetlja a: whileP)
     {
     cout<<"uslov: "<<a.cond<<endl;
     for(string ss:a.inst)
     cout<<ss<<endl;
     }
     */
    checkActiveList();

    int pos=0;
    while (!activeList.empty())
    {
        int rbW=activeList[pos];
        int rbI=whileP[rbW].nextLine;
        string s=whileP[rbW].inst[rbI];
        if(s[0]=='p')
            printL(s);
        else
            setL(s);
        if(rbI==whileP[rbW].inst.size()-1)
        {
            activeList.erase(activeList.begin()+ pos);
            whileP[rbW].active=false;
            whileP[rbW].nextLine=0;
        }
        else
        {
            pos++;
            whileP[rbW].nextLine++;
        }
        if(pos==activeList.size())
            pos=0;
        checkActiveList();
    }

    return 0;
}
