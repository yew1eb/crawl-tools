#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define N 100010
#define MOD 1000000007

bool isprime[N];
int primenum[N];
int cou;
int primeid[N];
long long int numa[N];

void getprime(){
    memset(isprime,true,sizeof(isprime));
    isprime[0]=false;
    isprime[1]=false;
    cou=0;
    for(int i=2;i<N;i++){
        if(isprime[i]==true){
            primenum[cou++]=i;
            primeid[i]=cou-1;
        }
        for(int j=0;j<cou&&primenum[j]*i<N;j++){
            isprime[i*primenum[j]]=false;
            if(i%primenum[j]==0){
                break;
            }
        }
    }

    return;
}

void add(int num,int a){
    //printf("%d %d\n",num,a);
    for(int j=0;j<cou&&primenum[j]*primenum[j]<=num;j++){
        if(num%primenum[j]==0){
            int tempcou=0;

            while(num%primenum[j]==0){
                tempcou++;
                num=num/primenum[j];
            }
            numa[j]=numa[j]+a*tempcou;
        }
    }
    if(num!=1){
        numa[primeid[num]]+=a;
    }

    return;
}

long long int km(long long int x,long long int y){
    long long int ans=1;

    while(y){
        if(y%2){
            ans=ans*x%MOD;
        }
        y=y/2;
        x=x*x%MOD;
    }

    return ans;
}

int main(){
    int n;
    int tempa;

    getprime();

    while(scanf("%d",&n)!=EOF){
        memset(numa,0,sizeof(numa));
        for(int i=1;i<=n;i++){
            scanf("%d",&tempa);
            add(i,tempa);//printf("wo shi da hao ren\n");
        }

        bool isodd=false;
        long long int q=1;

        for(int i=0;i<cou;i++){
            if(numa[i]%2==1&&isodd==false){
                q=q*((numa[i]+1)/2)%(MOD-1);
                isodd=true;
            }
            else{
                q=q*(numa[i]+1)%(MOD-1);
            }
        }

        long long int ans=1;

        if(isodd==false){//æ¯==ï¼èä¸æ¯=ï¼å ä¸ºè¿ä¸ªwräºï¼æ³¨æ
            for(int i=0;i<cou;i++){
                ans=ans*km(primenum[i],q*(numa[i]/2)%(MOD-1))%MOD;
            }
        }
        else{
            for(int i=0;i<cou;i++){
                ans=ans*km(primenum[i],q*numa[i]%(MOD-1))%MOD;
            }
        }

        //printf("%lld\n",q);
        printf("%lld\n",ans);
    }

    return 0;
}
