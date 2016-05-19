// by ashione 用<set>一直TLE 可能STL速度很慢吧，换成flag标记就好了。
#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
#define M 100001
int root[M+1];
bool mark,flag[M+1];
void init(int n){
        for(int i=0;i<=n;i++) root[i]=i,flag[i]=false;
}       
int Find(int y){
        while(root[y]!=y)
                y=root[y];
        return y;
}
void Merge(int x,int y){
        int a=Find(x),b=Find(y);
        if(a!=b) root[a]=b;//找集合最上父节点，
        else mark=true;//是同一个，则已经形成回路
}
int main(){
        int n,i=0,a,b,max;
        init(M);
        while( scanf("%d %d",&a,&b) && a+b >=0){
                if(a+b==0){//警惕0 0 陷阱
                 cout<<"Yes"<<endl;
                 continue;
                }
                max=0;//Max无非就是为了减少下次初始化的时间和空间
                mark=false;
                while((a+b)){
                        flag[a]=flag[b]=true;
                        max=max>a?max:a;
                        max=max>b?max:b;
                        if(!mark)   // 当mark=true就证明其存在回路，就是两个集合有交点
                        Merge(a,b);
                        scanf("%d %d",&a,&b);                   
                }
                if(mark){
                 cout<<"No"<<endl;
                continue;
                }
                int cnt=0;
                for(i=1;i<=max;i++)
                        if(flag[i] && root[i]==i) cnt++;
                puts(cnt==1?"Yes":"No");
                init(max);
        }       
        return 0;