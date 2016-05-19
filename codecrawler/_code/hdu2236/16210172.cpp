#include <stdio.h>          
#include <string.h>          
#define MAXN 102          

int mp[MAXN][MAXN];          
int from[MAXN],used[MAXN];
int mid,n,ptr;

int match(int x)//åçå©ç®æ³        
{          
    int i;          
    for(i=0;i<n;++i)         
    {          
        if(!used[i]&&mp[x][i]>=ptr&&mp[x][i]<=ptr+mid)          
        {          
            used[i]=1;          
            if(from[i]==-1||match(from[i]))          
            {          
                from[i]=x;       
                return 1;          
            }          
        }          
    }          
    return 0;          
}  

int hungary()
{
    int i;  
    memset(from,-1,sizeof(from));  
    for(i=0;i<n;++i)  
    {  
        memset(used,0,sizeof(used));  
        if(!match(i))  
            return 0;  
    }  
    return 1; 
}

int main()
{
    int test,i,j,Max,Min,MAX,MIN,flag;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        Min=110,Max=-10;
        for(i=0;i<n;++i)
        {
            for(j=0;j<n;++j)
            {
                scanf("%d",&mp[i][j]);
                Min=Min>mp[i][j]?mp[i][j]:Min;
                Max=Max<mp[i][j]?mp[i][j]:Max;
            }
        }
        MAX=Max-Min;
        MIN=0;
        while(1)
        {
            flag=0;
            mid=(MIN+MAX)>>1;
            for(ptr=Min;ptr+mid<=Max;ptr++)
            {
                if(hungary())
                {
                    flag=1;
                    break;
                }
            }
            if(MIN==mid)
                break;
            if(flag)
                MAX=mid;
            else
                MIN=mid;
        }
        printf("%d\n",MAX);
    }
}