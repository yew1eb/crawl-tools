#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct Eight
{
    char matrix[3][3];
    int x,y;
};
Eight src,dst;
int step[][2]= {{0,1},{-1,0},{1,0},{0,-1}};
int dep,nextstep;
char * cmd="dlru",ans[100];
bool flag;
bool OK(const Eight& src)
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(src.matrix[i][j] && src.matrix[i][j] !=i*3+j+1)
                return false;
    return true;
}
int h(const Eight& src)
{
    int ans =0;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(src.matrix[i][j])
                ans += abs(i-(src.matrix[i][j]-1)/3)+abs(j-(src.matrix[i][j]-1)%3);
    return ans;
}
bool CanSovle()
{
    int ans = 0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(src.matrix[i][j])
                for(int y=0;y<3;y++)
                    for(int x=0;y*3+x<=i*3+j && x<3;x++)
                        if(src.matrix[y][x] && src.matrix[y][x] >src.matrix[i][j])
                            ans++;
    return ans % 2 ==0;
}
void dfs(int x,Eight src,int from)
{
    if(OK(src))
    {
        flag = true;
        return;
    }
    int t = h(src);
    if(x + t >dep || flag)
    {
        nextstep = min (nextstep,x+t);
        return;
    }
    for(int i=0; i<4 && !flag; i++)
    {
        if(from + i ==3)
            continue;
        int tx = src.x + step[i][0];
        int ty = src.y + step[i][1];
        if(tx >=0 && tx<=2 && ty>=0 && ty<=2)
        {
            Eight tmp = src;
            swap(tmp.matrix[src.y][src.x],tmp.matrix[ty][tx]);
            tmp.x = tx;
            tmp.y = ty;
            dfs(x+1,tmp,i);
            if(flag)
                ans[x]=cmd[i];
        }
    }
}
void IDAstar(Eight src)
{
    memset(ans,0,sizeof(ans));
    for(dep = h(src);!flag; dep=nextstep)
    {
        nextstep=100;
        dfs(0,src,-1);
    }
}
int main()
{
    while(1)
    {
        flag = false;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(scanf(" %c",&src.matrix[i][j])!=1)
                    return 0;
                if(src.matrix[i][j]=='x')
                {
                    src.matrix[i][j]=0;
                    src.y=i;
                    src.x=j;
                }
                else
                    src.matrix[i][j]-='0';
            }
        }
        if(CanSovle())
        {
            IDAstar(src);
            printf("%s\n",ans);
        }
        else
            printf("unsolvable\n");
    }
    return 0;
}