#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

struct people
{
	int age;
	string name;
}p[100];

bool cmp(struct people a,struct people b)
{
	if(a.age!=b.age)
		return a.age>b.age;
	else
		return a.name<b.name;
}

int n;
string f[100],c[100];
int year[100];

int main()
{
	int t,count=1;
	cin>>t;
	int k;

	while(t--)
	{
		cin>>n;

		p[0].name="Ted";
		p[0].age=100;
		k=1;

		for(int i=0;i<n;i++)
			cin>>f[i]>>c[i]>>year[i];

		for(i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(f[j]==p[i].name)
				{
					p[k].name=c[j];
					p[k].age=p[i].age-year[j];
					k++;
				}
			}
		}
		sort(p,p+n+1,cmp);

		cout<<"DATASET "<<count++<<endl;
		for(i=1;i<=n;i++)
		{
			cout<<p[i].name<<" "<<p[i].age<<endl;
		}
	}
	return 0;
}