#include<iostream>
#include<queue>
using namespace std;
const int N = 1005;          //有N头牛
const int INF = 0x3f3f3f3f;  //定义一个大数作为无穷大
int NUM;                     //前向星变量，记录边数
int head[N];                 //前向星表头
bool flag[N];                //标记是否在队列
int dis[N];                  //标记1到其他顶点的最短距离
int sum[N];                  //标记入队次用，用于判断负环

struct Node{                 //记录关系
    int v,w,next;            //目标点，权值，下一点索引
}node[20005];


void add(int a,int b,int c){ //前向星加边函数
    node[NUM].v = b;
    node[NUM].w = c;
    node[NUM].next = head[a];
    head[a] = NUM++;
}

int SPFA(int s,int n){
    int i;
    for(i=0;i<=n;i++){    
        sum[i] = 0;         //初始化所有点入队次数为0
        flag[i] = false;    //初始化队列标记，false为未入队
        dis[i] = INF;       //初始化1到其他顶点距离为无穷大
    }
    queue<int> q;           //定义一个队列，存放维护的点
    q.push(s);              //把源点放进队列
    dis[s]=0;               //到自身距离为0
    while(!q.empty()){      //若队列不为空
        int u = q.front();  //取队列头元素
        q.pop();            //取元素后，元素弹出
        flag[u] = false;    //标记为不在队列
        for(i=head[u];~i;i=node[i].next)
        { //遍历与U相连的所有点
            int v = node[i].v;            //终点 
            int w = node[i].w;            //起点到终点权值
            if(dis[v] > dis[u] + w)
            {      //
                dis[v] = dis[u] + w;
                if(!flag[v])
                {             //若不再队列
                    q.push(v);            //把点放进队列维护 
                    flag[v] = true;       //标记为在队列
                    if(++sum[v] > n)
                    {     //入队数++，如果超过n，存在负环
                        return -1;  
                    }
                }
            }
        }

    }
    if(dis[n] == INF) return -2;
    return dis[n];
}

int main(){
    int n,ml,md,a,b,c;
    while(scanf("%d%d%d",&n,&ml,&md)!=EOF){
        memset(head,255,sizeof(head));   //初始化表头
        NUM = 0;
        while(ml--){                     //喜欢
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);                  //b-a<=c
        }
        while(md--){                     //不喜欢
            scanf("%d%d%d",&a,&b,&c); 
            add(b,a,-c);                 //b-a>=c
        }
        printf("%d\n",SPFA(1,n));
    }
    return 0;
}