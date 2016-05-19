#include <cmath>
#include <vector>
#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1005;

struct Node{
 double pi,qi;
};
Node node[maxn];
bool comp(const Node & t1,const Node & t2)
{
 return t1.pi*t2.qi < t2.pi*t1.qi; //ѡ��������ӳ�ȥ/�������� �������ġ�
}
double dp[maxn][13];
int main(int argc,char *argv[])
{
 int n,m;
 int t,i,j,ncase = 0;
 scanf("%d",&t);
 while(t --)
 {
 scanf("%d%d",&n,&m);
 for(i = 1;i <= n;i ++)
 scanf("%lf%lf",&node[i].pi,&node[i].qi);
 sort(node+1,node+n+1,comp);
 for(i = 0;i <= m;i ++) dp[1][i] = node[1].pi; //���Ѹ���
 //����ͬ 1 - pi - qi
 for(i = 2;i <= n;i ++)
 {
 for(j = 0;j <= m;j ++)
 {
 dp[i][j] = node[i].pi + (1-node[i].pi-node[i].qi)*dp[i-1][j];
 if(j >= 1)
 dp[i][j] += node[i].qi*dp[i-1][j-1];
 }
 }
 ncase ++;
 printf("Case %d: %.5f\n",ncase,dp[n][m]);
 }
 return 0;
}