#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<map>
#include<cmath>
#include<string>

//#define r(x,date) (*((STRUCT*)x).date)
//#define dp(i,j) dp[i][j]
//#define dp(i,j,k) dp[i][j][k]
#define INF 0x7ffffff
#define ff(i,from,to) for(i=from;i<=to;i++)
#define rff(i,from,to) for(i=from;i>=to;i--)
#define ll long long
#define mset(a,num) memset(a,num,sizeof(a))
using namespace std;

template<class T>bool myfun_upmax(T &a,const T&b){return b>a?a=b,1:0;}
template<class T>bool myfun_upmin(T &a,const T&b){return b<a?a=b,1:0;}
template<class T>void myfun_swap(T &a,T &b){T temp;temp=a;a=b;b=temp;}
template<class T>T myfun_max(const T a,const T b){return a>b?a:b;}
template<class T>T myfun_min(const T a,const T b){return a<b?a:b;}
template<class T>T myfun_abs(const T a){return a<0?-a:a;}

int cmp(const void *a,const void *b){
    return 0;
}

inline void readint(int &ret) {
    char c;
    do{c=getchar();}while(c<'0' || c>'9');
    ret=c-'0';
    while((c=getchar())>='0' && c<='9')
        ret=ret*10+(c-'0');
}

int step[1000000];
int n,m;

int to_long(int cx,int cy,int mx,int my,int px,int py){
    return py+10*px+100*my+1000*mx+10000*cy+100000*cx;
}

int to_short(int num,int &cx,int &cy,int &mx,int &my,int &px,int &py){
    py=num%10;num/=10;
    px=num%10;num/=10;
    my=num%10;num/=10;
    mx=num%10;num/=10;
    cy=num%10;num/=10;
    cx=num%10;num/=10;
}

char grid[10][11];


int get_c(int cx,int cy,int mx,int my,int px,int py,int x,int y){
    if(x<0||x>=n)return INF;
    if(y<0||y>=m)return INF;
    if(x!=cx&&y!=cy)return INF;
    int c=0;
    if(cx==x){
        int minest=myfun_min(cy,y);
        int maxest=myfun_max(cy,y);
        for(int i=minest+1;i<maxest;i++){
            if(grid[x][i]!='.')c++;
            else if(x==mx&&i==my)c++;
            else if(x==px&&i==py)c++;
            else;
        }
    }else if(cy==y){
        int minest=myfun_min(cx,x);
        int maxest=myfun_max(cx,x);
        for(int i=minest+1;i<maxest;i++){
            if(grid[i][y]!='.')c++;
            else if(i==mx&&y==my)c++;
            else if(i==px&&y==py)c++;
            else;
        }
    }else;
    return c;
}

int get_p(int cx,int cy,int mx,int my,int px,int py,int x,int y){
    if(x<0||x>=n)return INF;
    if(y<0||y>=m)return INF;
    if(px!=x&&py!=y)return INF;
    int c=0;
    if(px==x){
        int minest=myfun_min(py,y);
        int maxest=myfun_max(py,y);
        for(int i=minest+1;i<maxest;i++){
            if(grid[x][i]!='.')c++;
            else if(x==mx&&i==my)c++;
            else if(x==cx&&i==cy)c++;
            else;
        }
    }else if(py==y){
        int minest=myfun_min(px,x);
        int maxest=myfun_max(px,x);
        for(int i=minest+1;i<maxest;i++){
            if(grid[i][y]!='.')c++;
            else if(i==mx&&y==my)c++;
            else if(i==cx&&y==cy)c++;
            else;
        }
    }else;
    return c;
}

bool judge_m(int cx,int cy,int mx,int my,int px,int py,int x,int y){
    if(x<0||x>=n)return false;
    if(y<0||y>=m)return false;
    int dis_x=x-mx;int dis_y=y-my;
    if(myfun_abs(dis_x*dis_y)!=2)return false;
    int dx=mx+dis_x/2;int dy=my+dis_y/2;
    if(grid[dx][dy]=='D'||grid[dx][dy]=='S'){
        return false;
    }else if(dx==cx&&dy==cy) return false;
    else if(dx==px&&dy==py)return false;
    else if(grid[x][y]=='D'){
        return false;
    }else if(x==cx&&y==cy) return false;
    else if(x==px&&y==py)return false;
    else return true;
}

bool judge(int cx,int cy,int mx,int my,int px,int py,int x,int y){
    if(grid[x][y]!='.')return false;
    else if(x==cx&&y==cy)return false;
    else if(x==mx&&y==my)return false;
    else if(x==px&&y==py)return false;
    else return true;
}
int move_m[8][2]={-2,-1,-2,1,1,2,-1,2,2,-1,2,1,-1,-2,1,-2};


