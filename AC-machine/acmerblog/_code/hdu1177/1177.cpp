竟然和上次竞赛的一个题目差不多，可以上次没做出来

Problem : 1177 ( "Accepted today?" )     Judge Status : Accepted
RunId : 5592110    Language : C++    Author : ssun
Code Render Status : Rendered By HDOJ C++ Code Render Version 0.01 Beta

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct PP{
    int count;
    string time;
};

bool cmp(PP p1, PP p2)
{
    if(p1.count>p2.count || (p1.count==p2.count && p1.time<p2.time)) return true;
    return false;
}

int main()
{
    int n,g,s,c,m;
    int temp;
    PP pp[150];
    PP my;

    int i,j;
    while(scanf("%d%d%d%d%d",&n,&g,&s,&c,&m) && (n||g||s||c||m))
    {
        int num;
        bool flag = false;
        for(i=0; i<n; i++)
        {
            scanf("%d",&pp[i].count);
            cin>>pp[i].time;
        }
        my = pp[m-1];
        sort(pp,pp+n,cmp);

        for(i=0; i<n; i++)
        {
            if(pp[i].count == my.count  && my.time == pp[i].time) break;
        }
        num = i+1;
        if(num<=g) cout<<"Accepted today? I've got a golden medal :)"<<endl;
        else if(num<=g+s) cout<<"Accepted today? I've got a silver medal :)"<<endl;
        else if(num<=g+s+c) cout<<"Accepted today? I've got a copper medal :)"<<endl;
        else cout<<"Accepted today? I've got an honor mentioned :)"<<endl;
    }
    return 0;
}