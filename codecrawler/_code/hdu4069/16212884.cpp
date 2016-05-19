#include<cstdio>
#include<cstring>
#define N 4099
#define M 1029

const int m=3,n=9;
int tt,H=4*n*n,cnt,size[M],ans[15][15];
struct Node
{
    int r,c;
    Node *U,*D,*L,*R;
}node[N*M],row[N],col[M],head;
void init(int r,int c)
{
    cnt=0;
    head.r=r;
    head.c=c;
    head.L=head.R=head.U=head.D=&head;
    for(int i=0;i<c;i++)
    {
        col[i].r=r;
        col[i].c=i;
        col[i].L=&head;
        col[i].R=head.R;
        col[i].U=col[i].D=col[i].L->R=col[i].R->L=&col[i];
        size[i]=0;
    }
    for(int i=r-1;i>=0;i--)
    {
        row[i].r=i;
        row[i].c=c;
        row[i].U=&head;
        row[i].D=head.D;
        row[i].L=row[i].R=row[i].U->D=row[i].D->U=&row[i];
    }
}
void insert(int r,int c)
{
    Node *p=&node[cnt++];
    p->r=r;
    p->c=c;
    p->R=&row[r];
    p->L=row[r].L;
    p->L->R=p->R->L=p;
    p->U=&col[c];
    p->D=col[c].D;
    p->U->D=p->D->U=p;
    ++size[c];
}
void delLR(Node *p)
{
    p->L->R=p->R;
    p->R->L=p->L;
}
void delUD(Node *p)
{
    p->U->D=p->D;
    p->D->U=p->U;
}
void resumeLR(Node *p)
{p->L->R=p->R->L=p;}
void resumeUD(Node *p)
{p->U->D=p->D->U=p;}
void cover(int c)
{
    if(c==H)
        return;
    Node *R,*C;
    delLR(&col[c]);
    for(C=col[c].D;C!=&col[c];C=C->D)
        for(R=C->L;R!=C;R=R->L)
        {
            --size[R->c];
            delUD(R);
        }
}
void resume(int c)
{
    if(c==H)
        return;
    Node *R,*C;
    for(C=col[c].U;C!=&col[c];C=C->U)
        for(R=C->R;R!=C;R=R->R)
        {
            ++size[R->c];
            resumeUD(R);
        }
    resumeLR(&col[c]);
}
int num,tar,map[15][15],block[15][15];
int dfs(int k)
{
    if(head.L==&head)
    {
        num++;
        if(num==tar)//æç´¢ä¸¤æ¬¡æå
            return 1;
        return 0;
    }
    int INF=-1u>>1,r,c=-1;
    Node *p,*rc;
    for(p=head.L;p!=&head;p=p->L)
        if(size[p->c]<INF)
            INF=size[c=p->c];
    if(!INF)
        return 0;
    cover(c);
    for(p=col[c].D;p!=&col[c];p=p->D)
    {
        for(rc=p->L;rc!=p;rc=rc->L)
            cover(rc->c);
        r=p->r-1;
        if(num==0)
            ans[r/(n*n)][r/n%n]=r%n;
        if(dfs(k+1))
            return 1;
        for(rc=p->R;rc!=p;rc=rc->R)
            resume(rc->c);
    }
    resume(c);
    return 0;
}
int dir[4][2]={-1,0,0,1,1,0,0,-1};
void dfs(int x,int y)//é¢å¤çæ¯ä¸ªæ ¼å­æå±å
{
    block[x][y]=num;
    int i,xx,yy;
    for(i=0;i<4;i++)
        if((map[x][y]&(1<<(i+4)))==0)
        {
            xx=x+dir[i][0];
            yy=y+dir[i][1];
            if(xx>=0&&yy>=0&&xx<n&&yy<n&&block[xx][yy]==-1)
                dfs(xx,yy);
        }
}
void insert(int i,int j,int k)
{
    int r=(i*n+j)*n+k;
    insert(r,i*n+k-1);
    insert(r,n*n+j*n+k-1);
    insert(r,2*n*n+block[i][j]*n+k-1);
    insert(r,3*n*n+i*n+j);
}
void Sudoku()
{
    int i,j,k;
    init(n*n*n+1,H);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&map[i][j]);
    memset(block,-1,sizeof(block));
    num=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(block[i][j]==-1)//é¢å¤çæ¯ä¸ªæ ¼å­æå±å
            {
                dfs(i,j);
                num++;
            }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            k=map[i][j]&15;//åä½4ä½
            if(k)
                insert(i,j,k);
            else
                for(k=1;k<=n;k++)
                    insert(i,j,k);
        }
    num=0;
    tar=2;
    dfs(0);
    printf("Case %d:\n",++tt);
    if(!num)
        puts("No solution");
    if(num==2)
        puts("Multiple Solutions");
    if(num==1)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                printf("%d",ans[i][j]+1);
            puts("");
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
        Sudoku();
}
