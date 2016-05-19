    #include<cstdio>  
    #include<algorithm>  
    #include<cstring>  
    #include<iostream>  
    using namespace std;  
    struct point{  
        long long x,y;  
        friend bool operator < (const point &a,const point &b){  
            return max(a.x,a.y)<max(b.x,b.y);  
        }  
    };  
    point a[50001];  
    long long suma[50001],sumb[50001],suma_mul[50001],sumb_mul[50001];  
    point b[50001];  
    int find_a(int l,int r,long long t){  
        while(r>=l){  
            int m=(l+r)/2;  
            if(t==max(a[m].x,a[m].y))return m;  
            if(t<max(a[m].x,a[m].y))r=m-1;  
            else l=m+1;  
        }  
        return l;  
    }  
    int find_b(int l,int r,long long t){  
        while(r>=l){  
            int m=(l+r)/2;  
            if(t==max(b[m].x,b[m].y))return m;  
            if(t<max(b[m].x,b[m].y))r=m-1;  
            else l=m+1;  
        }  
        return l;  
    }  
    int main(){  
        int T;  
        scanf("%d",&T);  
        while(T--){  
            memset(suma,0,sizeof(suma));  
            memset(sumb,0,sizeof(sumb));  
            memset(suma_mul,0,sizeof(suma_mul));  
            memset(sumb_mul,0,sizeof(sumb_mul));  
            memset(a,0,sizeof(a));  
            memset(b,0,sizeof(b));  
            int n;  
            scanf("%d",&n);  
            for(int i=1;i<=n;i++){  
                long long x1,y1,x2,y2;  
                scanf("%I64d%I64d%I64d%I64d",&x1,&y1,&x2,&y2);  
                //cin>>x1>>y1>>x2>>y2;  
                a[2*i-1]=(point){x1,y1};  
                a[2*i]=(point){x2,y2};  
                b[2*i-1]=(point){x1,y2};  
                b[2*i]=(point){x2,y1};  
            }  
            sort(a,a+2*n+1);  
            sort(b,b+2*n+1);  
            for(int i=1;i<=2*n;i++){  
                suma[i]=suma[i-1]+a[i].x+a[i].y;  
                sumb[i]=sumb[i-1]+b[i].x+b[i].y;  
                suma_mul[i]=suma_mul[i-1]+a[i].x*a[i].y;  
                sumb_mul[i]=sumb_mul[i-1]+b[i].x*b[i].y;  
            }  
            suma[2*n+1]=suma[2*n];  
            sumb[2*n+1]=sumb[2*n];  
            suma_mul[2*n+1]=suma_mul[2*n];  
            sumb_mul[2*n+1]=sumb_mul[2*n];  
            int q;  
            scanf("%d",&q);  
            while(q--){  
                long long x;  
                scanf("%I64d",&x);  
                long long sum=0;  
                int m=find_a(1,2*n,x);  
                if(m>2*n)m=2*n;  
                if(x<max(a[m].x,a[m].y))m--;  
                sum=m*x*x-x*suma[m]+suma_mul[m];  
                m=find_b(1,2*n,x);  
                if(m>2*n)m=2*n;  
                if(x<max(b[m].x,b[m].y))m--;  
                sum=sum-(m*x*x-x*sumb[m]+sumb_mul[m]);  
                printf("%I64d\n",sum);  
                //cout<<sum<<endl;  
            }  
        }  
    }  