#include<iostream>
using namespace std ;
const int N = 40 ;
struct male
{
     int f,rev[N],tag;
}m[N];
struct female
{
     int tag,temp,val,wait[N];   
}f[N];
int n , t , k , mf[N][N] , fm[N][N];    
char ch[N]; 
bool ok()
{
    for(int i=1;i<=26;i++)
        if(m[i].f==0&&m[i].tag>0) return true ;
    return false ;
} 
int main()
{
    int T ;
    scanf("%d",&T) ;
    while(T--)
    { 
    scanf("%d",&n); 
    for(int i=1;i<=26;i++)
        f[i].tag=0,m[i].tag=0;  
    for(int i=1;i<=n;i++)
    {
        scanf("%s",&ch);
        t = ch[0]-'a' + 1 ;
        m[t].f=0 , m[t].tag=t;
        memset(m[t].rev,0,sizeof(m[t].rev));       
    } 
    for(int i=1;i<=n;i++)
    {
        scanf("%s",&ch);
        t = ch[0]-'A' + 1 ;
        f[t].tag = t ;
        f[t].temp = 0 ;
        f[t].val = 30 ;
        memset(f[t].wait,0,sizeof(f[t].wait));      
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%s",&ch);
        t = ch[0] - 'a' + 1 ;
        for(int j=2;j<=n+1;j++)
            mf[t][j-1] = ch[j] -'A' + 1 ;        
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%s",&ch);
        t = ch[0] - 'A' + 1 ;
        for(int j=2;j<=n+1;j++)
            fm[t][j-1] = ch[j] -'a' + 1 ;        
    }
    while(ok())
    {
        for(int i=1;i<=26;i++)
        {
            if(m[i].f==0&&m[i].tag>0)
            {
                  for(int j=1;j<=n;j++)
                  {
                       t = mf[i][j] ;  
                       if(m[i].rev[t]==0)
                       {
                             m[i].rev[t] = 1 ;
                             m[i].f = 1 ;
                             k = ++f[t].wait[0] ;    
                             f[t].wait[k] = i ;   
                             break;
                       }             
                  }    
            }   
        }
        for(int i=1;i<=26;i++)
        {
            if(f[i].tag>0)
            {
                for(int j=1;j<=f[i].wait[0];j++)
                {
                      t = f[i].wait[j] ;
                      for(k=1;k<=n;k++)
                      {
                          if(fm[i][k]==t)  break; 
                      } 
                      if(f[i].val>k)
                      {
                          m[f[i].temp].f = 0 ;
                          f[i].temp = t ;  
                          f[i].val = k ;
                      }
                      else m[t].f = 0 ;  
                }                
                f[i].wait[0] = 0 ;
            } 
        }
    }  
    int out[N]; 
    memset(out,0,sizeof(out));
    for(int i=1;i<=26;i++)
    {
          if(f[i].tag>0)
          {
               int j = f[i].temp ;
               out[j] = i ; 
          }
    }  
    for(int i=1;i<=26;