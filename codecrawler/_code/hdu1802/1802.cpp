#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
struct node{
	int row,col;
}a[30];
int ans;
int main(){
	int i,j,n;
	cin>>n;
	char c;
	char s[1000];
	node x,y;
	while(n--){
		cin>>c>>i>>j;
		a[c-'A'].row=i;
		a[c-'A'].col=j;
	}
	while(scanf("%s",s)!=EOF){
		stack<node>sk;
		ans=0;
		for(i=0;s[i];i++){
			if(s[i]==')'){
				y=sk.top();sk.pop();
				x=sk.top();sk.pop();
				//cout<<x.row<<" "<<x.col<<"|"<<y.row<<" "<<y.col<<endl;
				if(x.col!=y.row){ans=-1;break;}
				ans+=x.row*x.col*y.col;
				x.col=y.col;
				sk.push(x);
			}else if(s[i]=='('){}
			else{
				sk.push(a[s[i]-'A']);
			}
		}
		if(ans<0)cout<<"error"<<endl;
		else cout<<ans<<endl;
	}
return 0;
}