#ifdef _MSC_VER
#define DEBUG
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#define MAX  20
using namespace std;

int order[1000][2];

void func(const int &beg,const int &end,int *num)
{
    for(int i=beg;i<end;)
    {
        if(order[i][0]==3)
        {
            num[0]+=order[i][1];
            ++i;
        }
        else if(order[i][0]==2)
        {
            int temp[20];
            memset(temp,0,sizeof(temp));
            int sum=1;
            int t=i+1;
            while(sum)
            {
                if(order[t][0]==2)
                    ++sum;
                else if(order[t][0]==1)
                    --sum;
                ++t;
            }
            func(i+1,t-1,temp);
            
            if(order[i][1]==INT_MAX)
                for(int j=0;j<MAX-1;++j)
                    num[j+1]+=temp[j];
            else
                for(int j=0;j<MAX;++j)
                    num[j]+=temp[j]*order[i][1];

            i=t;
        }
    }
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

    string str,cost;
    int ncases;
    scanf("%d",&ncases);
  cin>>str;

    for(int nc=1;nc<=ncases;++nc)
    {
        int n=0;
    int sum=1;
        while(sum)
        {
            if(str=="BEGIN" )
                order[n++][0]=0;
            else if(str=="END")
      {
        order[n++][0]=1;
         --sum;
      }
            else 
            {
                cin>>cost;
                int temp;
                if(cost=="n")
                    temp=INT_MAX;
                else
                    temp=atoi(cost.c_str());
                if(str=="LOOP")
        {
                    order[n][0]=2;
          ++sum;
        }
                else
        {
                    order[n][0]=3;
        }
                order[n++][1]=temp;
            }
      cin>>str;
        }

        int ans[MAX];
        memset(ans,0,sizeof(ans));
        func(1,n-1,ans);
        printf("Program #%d\nRuntime =",nc);

    bool flag=false;
    for(int i=MAX-1;i>1;--i)
      if(ans[i]>1)
      {
        printf("%c%d*n^%d",flag?'+':' ',ans[i],i);
        flag=true;
      }
      else if(ans[i]==1)
      {
        printf("%cn^%d",flag?'+':' ',i);
        flag=true;
      }

      if(ans[1]>1)
      {
        printf("%c%d*n",flag?'+':' ',ans[1]);
        flag=true;
      }
      else if(ans[1])
      {
        printf("%cn",flag?'+':' ');
        flag=true;
      }

      if(ans[0])
      {
        printf("%c%d",flag?'+':' ',ans[0]);
        flag=true;
      }

      if(!flag)
        printf(" 0");
      printf("\n\n");

    }

  return 0;
}
