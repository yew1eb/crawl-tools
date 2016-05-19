#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct temp
{
    
    char ch[100];
    
    int r;
    
    int k;
}ss[310],mm[310];
int cmp(const void *p,const void *q)
{
    if((*(temp*)p).r==(*(temp*)q).r)
        return (*(temp*)p).k-(*(temp*)q).k;
    else
        return (*(temp*)p).r-(*(temp*)q).r>0?-1:1;
}
int main()
{
    int n,i;
    int flag1,flag2;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%s%d",ss[i].ch,&ss[i].r);
            
            ss[i].k=i;
            
        }
        for(i=0;i<n;i++)
        {
            scanf("%s%d",mm[i].ch,&mm[i].r);
        }
        
        qsort(ss,n,sizeof(ss[0]),cmp);
        
        flag1=0;flag2=0;
        
        for(i=0;i<n;i++)
        {
            
            if(ss[i].r!=mm[i].r)
            {
                
                flag1=1;
                break;
                
            }
            
        }
        for(i=0;i<n;i++)
        {
            
            if(strcmp(ss[i].ch,mm[i].ch)!=0)
            {
                flag2=1;
                break;
            }
        }
        if(!flag1&&!flag2)
            printf("Right\n");
        else
            
            if(flag1)
                
            {
                
                printf("Error\n");
                
                for(i=0;i<n;i++)
                    
                    printf("%s %d\n",ss[i].ch,ss[i].r);    
            }
            
            else
                
            {
                printf("Not Stable\n");
                
                for(i=0;i<n;i++)
                    
                    printf("%s %d\n",ss[i].ch,ss[i].r);    
                
            }
            
    }
    return 0;
    
} 
