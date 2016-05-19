#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;
int main()
{
    int i,j,k;
    int a[100];
    while(cin>>a[0]&&a[0]!=-1)
    {
        for(i=1;;i++)
        {
          cin>>a[i];
          if(a[i]==0) 
          break;
        }
        int count=0;
        for(j=0;j<i;j++)
        {
            for(int k=0;k<i;k++)
            {
                if(a[k]==2*a[j])
                count++;
            }
        }
        cout<<count<<endl;
           memset(a,0,sizeof(a));
    }
    return 0;
}