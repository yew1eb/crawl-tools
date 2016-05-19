#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct stu
{
    string id;
    set<long long>time;
    set<long long>course;
}st[25];
struct cour
{
    long long id;
    long long cap;
    int num;
    set<long long>time;
    long long no;
}co[25];
struct req
{
    string student;
    long long id;
    long long no;
    long long cno;
}re[410];
int n,m,r;
long long x;
bool cmp(req a,req b)
{
    if(a.cno==b.cno)
        return a.no<b.no;
    return a.cno<b.cno;
}
int main()
{
    int cas=0;
    while(cin>>n>>m>>r)
    {
        for(int i=0;i<n;i++)
        {
            cin>>st[i].id;
            st[i].course.clear();
            st[i].time.clear();
        }
        for(int i=0;i<m;i++)
        {
            co[i].no=i;
            co[i].time.clear();
            cin>>co[i].id>>co[i].cap>>co[i].num;
            for(int j=0;j<co[i].num;j++)
            {
                cin>>x;
                co[i].time.insert(x);
            }
        }
        int ans=0;
        for(int i=0;i<r;i++)
        {
            string s;
            long long c;
            cin>>s>>c;
            re[i].student=s;
            re[i].id=c;
            int y=-1;
            for(int i=0;i<m;i++)
            {
                if(co[i].id==c)
                {
                    y=i;
                    break;
                }
            }
            re[i].no=i;
            re[i].cno=co[y].no;
        }
        sort(re,re+r,cmp);
        for(int cas=0;cas<r;cas++)
        {
            string s=re[cas].student;
            long long c=re[cas].id;
            int x=-1,y=-1;
            for(int i=0;i<n;i++)
            {
                if(st[i].id==s)
                {
                    x=i;
                    break;
                }
            }
            for(int i=0;i<m;i++)
            {
                if(co[i].id==c)
                {
                    y=i;
                    break;
                }
            }
            if(x==-1 || y==-1 || co[y].cap<=0)
                continue;
            bool ok=true;
            if(st[x].course.count(c)) //选过了
                continue;
            for(set<long long>::iterator ii=st[x].time.begin();ii!=st[x].time.end();ii++)
            {
                if(ok==false)
                    break;
                for(set<long long>::iterator it=co[y].time.begin();it!=co[y].time.end();it++)
                {
                    if(*ii == *it)
                    {
                        ok=false;
                        break;
                    }
                }
            }
            if(ok==false)
                continue;

            st[x].course.insert(c);
            for(set<long long>::iterator it=co[y].time.begin();it!=co[y].time.end();it++)
                st[x].time.insert(*it);
            co[y].cap--;
            ans++;
        }
        /*for(set<long long>::iterator ii=st[1].time.begin();ii!=st[1].time.end();ii++)
            cout<<*ii<<" ";
            cout<<endl;*/
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}