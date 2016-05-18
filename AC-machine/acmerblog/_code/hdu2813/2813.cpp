//Accepted	496 KB	734 ms	C++	1967 B	
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;
map<string,int> m1;
map<string,int> m2;
const int maxn=210;
int w[maxn][maxn];
bool s[maxn],t[maxn];
int lx[maxn],ly[maxn];
int match[maxn];
int n,m,k;
 
bool hungary(int u){
     s[u]=true;
     for(int v=1;v<=m;v++){
         if(!t[v] && lx[u]+ly[v]==w[u][v]){
            t[v]=true;//易遗忘 
            if(match[v]==-1 || hungary(match[v])){
               match[v]=u;
               return true;
            }
         }
     }
     return false;
}
int KM(){
    int ans=0;
    memset(match,-1,sizeof(match));
    for(int i=1;i<=n;i++){
    	lx[i]=-1<<30;//注意 
    }
    memset(ly,0,sizeof(ly));
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
          lx[i]=max(lx[i],w[i][j]);
    for(int i=1;i<=n;i++){
        while(1){
           memset(s,false,sizeof(s));
           memset(t,false,sizeof(t));
           if(hungary(i)) break;
           else{
                int a=1<<30;
                for(int j=1;j<=n;j++) if(s[j]){
                    for(int k=1;k<=m;k++) if(!t[k] && a>lx[j]+ly[k]-w[j][k])
                        a=lx[j]+ly[k]-w[j][k];
                }
                for(int j=1;j<=n;j++){
                   if(s[j]) lx[j]-=a;   
                }
                for(int j=1;j<=m;j++){
                	if(t[j]) ly[j]+=a;
                }
           }
        }
    }
    for(int i=1;i<=m;i++) if(match[i]!=-1)//
	    ans+=w[match[i]][i];
    return -ans;//易遗忘 
}
int main(){
	char name1[21],name2[21];
	int u,v,injury;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		m1.clear();
		m2.clear();
		u=v=1;
		for(int i=1;i<=n;i++){//不要忘了初始化图，因为此题不一定会填满n*m的边 
			for(int j=1;j<=m;j++)
			w[i][j]=-1<<30;
		}
		while(k--){
			scanf("%s%s%d",name1,name2,&injury);
			if(m1.find(name1)==m1.end()) m1[name1]=u++;//若战将没有入图 
			if(m2.find(name2)==m2.end()) m2[name2]=v++;
			w[m1[name1]][m2[name2]]=-injury;
		}
		printf("%d\n",KM());
	}
	return 0;
}