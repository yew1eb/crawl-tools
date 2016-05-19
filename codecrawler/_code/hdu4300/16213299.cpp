#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 1000005;
char a[50];
char b[MAXN];
char str[MAXN];
int  f[MAXN];
int  val[200];

int main(){
    int nCase;
    scanf("%d",&nCase);
    while(nCase--){
        scanf("%s %s",a,b);
        for(int i=0; a[i]; ++i){
            val[a[i]] = i+'a';
        }
        int len=strlen(b);
        int mid;
        if(len & 1) mid=len/2;
        else mid=len/2-1;
        int pos;
        for(int i=mid; i<len; ++i){
            bool flag=true;
            for(int k=0,j=i+1; j<len; ++j,++k){
                if(val[b[k]]!=b[j]){
                    flag=false;
                    break; 
                }
            }
            if(flag){
                pos=i;
                break;    
            }
        }
        memset(str, 0, sizeof(str));
        for(int i=0; i<=pos; ++i)
            str[i]=b[i];
        for(int i=pos+1,k=0; k<=pos; ++i,++k)
            str[i]=val[str[k]];
        puts(str);
    }
    return 0;
}