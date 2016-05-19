#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int n;
struct node{
    double x,y;
}d[30];
double getdis(node a,node b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool isequal(double x,double y){
    if(x-y>=-1e-8&&x-y<=1e-8)
        return true;
    return false;
}

bool isSquare(node a,node b,node c,node d){
    double len[6];
    len[0]=getdis(a,b);
    len[1]=getdis(a,c);
    len[2]=getdis(a,d);
    len[3]=getdis(b,c);
    len[4]=getdis(b,d);
    len[5]=getdis(c,d);
    double len1=len[0];
    double len2=len[0];
    for(int i=1;i<6;++i){
        if(!isequal(len[i],len2)&&!isequal(len[i],len1))
            len2=len[i];
    }
    for(int i=0;i<6;++i){
        if(isequal(len[i],len2)||isequal(len[i],len1));
        else return false;
    }
    if(len2-len1<-1e-8)
        swap(len1,len2);
    if(!isequal(2*len1*len1,len2*len2))
        return false;
    return true;
}


int main(){
    while(scanf("%d",&n)==1){
        long long ans=0;///ä¸ç¥éç»ææå¤å°ç§çæåµä¸ï¼ç´æ¥longlongï¼é²æ­¢æº¢åºï¼å½ç¶æ¬é¢æ¯å¯ä»¥ç¥éç
        for(int i=0;i<n;++i)
            scanf("%lf%lf",&d[i].x,&d[i].y);
        for(int i=0;i<n;++i)
            for(int j=i+1;j<n;++j)
                for(int u=j+1;u<n;++u)
                    for(int v=u+1;v<n;v++)
                        if(isSquare(d[i],d[j],d[u],d[v]))
                            ans++;
        printf("%I64d\n",ans);
    }
    return 0;
}
