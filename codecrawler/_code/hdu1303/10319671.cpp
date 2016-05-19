#include<stdio.h>
int main()
{    
    int s[16],i,j;
    while(scanf("%d",&s[0])&&(s[0]!=-1))
    {
        for(i=1;;i++)
        {
            scanf("%d",s+i);
            if(s[i]==0)
                break;
        }
        int count;
        for(count=0,i=0;s[i]!=0;i++)
            for(j=0;s[j]!=0;j++)
                if(s[i]==s[j]*2)
                    count++;
        printf("%d\n",count);
    }
    return 0;
}