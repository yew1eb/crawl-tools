#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define _DEBUG 0
#define MAXN 30
#define MAXK 100
#define MAX(X,Y) (X)>(Y)?(X):(Y)
#define MIN(X,Y) (X)<(Y)?(X):(Y)

typedef struct{
    long long x;
    long long y;
}Point;
Point pipes[MAXN][MAXK];

long long crossMultiply(const Point &p1,
    const Point &p2,const Point p3){
        return (p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y);
}

bool inSegment(const Point &p1,
    const Point &p2,const Point p3){
        int minx=MIN(p1.x,p2.x);
        int maxx=MAX(p1.x,p2.x);
        int miny=MIN(p1.y,p2.y);
        int maxy=MAX(p1.y,p2.y);
        return (p3.x>=minx && p3.x<=maxx
            && p3.y>=miny && p3.y<=maxy);
}

bool isIntersect(const Point &p1,
    const Point &p2,const Point p3,
    const Point p4){//p1--P2ä¸p3--p4çº¿æ®µæ¯å¦ç¸äº¤
        long long d1=crossMultiply(p1,p2,p3);
        long long d2=crossMultiply(p1,p2,p4);
        long long d3=crossMultiply(p3,p4,p1);
        long long d4=crossMultiply(p3,p4,p2);
        if((d1>0 && d2<0 || d1<0 && d2>0) 
            && (d3>0 && d4<0 || d3<0 && d4>0)){
            return true;
        }
        if(d1==0 && inSegment(p1,p2,p3))
            return true;
        if(d2==0 && inSegment(p1,p2,p4))
            return true;
        if(d3==0 && inSegment(p3,p4,p1))
            return true;
        if(d4==0 && inSegment(p3,p4,p2))
            return true;
        return false;
}

bool check(int row,int col){
    assert(row>0 && col>0);
    int i,j;
    for(i=0;i<row;i++){
        for(j=1;;j++){
            if(pipes[i][j].x == 100000 && 
                pipes[i][j].y == 100000)//å°è¾¾è¾¹ç
                break;
            if(isIntersect(pipes[i][j-1],pipes[i][j],
                pipes[row][col-1],pipes[row][col])){//æäº¤å
                    return true;
            }
        }
    }
    return false;
}
int main(){
#if _DEBUG == 1
    freopen("2150.in","r",stdin);
#endif
    int n,k;
    int i,j;
    while(scanf("%d",&n)!=EOF){
        bool flag = false;//1è¡¨ç¤ºæäº¤åç¹ï¼0è¡¨ç¤ºæ²¡æ
        for(i=0;i<n;i++){
            scanf("%d",&k);
            for(j=0;j<k;j++){
                scanf("%lld %lld",&pipes[i][j].x,&pipes[i][j].y);
                if(flag)//å·²å¤å®æäº¤åç¹
                    continue;
                if(i>=1 && j>=1 && check(i,j)){//å¦ææ£æ¥ä¸ä¹åçç¹æäº¤åç¹
                    flag=true;
                }                    
            }
            //æ¾ç½®ä¸ä¸å¯è½çç¹ï¼ä½ä¸ºè¾¹ç
            pipes[i][k].x = 100000;
            pipes[i][k].y = 100000;
        }
        printf("%s\n",flag?"Yes":"No");
    }
    return 0;
}