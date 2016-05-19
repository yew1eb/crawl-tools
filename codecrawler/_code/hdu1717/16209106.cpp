# include<stdio.h> 
int gcd(int a,int b) 
{ 
    int temp; 
    while(a%b!=0) 
    { 
        temp=a%b; 
        a=b; 
        b=temp; 
    } 
    return b; 
} 
int main() 
{ 
    int i,ncase,ans,p,q,t,m,n,x,y,k,l; 
    char ch[25]; 
    scanf("%d",&ncase); 
    while(ncase--) 
    { 
        scanf("%s",ch); 
        x=0; 
        t=0; 
        p=0; 
        q=0; 
        k=1;l=1; 
        for(i=2;ch[i]!=0;i++) 
        { 
            if(t==0 && ch[i]!='(')  
            { 
                p++; 
                x*=10; 
                x+=ch[i]-'0'; 
            } 
            if(t==1&& ch[i]!=')') 
            { 
                q++; 
                y*=10; 
                y+=ch[i]-'0'; 
            } 
            if(ch[i]=='(') {t=1;y=x;q=p;} 
        } 
        if(q==0) 
        { 
            while(p--) 
                k*=10; 
            ans=gcd(x,k); 
            x/=ans; 
            k/=ans; 
            printf("%d/%d\n",x,k); 
        } 
        else 
        { 
            m=y-x; 
            while(p--) 
                k*=10; 
            while(q--) 
                l*=10; 
            n=l-k; 
            ans=gcd(m,n); 
            m/=ans; 
            n/=ans; 
            printf("%d/%d\n",m,n); 
        } 
    } 
    return 0; 
} 
