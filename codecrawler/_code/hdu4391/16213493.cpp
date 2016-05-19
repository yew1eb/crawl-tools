#include <map>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <algorithm>

using namespace std;

#define size(v) (int)v.size()

const int N = 1e5 + 5;

int n,color,a[N],block_len;

map<int,int> blocks_colors[333];

void bf_update(int l,int r)
{
    int block_id = l / block_len;
    if(size(blocks_colors[block_id]) == 1)
    {
        map<int,int>::iterator it = blocks_colors[block_id].begin();
        int old_color = it->first;
        int old_cnt   = it->second;
        if(color == old_color)
            return ;
        if(r - l + 1 == old_cnt)
        {
            blocks_colors[block_id][color] = r - l + 1;
            blocks_colors[block_id].erase(it);
            return ;
        }
        for(int i=block_len*block_id;i<n && i<block_len*(block_id+1);i++)
        {
            if(i >= l && i <= r)
                a[i] = color;
            else
                a[i] = old_color;
        }
        blocks_colors[block_id][color] = r - l + 1;
        blocks_colors[block_id][old_color] = old_cnt - (r - l + 1);
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            if(a[i] == color)
                continue;
            map<int,int>::iterator it = blocks_colors[block_id].find(a[i]);
            if(it->second == 1)
                blocks_colors[block_id].erase(it);
            else
                it->second--;
            blocks_colors[block_id][color]++;
            a[i] = color;
        }
    }
}

int bf_query(int l,int r)
{
    int block_id = l / block_len;
    if(blocks_colors[block_id].count(color))
    {
        if(size(blocks_colors[block_id]) == 1)
            return r - l + 1;
        else
        {
            int ret = 0;
            for(int i=l;i<=r;i++)
                if(a[i] == color)
                    ++ret;
            return ret;
        }
    }
    else
        return 0;
}

void update(int l,int r)
{
    int block_id1 = l / block_len;
    int block_id2 = r / block_len;
    if(block_id1 == block_id2)
    {
        bf_update(l,r);
        return ;
    }
    int rr = block_len * (block_id1 + 1) - 1;
    int ll = block_len * block_id2;
    bf_update(l,rr);
    bf_update(ll,r);
    for(int id=block_id1+1;id<block_id2;id++)
    {
        blocks_colors[id].clear();
        blocks_colors[id][color] = block_len;
    }
}

int query(int l,int r)
{
    int block_id1 = l / block_len;
    int block_id2 = r / block_len;
    if(block_id1 == block_id2)
        return bf_query(l,r);
    int rr = block_len * (block_id1 + 1) - 1;
    int ll = block_len * block_id2;
    int ret = bf_query(l,rr) + bf_query(ll,r);
    for(int id=block_id1+1;id<block_id2;id++)
        if(blocks_colors[id].count(color))
            ret += blocks_colors[id][color];
    return ret;
}

void debug(int n,int max_id)
{
    printf("color of a[]: ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    puts("***");
    for(int i=0;i<=max_id;i++)
    {
        printf("the %dth block[%d,%d]=>\n",i,i*block_len,(i+1)*block_len-1);
        for(map<int,int>::iterator it=blocks_colors[i].begin();it!=blocks_colors[i].end();it++)
            printf("\t\t\t %d -> %d\n",it->first,it->second);
        puts("");
    }
}

int main()
{
    //freopen("in.ads","r",stdin);
    int m;
    while(~scanf("%d%d",&n,&m))
    {
        block_len = (int)sqrt(n * 1.0);
        //block_len = 400;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int block_id_max = n / block_len;
        for(int i=0;i<=block_id_max;i++)
            blocks_colors[i].clear();
        for(int i=0;i<n;i++)
        {
            int block_id = i / block_len;
            blocks_colors[block_id][ a[i] ]++;
        }
        int op,l,r;
        while(m--)
        {
            scanf("%d%d%d%d",&op,&l,&r,&color);
            if(op == 1)
                update(l,r);
            else
                printf("%d\n",query(l,r));
        }
    }
    return 0;
}
