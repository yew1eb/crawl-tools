#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
#define MAX 10005
int n,sum,ans;
int into[MAX],head[MAX],money[MAX];
struct Reward
{
    int to;
    int next;
} edge[2*MAX];
void topu()
{
    int i,j,l,v;
    queue<int>Q;
    for(i=1; i<=n; i++)
        if(into[i]==0)
            Q.push(i);//把入度为0的点压如队列
    while(!Q.empty())
    {
        v=Q.front();//调用首位元素
        sum+=money[v];
        Q.pop();//出队
        ans++; //用一个变量记录调用元素的总量，最后与n作比较
        for(l=head[v]; l!=-1; l=edge[l].next)//与队首元素v有关的都枚举一遍
        {
            if(--into[edge[l].to]==0)//如果入度-1为0，即为v的下一个元素
            {
                Q.push(edge[l].to);//将其压入队列
                money[edge[l].to]=money[v]+1;//保证后一个要比前一个多1
            }
        }

    }
}
int main()
{
    int m,a,b,tot;
    while(scanf("%d%d",&n,&m)!=EOF)
    {

        memset(head,-1,sizeof(head));
        memset(into,0,sizeof(into));
        for(int i=1; i<=n; i++)
            money[i]=888;//所有人一开始都为888
        tot=0;
        sum=0;
        ans=0;
        while(m--)
        {
            scanf("%d%d",&a,&b);//注意要逆过来，因为后一个b是基础的888，应当作为出度
            edge[tot].to=a;
            edge[tot].next=head[b];
            head[b]=tot++;
            into[a]++;//记录入度
        }
        topu();
        if(ans!=n)//有可能在中间出现矛盾，必须保证每个地方都不矛盾
            sum=-1;
        cout<<sum<<endl;

    }

}