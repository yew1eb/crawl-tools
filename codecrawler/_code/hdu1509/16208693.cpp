#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=6e4+10;
struct node{
    char name[30];
    int par;
    int pri;
    int num;
    bool operator <(const node a)const{
        if(pri==a.pri)
            return num>a.num;
        return pri>a.pri;
    }
}e[maxn],g;
char a[30];
priority_queue<node>q;
int main()
{
    int tt=0;
    while(cin>>a)
    {
        if(strcmp("GET",a)==0)
        {
            if(q.empty())cout<<"EMPTY QUEUE!"<<endl;
            else
            {
                g=q.top();
                q.pop();
                cout<<g.name<<" "<<g.par<<endl;
            }
        }
        else
        {
            cin>>g.name>>g.par>>g.pri;
            g.num=++tt;
            q.push(g);
        }
    }
    return 0;
}
