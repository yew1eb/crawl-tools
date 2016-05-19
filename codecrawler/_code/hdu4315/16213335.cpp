#include<iostream>
#include<cstdio>
using namespace std;
int a[1005],ans;
int n,k;
void move(){
    int i;
    if(n%2==0){
        for(i=1;i<=n;i+=2){
            ans^=(a[i+1]-a[i]-1);
        }
    }
    else{
        ans^=a[1];
        for(i=2;i<=n;i+=2){
            ans^=(a[i+1]-a[i]-1);
        }
    }

}
int main(){

    while(~scanf("%d%d",&n,&k)){
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        ans=0;
        if(k==1) {
            printf("Alice\n");
            continue;
        }
        if(k==2 && n%2==1){
            a[1]--;
            move();
        }
        else move();
//        cout<<ans<<endl;
        if(ans==0) printf("Bob\n");
        else printf("Alice\n");
    }

}
