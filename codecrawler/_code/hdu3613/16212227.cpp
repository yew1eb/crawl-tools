#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 500005;
char S[MAXN];
char T[MAXN];
int  f[MAXN];
int  extend1[MAXN];
int  extend2[MAXN];
int  val[30];
int  sum[MAXN];

void revcpy(char* s,char* t,int len){
    memset(t, 0, sizeof(t));
    for(int i=0, k=len-1; i<len; ++i,--k)
        t[i] = s[k];
}
void getNext(char* T,int* next){
    int len=strlen(T), a=0;
    next[0]=len;
    while(a<len-1 && T[a]==T[a+1]) ++a;
    next[1]=a;
    a=1;
    for(int k=2; k<len; ++k){
        int p=a+next[a]-1, L=next[k-a];
        if(k+L-1>=p){
            int j=max(p-k+1,0);
            while(k+j<len && T[k+j]==T[j])++j;
            next[k]=j;
            a=k;
        }
        else
            next[k]=L;
   }
}

void EKMP(char* S,char* T,int* next, int* extend){  
    getNext(T,next);  
    int slen=strlen(S), tlen=strlen(T), a=0;  
    int minlen=min(slen,tlen);  
    while(a<minlen && S[a]==T[a])++a;  
    extend[0] = a;  
    a=0;  
    for(int k=1; k<slen; ++k){  
        int p=a+extend[a]-1, L=next[k-a];  
        if(k-1+L >= p){  
            int j=max(p-k+1,0);  
            while(k+j<slen && j<tlen && S[k+j]==T[j]) ++j;  
            extend[k] = j;  
            a=k;  
        }  
        else  
            extend[k] = L;  
    }  
}   

int main(){
    int nCase;
    scanf("%d",&nCase);
    while(nCase--){
        for(int i=0; i<26; ++i)
            scanf("%d",&val[i]);
        scanf("%s",S);
        memset(sum, 0, sizeof(sum));
        for(int i=0; S[i]; ++i){
            sum[i+1] = val[S[i]-'a']+sum[i];
        }
        int len=strlen(S);
        revcpy(S,T,strlen(S));
        EKMP(S,T,f,extend2);
        EKMP(T,S,f,extend1);

        int maxx=-1000000000;

        for(int i=0; i<len; ++i){
            if(i && extend1[i]+i==len){ //å¦æåé¨åæ¯åæ
                int pos=extend1[i];
                int tmp=sum[pos];
                if(extend2[pos]+pos==len){  // çååé¨åæ¯å¦ä¹æ¯åæ
                    tmp += sum[len]-sum[pos];
                }
                if(tmp > maxx)
                    maxx=tmp;
            }
            else{ //å¦æååé¨åä¸æ¯åæï¼çååä¸é¨å
                int pos=i+1,tmp=0;
                if(extend2[pos]+pos==len){
                    tmp += sum[len]-sum[pos];
                }
                if(tmp > maxx)
                    maxx=tmp;
            }
        }
        printf("%d\n",maxx);
    }
    return 0;
}