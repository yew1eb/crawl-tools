#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int k;

int fi(char c){
    if(c=='_')
        return 0;
    if(c=='.')
        return 27;
    return (int)(c-'a'+1);
}

char fc(int i){
    if(i==0)return '_';
    if(i==27)return '.';
    return (char)(i+'a'-1);
}

int p[80];
char c[80];
int len;
void solve(char c,int i){
    int n=fi(c);
    n=(i+n)%28;
    p[k*i%len]=n;
}

int main()
{
    scanf("%d",&k);
    while(k){
            scanf("%s",c);
            len=strlen(c);
            for(int i=0;i<len;i++){
                    solve(c[i],i);
            }
            for(int i=0;i<len;i++){
                    printf("%c",fc(p[i]));
            }
            printf("\n");
            scanf("%d",&k);
    }
    return 0;
}



