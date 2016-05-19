#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    char s[20];
    int n,y,r;
    while(scanf("%d",&n) && n)
    {
        y = r = 0;
        cin>>s;
        for(int i = 0 ; s[i] != 0 ; i++ )
        {
            if(s[i] == 'R')
            {
                r++;
            }
            else if(s[i] == 'Y')
            {
                y++;
            }
        }
        if(s[strlen(s)-1] == 'L')
        {
            if(y < 7)
            {
                printf("Red\n");
            }
            else
            {
                printf("Yellow\n");
            }
        }
        else
        {
            if( r < 7)
            {
                printf("Yellow\n");
            }
            else
            {
                printf("Red\n");
            }
        }
    }
    return 0;
}