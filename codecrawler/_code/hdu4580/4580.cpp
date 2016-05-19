#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
int mp[26][26][26][26];
char ss[555555];
int main(){
    int n;
    
    while(~scanf("%d",&n)){
        if(n>=456980){printf("Impossible\n");continue;}
        memset(mp,0,sizeof mp);
        memset(ss,0,sizeof ss);
        ss[0]='a';
        ss[1]='a';
        ss[2]='a';
        ss[3]='a';
        int tot=0;
        mp[0][0][0][0]=1;
        int fl=0,im=0;
        if(n==1)printf("a\n");
        else if(n==2)printf("aa\n");
        else if(n==3)printf("aaa\n");
        else if(n==4)printf("aaaa\n");
        else{
            int j=0;
            for(int i=4;i<min(n,456976);++i){
                int fl=0;
                for(j=0;j<26;++j){
                    if(!mp[ss[i-3]-'a'][ss[i-2]-'a'][ss[i-1]-'a'][j]){
                        mp[ss[i-3]-'a'][ss[i-2]-'a'][ss[i-1]-'a'][j]=1;
                        ss[i]=j+'a';
                        fl=1;
                        break;
                    }
                }
                if(fl==0)i-=2;
            }
            printf("%s",ss);
            for(int i=0;i<(n-456976);++i)printf("a");
            printf("\n");
        }
    }
    return 0;
}