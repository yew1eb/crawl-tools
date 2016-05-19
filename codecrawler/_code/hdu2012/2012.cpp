#include<iostream>  
#include<algorithm>  
#include<math.h>  
#include<stdio.h>    
#include<string.h>    
#include<time.h>    
#include<stdlib.h>    
typedef __int64 LL;   
LL a,b,sum;   
const int S=20;//随机算法判定次数，S越大，判错概率越小     
//***************Miller_Rabin 算法进行素数测试***************    
int cmp(void const *a,void const *b)  
{  
    if(*(LL *)a>*(LL *)b)  
        return 1;  
    else return -1;  
}  
LL mult_mod(LL a,LL x,LL n)//返回(a*x) mod n,a,x,n<2^63    
{    
    a%=n;x%=n;    
    LL ret=0;    
    while(x)    
    {    
        if(x&1){ret+=a;if(ret>=n)ret-=n;}    
        a<<=1;    
        if(a>=n)a-=n;    
        x>>=1;    
    }    
    return ret;    
}    
LL pow_mod(LL a,LL x,LL n)//返回a^x mod n    
{    
    if(x==1)return a%n;    
    int bit[70],k=0;    
    while(x)    
    {    
        bit[k++]=(x&1?1:0);    
        x>>=1;    
    }    
    LL ret=1;    
    for(--k;k>=0;k--)    
    {    
       ret=mult_mod(ret,ret,n);    
       if(bit[k])ret=mult_mod(ret,a,n);    
    }    
    return ret;    
}    
bool judge(LL a,LL n,LL x,LL t)//以a为基，n-1=x*2^t，检验n是不是合数    
{    
    LL ret=pow_mod(a,x,n),flag=ret;    
    for(LL i=1;i<=t;i++)    
    {    
        ret=mult_mod(ret,ret,n);    
        if(ret==1&&flag!=1&&flag!=n-1)return true;    
        flag=ret;    
    }    
    if(ret!=1)return true;    
    return false;    
}    
bool Miller_Rabin(LL n)    
{    
    if(n==2||n==5||n==7||n==11)return true;    
    if(n%2==0||n%5==0||n%7==0||n%11==0)return false;    
    LL x=n-1,t=0;    
    while((x&1)==0)x>>=1,t++;    
    bool flag=true;    
    if(t>=1&&(x&1)==1)    
    {    
        for(int i=1;i<=S;i++)    
        {    
            LL a=rand()%(n-1)+1;    
            if(judge(a,n,x,t)){flag=true;break;}    
            flag=false;    
        }    
    }    
    if(flag)return false;    
    else return true;    
}
int main()
{
	int i,j;
	LL p,a,b;
	while(scanf("%I64d %I64d",&p,&a),p||a)
	{
		if(Miller_Rabin(p)){printf("no\n");continue;}
		b=pow_mod(a,p,p);
		if(b==a)
			printf("yes\n");
		else printf("no\n");
	}
	return 0;
}