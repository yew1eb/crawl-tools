//题意：按照题中给的金字塔的位置 ,s代表起点 ，*代表障碍，@代表此路可走
//      D代表出口（注意出口不止一个），在规定的时间内判断是否能走出金字塔
//思路：BFS求最短的路径上面所走的步数，注意搜索失败的时候队列是空的，判断一下子
//调试注意：
//  1.注意步数是1这种特殊情况（对应题目中所给样例的case3） 输出的是1 minute 而不是1 minutes
//  2.注意是两个案例之间有空格，最后一个案例后面没有空格
//  3.printf()在很多输出时候就显示出优势来啦，不改啦，下次a题的时候用printf(),cout太恶心啦！
#include<iostream>
#include<cstring>
#include<queue>
#define maxlen  110
using namespace std;
struct node
{
    int x,y,step;
};
int mat[maxlen][maxlen];
int dir[6][2]= {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1}};
int BFS(node s,node e[],int count,int m)
{
    int i;
    queue<node> q;
    node ol,ne;//旧的状态和新的状态
    while(!q.empty())
    {
        q.pop();
    }//建立空队列
    s.step=0;
    q.push(s);//搜索起点入队
    mat[s.x][s.y]=1;
    while(!q.empty())
    {
        ol=q.front();
        q.pop();
        for(i=0; i<count; i++)
        {
            if(ol.x==e[i].x&&ol.y==e[i].y)
              {
                  return ol.step;
              }
        }//搜索到出口，直接返回，因为是BFS，故最先搜索到的尾最小
        for(i=0; i<6; i++)
        {
            ne.x=ol.x+dir[i][0];
            ne.y=ol.y+dir[i][1];
            ne.step=ol.step;
            if(!(ne.x>=0&&ne.y>=0&&ne.x<m&&ne.y<m&&ne.y<=ne.x&&!mat[ne.x][ne.y]))
                  continue;
            else
            {
                mat[ne.x][ne.y]=1;
                ne.step++;
                q.push(ne);
            }
        }
    }
    if(q.empty())return -1;//搜索失败
    else return ne.step;
}
int main()
{
    node s,e[maxlen];//出口有可能不止一个，设数组
    int m,n,N=0,tem=0,i,j,count,minl;
    char k;
    while(cin >>m >>n)
    {
        if(tem==1) cout << endl;
        tem=1;//两个样例之间有一空格，最后一个样例后面没有
        count=0;
        memset(mat,0,sizeof(mat));
        N++;//样例的个数
        for (i=0; i<m; i++)
        {
            for (j=0; j<=i; j++)
            {
                cin>> k;
                if(k=='S')
                {
                    s.x=i;
                    s.y=j;
                }
                else if(k=='*')  mat[i][j]=1;//不能走
                else if(k=='D')
                {
                    e[count].x=i;
                    e[count].y=j;
                    count++;//出口的个数
                }
                else  mat[i][j]=0;//可以走
            }
        }
        minl=BFS(s,e,count,m);
        if(minl>1&&minl<=n)  cout << "Maze #" << N << " :" <<  endl << "Hurry up, You need " << minl << " minutes to escape!" << endl ;
        else if(minl==1&&minl<=n)  cout <<"Maze #" << N <<  " :" << endl <<  "Hurry up, You need 1 minute to escape!" << endl;
          else  cout << "Maze #" << N << " :" <<  endl <<"Oh No, I'm afraid that you don't have enough time to escape!" << endl ;
        //注意1的情况，恶心啦一天啊
    }
    return 0;
}