#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=100+10;
char s[MAX];
int num[MAX][2];
typedef pair<int,int>mp;

int main(){
    int n,Case=0,a;
    mp temp;
    while(cin>>n,n){
        stack<mp>p[MAX];
        cin>>s;
        for(int i=0;s[i] != '\0';++i){
            if(s[i] == 'U')p[i].push(mp(i+1,1));
            else p[i].push(mp(i+1,0));
        }
        cin>>s;
        int L=0,R=n-1;
        for(int i=0;s[i] != '\0';++i){
            if(s[i] == 'L'){
                int size=p[L].size();
                while(size--)temp=p[L].top(),p[L].pop(),p[L+1].push(mp(temp.first,!temp.second));
                ++L;
            }else{
                int size=p[R].size();
                while(size--)temp=p[R].top(),p[R].pop(),p[R-1].push(mp(temp.first,!temp.second));
                --R;
            }
        }
        int size=p[L].size();
        for(int i=1;i<=size;++i){
            temp=p[L].top();
            p[L].pop();
            num[i][0]=temp.first;
            num[i][1]=temp.second; 
        }
        printf("Pile %d\n",++Case);
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>a;
            printf("Card %d is a face %s %d.\n",a,num[a][1]?"up":"down",num[a][0]);
        }
    }
    return 0;
}