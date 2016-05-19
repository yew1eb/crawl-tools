#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=1000+10;
map<int,int>Map;
queue<int>oq[MAX],p;
string name;
bool mark[MAX];

int main(){
    int n,m,a,num=0;
    while(scanf("%d",&n),n){
        Map.clear();
        while(!p.empty())p.pop();
        memset(mark,false,sizeof mark);
        for(int i=1;i<=n;++i)while(!oq[i].empty())oq[i].pop();
        for(int i=1;i<=n;++i){
            scanf("%d",&m);
            while(m--)scanf("%d",&a),Map[a]=i;
        }
        printf("Scenario #%d\n",++num);
        while(cin>>name,name != "STOP"){
            if(name == "ENQUEUE"){
                scanf("%d",&a);
                int id=Map[a];
                oq[id].push(a);
                if(!mark[id])p.push(id);
                mark[id]=true;
            }else{
                int k=p.front();
                printf("%d\n",oq[k].front());
                oq[k].pop();
                if(oq[k].empty())p.pop(),mark[k]=false;
            }
        }
        cout<<endl;
    }
    return 0;
}