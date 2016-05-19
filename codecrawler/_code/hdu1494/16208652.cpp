#include<iostream>
using namespace std;
const int inf=0x7fffffff;
int L,N,temp;        
int dp[128][15];
int a[128],b[128];
int dn[128][15];
int need[15][15];
inline void dpinit()
{
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<=L;j++)
        {               
           dp[j][i]=-1;
        }
    }
    return ;
}
inline void dpninit()
{
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<=N;j++)
        {
            dn[j][i]=inf;
        }
    }
}
void dpstart(int t)
{
    dpinit();
    dp[0][t]=0;
    for(int i=1;i<=L;i++)
    {
        if( -1 != dp[i-1][5] )
        {
            dp[i][0]=dp[i-1][5]+b[i];
        }
        for(int j=1;j<15;j++)
        {
            if( -1 != dp[i-1][j-1] )
            {
                dp[i][j]=dp[i-1][j-1]+a[i];  
            }    
            if( j < 10 && -1 != dp[i-1][j+5] )
            {
                temp = dp[i-1][j+5]+b[i];
                if(-1 == dp[i][j]) 
                {
                    dp[i][j]=temp;
                }                
                else
                {
                    if(temp < dp[i][j])
                    {
                        dp[i][j]=temp;
                    }       
                }                  
            }
        }
        if(-1 != dp[i-1][14])
        {
            temp=dp[i-1][14]+a[i];
            if(-1 == dp[i][10])
            {
                dp[i][10]=temp;
            }
            else
            {
                if(temp < dp[i][10])
                {
                    dp[i][10]=temp;
                }
            }
        }   
    }       
    for(int i=0;i<15;i++)
    {
        if(-1 == dp[L][i])
        {
            need[t][i]=inf;   
        }
        else
        {
            need[t][i]=dp[L][i];
        }
    }
    return ;
}
void find_the_min (int x,int y)
{
    for(int i=0;i<15;i++)
    {   
        if(need[y][i]==inf)
        {
            continue;
        }
        else
        {
            temp=dn[x][y]+need[y][i];
            if(temp < dn[x+1][i] )
            {
                dn[x+1][i]=temp;
            }
        }
    }                
    return ;
}
void n_dpstart()
{       
    dpninit();
    dn[0][0]=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(inf != dn[i][j])
            {
                find_the_min(i,j);    
            }            
        }
    }  
    temp=inf;
    for(int i=0;i<15;i++)
    {
        if(dn[N][i] < temp)
        {
            temp=dn[N][i];
        }    
    }        
    cout<<temp<<endl;  
}
int main()
{
    while(cin>>L>>N)
    {
        for(int i=1;i<=L;i++)   
        {
            cin>>a[i];
        }  
        for(int i=1;i<=L;i++)
        {
            cin>>b[i];
        }
        for(int t=0;t<15;t++)    
        {
            dpstart(t);    
        } 
        n_dpstart();
    }    
    return 0;   
}
