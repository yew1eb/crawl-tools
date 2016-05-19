#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<map>
#include<string>
#define inf 1<<30
#define eps 1e-7
#define LD long double
#define LL long long
#define maxn 1005
using namespace std;
int a[4][4];
int depth;
bool flag;
void change(int b[4][4],int k){
    if(k<8){
        if(k&1){
            int tmp=b[0][k/2];
            for(int i=1;i<4;i++)
                b[i-1][k/2]=b[i][k/2];
            b[3][k/2]=tmp;
        }
        else{
            int tmp=b[3][k/2];
            for(int i=3;i>0;i--)
                b[i][k/2]=b[i-1][k/2];
            b[0][k/2]=tmp;
        }
    }
    else{
        if(k&1){
            int tmp=b[(k-8)/2][0];
            for(int i=1;i<4;i++)
                b[(k-8)/2][i-1]=b[(k-8)/2][i];
            b[(k-8)/2][3]=tmp;
        }
        else{
            int tmp=b[(k-8)/2][3];
            for(int i=3;i>0;i--)
                b[(k-8)/2][i]=b[(k-8)/2][i-1];
            b[(k-8)/2][0]=tmp;
        }
    }
}
int get_h(int b[4][4]){
    int ans=inf,tmp=0;
    for(int i=0;i<4;i++){
        bool flag[5];
        int cnt=4;
        memset(flag,false,sizeof(flag));
        for(int j=0;j<4;j++)
            if(!flag[b[i][j]]){
                cnt--;
                flag[b[i][j]]=true;
            }
        tmp+=3-cnt;
    }
    ans=min(tmp,ans);
    tmp=0;
    for(int j=0;j<4;j++){
        bool flag[5];
        int cnt=4;
        memset(flag,false,sizeof(flag));
        for(int i=0;i<4;i++)
            if(!flag[b[i][j]]){
                cnt--;
                flag[b[i][j]]=true;
            }
        tmp+=3-cnt;
    }
    ans=min(tmp,ans);
    return (ans+3)/4;    
}
void IDAstar(int b[4][4],int tmp_depth,int father){
    if(flag)
        return;
    if(get_h(b)>tmp_depth)
        return;
    if(tmp_depth==0){
        flag=true;
        return;
    }
    for(int i=0;i<16;i++){
        if(father!=-1&&father/2==i/2&&(father%2)^(i%2))
            continue;
        int tmp[4][4];
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                tmp[i][j]=b[i][j];
        change(tmp,i);
        IDAstar(tmp,tmp_depth-1,i);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                scanf("%d",&a[i][j]);
        flag=false;
        for(depth=0;depth<=5;depth++){
            IDAstar(a,depth,-1);
            if(flag){
                printf("%d\n",depth);
                break;
            }
        }
        if(!flag)
            printf("-1\n");    
    }
    return 0;
}