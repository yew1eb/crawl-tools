#include<stdio.h>   
#include<string.h>   
#define N 110   
int map[N][N],used[N],match[N],n,m;       
int find(int k)     
{   
    int i;   
    for(i=1;i<m;i++) 
    {   
        if(map[k][i] && !used[i])  
        {   
            used[i]=1; 
            if(match[i]==0 || find(match[i]))   
            {   
                match[i]=k;   
                return 1;    
            }   
        }   
    }   
    return 0;   
}   
int main()   
{   
    int i,k,count,x,y;      
    while(scanf("%d",&n),n!=0)
	{
		scanf("%d%d",&m,&k);
		memset(map,0,sizeof(map));  /*第一次忘了这句初始化，wrong了*/
		while(k--)
		{
			scanf("%d%d%d",&i,&x,&y);
			if(x && y)
				map[x][y]=1;
		}
        count=0;  /*记录匹配数*/  
        memset(match,0,sizeof(match));  /*初始时匹配边为空*/     
        for(i=1;i<n;i++)   
        {   
            memset(used,0,sizeof(used));   /*所有顶点置未访问标记*/  
            if(find(i))   
                count++;  /*若找到i的匹配边，则计数器加一*/     
        }   
        printf("%d/n",count);   
    }   
    return 0;   
}