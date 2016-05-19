#include<iostream>
 #include<stdio.h>
 #include<math.h>
 #include<algorithm>
 #include<string.h>
 #include<string>
 #include<ctime>
 #include<queue>
 #include<list>
 #include<map>
 #include<set>
 #define INF 999999999
 #define MAXN 100000
 using namespace std;
 int b[10],mark[10],a[10],arr[MAXN+1],pos;
 set<int> ss;
 
 //针对6种运算情况进行计算
 int fenjie(int a,int b,int p)
 {
     if(p==0)
         return a+b;
     else if(p==1)
         return a-b;
     else if(p==5)
         return a*b;
     else if(p==3)
     {
         if(!b||a%b!=0)
             return INF;    //当遇到除法则先判断除数是否为0，这是必要的，不然会RE
         return a/b;
     }
     else if(p==4)
     {
         if(!a||b%a!=0)
             return INF;    //同上
         return b/a;
     }
     else if(p==2)
         return b-a;
 }
 
 void baoli()
 {
     int i,j,k,temp2,sum1,sum2,sum3;
     for(i=0;i<6;i++)
     {
         if((sum1=fenjie(a[b[0]],a[b[1]],i))==INF)   //1.非法时候进行处理
             continue;
         for(j=0;j<6;j++)
         {
             if((sum2=fenjie(sum1,a[b[2]],j))==INF)  //2
                 continue;
             for(k=0;k<6;k++)
             {
                 if((sum3=fenjie(sum2,a[b[3]],k))!=INF)  //3
                     ss.insert(sum3);
                 //1 2 3 是对前6种可能得暴力枚举
                 
                 //最后一种([email protected]/* <![CDATA[ */!function(t,e,r,n,c,a,p){try{t=document.currentScript||function(){for(t=document.getElementsByTagName('script'),e=t.length;e--;)if(t[e].getAttribute('data-cfhash'))return t[e]}();if(t&&(c=t.previousSibling)){p=t.parentNode;if(a=c.getAttribute('data-cfemail')){for(e='',r='0x'+a.substr(0,2)|0,n=2;a.length-n;n+=2)e+='%'+('0'+('0x'+a.substr(n,2)^r).toString(16)).slice(-2);p.replaceChild(document.createTextNode(decodeURIComponent(e)),c)}p.removeChild(t)}}catch(u){}}()/* ]]> */)@([email protected]/* <![CDATA[ */!function(t,e,r,n,c,a,p){try{t=document.currentScript||function(){for(t=document.getElementsByTagName('script'),e=t.length;e--;)if(t[e].getAttribute('data-cfhash'))return t[e]}();if(t&&(c=t.previousSibling)){p=t.parentNode;if(a=c.getAttribute('data-cfemail')){for(e='',r='0x'+a.substr(0,2)|0,n=2;a.length-n;n+=2)e+='%'+('0'+('0x'+a.substr(n,2)^r).toString(16)).slice(-2);p.replaceChild(document.createTextNode(decodeURIComponent(e)),c)}p.removeChild(t)}}catch(u){}}()/* ]]> */)的处理
                 if((temp2=fenjie(a[b[2]],a[b[3]],k))==INF)
                     continue;
                 if((sum3=fenjie(sum1,temp2,j))==INF)
                     continue;
                 ss.insert(sum3);
             }
         }
     }
 }
 
 //dfs对数组进行全排列
 void dfs(int s)   
 {
     int i;
     if(s>=4)
     {
         baoli();
     }
     else
     {
         for(i=0;i<4;i++)
         {
             if(!mark[i])
             {
                 mark[i]=1;
                 b[s]=i;
                 dfs(s+1);
                 mark[i]=0;
             }
         }
     }
 }
 int main()
 {
     int sb=1;
     while(~scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]))
     {
         if(a[0]+a[1]+a[2]+a[3]==0)
             break;
         int i;
         memset(mark,0,sizeof(mark));
         pos=0;
         ss.clear();
         dfs(0);
         while(!ss.empty())
         {
             arr[pos++]= * ss.begin();
             ss.erase(ss.begin());
         }
         int maks=0,cnt=0,ed=0;
         for(i=1;i<pos;i++)
         {
             if(arr[i]==arr[i-1]+1)
                 cnt++;
             else
                 cnt=0;
             if(maks<=cnt)
             {
                 maks=cnt;
                 ed=arr[i];
             }
         }
         printf("Case %d: %d to %d\n",sb++,ed-maks,ed);
     }
     return 0;
 }