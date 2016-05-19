#include<iostream>
#include<cstdlib>
#include<stdio.h>
using namespace std;
int main()
{
    int t,n,m;
    int cc=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int mm=1000010;
        int num;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&num);
            if(num<mm)
            mm=num;
        }
        int s=0;
        printf("Case #%d: ",cc++);
        int count=0;
        while(s<=n)
        {
            s+=mm;count++;
        }
        if(count%2==0)
        cout<<"Bob"<<endl;
        else
        cout<<"Alice"<<endl;
    }
}
