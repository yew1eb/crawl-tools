/*
题意：
三种操作
0 x：向容器里加入x;
1 x: 在容器内删除x，不存在x则输出“No Elment”
2 x y:在容器中找到大于x的第y个数，没有则输出“Not Find”
题解： 树状数组
操作1：直接add(x,1)
操作2：查找sum(x)和sum(x-1)，差值为0则不存在x,反之，add(x,-1)即可删除一个x
操作3：首先查找小于等于x的个数s，则找到大于x的第y个数相当于找到第s+y小数
*/
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std ;

const int maxn = 100005 ;

struct bit{
     int c[maxn] ; 
     void init(){
          memset(c , 0 ,sizeof(c));
     }
     int lowbit(int x){
         return x&(-x);
     }
     void add(int x ,int d){ //在x处加上d
          for( ; x < maxn ; x+=lowbit(x)) c[x]+=d ; 
     }
     int sum(int x){ //求小于等于x的个数
          int ans = 0 ;
          for( ; x>0 ; x-=lowbit(x))  ans +=c[x] ; 
          return ans ;
     }
     int getkth1(int k){// 求第K小数模版1
          int ans = 0 , cnt = 0 , i ;
          for(i = 20 ; i>=0 ; --i){
                ans += 1<<i ;
                if(ans>=maxn||cnt+c[ans]>=k) ans-=1<<i ;
                else cnt +=c[ans] ;      
          }
          return ans+1 ; 
     }
	 
		int getkth2(int k){//求第K小数模版2
			int l=0,r=maxn,mid,f;
			while(l<r-1)
			{ mid=(l+r)>>1;
			  f=sum(mid);
				if(f>=k) r=mid;
				else l=mid;
			}
			return r;
		}
};

int main()
{
	bit my;
	int op,m,x,y;
	while(scanf("%d",&m)!=EOF)
	{
		my.init();
		while(m--)
		{
			scanf("%d%d",&op,&x);
			if(op==0)
			{
				my.add(x,1);
			}
			else if(op==1)
			{
				if(my.sum(x)-my.sum(x-1)==0)
				puts("No Elment!");
				else 
				my.add(x,-1);
			}
			else 
			{
				scanf("%d",&y);
				if(my.sum(maxn-1)-my.sum(x)<y)
				puts("Not Find!");
				else 
				{
					printf("%d\n",my.getkth2(y+my.sum(x)));
				}
			}
		}
	}
    return 0 ;
}