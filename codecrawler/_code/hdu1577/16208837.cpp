#include<iostream>
#include<cmath>
#include<cstdio>
#include<fstream>
using namespace std;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    //freopen("d:\\test.txt","r",stdin);
    int l,x1,x2,y1,y2;
    while(scanf("%d",&l) && l)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(abs(x2)<=l && abs(y2)<=l)
        {
            int x=abs(x1-x2);
            int y=abs(y1-y2);
            if(gcd(x,y)==1)
                printf("Yes\n");
            else
                printf("No\n");
        }
        else
            printf("Out Of Range\n");
    }
    return 0;
}
