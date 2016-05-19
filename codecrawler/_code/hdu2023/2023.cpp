#include <iostream>
using namespace std;
int main()
{
	int n,m;
	float sum=0;
	float a[50][5];
	float obj[5];//每门课程的平均成绩 
	int num=0,cont_obj=0,cont_hum=0;
	while(cin>>n>>m){
		num=0,sum=0;
		cont_obj=0,cont_hum=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
			}
		}
		//输出n个学生的平均成绩 
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				sum=sum+a[i][j];
			}
			if(i!=0) cout<<" ";
			printf("%.2f",sum/m);
			sum=0;
		}
		cout<<endl;
		//m门课的平均成绩
		for(int j=0;j<m;j++){
			for(int i=0;i<n;i++){
				sum=sum+a[i][j];
			}
			if(j!=0) cout<<" ";
			printf("%.2f",sum/n);
			obj[num++]=sum/n; 
			sum=0;
		}
		cout<<endl;
		//各科成绩均大于等于平均成绩的学生数量
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				if(a[i][j]>=obj[j]) cont_obj++;
			if(cont_obj==m) cont_hum++;
			cont_obj=0;
		}
		cout<<cont_hum<<endl<<endl;
	}
	return 0;
}