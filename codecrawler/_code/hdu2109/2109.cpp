#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
int jap[105];
int chin[105];
int main()
{
    int n,i,j,c;
    while(scanf("%d",&n)==1&&n)
    {
        for(i=0;i<n;i++)
           scanf("%d",&chin[i]);

        for(i=0;i<n;i++)
           scanf("%d",&jap[i]);
        sort(jap,jap+n);
        sort(chin,chin+n);
        j=0;c=0;
        for(i=0;i<n;i++)
        {
            if(chin[i]==jap[i])
            {
                j++;c++;
            }
            else if(chin[i]>jap[i])
                c=c+2;
            else
                j+=2;
        }
        printf("%d vs %d\n",c,j);

    }
    return 0;
}