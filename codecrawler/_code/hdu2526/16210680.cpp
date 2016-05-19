#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char c[2][50];    
int T,val,M;
int main()
{
    char a[4],b[9];    
    for(int i=0;i<2;i++) c[i][0]='0';
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&M);
        for(int i=1;i<=8;i++)
        {
            scanf("%s",a);
            int num=(a[0]-'0')*4+(a[1]-'0')*2+a[2]-'0';
            scanf("%d",&val);
            b[num] = '0' + val;
        }
        scanf("%s",&c[0][1]);
        int len=strlen(&c[0][1]);
        for(int i=0;i<2;i++) c[i][len+1]='0';
        for(int j=0;j<M;j++)
        {
            for(int i=0;i<len;i++)
            {
                int num=(c[j%2][i]-'0')*4+(c[j%2][i+1]-'0')*2+c[j%2][i+2]-'0';
                c[(j+1)%2][i+1]=b[num];
                printf("%c",c[j%2][i+1]);
            }    
            printf("\n");
        }    
    }
    return 0;
}
