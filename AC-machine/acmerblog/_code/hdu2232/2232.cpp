#include <iostream>

using namespace std;

int B[4][4]={						//n=1时各位置上的机器人到达各位置的方案数
				{1,1,0,1},
				{1,1,1,0},
				{0,1,1,1},
				{1,0,1,1}
			};

struct In{
	int A[4][4];
};

In a,b;               //a,b分别用来记录1步、2步……n步的方案数
void f(int n)		  //先把前1步求出给a,再由a求出后1步时的方案数后用b记，如此递归地求出n步
{
	int i,j;
	if(n==0)
	{
		for(i=0; i<4; i++)
		{
			for(j=0; j<4; j++)
			{
				b.A[i][j]=B[i][j];
			}
		}
	}
	else
	{
		f(n-1);
		for(i=0; i<4; i++)
		{
			for(j=0; j<4; j++)
			{
				a.A[i][j]=b.A[i][j];
				a.A[i][j]%=9937;			//数据过大，则对其取模
			}
		}
		if(n==1)
			return ;
		for(i=0; i<4; i++)        
		{
			b.A[i][0]=a.A[i][0]+a.A[i][1]+a.A[i][3];
			b.A[i][1]=a.A[i][0]+a.A[i][2]+a.A[i][1];
			b.A[i][2]=a.A[i][1]+a.A[i][2]+a.A[i][3];
			b.A[i][3]=a.A[i][0]+a.A[i][2]+a.A[i][3];
		}
	}
}

void Solve()
{
	int i,j,e,f,sum=0;
	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			for(e=0; e<4; e++)
			{
				for(f=0; f<4; f++)
				{
					if(i==j || i==e || i==f || j==e || j==f || e==f)    //每个位置上都得有一个机器人
						continue;
					sum+=((((((b.A[0][i]*b.A[1][j])%9937)*b.A[2][e])%9937)*b.A[3][f])%9937)%9937;   //防止越界，必须每两个方案相乘就得取模
					sum%=9937;
				}
			}
		}
	}
	cout<<sum<<endl;
}

int main()
{
	int n;
	while(cin>>n)
	{
		f(n);
		Solve();
	}
	return 0;
}