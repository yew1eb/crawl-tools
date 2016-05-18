//Memory Time 
//584K   63MS 

#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

class coordinate
{
public:
	double x,y;
}point[201];

double path[201][201];   //两点间的权值

int main(void)
{
	int i,j,k;

	int cases=1;
	while(cases)
	{
		/*Read in*/

		int n;   //numbers of stones;
		cin>>n;
		if(!n)break;

		for(i=1;i<=n;i++)
			cin>>point[i].x>>point[i].y;

		/*Compute the weights of any two points*/

		for(i=1;i<=n-1;i++)
			for(j=i+1;j<=n;j++)
			{
				double x2=point[i].x-point[j].x;
				double y2=point[i].y-point[j].y;
				path[i][j]=path[j][i]=sqrt(x2*x2+y2*y2);  //双向性
			}

		/*Floyd Algorithm*/

		for(k=1;k<=n;k++)    //k点是第3点
			for(i=1;i<=n-1;i++)    //主要针对由i到j的松弛,最终任意两点间的权值都会被分别松弛为最大跳的最小（但每个两点的最小不一定相同）
				for(j=i+1;j<=n;j++)
					if(path[i][k]<path[i][j] && path[k][j]<path[i][j])    //当边ik,kj的权值都小于ij时，则走i->k->j路线，否则走i->j路线
						if(path[i][k]<path[k][j])               //当走i->k->j路线时，选择max{ik,kj},只有选择最大跳才能保证连通
							path[i][j]=path[j][i]=path[k][j];
						else
							path[i][j]=path[j][i]=path[i][k];

		cout<<"Scenario #"<<cases++<<endl;
		cout<<fixed<<setprecision(3)<<"Frog Distance = "<<path[1][2]<<endl;
		//fixed用固定的小数点位数来显示浮点数（包括小数位全为0)
		//setprecision(3)设置小数位数为3
		cout<<endl;
	}
	return 0;
}