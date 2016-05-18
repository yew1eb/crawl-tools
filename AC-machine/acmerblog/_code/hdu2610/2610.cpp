#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
const int maxn = 10010;
const int maxm = 1100;
struct node {
	int value;
	int index;
};
node in[maxm];
node ans[maxn];//result;
int n, p;
int cnt = 0;
bool f[maxm];

void print(int len) {
	for(int i = 1; i < len; i++) printf("%d ", ans[i].value);
	printf("%d\n", ans[len].value);
	cnt++;
	if(cnt==p) return;
}

void init() {
    int i, j;
    f[1] = true;
    for(i = 1; i <= n; i++) {
        for(j = 1; j < i; j++) {
            if(in[j].value == in[i].value) {
                break;
            }
        }
        if(j==i) {
            printf("%d\n", in[i].value);
            cnt++;
            if(cnt==p) return;
        }
    }
}

void dfs(int lev, int len)
{
	if(cnt>=p) return;
	if(lev==0) {// process the repeated root
        int i, j;
		for(i = 1; i <= n; i++) {
			for(j = 1; j < i; j++){
				if(in[j].value == in[i].value){
                    break;
				}
			}
            if(j==i) {
                ans[1].value = in[i].value;
                ans[1].index = in[i].index;
                dfs(lev+1, len);
            }
		}
	}
	if(lev==len) {
	    f[len] = true;
		print(len);
		return;
	}
	if(lev>=1) {
		for(int i = ans[lev].index+1; i <= n; i++) {
			if(in[i].value >= ans[lev].value) {
				int mark = true;
				for(int v = ans[lev].index+1; v < in[i].index; v++) {
					if(in[v].value == in[i].value) {
						mark = false;
						break;
					}
				}
				if(mark) {
					ans[lev+1].value = in[i].value;
					ans[lev+1].index = in[i].index;
					dfs(lev+1, len);
				}
			}
		}
	}
}

int main()
{
	while(scanf("%d%d", &n, &p) != EOF) {
		cnt = 0;
		for(int i = 1; i <= n; i++) {
            f[i] = false;
		}
		for(int i = 1; i <= n; i++) {
			scanf("%d", &in[i].value);
			in[i].index = i;
			ans[i].value = in[i].value;
			ans[i].index = i;
		}
		init();//if the len equal 1
		for(int i = 2; i <= n-1; i++) {// get different length
                if(f[i-1]==true) {
                    dfs(0, i);
                }
                else break;
		}
		printf("\n");
	}
	return 0;
}