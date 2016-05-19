#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int r,c; //R行C列
//思路，先遍历第一行的点击可能--最多有2^16种
//然后接下来的行一定要点击上一行为*的点
int dir[5][2] = 
{
    0,0,
    0,1,
    1,0,
    -1,0,
    0,-1
};
struct Node
{
    char g[17][17];
    int b[17];
};
Node start;
Node temp;
int counter;

bool fine(int x)
{
    int i,j,k;
    int change;
    temp = start;
    for (i=0;i<r;i++)
    {
        if(i==0)
            change = x;
        else
            change = temp.b[i-1];
        temp.b[i] ^= change; //对原始行,进行原始操作，即中心点
        temp.b[i] ^= change>>1; //右边点
        temp.b[i] ^= (change<<1)&((1<<c)-1); //左边点，要去掉第一个可能超范围的“1”
        temp.b[i+1] ^= change;
        for(j=0;j<c;j++) //计算每一个的change数
        {
            if ((change >> j)&1)
                counter++;
        }
    }
    if (temp.b[r-1])
            return 0;
    return 1;
}
int main()
{
    int i,j,k,n,m,t;        
    while (scanf("%d %d",&r,&c)!=EOF)
    {
        memset(start.b,0,sizeof(start.b));
        memset(temp.b,0,sizeof(temp.b));
        if(r == 0 && c == 0)
            break;
        for (i=0;i<r;i++)
        {
            scanf ("%s",start.g[i]);
            for (j=0;j<c;j++)
            {
                if (start.g[i][j] == 'X')
                    start.b[i] = start.b[i] | (1<<(c-1-j));
            }
        }
        //----------------------------
        //for (i=0;i<r;i++)
        //    printf("%d/n",start.b[i]);
        //先遍历第一行的点击可能--最多有2^16种
        int mincount=-1;
        for (i=0;i<pow(2,c);i++) //用二进位来确定点哪个点0~(2^c-1)
        {
            counter = 0;
            if(fine(i)) //如果可以得到结果，那记录一下
            {
                if (counter < mincount || mincount == -1) //如果步数小，或求出来一个
                    mincount = counter;
            }
        }
        if (mincount == -1)
        {
            printf("Damaged billboard./n");
        }
        else
            printf("You have to tap %d tiles./n",mincount);
        memset(start.g,NULL,sizeof(start.g));
        memset(temp.g,NULL,sizeof(temp.g));
    }
    return 0;
}