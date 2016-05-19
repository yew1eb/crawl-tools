#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N=320;

int money[]={0,1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289};
int c1[N],c2[N];

int main(){

    //freopen("input.txt","r",stdin);

    int n;
    while(~scanf("%d",&n) && n){
        for(int i=0;i<=n;i++){
            c1[i]=0;
            c2[i]=0;
        }
        c1[0]=1;
        for(int i=1;i<=17;i++){
            for(int j=0;j<=n;j++)
                for(int k=0;j+k*money[i]<=n;k++)
                    c2[j+k*money[i]]+=c1[j];
            for(int j=0;j<=n;j++){
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        printf("%d\n",c1[n]);
    }
    return 0;
}