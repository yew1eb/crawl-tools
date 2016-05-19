#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int gcd(int a,int b){
    return a%b==0?b:gcd(b,a%b);
}

int main(){
    char str1[1100],str2[1100];
    while(scanf("%s",str1),strcmp(str1,"-1")){
        scanf("%s",str2);
        int len1=strlen(str1);
        int len2=strlen(str2);
        int MAX=0,len=0;
        for(int i=0;i<len1;i++){
            for(int j=0;j<len2;j++){
                len=0;
                for(int k1=i,k2=j;k1<len1&&k2<len2;k1++,k2++){
                    if(str1[k1]==str2[k2])len++;
                }
                if(len>MAX)MAX=len;
            }
        }
        if(MAX==0)printf("appx(%s,%s) = 0\n",str1,str2);
        else {
            int len=len1+len2;
            MAX*=2;
            int x=gcd(MAX,len);
            if(MAX==len){
                printf("appx(%s,%s) = 1\n",str1,str2);
            }else 
                printf("appx(%s,%s) = %d/%d\n",str1,str2,MAX/x,len/x);
        }
    }
    return 0;
}