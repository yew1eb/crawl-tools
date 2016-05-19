#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
struct P
{
    int num;
    char name[30];
    char ro[3];
    int year;
    bool operator<(const P t) const
    {
        return num<t.num;
    }
} re[25];
int a,b,c;

void out(int i)
{
    cout<<re[i].num<<" "<<re[i].name<<" "<<re[i].ro<<endl;//<<" "<<re[i].year<<endl;
}
bool solve()
{
    bool v[25];
    memset(v,false,sizeof(v));
    int g=-1,d[10],m[10],s[10];
    int ma=-1;
    for(int i=0; i<22; i++)
        if(!v[i]&&re[i].ro[0]=='G')
        {
            ma =1;
            g=i;
            break;
        }
    if(ma==-1) return false;
    v[g] = true;
    for(int j=0; j<a; j++)
    {
        ma=-1;
        for(int i=0; i<22; i++)
            if(!v[i]&&re[i].ro[0]=='D')
            {
                ma =1;
                d[j]=i;
                break;
            }
        if(ma==-1) return false;
        v[d[j]]=true;
    }
    for(int j=0; j<b; j++)
    {
        ma=-1;
        for(int i=0; i<22; i++)
            if(!v[i]&&re[i].ro[0]=='M')
            {
                ma =1;
                m[j]=i;
                break;
            }
        if(ma==-1) return false;
        v[m[j]]=true;
    }
    for(int j=0; j<c; j++)
    {
        ma=-1;
        for(int i=0; i<22; i++)
            if(!v[i]&&re[i].ro[0]=='S')
            {
                ma =1;
                s[j]=i;
                break;
            }
        if(ma==-1) return false;
        v[s[j]]=true;
    }
    int ans = 0;
    ma = -1;
    for(int i=0; i<22; i++)
        if(v[i]&&ma<=re[i].year)
        {
            ans = i;
            ma = re[i].year;
        }
    v[ans] = false;
    out(ans);
    if(v[g])
    out(g);
    for(int i=0; i<22; i++)
        if(v[i]&&re[i].ro[0]=='D')
            out(i);
    for(int i=0; i<22; i++)
        if(v[i]&&re[i].ro[0]=='M')
            out(i);
    for(int i=0; i<22; i++)
        if(v[i]&&re[i].ro[0]=='S')
            out(i);
    return true;
}
int main()
{
    freopen("in.txt","r",stdin);
    while(1)
    {
        int num,f,t,tim;
        char name[30],rol[5];
        char s;
        for(int i=0; i<22; i++)
        {
            scanf("%d",&num);
            if(num==0) goto tttt;
            scanf("%s",name);
            scanf("%s",rol);
            tim = 0;
            while(1)
            {
                scanf("%d-%d",&f,&t);
                tim+=(t-f+1);
                s = getchar();
                if(s=='\n') break;
            }
            re[i].num = num;
            strcpy(re[i].name,name);
            strcpy(re[i].ro,rol);
            re[i].year = tim;
        }
        sort(re,re+22);
        scanf("%d-%d-%d",&a,&b,&c);
        if(!solve())
            cout<<"IMPOSSIBLE TO ARRANGE"<<endl;
            cout<<endl;
    }
tttt:
    ;
    return 0;
}