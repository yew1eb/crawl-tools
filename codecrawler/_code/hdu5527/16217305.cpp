#include<bits/stdc++.h>
using namespace std;
const int val[]={1,5,10,20,50,100,200,500,1000,2000};
int c[11],ans,tot,sum,p;
void update(int x,int tmp,int s1,int s2){
    if(x<0)return;
    for(int i=9;i>=0;i--){
        //printf("%d %d %d %d %d %d\n",x,c[i],val[i],tmp,s1,s2);
        if(i==4){
            if(x>=100*s1){
                x-=100*s1;
                tmp-=s1*2;
            }else{
                tmp-=x/100*2;
                x%=100;
            }
            continue;
        }
        if(i==7){
            if(x>=1000*s2){
                x-=1000*s2;
                tmp-=s2*2;
            }else{
                tmp-=x/1000*2;
                x%=1000;
            }
            continue;
        }

        if(x>=c[i]*val[i]){
            x-=c[i]*val[i];
            tmp-=c[i];
        }else{
            tmp-=x/val[i];
            x%=val[i];
        }
    }
  //  printf("%d %d\n",x,tmp);
    if(x==0)ans=max(tmp,ans);
}
void work(){
    ans=-1;tot=sum=0;
    scanf("%d",&p);
    for(int  i=0;i<10;i++){
        scanf("%d",c+i);
        tot+=val[i]*c[i];
        sum+=c[i];
    }
    if(tot<p){
        printf("-1\n");
        return;
    }
    if(tot==p){
        printf("%d\n",sum);
        return;
    }
   // printf("tot =%d  sum= %d p= %d\n",tot,sum,p);
    update(tot-p,sum,c[4]/2,c[7]/2);
    if(c[4]&&c[7])
        update(tot-p-50-500,sum-2,(c[4]-1)/2,(c[7]-1)/2);
    if(c[4])
        update(tot-p-50,sum-1,(c[4]-1)/2,c[7]/2);
    if(c[7])
        update(tot-p-500,sum-1,c[4]/2,(c[7]-1)/2);
    printf("%d\n",ans);
}
int main(){
    int t;scanf("%d",&t);
    while(t--)work();
    return 0;
}