queue<int>q;
int save_cx,save_cy,save_mx,save_my,save_px,save_py;
int sx,sy;
int solve(){
    memset(step,-1,sizeof(step));
    while(!q.empty())q.pop();
    int cx=save_cx;int cy=save_cy;
    int mx=save_mx;int my=save_my;
    int px=save_px;int py=save_py;
    int x,y;
    int long_num=to_long(cx,cy,mx,my,px,py);
    step[long_num]=0;
    q.push(long_num);
    while(!q.empty()){

        long_num=q.front();q.pop();
        //judge part
        //printf("%d\n",long_num);
        to_short(long_num,cx,cy,mx,my,px,py);
        if(get_c(cx,cy,mx,my,px,py,sx,sy)==0){
            //printf("%d\n",long_num);
            return step[long_num]+1;
        }
        else if(get_p(cx,cy,mx,my,px,py,sx,sy)==1){
            //printf("%d\n",long_num);
            return step[long_num]+1;
        }
        else{
            if(judge_m(cx,cy,mx,my,px,py,sx,sy)){
                //printf("%d\n",long_num);
                return step[long_num]+1;
            }
        }
        //move c
        //up and down
        x=cx-1;y=cy;
        while(get_c(cx,cy,mx,my,px,py,x,y)==0&&judge(cx,cy,mx,my,px,py,x,y)){
            int temp=to_long(x,y,mx,my,px,py);
            if(step[temp]==-1){
                step[temp]=step[long_num]+1;
                q.push(temp);
            }
            x--;
        }
        x=cx+1;y=cy;
        while(get_c(cx,cy,mx,my,px,py,x,y)==0&&judge(cx,cy,mx,my,px,py,x,y)){
            int temp=to_long(x,y,mx,my,px,py);
            if(step[temp]==-1){
                step[temp]=step[long_num]+1;
                q.push(temp);
            }
            x++;
        }
        //left and right
        x=cx;y=cy-1;
        while(get_c(cx,cy,mx,my,px,py,x,y)==0&&judge(cx,cy,mx,my,px,py,x,y)){
            int temp=to_long(x,y,mx,my,px,py);
            if(step[temp]==-1){
                step[temp]=step[long_num]+1;
                q.push(temp);
            }
            y--;
        }
        x=cx;y=cy+1;
        while(get_c(cx,cy,mx,my,px,py,x,y)==0&&judge(cx,cy,mx,my,px,py,x,y)){
            int temp=to_long(x,y,mx,my,px,py);
            if(step[temp]==-1){
                step[temp]=step[long_num]+1;
                q.push(temp);
            }
            y++;
        }

        //move m
        for(int i=0;i<8;i++){
            x=mx+move_m[i][0];
            y=my+move_m[i][1];
            if(judge_m(cx,cy,mx,my,px,py,x,y)&&judge(cx,cy,mx,my,px,py,x,y)){
                int temp=to_long(cx,cy,x,y,px,py);
                if(step[temp]==-1){
                    step[temp]=step[long_num]+1;
                    q.push(temp);
                }
            }
        }

        //move p
        //up and down
        x=px-1;y=py;
        while(get_p(cx,cy,mx,my,px,py,x,y)==0&&judge(cx,cy,mx,my,px,py,x,y)){
            int temp=to_long(cx,cy,mx,my,x,y);
            if(step[temp]==-1){
                step[temp]=step[long_num]+1;
                q.push(temp);
            }
            x--;
        }
        x=px+1;y=py;
        while(get_p(cx,cy,mx,my,px,py,x,y)==0&&judge(cx,cy,mx,my,px,py,x,y)){
            int temp=to_long(cx,cy,mx,my,x,y);
            if(step[temp]==-1){
                step[temp]=step[long_num]+1;
                q.push(temp);
            }
            x++;
        }
        //left and right
        x=px;y=py-1;
        while(get_p(cx,cy,mx,my,px,py,x,y)==0&&judge(cx,cy,mx,my,px,py,x,y)){
            int temp=to_long(cx,cy,mx,my,x,y);
            if(step[temp]==-1){
                step[temp]=step[long_num]+1;
                q.push(temp);
            }
            y--;
        }
        x=px;y=py+1;
        while(get_p(cx,cy,mx,my,px,py,x,y)==0&&judge(cx,cy,mx,my,px,py,x,y)){
            int temp=to_long(cx,cy,mx,my,x,y);
            if(step[temp]==-1){
                step[temp]=step[long_num]+1;
                q.push(temp);
            }
            y++;
        }
    }
    return 0;
}
int main()
{
    int t=1;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++){
            scanf("%s",grid[i]);
            for(int j=0;j<m;j++){
                if(grid[i][j]=='S'){
                    sx=i;
                    sy=j;
                }else if(grid[i][j]=='C'){
                    save_cx=i;
                    save_cy=j;
                    grid[i][j]='.';
                }else if(grid[i][j]=='M'){
                    save_mx=i;
                    save_my=j;
                    grid[i][j]='.';
                }else if(grid[i][j]=='P'){
                    save_px=i;
                    save_py=j;
                    grid[i][j]='.';
                }else;
            }
        }
        printf("Scenario #%d\n",t++);
        int r=solve();
        if(r)printf("%d\n",r);
        else printf("OH!That's impossible!\n");
        printf("\n");
    }
    return 0;
}
