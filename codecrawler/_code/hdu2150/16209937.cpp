#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<set>
#include<vector>
#include<algorithm>
#define LL long long
#define inf 1<<30
#define s(a) scanf("%d",&a)
#define Clear(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=200005;
int n,a,b;
int num[105];
struct node
{
    double x,y;
};
node P[35][105];
double Cross_Prouct(node A,node B,node C)       //  è®¡ç®BAåä¹CAï¼
{
    return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
}
bool Intersect(node A,node B,node C,node D)     //  éè¿åä¹å¤æ­çº¿æ®µæ¯å¦ç¸äº¤ï¼
{
    if(min(A.x,B.x)<=max(C.x,D.x)&&         //  å¿«éææ¥å®éªï¼
       min(C.x,D.x)<=max(A.x,B.x)&&
       min(A.y,B.y)<=max(C.y,D.y)&&
       min(C.y,D.y)<=max(A.y,B.y)&&
       Cross_Prouct(A,B,C)*Cross_Prouct(A,B,D)<0&&      //  è·¨ç«å®éªï¼
       Cross_Prouct(C,D,A)*Cross_Prouct(C,D,B)<0)       //  åä¹å¼å·è¡¨ç¤ºå¨ä¸¤ä¾§ï¼
       return true;
    else return false;
}
bool Solve()    //  æ´åæä¸¾æ¯æ¡æçº¿çæ¯æ¡çº¿æ®µæ¯å¦ç¸äº¤ï¼
{
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            for(int ii=1;ii<num[i];ii++){
                for(int jj=1;jj<num[j];jj++){
                    if(Intersect(P[i][ii-1],P[i][ii],P[j][jj-1],P[j][jj])) return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            s(num[i]);
            for(int j=0;j<num[i];j++){
                scanf("%lf%lf",&P[i][j].x,&P[i][j].y);
            }
        }
        if(n==1) printf("No\n");
        else{
            bool flag=Solve();
            if(!flag)printf("No\n");
            else printf("Yes\n");
        }
    }
    return 0;
}

