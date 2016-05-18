#include <cstdio>
#include <algorithm>
using namespace std;
typedef __int64 LL;
const int maxn=505;
LL a[maxn],b[maxn],c[maxn],ab[maxn*maxn];
int cas=1,n,m,l,ks,k,low,high,mid;
bool findk(int x){
	low=0,high=l*n;
	while(high-low>1){
		int mid=(high+low)/2;
		if(ab[mid]==x)return true;
		if(ab[mid]>x)high=mid;
		else low=mid;	
	}
	return false;
}
int main(){
	while(scanf("%d%d%d",&l,&n,&m)!=EOF){
		for(int i=0;i<l;i++)scanf("%I64d",&a[i]);
		for(int i=0;i<n;i++)scanf("%I64d",&b[i]);
		for(int i=0;i<m;i++)scanf("%I64d",&c[i]);
		
		//储存a+b的结果并排序 
		for(int i=0;i<l;i++)
			for(int j=0;j<n;j++)
				ab[i*n+j]=a[i]+b[j];
		sort(ab,ab+l*n);
		
		printf("Case %d:\n",cas++);
		scanf("%d",&ks);
		while(ks--){
			scanf("%d",&k);
			int find=0;
			//在[a+b]中查找有没有等于c-k的值 
			for(int i=0;i<m;i++){
				if(findk(k-c[i])){find=1;break;}				
			}
			printf(find?"YES\n":"NO\n");
		}
					
	}	
	
}