#include<stdio.h>
int main()
{
    int map[25][25];
    int i,j,n;
    int count;
    int x,y;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {  
            for(j=1;j<=n;j++)
            {
                map[i][j]=0;
            }
            
        }
        count=1;
        i=1;j=n/2+1;
        
        map[1][n/2+1]=1;
        
        while(count!=(n*n))
        {
            
            count++;
            
            x=i-1;y=j+1;
            
            if(x<1) x=n;
            if(y>n) y=1;
            
            if(map[x][y]!=0) 
            {
                i+=1; 
                map[i][j]=count;
                i=i;j=j;
            }
            else
            { 
                map[x][y]=count; i=x;j=y;
            }
            
        }
        for(i=1;i<=n;i++)
        {  
            for(j=1;j<=n;j++)
            {
                printf("%4d",map[i][j]);
            }
            printf("\n");

        }
    }
    return 0;
}
