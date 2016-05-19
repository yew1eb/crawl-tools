#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int main()
{
    char str[30];
    int n;
    int r,y;
    int i;
    
    while(cin>>n)
    {
        if(n==0)
        break;
        r=y=0;
        memset(str,0,sizeof(str));
        for(i=0;i<n;i++)
        {
            cin>>str[i];
            if(str[i]=='R')
            r++;
            if(str[i]=='Y')
            y++;
        }
        
        if(str[n-1]=='B')
        {
            if(r==7)
            printf("Red\n");
            else
            printf("Yellow\n");
        }
        else
        {
            if(y==7)
            printf("Yellow\n");
            else
            printf("Red\n");
        }
    }
    return 0;
} 