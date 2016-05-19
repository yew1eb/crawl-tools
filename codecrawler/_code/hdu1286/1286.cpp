#include<stdio.h>
#include<string.h>
int phi[33000];
int gphi()
{
    int i,j;
    memset(phi,0,sizeof(phi));
    phi[1]=1;//与1互质的只有他本身一个 
    for(i=2;i<33000;i++)
       if(!phi[i])//因为在计算中j是以i在叠加的，所以所有被叠加到的数都是合数，所以当i
       //依次增加到那个数的时候发现那个数已经被赋值，表明那是个合数，无须再算，所以这里如果已经被赋值过了，就不能再进行计算了 
       //反之如果没被赋值，说明这个数肯定不是之前数的倍数，也就是i是质数，可以进行下面phi的计算 
           for(j=i;j<33000;j+=i)//这里重要的筛法，j+=i，表示以下出现的数，i都是j的因子 
           {
              if(!phi[j])phi[j]=j;//未赋值的时候，要先赋值为其本身 
              phi[j]=phi[j]/i*(i-1);//phi[j]=phi[j]*(1-1/i)会出现错误，因为1/i都变成0了 
           }
}
int main()
{
    int cn,n;
    gphi();
    scanf("%d",&cn);
    while(cn--&&scanf("%d",&n))
    printf("%d\n",phi[n]);
    return 0;
}