#include<iostream>
using namespace std;
int main()
{
    int t,r,e,c;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            scanf("%d%d%d",&r,&e,&c);
            if(r>(e-c))printf("do not advertise\n");
            else if(r<(e-c))printf("advertise\n");
            else printf("does not matter\n");
        }

    }
    return 0;
}