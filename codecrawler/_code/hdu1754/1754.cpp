#include <stdio.h>

int max(int d,int b)//这里如果用inline会加速好多啊
{
    return d>b?d:b;
}


#define  MAXN  2000000
int a[MAXN+5];


struct node
{
    int left;
    int right;
    int sum;
} b[MAXN*2];


void build(int left , int right , int i)//为left，right ，sum赋值
{
    int mid;
    b[i].left=left;
    b[i].right=right;
    if(left==right)
    {
        b[i].sum=a[left];
        return ;
    }

    mid=(left+right)/2;
    build(left,mid,2*i);
    build(mid+1,right,2*i+1);
    b[i].sum=max(b[2*i].sum , b[2*i+1].sum);

}

void  Update(int id,int value,int i)
{
    if(b[i].left==b[i].right)
    {
        b[i].sum=value;
        return ;
    }


        int mid =(b[i].left+b[i].right)/2;
        if(mid>=id) Update(id,value,2*i);
        if(id>mid) Update(id ,value,2*i+1);
        b[i].sum=max(b[i*2].sum , b[2*i+1].sum);//注意更新的时候不仅更新子节点，还要更新父节点

}


int Query(int left, int right,int i)
{
    int mid;
    if(b[i].left==left && b[i].right ==right) return b[i].sum;
    mid=(b[i].left+b[i].right)/2;
    if(right<=mid) return Query(left,right,2*i);
    if (left>mid ) return Query(left,right,2*i+1);
    if(left<=mid && mid<right)
    return max(Query(left,mid,2*i) , Query(mid+1,right,2*i+1));
}


int main()
{
    int n,m;
    char c;
    int id,value;
    int i;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        //scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        build(1,n,1);
        for(i=0;i<m;i++)
        {
            scanf("%c",&c);
            scanf("%d%d",&id,&value);
            if(c=='U') Update(id,value,1);
            if(c=='Q') printf("%d\n",Query(id,value,1));
        }
    }
    return 0;
}
终于知道哪错了，有两个地方，第一b[]数组开小了，至少要三倍或者四倍a[]数组，第二输入char c时有误，要用char c[3],要输入一个字符串，因为单独输入一个字符的话会把回车给独到
char c 中，在最下面贴最新的代码