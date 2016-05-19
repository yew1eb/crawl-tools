#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

class Mat
{
public:
    int mat[15][15];
};

int n;     //维度,即矩阵A的行数
int MOD=9973;//好多问题要求给出取余之后的数字
Mat E;

void initE()
{
	for(int i=0;i<15;i++)
		E.mat[i][i]=1;
}

Mat operator*(Mat a,Mat b)
{
    int i,j,k;
    Mat c;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
       		c.mat[i][j] = 0;
       		for (k=0;k<n;k++)
       		{
                	c.mat[i][j]+=(a.mat[i][k]*b.mat[k][j]);
       		}
       		c.mat[i][j]%=MOD;
        }
    }
    return c;
}

Mat operator+(Mat a,Mat b)
{
    Mat c;
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            c.mat[i][j] = a.mat[i][j]+b.mat[i][j];
        c.mat[i][j]%=9973;
    }
    return c;
}

Mat operator^(Mat a,int x)  
{  
     Mat p = E,q = a;  
     while (x>=1)  
     {  
         if(x%2==1)  
             p = p*q;  
         x/=2;  
         q = q*q;  
     }  
     return p;  
}

Mat solve(Mat a,int p)  
{  
     if(p==1)  
         return a;
     else if(p&1)  
         return (a^p)+solve(a,p-1);  
     else  
         return ((a^(p>>1))+E)*solve(a,p>>1);  
}  


int main()
{
	int testcase;
	cin>>testcase;
	Mat at,bt;
	int res;
	int kp;
	while(testcase--)
	{	
		res=0;
		initE();
		memset(at.mat,0,sizeof(at.mat));
		memset(bt.mat,0,sizeof(bt.mat));
		cin>>n>>kp;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>at.mat[i][j];
			}
		}
		
		bt=at^kp;
		
		for(int i=0;i<n;i++)
		{
			res+=bt.mat[i][i];
		}
		cout<<res%9973<<endl;
	}
	return 0;
}