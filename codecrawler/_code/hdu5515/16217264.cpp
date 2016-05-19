#include<stdio.h>
#include<string.h>
#include<math.h>
#define eps 0.00000001
double T,V1,V2;
void solve()
{
     double l,r;
       double t1,t2,x,mid;
    if(V1==V2){
        printf("Yes\n");
        return;
    }
    else if(2*V1*V1>V2*V2){    //å¨2-3ä¹é´æ¦æª

       l=0;
       r=300;
        while(fabs(l-r)>eps)    //äºåæ¨ªåæ 
        {
             mid=(l+r)/2.0;
           t1=sqrt(300*300+mid*mid)/V1;
           t2=(300+mid)/V2;
           if(t1>=t2)l=mid;
           else r=mid;
        }
        mid=(l+r)/2.0;


        t1=(mid+600)/V1;
        t2=T+(600-mid)/V2;
        if(t1>t2){
            printf("No\n");
            return;
        }
        else {
            printf("Yes\n");
            return;
        }
    }
    else if(3*V1>V2)    //å¨3-4ä¹é´æ¦æª
    {
        l=0;
        r=300;
        while(fabs(l-r)>eps)    //äºåçºµåæ 
        {
             mid=(l+r)/2.0;
            t1=sqrt(300*300+(300-mid)*(300-mid))/V1;
            t2=(600+mid)/V2;
            if(t1>=t2)l=mid;
            else r=mid;
        }
        mid=(l+r)/2.0;
        t1=(sqrt(mid*mid+300*300)+900)/V1;
        t2=(600-mid)/V2+T;
        if(t1>t2){
            printf("No\n");
            return;
        }
        else {
            printf("Yes\n");
            return;
        }
    }
    else {
        printf("No\n");
        return ;
    }
}
int main()
{
    int t,i,j,k,icase=0;

    scanf("%d",&t);
    while(t--)
    {
        icase++;
        scanf("%lf%lf%lf",&T,&V1,&V2);
        printf("Case #%d: ",icase);
        solve();

    }
    return 0;
}
