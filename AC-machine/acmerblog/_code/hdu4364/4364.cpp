#include <iostream>
#include <cstdio>
using namespace std;
int mat[4][4]={2,3,1,1,1,2,3,1,1,1,2,3,3,1,1,2};
int state[4][4],ans[4][4];

void work()
{
    int i,j,k,temp1,temp2[4];
    for(i=0;i<4;i++)
    for(j=0;j<4;j++)
    {
        for(k=0;k<4;k++)
        {
            if(mat[i][k]==2)
            {
                temp1=state[k][j]<<1;
                if(temp1>0xFF)
                temp1^=0x1B;
                if(temp1>0xFF)
                temp1%=(0xFF+1);
            }
            else if(mat[i][k]==3)
            {
                temp1=state[k][j]<<1;
                if(temp1>0xFF)
                temp1^=0x1B;
                temp1^=state[k][j];
                if(temp1>0xFF)
                temp1%=(0xFF+1);
            }
            else
            temp1=state[k][j];
            temp2[k]=temp1;
        }
        for(k=1;k<4;k++)
        temp2[0]^=temp2[k];
        ans[i][j]=temp2[0];
    }
}

int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        scanf("%X",&state[i][j]);
        work();
        for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        if(j!=3)
        printf("%02X ",ans[i][j]);
        else
        printf("%02X\n",ans[i][j]);
        if(t!=0)
        printf("\n");
    }
    return 0;
}
