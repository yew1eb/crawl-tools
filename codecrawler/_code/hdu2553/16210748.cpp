#include <iostream>
#include <cstring>
using namespace std;
#define N 10
int Maze[N][N];
int sum;
int n;
bool Valid(int i,int j);

void Total(int cur,int n)
{
    if(cur==n) { sum++; return;}
    int i;
    for(i=0;i<n;++i)
    {
        if(Valid(cur,i))
        {
            Maze[cur][i]=1;
            Total(cur+1,n);
            Maze[cur][i]=0;
        }
    }
}
bool Valid(int x,int y)
{
     int i,j;
    for(i=0;i<n;++i)
    if(Maze[i][y]) return false;         //æé¤ååçåç´ 
    //æé¤å·¦æçº¿é¨å
    j=y-1;
    for(i=x-1;i>=0;i--)
    {
            if(i>=0&&j>=0&&Maze[i][j--])
            return false;
    }
    //æé¤å³æçº¿é¨å
    j=y+1;
    for(i=x-1;i>=0;i--)
    {
        
        if(i>=0&&j<n&&Maze[i][j++])
            return false;
    }
    return true;
}
int result[11]={0,1,0,0,2,10,4,40,92,352,724}; //éç¨æè¡¨~~
int main()
{
    memset(Maze,0,sizeof(Maze));
    while (cin>>n,n)
    {
    cout<<result[n]<<endl;
    }
    return 0;                                    
}