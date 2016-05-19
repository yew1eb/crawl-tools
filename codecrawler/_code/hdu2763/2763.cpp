#include<iostream>
#include<cstring>
using namespace std;
int d[55];
__int64 i,len,j;
__int64 f(int r){
	memset(d,0,sizeof(d));
	len=1;
	d[0]=1;
	for(i=1;;i++){
	  for(j=0;j<len;j++)d[j]*=2;
	    for(j=0;j<len;j++)
	    {
		  if(d[j]>9)d[j+1]+=d[j]/10;
		  d[j]=d[j]%10;
	    }
	    if(d[len])len++;
	    if(len>50)len=51; 
	  for(j=0;j<len;j++)
	    if(d[j]==1||d[j]==2) continue;
	    else break;
	  if(j>=r)return i;
	  else continue;
	}
}
int main(){
	int n,r,le=1;
    cin>>n;
	while(n--){
		cin>>r;
		cout<<le++<<' '<<r<<' '<<f(r)<<endl;
	}
	return 0;
}