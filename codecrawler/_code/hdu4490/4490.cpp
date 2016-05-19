#include<cstdio>
#include<cstring>
using namespace std;
bool vis[12][12][12];
int tras[4][4];
struct node
{
    int a[4];
    int dis;
}st,end,q[1000];
char path[1000];
int fa[1000];
char h[]="ZABCabc";
int num;
void print(int k)
{
    if(!k) return;
    print(fa[k]);
    putchar(path[k]);
}
void bfs()
{
    node f,r;
    int rear=0,front=0;
    st.dis=0;
    q[rear++]=st;
    vis[st.a[1]][st.a[2]][st.a[3]]=1;
    while(front<rear)
    {
        f=q[front];
        f.dis++;
        for(int i=1;i<=3;i++)
        {
            r=f;
            if(r.a[i])
            {
                r.a[i]--;
                for(int j=1;j<=3;j++)
                {
                    r.a[j]+=tras[i][j];
                }
                if(r.a[1]>10||r.a[2]>10||r.a[3]>10) continue;
                if(!vis[r.a[1]][r.a[2]][r.a[3]])
                {
                    fa[rear]=front;
                    path[rear]=h[i];
                    if(r.a[1]==end.a[1]&&r.a[2]==end.a[2]&&r.a[3]==end.a[3]) {printf("%d %d ",num,r.dis);print(rear);return;}
                    vis[r.a[1]][r.a[2]][r.a[3]]=1;
                    q[rear++]=r;
                }
            }
        }
        for(int i=4;i<=6;i++)
        {
            r=f;
            int ok=1;
            for(int j=1;j<=3;j++)
            {
                if(r.a[j]<tras[i-3][j]) ok=0;
            }
            if(ok)
            {
                for(int j=1;j<=3;j++)
                {
                    r.a[j]-=tras[i-3][j];
                }
                r.a[i-3]++;
                if(r.a[1]>10||r.a[2]>10||r.a[3]>10) continue;
                if(!vis[r.a[1]][r.a[2]][r.a[3]])
                {
                    path[rear]=h[i];
                    fa[rear]=front;
                    if(r.a[1]==end.a[1]&&r.a[2]==end.a[2]&&r.a[3]==end.a[3]) {printf("%d %d ",num,r.dis);print(rear);return;}
                    vis[r.a[1]][r.a[2]][r.a[3]]=1;
                    q[rear++]=r;
                }
            }
        }
        front++;
    }
    printf("%d NO SOLUTION",num);
}
int main()
{
    int p,casq,n;
    scanf("%d",&p);
    while(p--)
    {
        scanf("%d %d",&casq,&n);
        printf("%d %d\n",casq,n);
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
                scanf("%d",&tras[i][j]);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d %d %d %d %d %d",&num,&st.a[1],&st.a[2],&st.a[3],&end.a[1],&end.a[2],&end.a[3]);
            if(st.a[1]==end.a[1]&&st.a[2]==end.a[2]&&st.a[3]==end.a[3])
            {
                printf("%d 0\n",num);
                continue;
            }
            memset(vis,0,sizeof(vis));
            bfs();
            puts("");
        }
    }
    return 0;
}
