#include<stdio.h>
#include<queue>
using namespace std;
int main(){
    int t,n;
    int a[20];
    queue<int>q;
    scanf("%d",&t);
    while(t--){
            scanf("%d",&n);
            int l,res,k;
            l=0;
        for(int i=n;i>=1;i--){
            l++;
            q.push(i);
            res=i%l;
            if(res==0)continue;
            else{
                for(int j=1;j<=res;j++){
                     k=q.front();
                     q.pop();
                     q.push(k);
                }
            }
        }
        int m=0;
        while(!q.empty()){
            a[++m]=q.front();
            q.pop();
        }
        for(int i=m;i>=1;i--){
            if(i==1){
                printf("%d\n",a[i]);
            }
            else printf("%d ",a[i]);
        }
    }
    return 0;
}