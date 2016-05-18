#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<queue>
#include <iomanip>
#include<iostream>
#include<algorithm>
using namespace std ;
const int M=110 ;
struct node
{
	int  x,y ;
}men[M],house[M];
int lx[M],ly[M],fx[M],fy[M],w[M][M],match[M];
char mm[M][M];
int n , m ;

int dfs(int x)
{
	fx[x]=1;
   for(int i = 1 ; i <= n ; i++)
   {
   	   if(!fy[i] && lx[x]+ly[i]==w[x][i])
   	   {
   	   	    fy[i]=1;
   	   	    if(match[i]==-1 || dfs(match[i]))
   	   	    {
   	   	    	   match[i]=x;
   	   	    	   return 1;
   	   	    }
   	   }
   }	
	 return 0;
}

void KM_match()
{
     int  Min ;
	  for(int i = 1 ; i <= n ; i++)
	  {
	  	   lx[i]=w[i][1];
	  	   for(int j = 2 ; j <= n ; j++)
	  	      lx[i]=max(lx[i],w[i][j]);
	  }	
	  memset(ly,0,sizeof(ly));
	  memset(match,-1,sizeof(match));
	 for(int k = 1 ; k <= n ; k++)
	 { 
	      while(1)
		  {
		  	   memset(fx,0,sizeof(fx));
		  	   memset(fy,0,sizeof(fy));
		  	   if(dfs(k)) break ;
		  	   Min=2147483647;
		  	   for(int i = 1 ; i <= n ;i++)
		  	     if(fx[i])
		  	     	   for(int j = 1 ; j <= n ; j++)
		  	     	      if(!fy[j])
		  	     	          Min=min(Min,lx[i]+ly[j]-w[i][j]);
		  	     	
		  	    for(int i = 1 ; i<= n ;i++)  if(fx[i]) lx[i]-=Min;
				for(int i = 1 ; i<= n ; i++) if(fy[i]) ly[i]+=Min;   	
		  }	
	 }
} 

int main()
{
	 int  sum , f1,f2 ;
	 while(~scanf("%d%d",&n,&m))
	 {
	 	   if(m+n==0) break;
	 	   f1=f2=0;
	 	   for(int i = 0 ; i < n ; i++)
	 	   {
	 	   	     scanf("%s",mm[i]);
	 	   	     for(int j = 0 ; mm[i][j] ; j++)
	 	   	     {
	 	   	     	   if(mm[i][j]=='m') {  f1++ ; men[f1].x=i ; men[f1].y=j ;}
	 	   	     	   if(mm[i][j]=='H') {  f2++ ; house[f2].x=i ; house[f2].y=j;}
	 	   	     }
	 	   }
	 	   for(int i = 1 ; i <= f1 ; i++)
			 for(int j = 1 ; j <= f2 ; j++)
			      w[i][j] = -(abs(men[i].x-house[j].x)+abs(men[i].y-house[j].y)) ;  
	 	   n=f1 ; sum=0 ;
	 	   KM_match();
	 	   for(int i = 1 ; i <= n ; i++)    sum += w[match[i]][i]  ;
	 	   printf("%d\n",-sum) ;
	 }
	  return 0;
}

	
 