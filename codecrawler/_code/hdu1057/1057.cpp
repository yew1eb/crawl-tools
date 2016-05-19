#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
int mat[20][20],tar[20][20],tar2[20][20];
char transtar[20][20];
int pxvalue[16];

int main()
{
	int testcase;
	cin>>testcase;
	for(int s=1;s<=testcase;s++)
	{
		memset(mat,0,sizeof(mat));
		memset(tar,0,sizeof(tar));
		memset(pxvalue,0,sizeof(pxvalue));
		int day,tmp,tmpx,tmpy;
		cin>>day;
		
		for(int i=0;i<16;i++)
		{
			cin>>pxvalue[i];
		}
		
		for(int i=0;i<20;i++)
		{
			for(int j=0;j<20;j++)
			{
				cin>>mat[i][j];
			}
		}
		
		for(int k=0;k<day;k++)
		{
			for(int i=0;i<20;i++)
			{
				for(int j=0;j<20;j++)
				{
					tmp=mat[i][j];
					for(int z=0;z<4;z++)
					{
						tmpx=i+dir[z][0];
						tmpy=j+dir[z][1];
						if(tmpx>=0 && tmpx<20 && tmpy>=0 && tmpy<20)
							tmp+=mat[tmpx][tmpy];
					}
	    		
                    tar[i][j] = mat[i][j]+pxvalue[tmp];   
					
					if(tar[i][j]>3)
						tar[i][j]=3;
					if(tar[i][j]<0)
						tar[i][j]=0;
				}
			}
			memcpy(mat,tar,sizeof(mat));    //滚动更新，重中之重 
		}
		
		for(int i=0;i<20;i++)
		{
			for(int j=0;j<20;j++)
			{
				if(tar[i][j]==0)
				{
					transtar[i][j]='.';
				}
				else if(tar[i][j]==1)
				{
					transtar[i][j]='!';
				}
				else if(tar[i][j]==2)
				{
					transtar[i][j]='X';
				}
				else if(tar[i][j]==3)
					transtar[i][j]='#';
			}
		}
		
		for(int i=0;i<20;i++)
		{
			for(int j=0;j<20;j++)
			{
				cout<<transtar[i][j];
			}
			cout<<endl;
		}
		if(s!=testcase)
			cout<<endl;
		
	}
	return 0;
}