#include<iostream>
#include<cstring>
using namespace std;
int f[105];
int mark[105];
int change(char *s)
{
    int hour=0,minute=0,i,len;
    len=strlen(s);
    for(i=0;s[i]!=':';i++)
        hour=hour*10+s[i]-'0';
    
    i++;
    for(;i<len;i++)
        minute=minute*10+s[i]-'0';
    
    
    
    return hour*60+minute;
}
int main()
{
    int n;
    char order,s[10];
    int ca=0;
    double sum=0;
    while(cin>>n)
    {
        
        if(n==-1)
            break;
        cin>>order>>s;
        
        if(n==0)
        {
            if(ca!=0)
                printf("%d %.0lf\n",ca,sum/ca);    
            else
                printf("0 0\n");
            ca=0,sum=0;
            memset(f,0,sizeof(f));
            memset(mark,0,sizeof(f));
        }
        else 
        {
            if(order=='S')
            {
                mark[n]=1;
                f[n]=change(s);
            }
            if(order=='E')
            {
                int temp;
                if(mark[n]==1)
                {
                    ca++;
                    temp=change(s);
                    sum+=temp-f[n];
                }
            }
            
        }
        
    }
    return 0;
}