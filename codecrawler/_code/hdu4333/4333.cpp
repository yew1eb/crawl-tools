#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 999999999
using namespace std;

const int MAX=100000+10;
char s[MAX*2];
int next[MAX];

void get_next(char *a,int len){
	int i=-1,j=0;
	next[0]=-1;
	while(j<len){
		if(i == -1 || a[i] == a[j])next[++j]=++i;
		else i=next[i];
	}
}

void get_extend(char *a,int len){
	int k=0,i=1;
	next[0]=len;
	while(k+1<len && a[k] == a[k+1])++k;
	next[1]=k;
	k=1;
	while(++i<len/2){//只需要求到原串的长度即可 
		int maxr=k+next[k]-1;
		next[i]=min(next[i-k],max(maxr-i+1,0));
		while(i+next[i]<len && a[next[i]] == a[i+next[i]])++next[i];
		if(i+next[i]>k+next[k])k=i;
	}
}

int main(){
	int t,num=0;
	cin>>t;
	while(t--){
		scanf("%s",s);
		int len=strlen(s);
		get_next(s,len);
		int temp=len%(len-next[len]) == 0?len/(len-next[len]):1;//求循环节循环了几次 
		for(int i=0;i<=len;++i)s[i+len]=s[i];
		get_extend(s,len+len);
		int a=0,b=0,c=0;
		for(int i=0;i<len;++i){
			if(next[i]>=len)++b;//表示等于原串的 
			else if(s[next[i]]<s[i+next[i]])++c;//表示大于原串的
			else ++a;//表示小于原串的 
		}
		cout<<"Case "<<++num<<": "<<a/temp<<' '<<b/temp<<' '<<c/temp<<endl;
	}
	return 0;
}