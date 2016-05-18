#include<cstdio>
#include<cstring>

const int N = 100005;
int n,m;

int main() {
	int t;
	int cas = 1;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&m,&n);
		printf("Case #%d: ",cas++);
		if(m == 1) {
			for(int i = 0; i < n; i++)
				printf("a");
			printf("\n");
		}else if(m == 2) {
			if(n == 1)
				printf("a");
			else if(n == 2)
				printf("ab");
			else if(n == 3)
				printf("aab");
			else if(n == 4)
				printf("aabb");
			else if(n == 5)
				printf("aaaba");
			else if(n == 6)
				printf("aaabab");
			else if(n == 7)
				printf("aaababb");
			else if(n == 8)
				printf("aaababbb");
			else{
				char temp[] = {"aababb"};
				printf("aa");
				int mod = (n - 2) % 6;
				int c = (n - 2) / 6;
				for(int i = 0; i < c; i++) {
					printf("%s",temp);
				}
				if(mod <= 4) {
					for(int i = 1; i <= mod; i++) 
						printf("a");
				}
				if(mod == 5)
					printf("aaaab");
			}
			printf("\n");
		}else {
			for(int i = 0; i < n; i++)
				printf("%c",'a' + (i % 3));
			printf("\n");
		}
	}
}