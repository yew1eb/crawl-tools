#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long lll;
int gcd(int p,int q){
    if(q==0) return p;
    return gcd(q,p%q);
}
lll fa[10];
lll b[1000005];
int main()
{
    int i,j,x,y,t,N=0;
    cin>>t;
    fa[0]=1;
    for(i=1;i<10;i++) fa[i]=fa[i-1]*10;
    while(t--){
        double u;
        scanf("%lf",&u);
        x=(u+(1e-8))*1000000;
        y=1000000;
        int p=gcd(x,y);
        x=x/p;
        y=y/p;
        if(x==0){
            printf("Case #%d:\n",++N);
            printf("%d\n",0);
            continue;
        }
        int s=0;
        for(i=1;i<10;i++){
            if(i%y==0){
                int w=i/y*x;
                if(w==i){
                    b[s++]=i;
                }
            }
        }
        for(i=1;i<=9;i++){
            for(j=0;j<=9;j++){
                int w=i*10+j;
                if(w%y==0){
                    w=w/y*x;
                    if(w%10==(i*10+j)/10&&(w/10==(i*10+j)%10)){
                        b[s++]=i*10+j;
                    }
                }
            }
        }
        for(i=3;i<=10;i++){
            for(j=1;j<=9;j++){
                for(int f=0;f<=9;f++){
                    lll a1,b1;
                    a1=(j*fa[i-1]+f)%y;
                    b1=(f*fa[i-1]+j)%x;
                    lll w;
                    w=(j*fa[i-1]+f)/y-(f*fa[i-1]+j)/x;
                    lll x1,y1;
                        x1=(lll)x*y*w-(y*b1-x*a1);
                        y1=(10*y-10*x);
                            if(y1!=0&&x1%y1==0){
                                lll k=x1/y1;
                                if(k>=0&&k<=fa[i-2]-1&&(k*10+b1)%x==0&&(k*10+a1)%y==0){
                                    b[s++]=k*10+j*fa[i-1]+f;
                                }
                            }
                }
            }
        }
        printf("Case #%d:\n",++N);
        printf("%d\n",s);
        sort(b,b+s);
        for(i=0;i<s;i++){
            if(i!=0) printf(" ");
            printf("%I64d",b[i]);
        }
        if(s!=0) printf("\n");
    }
}
