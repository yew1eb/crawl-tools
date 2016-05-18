#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool flag[31];
int bound[210];
struct Seg
{
    int left,right,color;
} seg[210][210*4];
void build(int tree,int n,int left,int right)
{
    int mid = (left + right) / 2;
    seg[tree][n].left = left ;
    seg[tree][n].right = right ;
    seg[tree][n].color = 0 ;
    if(left == right)
        return ;
    build(tree,2*n,left,mid);
    build(tree,2*n+1,mid+1,right);
}
void insert(int tree,int n,int left,int right,int color)
{
    int mid = (seg[tree][n].left + seg[tree][n].right) / 2;
    if(seg[tree][n].left == left && seg[tree][n].right == right)
    {
        seg[tree][n].color = color;
    }
    else
    {
        if(seg[tree][n].color>=0)
        {
            seg[tree][2*n].color= seg[tree][n].color;
            seg[tree][2*n+1].color= seg[tree][n].color;
            seg[tree][n].color = -1;
        }
        if(right<=mid)
        {
            insert(tree,n*2,left,right,color);
        }
        else if(left>mid)
        {
            insert(tree,n*2+1,left,right,color);
        }
        else
        {
            insert(tree,n*2,left,mid,color);
            insert(tree,n*2+1,mid+1,right,color);
        }
    }
}
void query(int tree,int n,int left,int right)
{
    int mid = (seg[tree][n].left + seg[tree][n].right) / 2;
    if(seg[tree][n].color>=0)
    {
        flag[seg[tree][n].color] = true;
        return;
    }
    if(seg[tree][n].left == left && seg[tree][n].right ==right && seg[tree][n].color>=0)
    {
        flag[seg[tree][n].color] = true;
    }
    else
    {
        if(right<=mid)
        {
            query(tree,n*2,left,right);
        }
        else if(left>mid)
        {
            query(tree,n*2+1,left,right);
        }
        else
        {
            query(tree,n*2,left,mid);
            query(tree,n*2+1,mid+1,right);
        }
    }
}
 
int main()
{
    int h,n,k,x,y,v,s,cas=1;
    char ch;
    while(scanf("%d %d %d",&h,&n,&k)==3)
    {
        printf("Petri Dish #%d\n",cas++);
        int tree = 1;
        for(int i=h; i<2*h-1; i++)
        {
            bound[tree]=i;
            build(tree++,1,1,i);
        }
        for(int i=2*h-1; i>=h; i--)
        {
            bound[tree]=i;
            build(tree++,1,1,i);
        }
        while(n--)
        {
            scanf(" %c",&ch);
            if(ch == 'I')
            {
                scanf("%d %d %d %d",&x,&y,&v,&s);
                x++;
                y++;
                int left = x - s +1;
                for(int i=y-1; i>=y-s+1; i--)
                {
                    if(i < 1)
                        break;
                    if(i >=h)
                        left++;
                    int right = left + 2*s - 2- y +i;
                    if(right<1)
                        break;
                    insert(i,1,max(1,left),min(bound[i],right),v);
 
                }
                left = x - s +1;
                for(int i=y; i<=y+s-1; i++)
                {
                    if(i > 2*h-1)
                        break;
                    int right =  left + 2*s - 2+ y -i;
                    if(right<1)
                        break;
                    insert(i,1,max(1,left),min(bound[i],right),v);
                    if(i <h)
                        left++;
                }
            }
            else
            {
                scanf("%d %d %d",&x,&y,&s);
                memset(flag,0,sizeof(flag));
                int sum = 0;
                x++;
                y++;
                int left = x - s +1;
                for(int i=y-1; i>=y-s+1; i--)
                {
                    if(i < 1)
                        break;
                    if(i >=h)
                        left++;
                    int right = left + 2*s - 2- y +i;
                    if(right<1)
                        break;
                    query(i,1,max(1,left),min(bound[i],right));
 
                }
                left = x - s +1;
                for(int i=y; i<=y+s-1; i++)
                {
                    if(i > 2*h-1)
                        break;
                    int right =  left + 2*s - 2+ y -i;
                    if(right<1)
                        break;
                    query(i,1,max(1,left),min(bound[i],right));
                    if(i <h)
                        left++;
                }
                for(int i=1; i<=k; i++)
                {
                    if(flag[i])
                        sum++;
                }
                printf("%d\n",sum);
            }
        }
    }
    return 0;
}