#include <iostream>    
#include <queue>
using namespace std;
char map[11][11][11];
int dir[6][3]={-1,0,0,0,1,0,1,0,0,0,-1,0,0,0,1,0,0,-1};
struct point
{
    int x;
    int y;
    int z;
    int step;
}sta,end1;
int n;
bool islegal(int x,int y,int z)
{
    return x>=0&&x<n&&y>=0&&y<n&&z>=0&&z<n&&map[z][x][y]!='X';
}
void BFS()
{
    queue<point> Q;
    sta.step = 0;
    Q.push(sta);
    while(!Q.empty())
    {
        point now = Q.front();
        Q.pop();
        if(now.x==end1.x&&now.y==end1.y&&now.z==end1.z)
        {
            cout<<n<<" "<<now.step<<endl;
            return;
        }
        for(int i=0;i<6;i++)
        {
            int nextX = now.x + dir[i][0];
            int nextY = now.y + dir[i][1];
            int nextZ = now.z + dir[i][2];
            if(islegal(nextX,nextY,nextZ))
            {
                point next = {nextX,nextY,nextZ,now.step+1};
                map[nextZ][nextX][nextY]='X';
                Q.push(next);
            }
        }
    }
    cout<<"NO ROUTE"<<endl;
}

int main(int argc, const char *argv[])
{
    //freopen("input.txt","r",stdin);
    char a[10];

    while(cin>>a>>n)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                cin>>map[i][j];
            }
            cin>>sta.x>>sta.y>>sta.z;
            cin>>end1.x>>end1.y>>end1.z;
            cin>>a;
            BFS();
    }
    return 0;
}