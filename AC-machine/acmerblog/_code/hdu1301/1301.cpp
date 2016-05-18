#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>
typedef struct{
	int a,b;
	int len;
}Edge;

Edge input[120];

/*********************************************************/
/*并查集                                                 */ 
/*********************************************************/
int parent[30]; //节点个数 
int root(int n){
	if(parent[n] == 0) return n;
	else return parent[n] = root(parent[n]);
}

/*********************************************************/
/*kruskal                                                */ 
/*********************************************************/ 
int cmp(const void  *a,const void  *b){
	return (((Edge *)a)->len - ((Edge *)b)->len);
} 
int kuruskal(int edge_top){
	int a_root,b_root;
	int sum = 0;
	for(int i = 0; i < edge_top;++i){
		a_root = root(input[i].a);
		b_root = root(input[i].b);
		if(a_root != b_root){
			a_root < b_root?parent[b_root] = a_root:parent[a_root] = b_root;
			sum += input[i].len;
		}
	}
	return sum;
} 
/*********************************************************/
int main(int argc, char *argv[])
{
	//FILE *fp;	
	//fp = freopen("in3.txt","r",stdin);
	int n,a_v_Edge_num,edge_top;
	char tem,tem_an;

	while(scanf("%d%*c",&n),n){
		edge_top = 0;
	
		for(int i = 0; i < n - 1; ++i){
			scanf("%c %d%*c",&tem,&a_v_Edge_num);
			//getchar();
			//cin>>tem>>a_v_Edge_num;
			while(a_v_Edge_num --){
				scanf("%c %d%*c",&tem_an,&input[edge_top].len);
				//getchar();
				//cin>>tem_an>>input[edge_top].len;
				
				input[edge_top].a = tem - 'A' + 1;
				input[edge_top].b = tem_an - 'A' + 1;
				++edge_top;
 			}
		}
		qsort(input,edge_top,sizeof(Edge),cmp);
		memset(parent,0,sizeof(parent));
		printf("%d\n",kuruskal(edge_top));
	}
	return 0;
}