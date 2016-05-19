#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 10001

int V[max],E[max];
void solve()
{
    int i;
    memset(V,0,sizeof(V));
    memset(E,0,sizeof(E));
    E[1]=V[1]=3;
    for(i=2;i<max;i++)
        E[i]=E[i-1]+(4*i-3)*3;
    
    for(i=2;i<max;i++)
        V[i]=V[i-1]+(2*i-1)*3;        
}
int main()
{
    int T,n;
    solve();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);    
        printf("%d\n",E[n]-V[n]+2);
    }
    return 0;
}
