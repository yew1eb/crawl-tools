#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=50000+10;
char s1[MAX*2],s2[MAX];
int next[MAX*2];

void get_next(char *a){
	int i=-1,j=0,len=strlen(a);
	next[0]=-1;
	while(j<len){
		if(i == -1 || a[i] == a[j])next[++j]=++i;
		else i=next[i];
	}
	return;
}

int main(){
	while(cin>>s1>>s2){
		int lena=strlen(s1),lenb=strlen(s2),len=lena+lenb;
		strcat(s1,s2);
		get_next(s1);
		while(next[len]>lena || next[len]>lenb)len=next[len];
		len=next[len];
		for(int i=0;i<len;++i)cout<<s1[i];
		if(len)cout<<' ';
		cout<<len<<endl; 
	}
	return 0;
}