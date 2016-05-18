#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;
#define Max 1100000
int isp[Max];
void isprim()
{
    int i,j;
    isp[0]=isp[1]=0;
    isp[2]=1;
    for(i=3;i<Max;i++)
        isp[i]=i%2;
    int ns;
    ns=(int)sqrt(Max*1.0);
    for(i=3;i<=ns;i++)
    {
        if(isp[i])
        {
            for(j=i*2;j<Max;j+=i)
                isp[j]=0;
        }
    }
}
int main()
{
    int len,n,i,j,k,ks;
    int num,nums;
    char str[1000];
    isprim();
    while(scanf("%s%d%*c",str,&n)&&(!(str[0]=='0'&&n==0)))
    {
        len=strlen(str);
        for(k=2;k<n;k++)
        {
            if(isp[k]==0)
            {
                continue;
            }
            num=0;
            for(i=0;i<len;i+=3)
            {
                nums=0;
                ks=1;
                for(j=i;j<i+3&&j<len;j++)
                {
                    ks=ks*10;
                    nums=nums*10+(str[j]-'0');
                }
                num=num*ks+nums;
                num=num%k;
            }
         //   printf("num=%d,k=%d\n",num,k);
            if(num==0)
            {
                printf("BAD %d\n",k);
                break;
            }
        }
        if(k==n)printf("GOOD\n");
    }
    return 0;
}