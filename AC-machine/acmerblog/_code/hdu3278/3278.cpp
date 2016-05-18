#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

const int maxn=17000000;

struct node{
    int maze[4][6];
    int Zip(){
        int res=0;
        for(int i=0;i<4;i++)
            for(int j=0;j<6;j++){
                res<<=1;
                res+=maze[i][j];
            }
        return res;
    }
    void ReZip(int res){
        for(int i=3;i>=0;i--)
            for(int j=5;j>=0;j--){
                maze[i][j]=res&1;
                res>>=1;
            }
    }
}s,t;

void L_move(int si){
    int i,j;
    for(i=0;i<4;i++){
        if(si!=i){
            for(j=0;j<6;j++)
                t.maze[i][j]=s.maze[i][j];
        }else{
            for(j=0;j<5;j++)
                t.maze[i][j]=s.maze[i][j+1];
            t.maze[i][5]=s.maze[i][0];
        }
    }
}

void R_move(int si){
    int i,j;
    for(i=0;i<4;i++){
        if(si!=i){
            for(j=0;j<6;j++)
                t.maze[i][j]=s.maze[i][j];
        }else{
            for(j=5;j>0;j--)
                t.maze[i][j]=s.maze[i][j-1];
            t.maze[i][0]=s.maze[i][5];
        }
    }
}

void U_move(int sj){
    int i,j;
    for(j=0;j<6;j++){
        if(sj!=j){
            for(i=0;i<4;i++)
                t.maze[i][j]=s.maze[i][j];
        }else{
            for(i=0;i<3;i++)
                t.maze[i][j]=s.maze[i+1][j];
            t.maze[3][j]=s.maze[0][j];
        }
    }
}

void D_move(int sj){
    int i,j;
    for(j=0;j<6;j++){
        if(sj!=j){
            for(i=0;i<4;i++)
                t.maze[i][j]=s.maze[i][j];
        }else{
            for(i=3;i>0;i--)
                t.maze[i][j]=s.maze[i-1][j];
            t.maze[0][j]=s.maze[3][j];
        }
    }
}

char step[maxn]; //用int会超内存！！！！！！！！！！

void BFS(){
    memset(s.maze,0,sizeof(s.maze));
    memset(t.maze,0,sizeof(t.maze));
    for(int i=1;i<=2;i++)
        for(int j=1;j<=4;j++){
            s.maze[i][j]=1;
            t.maze[i][j]=1;
        }
    int szip,nzip=s.Zip();
    memset(step,-1,sizeof(step));
    queue<int> q;
    while(!q.empty())
        q.pop();
    q.push(nzip);
    step[nzip]=0;
    while(!q.empty()){
        nzip=q.front();
        q.pop();
        s.ReZip(nzip);
        for(int i=0;i<4;i++){
            R_move(i);
            szip=t.Zip();
            if(step[szip]==-1){
                step[szip]=step[nzip]+1;
                q.push(szip);
            }

            L_move(i);
            szip=t.Zip();
            if(step[szip]==-1){
                step[szip]=step[nzip]+1;
                q.push(szip);
            }
        }
        for(int i=0;i<6;i++){
            U_move(i);
            szip=t.Zip();
            if(step[szip]==-1){
                step[szip]=step[nzip]+1;
                q.push(szip);
            }

            D_move(i);
            szip=t.Zip();
            if(step[szip]==-1){
                step[szip]=step[nzip]+1;
                q.push(szip);
            }
        }
    }
}

void Solve(int x){
    for(int i=0;i<4;i++)
        for(int j=0;j<6;j++)
            if(s.maze[i][j]==x)
                t.maze[i][j]=1;
            else
                t.maze[i][j]=0;
}

int main(){

    //freopen("input.txt","r",stdin);

    int T,res;
    BFS();
    char map[6];
    scanf("%d",&T);
    int cases=0;
    while(T--){
        int i,j;
        for(i=0;i<4;i++){
            scanf("%s",map);
            for(j=0;j<6;j++){
                if(map[j]=='W')
                    s.maze[i][j]=0;
                else if(map[j]=='B')
                    s.maze[i][j]=1;
                else
                    s.maze[i][j]=2;
            }
        }
        res=maxn;
        for(i=0;i<3;i++){
            Solve(i);
            int nzip=t.Zip();
            if(res>step[nzip])
                res=step[nzip];
        }
        printf("Case %d: %d\n",++cases,res);
    }
    return 0;
}