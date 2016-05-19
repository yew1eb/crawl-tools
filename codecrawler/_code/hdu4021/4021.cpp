#include<stdio.h>
#include<algorithm>
using namespace std;
int n,q[]={0,1,3,2,8,17,23,22,24},e[]={0,4,4,7,7,18,18,21,21};
int abs(int x){
	return x>0?x:(-x);
}
int main(){
	scanf("%d",&n);
	while(n--){
		int begin[33],end[33];
		for(int i=1;i<=24;i++)
			scanf("%d",&begin[i]);
		for(int i=1;i<=24;i++)
			scanf("%d",&end[i]);
		for(int i=1;i<=8;i++){
			if(begin[q[i]]==0)
				swap(begin[q[i]],begin[e[i]]);
			if(end[q[i]]==0)
				swap(end[q[i]],end[e[i]]);
		}
		bool flag=0;
		for(int i=1;i<=8;i++){
			if(begin[q[i]]!=end[q[i]]){
				flag=1;
				break;
			}
		}
		if(flag){
            printf("Y\n");
			continue;
		}
		int n1=0,n2=0,m_pos1=0,m_pos2=0;
		int a[33],b[33],sum1=0,sum2=0;
		for(int i=1;i<=24;i++){
			flag=0;
			for(int j=1;j<=8;j++)
				if(i==q[j])
					flag=1;
			if(flag)continue;
			a[sum1++]=begin[i];
		}
        for(int i=1;i<=24;i++){
			flag=0;
			for(int j=1;j<=8;j++)
				if(i==q[j])
					flag=1;
			if(flag)continue;
			b[sum2++]=end[i];
		}
		for(int i=1;i<sum1;i++){
			if(a[i]==0)
				m_pos1=i;
			else{
				for(int j=0;j<i;j++){
					if(a[i]<a[j])
					    n1++;
				}
			}
		}
		for(int i=1;i<sum2;i++){
			if(b[i]==0)
			    m_pos2=i;
			else{
				for(int j=0;j<i;j++){
					if(b[i]<b[j])
					    n2++;
				}
			}
		}
		int it=abs(m_pos1/4-m_pos2/4);
		if(abs(it+n1-n2)%2==0)
			printf("N\n");
		else
			printf("Y\n");
	}
	return 0;
}
