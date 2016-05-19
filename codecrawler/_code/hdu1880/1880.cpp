#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAX=210000;
const int mod=100007;
struct Node{
	Node* ne;
	char st[81];
}hash[MAX],*h[mod],*cur;
unsigned int BKDHash(char* s){
	unsigned int seed=131;
	unsigned int ret=0;
	
	while(*s){
		ret=ret*seed+*s++;
	}
	
	return (ret&0x7FFFFFFF)%mod;
}
int getId(char* s){
	int code=BKDHash(s);
	Node* ptr=h[code];
	
	while(ptr){
		if(strcmp(ptr->st,s)==0){
			return ptr-hash;
		}else{
			ptr=ptr->ne;
		}
	}
	strcpy(cur->st,s);
	cur->ne=h[code];
	h[code]=cur++;
	return cur-hash-1;
}
int find(char* s){
	int code=BKDHash(s);
	Node* ptr=h[code];
	
	while(ptr){
		if(strcmp(ptr->st,s)==0){
			return ptr-hash;
		}else{
			ptr=ptr->ne;
		}
	}
	return -1;
}
int main(){
	char s[100],*p;
	int id,n;
	
	cur=hash;
	memset(h,0,sizeof(h));
	while(scanf("%s",s),s[0]!='@'){
		getId(s);
		getchar();
		gets(s);
		getId(s);
	}
	scanf("%d",&n);
	gets(s);
	while(n--){
		gets(s);
		id=find(s);
		if(id==-1){
			puts("what?");
		}else{
			p=hash[id^1].st;
			if(p[0]!='['){
				puts(p);
			}else{
				p++;
				while(*p!=']'){
					putchar(*p++);
				}
				puts("");
			}
		}
	}
	
	return 0;
}