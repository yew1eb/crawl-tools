/*åæï¼
å¯¹äºç¹iï¼
1,ç¹iæ¯å¶å­ç»ç¹ï¼åï¼
E(i)=ki*E(1)+ei*0+(1-ki-ei)*(E(father)+1)
=>E(i)=ki*E(1)+(1-ki-ei)*E(father)+(1-ki-ei)
2,ç¹iéå¶å­ç»ç¹ï¼åï¼
E(i)=ki*E(1)+ei*0+(1-ki-ei)/m *(E(father)+1)+(1-ki-ei)/m*SUM(E(child)+1)
=>E(i)=ki*E(1)+(1-ki-ei)/m *E(father)+(1-ki-ei)/m*SUM(E(child))+(1-ki-ei);//ä½ä¸º1å¼ 

ä»å¬å¼å¯ç¥æ±E(i)éè¦æ±å°E(father),E(child)
ä½è¿æ¯å¾é¾æ±å°çï¼å ä¸ºå³ä½¿æ¯å¶å­ç»ç¹ä¹éè¦ç¥éE(1),ä½æ¯E(1)æ¯æªç¥çéè¦æ±ç

åè®¾:E(i)=Ai*E(1)+Bi*E(father)+Ci;//ä½ä¸º2å¼

æä»¥:E(child)=Aj*E(1)+Bj*E(i)+Cj;
=>SUM(E(child))=SUm(Aj*E(1)+Bj*E(i)+Cj);
å¸¦å¥1å¼ 
 =>E(i)=ki*E(1)+(1-ki-ei)/m *E(father)+(1-ki-ei)/m*SUm(Aj*E(1)+Bj*E(i)+Cj)+(1-ki-ei);
 =>(1-(1-ki-ei)/m*SUM(Bj))*E(i)=(ki+(1-ki-ei)/m*SUM(Aj))*E(1)+(1-ki-ei)/m *E(father)+(1-ki-ei+(1-ki-ei)/m*SUM(cj));
 ä¸ä¸è¿°2å¼å¯¹æ¯å¾å°:
 Ai=(ki+(1-ki-ei)/m*SUM(Aj))       / (1-(1-ki-ei)/m*SUM(Bj))
 Bi=(1-ki-ei)/m                   / (1-(1-ki-ei)/m*SUM(Bj))
 Ci=(1-ki-ei+(1-ki-ei)/m*SUM(cj)) / (1-(1-ki-ei)/m*SUM(Bj))
 æä»¥Ai,Bi,Ciåªä¸içå­©å­Aj,Bj,Cjåæ¬èº«ki,eiæå³
 äºæ¯å¯ä»¥ä»å¶å­å¼å§éæ¨å¾å°A1,B1,C1
 å¨å¶å­èç¹ï¼
 Ai=ki;
 Bi=(1-ki-ei);
 Ci=(1-ki-ei);
 èE(1)=A1*E(1)+B1*0+C1;
 =>E(1)=C1/(1-A1);
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=10000+10;
const double eps=1e-9;
int n,size;
int head[MAX];
double A,B,C,k[MAX],e[MAX];

struct Edge{
    int v,next;
    Edge(){}
    Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*2];

void Init(){
    memset(head,-1,sizeof head);
    size=0;
}

void InsertEdge(int u,int v){
    edge[size]=Edge(v,head[u]);
    head[u]=size++; 
}

void dfs(int u,int father){
    double a=0,b=0,c=0,p;
    int m=0;
    for(int i=head[u]; i != -1;i=edge[i].next){
        int v=edge[i].v;
        if(v == father)continue;
        dfs(v,u);
        a+=A;
        b+=B;
        c+=C;
        ++m;
    }
    if(father != -1)++m;
    p=(1-k[u]-e[u])/m;
    A=(k[u]+p*a)/(1-p*b);
    B=p/(1-p*b);
    C=(1-k[u]-e[u]+p*c)/(1-p*b);
}

int main(){
    int t,u,v,num=0;
    scanf("%d",&t);
    while(t--){
        scanf( "%d",&n);
        Init();
        for(int i=1;i<n;++i){
            scanf("%d%d",&u,&v);
            InsertEdge(u,v);
            InsertEdge(v,u);
        }
        for(int i=1;i<=n;++i){
            scanf("%lf%lf",&k[i],&e[i]);
            k[i]/=100;
            e[i]/=100;
        } 
        dfs(1,-1);
        if(fabs(A-1)<eps)printf("Case %d: impossible\n",++num);
        else printf("Case %d: %.6f\n",++num,C/(1-A));
    }
    return 0;
}