#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,m,ans,flag,len,bit[11];
bool Mark[22],mark[22];
void dfs(int pos,int sum,int num)
{
    if(sum+num>n)//ä¸æ»¡è¶³æ¡ä»¶ 
        return ;
    if(pos==len)//å·²ç»åå® 
    {
        sum+=num;
        if(sum<=n&&sum>ans)//æ´æ°ç­æ¡ 
        {
            ans=sum;
            flag=false;
            for(int i=0;i<len;i++)
                Mark[i]=mark[i];
            return ;
        }
        if(sum==ans)//å¤ç»è§£ 
            flag=true;
        return ;
    }
    dfs(pos+1,sum,num*10+bit[pos]);//å°posä½å½å°è¿ä¸æ®µ 
    mark[pos]=true;//æ è®° 
    dfs(pos+1,sum+num,bit[pos]);//å°posä½å½å°ä¸ä¸æ®µ 
    mark[pos]=false;//åæº¯ 
}
int main()
{
    while(scanf("%d%d",&n,&m),n||m)
    {
        flag=len=ans=0;
        memset(mark,false,sizeof(mark));//è®°å½æ¯ä¸ä½åæ¯å¦è¦å ç©ºæ ¼ 
        int temp[11];
        while(m)//å°æ°å­è½¬åä¸ºå­ç¬¦ä¸²å¤ç 
        {
            temp[len++]=m%10;
            m/=10;  
        } 
        for(int i=0;i<len;i++)
            bit[len-i-1]=temp[i];
        dfs(1,0,bit[0]);
        if(!ans)//æ è§£ 
            printf("error\n");
        else if(flag)//å¤ç»è§£ 
            printf("rejected\n");
        else//å¯ä¸è§£ 
        {
            printf("%d ",ans);
            for(int i=0;i<len;i++)
            {
                if(Mark[i])//å¤æ­æ¯ä¸ä½åæ¯å¦è¦å ç©ºæ ¼ 
                    printf(" ");
                printf("%d",bit[i]);                
            }
            printf("\n");
        }
    }
    return 0;
}