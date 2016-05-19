//1398 16:07
#include<iostream>
using namespace std;
const int iNum=8005;
int c1[iNum],c2[iNum];
int main()
{
	int n,i,j,k,sum;
	int elem[3]={1,2,5};
	int a[3];
	while (cin>>a[0]>>a[1]>>a[2]){
			if(a[0]==0&&a[1]==0&&a[2]==0)
				break;
			if(a[0]==0){
				printf("1\n");
				continue;
			}
			sum=a[0]+a[1]*2+a[2]*5;//有可能达到的指数的上限
			for (i=0;i<=iNum;i++){//c1保存第1个括号，c2总是保存一趟运算的结果（每一对括号合并成一个括号）  
				c1[i]=0;
				c2[i]=0; 
			} 

			for (i=0;i<=a[0];i++)//此题1元硬币只有a[0]个
				c1[i]=1;  
			for (i=1;i<=2;i++){//n个括号要进行n-1趟运算				
				for (j=0;j<=sum;j++)//j是第一个括号的指数，虽然第1趟时j<=a[0]，但其它趟可能超过，故上限为sum  
					for (k=0;k*elem[i]+j<=iNum&&k<=a[i];k++){//k是第i种硬币的个数，k*elem[i]才是第二个括号的指数  
						c2[j+k*elem[i]]+=c1[j];//第二个括号的系数都是1，隐含了c2[j+k]+=c1[j]*1; 
					} 
				for (j=0;j<=iNum;j++){//c1保存第1个括号，要保存成前一趟运算的结果
					c1[j]=c2[j];
					c2[j]=0;
				}  
			}  
			for(i=0;i<=iNum;i++){
				if(c1[i]==0){
					printf("%d\n",i);
					break;
				}

			}
	}
	return 0;
}