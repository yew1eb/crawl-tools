#include <iostream>
#include <algorithm>
using namespace std;

struct stu
{
    int sum;
    string ID;
    bool operator <(const stu& t) const
    {
        return sum>t.sum||(sum==t.sum&&ID<t.ID);
    }
} a[1005];

int main()
{
    int n, m, g;
    int pro[11];
    int i, x,j, sum, total, t, k;
    while(cin>>n,n)
    {
        cin>>m>>g;
        for(i=1; i<=m; i++) cin>>pro[i];
        total = 0;
        for(j=1; j<=n; j++)
        {
            sum = 0;
            cin>>a[j].ID;
            cin>>t;
            for(k=1; k<=t; k++)
            {
                cin>>x;
                sum+=pro[x];
            }
            if(sum>=g) total++;
            a[j].sum = sum;
//            cout<<a[j].ID<<" "<<a[j].sum<<endl;
        }
        sort(a+1,a+n+1);
        cout<<total<<endl;
        for(i=1; i<=total; i++)
            cout<<a[i].ID<<" "<<a[i].sum<<endl;
    }
    return 0;
}



