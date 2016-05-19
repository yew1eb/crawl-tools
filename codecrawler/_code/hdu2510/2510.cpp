#include <iostream>
using namespace std;

int map[25][25];
int n;
int DFS(int d,int num)
{
    if(num > n*(n+1)/4) return 0;//小小的剪枝,+号大于总数的1/2时,不满足条件
    if(d>=n)
    {
        if(n*(n+1)/2 == 2 * num)
        {
            return 1;
        }else return 0;
    }
    if(d==0)
    {
        map[0][0] = 1;
        int sum = DFS(1,1) + DFS(1,1);
        map[0][0] = 0;
        sum += DFS(1,0) + DFS(1,0);
        return sum;
    }
    else 
    {
      int sum = 0;
      for(int k=0;k<2;k++)
      {
          int t = num;
          for(int j=0;j<=d;j++)
          {
            if(j==0)
            {
                map[d][0] = k;
                t+= k;
            }
            else 
            {
                map[d][j] = map[d-1][j-1] ^ map[d][j-1];
                t+=map[d][j];
            }
          }
        sum += DFS(d+1,t);
      }
        return sum;
    }
}
int main(int argc, const char *argv[])
{
　　freopen("output.txt","r",stdout);
    for(int i=1;i<=24;i++)
    {
        n = i;
        if(n*(n+1)/2%2!=0) cout<<"0,";
        else
        {
            int ans = DFS(0,0);
            cout<<ans/2<<",";
        }
    }
    return 0;
}