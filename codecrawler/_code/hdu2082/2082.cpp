#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N=50;

int c1[N+10],c2[N+10],num[30];

int main(){

    //freopen("input.txt","r",stdin);

    int t;
    scanf("%d",&t);
    while(t--){
        memset(c1,0,sizeof(c1));    //c1[ ]保存当前得到的多项式各项系数
        memset(c2,0,sizeof(c2));    //c2[ ]保存每次计算时的临时结果
        for(int i=1;i<=26;i++)
            scanf("%d",&num[i]);
        c1[0]=1;                //相当于用X^0去乘以后面的多项式 
        for(int i=1;i<=26;i++){     //要乘以26个多项式
            for(int j=0;j<=N;j++)   //c1的各项的指数
                for(int k=0;k<=num[i] && j+k*i<=N;k++)  //k*i表示被乘多项式各项的指数,(X^0*i + X^1*i + X^2*i + ……)
                    c2[j+k*i]+=c1[j];       //指数相加得j+k*i,加多少只取决于c1[j]的系数，因为被乘多项式的各项系数均为1
            for(int j=0;j<=N;j++){
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        int ans=0;
        for(int i=1;i<=N;i++)
            ans+=c1[i];
        printf("%d\n",ans);
    }
    return 0;
}