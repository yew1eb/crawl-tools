#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct haha
{
    int num1;
    int num0;
    int flag;
    int left;
    int right;
}node[100000*4];
char s[100000+100];
void build(int nd,int left,int right)
{
     node[nd].left=left;
     node[nd].right=right;
     node[nd].flag=0;
     if(node[nd].left==node[nd].right)
     {
         if(s[node[nd].left]=='1')
         {
             node[nd].num0=0;
             node[nd].num1=1;
         }
         else
         {
             node[nd].num1=0;
             node[nd].num0=1;
         }
             return ;
     }
     int mid=(left+right)/2;
     build(nd*2,left,mid);
     build(nd*2+1,mid+1,right);
     node[nd].num0=node[nd*2].num0+node[nd*2+1].num0;
     node[nd].num1=node[nd*2].num1+node[nd*2+1].num1;
}
void change(int nd)
{
       int temp;
       if(node[nd].left==node[nd].right) return ;
       temp=node[nd*2].num0;node[nd*2].num0=node[nd*2].num1;node[nd*2].num1=temp;
       temp=node[nd*2+1].num0;node[nd*2+1].num0=node[nd*2+1].num1;node[nd*2+1].num1=temp;
     //  node[nd].flag=0;node[nd*2].flag=1;node[nd*2+1].flag=1;//这样写是绝对错误的 因为这里 我错了10几遍啊 呜呜
	   node[nd].flag=!node[nd].flag;node[nd*2].flag=!node[nd*2].flag;//应该这样写 注意 以后都要这样规范的写
	   node[nd*2+1].flag=!node[nd*2+1].flag;//因为你不能保证一个不被标记2边 即子节点可能标记2边 

}
int query(int nd)
{
    if(node[nd].left==node[nd].right)  return node[nd].left;//==写成了=  一个劲的错 呜呜
    if(node[nd].flag) change(nd);
    int pos=-1;
    if(node[nd*2].num0) pos=query(nd*2);
    else
    if(node[nd*2+1].num0)  pos=query(nd*2+1);
     node[nd].num0=node[nd*2].num0+node[nd*2+1].num0;
     node[nd].num1=node[nd*2].num1+node[nd*2+1].num1;
    return pos;
 }
void update(int nd,int left,int right)
{
       int i,j,mid;
       if(node[nd].flag) change(nd);
       if(node[nd].left==left&&node[nd].right==right)
       {
           int temp;
           temp=node[nd].num0;node[nd].num0=node[nd].num1;node[nd].num1=temp;
           node[nd].flag=1;
           return ;
       }
       
       mid=(node[nd].left+node[nd].right)/2;
       if(right<=mid) update(nd*2,left,right);
       else if(left>mid) update(nd*2+1,left,right);
       else 
       {
           update(nd*2,left,mid);
           update(nd*2+1,mid+1,right);
       }
     node[nd].num0=node[nd*2].num0+node[nd*2+1].num0;
     node[nd].num1=node[nd*2].num1+node[nd*2+1].num1;
       return ;

}
int main()
{
    int n,k,i,j,flag,left,right,ans,num,len;

    while(scanf("%d %d",&n,&k)!=EOF)
    {
        flag=0;ans=0;num=0;
        if(!n&&!k) break;
        scanf("%s",s+1);//只要输入 不用再转化进一个int数组 否则会超时 所以不必要的操作一定不要要
		len=strlen(s+1);
		 build(1,1,len);
        for(i=1;i<=len;i++)
			if(s[i]=='0') {flag=1;break;}
        if(k==0)
        {
			if(node[1].num1==len) printf("0\n");
			else
             printf("-1\n");
            continue;
        }
		if(flag==0) {printf("0\n");continue;}
        int pos;//记录最左边0的位置
        flag=0;
        while(pos=query(1))
        {
              if(pos==-1) break;
              left=pos;right=pos+k-1;
              if(right>len) {printf("-1\n");flag=1;break;}
              update(1,left,right);
              ans++;
        }
        if(flag) continue;
        else printf("%d\n",ans);
    }
    return 0;
}