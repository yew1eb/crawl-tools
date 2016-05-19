#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
#include<stack>
#include<cstring>
#include<vector>
#include<list>
#include<set>
#include<string>
#include<map>
using namespace std;
struct p
{
    string name;
    int year;
};
bool cmp(p a1,p a2)
{
    return a1.year>a2.year;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        p a[105];
        int n;
        scanf("%d",&n);
        getchar();
        for(int i=0; i<n; i++)
        {
            getline(cin,a[i].name);
            string &b=a[i].name;
            a[i].year=0;
            for(string ::iterator j=b.end()-4;j!=b.end();)
            {
                a[i].year=a[i].year*10+*j-'0';
                b.erase(j);
            }
            b.erase(b.end()-1);
        }
        sort(a,a+n,cmp);
        for(int i=0; i<n; i++)
            cout<<a[i].name<<endl;
    }
    return  0;
}
