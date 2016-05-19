#include <iostream>
using namespace std;

void transform(int r,int n){
	if (n==0)
		return ;
	int b,c;
	b=n/r;
	c=n%r;
	transform(r,b);
	if (c>=10)
		printf("%c",c+55);
	else printf("%d",c);
}	

int main(){
	int n,m;
	while (scanf("%d%d",&n,&m)!=EOF){
		if (n==0)
			printf("0");
		else if (n<0){
			printf("-");
			transform(m,-n);
		}
		else transform(m,n);
		putchar(10);
	}
	return 0;
}