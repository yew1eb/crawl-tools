#include <iostream>
#include <cmath>
using namespace std;

struct Tree
{
    int l,r,mid;
    int sum;
}T[15555];

int min(int a,int b)
{
    return a>b?b:a;
}

void build(int l,int r,int k)
{
    T[k].l = l;
    T[k].r = r;
    T[k].mid = (l+r) >> 1;
    T[k].sum = 0;
    if (l == r)
    return ;
    build(l,T[k].mid,k << 1);
    build(T[k].mid+1,r,k<<1|1);
}

void insert(int aim,int l,int r,int k)
{
    if(T[k].l == aim && T[k].r == aim)
    {
        T[k].sum++;
        return;
    }
    if(aim <= T[k].mid)
    insert(aim,l,T[k].mid,k<<1);
    else
    insert(aim,T[k].mid+1,r,k<<1|1);
    T[k].sum = T[k<<1].sum + T[k<<1|1].sum;
}

int ans;
void search(int l,int r,int k)
{
    if(T[k].l == l && T[k].r == r)
    {
        ans+=T[k].sum;
        return ;
    }
    if(r <= T[k].mid)
    search(l,r,k<<1);
    else if(l > T[k].mid)
    search(l,r,k<<1|1);
    else
    {
        search(l,T[k].mid,k<<1);
        search(T[k].mid+1,r,k<<1|1);
    }
}

int main()
{
    int n,i,num[5005],sum,text;
    while(cin >> n)
    {
        build(1,n,1);
        sum = 0;
        for(i = 0;i<n;i++)
        {
            cin >> num[i];
            num[i]++;
            ans = 0;
            if(num[i]!=n)
            search(num[i]+1,n,1);
            sum += ans;
            insert(num[i],1,num[i],1);
        }
        text = sum;
        for(i = n-1;i>=0;i--)
        {
            sum = sum - (n-num[i])+(num[i]-1);
            text = min(text,sum);
        }
        cout << text << endl;
    }

    return 0;
}
