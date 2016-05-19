#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;


int main()
{
    ll n;
    char c;
    while(~scanf("%I64d",&n))
    {
        ll dk=0,flag=0,bbj=0;
        ll last1=1,suml,sumk,summ,last2=1,bj;
        getchar();
        for(ll i=0;i<n;++i){
            while((c=getchar())!='\n'){
                if(c=='{')
                {
                        dk=1;
                        suml=0;
                }
                if(dk==1)
                {
                    if(c=='|')
                        suml++;
                }
                if(c=='}')
                {
                    dk=0;
                    last1=last1*(suml+1);
                    if(last1>100000)
                        bbj=1;
                }
                if(c=='$'&&flag==0) {flag=1;sumk=0;summ=0;continue;}
                if(flag==1)
                {
                    if(c==' '&&bj==0) {summ=1;bj=1;}
                    else if(c==' '&&bj==1)
                    {
                        summ++;
                    }
                    if(c!=' '&&c!='\n')
                    {
                        last2=last2*(summ+1);
                        summ=0;bj=0;
                    }
                    if(last2>100000)
                        bbj=1;

                }
                if(flag==1&&c=='$') flag=0;
            }
        }
        if(bbj)
            printf("doge\n");
        else
        {
            ll ans = last1 * last2 ;
            if(ans>100000)
                printf("doge\n");
            else printf("%I64d\n",ans);
        }
    }
    return 0;
}