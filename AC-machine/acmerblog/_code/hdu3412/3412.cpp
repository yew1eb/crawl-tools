#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxx=25;

struct Stu{
	string name;
	int sco;
};

Stu stu[maxx];
string name[maxx];
int yi[maxx][305],yihwi[305];
int st;

void init(){
	st=0;
	memset(yi,0,sizeof(yi));
	memset(yihwi,0,sizeof(yihwi));
}

int main(){
	int T,n,i,j,k;
    scanf("%d",&T);
	while(T--){
		init();
		scanf("%d",&n);
		for(i=0;i<n;i++){
			cin>>stu[i].name>>stu[i].sco;
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i==j)continue;
				yi[i][stu[i].sco+stu[j].sco]++;
				for(k=0;k<n;k++){
					if(i==k || j==k)continue;
					yi[i][stu[i].sco+stu[j].sco+stu[k].sco]++;
				}
			}
		}
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				yihwi[stu[i].sco+stu[j].sco]++;
				for(k=j+1;k<n;k++){
					yihwi[stu[i].sco+stu[j].sco+stu[k].sco]++;
				}
			}
		}
		for(i=0;i<n;i++){
			if(yihwi[stu[i].sco] && yihwi[stu[i].sco]>yi[i][stu[i].sco]){
				name[st++]=stu[i].name;
			}
		}
		sort(name,name+st);
		printf("%d\n",st);
		for(i=0;i<st;i++){
			cout<<name[i]<<endl;
		}
	}
	return 0;
}