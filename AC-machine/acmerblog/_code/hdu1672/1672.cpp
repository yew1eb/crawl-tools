#include<iostream>
using namespace std;
#define M 10002

int arr[M][2];
bool used[M];
int link[M];//link[i] represents the point on the i-th position

int ans,t,n,m;

bool dfs(int a)
{
	for(int i=0; i<2; i++)
	{
		int j = arr[a][i];
		if(!used[j])
		{
			used[j] = true;
			if(link[j]==-1||dfs(link[j]))
			{
				link[j] = a;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int i;
	cin>>t;
	while(t--)
	{
		memset(link,-1,sizeof(link));
		scanf("%d%d",&m,&n);
		for(i=0; i<m; i++)
			scanf("%d%d",&arr[i][0],&arr[i][1]);
		ans = 0;
		for(i=0; i<m; i++)
		{
			memset(used,false,sizeof(used));
			if(!dfs(i))
				break;
		}
		if(i==m)
			cout<<"successful hashing"<<endl;
		else cout<<"rehash necessary"<<endl;
	}
	return 0;
}