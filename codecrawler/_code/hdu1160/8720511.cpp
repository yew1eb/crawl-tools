    #include <algorithm>  
    #include <iostream>  
    #include <cstdio>  
    #define MAXN 1001  
    using namespace std;  
    struct mouse  
    {  
        int W;  
        int S;  
        int ID;  
        bool operator <(const mouse &tmp) const  
        {  
                if(W == tmp.W)  
                    return S > tmp.S;  
                else  
                    return W < tmp.W;  
        };  
    }mice[MAXN];  
    struct tt  
    {  
        int tot;  
        int next;  
    }f[MAXN];  
    int n;  
      
    void init()  
    {  
        int i;  
        int w, s;  
        n = 0;  
        while(~scanf("%d%d",&w,&s))  
        {  
            mice[n].W = w;  
            mice[n].S = s;  
            mice[n].ID = n+1;  
            n++;  
        }  
        sort(mice, mice +n);  
       /* for(i=0; i<n; ++i) 
        { 
            printf("%d %d %d\n",mice[i].W, mice[i].S, mice[i].ID); 
        } 
        */  
        for(i=0; i<n; ++i)  
        {  
            f[i].tot = 0;  
            f[i].next = -1;  
        }  
    }  
    void visit(int x)  
    {  
        printf("%d\n",mice[x].ID);  
        if(f[x].next >0)  
             visit(f[x].next);  
    }  
    void dp()  
    {  
        int i, j, max,k;  
        for(i=n-1; i>=0; --i)  
        {  
            max = 0;k = -1;  
            for(j=n-1;j>i; --j)  
                if(mice[i].S > mice[j].S && mice[i].W < mice[j].W && max <f[j].tot)  
                {  
                    max = f[j].tot;  
                    k =j;  
                }  
            f[i].tot = max + 1;  
            f[i].next = k;  
        }  
        max = 0;  
        for(i=0; i<n; ++i)  
            if(max < f[i].tot)  
            {  
                max = f[i].tot;  
                k = i;  
            }  
        printf("%d\n",max);  
        visit(k);  
    }  
    int main()  
    {  
        //freopen("in.txt","r",stdin);  
        init();  
        dp();  
        return 0;  
    }  