#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int n,i,s1,s2;
    char a[16];
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        s1=s2=0;
        getchar();
        for(i=0;i<n;i++)
        {
            scanf("%c",&a[i]);
            if(a[i]=='R')s1++;
            else if(a[i]=='Y')s2++;
            else if(a[i]=='B')
            {
                if(s1==7)printf("Red\n");
                else printf("Yellow\n");
            }
            else
            {
                if(s2==7)printf("Yellow\n");
                else printf("Red\n");
            }
        }

    }
    return 0;
}