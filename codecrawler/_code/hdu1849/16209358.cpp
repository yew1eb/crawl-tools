#include<iostream>
#include<cstdlib>
#include<stdio.h>
using namespace std;
int main()
{
    int n,num;
    while(scanf("%d",&n)&&n)
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num);
            ans^=num;
        }
        if(ans) puts("Rabbit Win!");
        else puts("Grass Win!");
    }

}
/*
2
3 5
3
3 5 6
0

Rabbit Win!
Grass Win!
*/
