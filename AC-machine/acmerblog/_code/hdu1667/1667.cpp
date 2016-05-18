#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<map>
#include<string>
#define inf 1<<30
#define eps 1e-7
#define LD long double
#define LL long long
#define maxn 1005
using namespace std;
int central[8]={6,7,8,11,12,15,16,17};  //中间8个方格的位置
int rotation[4][7]={{0,2,6,11,15,20,22},{1,3,8,12,17,21,23},{10,9,8,7,6,5,4},{19,18,17,16,15,14,13}};//分别是每7个按顺序列好
int to[8]={0,1,2,3,1,0,3,2};    //8种转换分别对应于哪7个方块
int rev[8]={5,4,7,6,1,0,3,2};   //每一种转换的相反转换是哪个
int ope[maxn];    //存储转换操作
int a[24];    //原始序列
bool flag;  //是否有解
int depth;    //当前搜索深度
int get_h(int *m){   //得到估价函数h
	int a=0,b=0,c=0; 
	for(int i=0;i<8;i++)
		if(m[central[i]]==1)
			a++;
		else if(m[central[i]]==2)
			b++;
		else if(m[central[i]]==3)
			c++;
	return 8-max(a,max(b,c));
}
void change(int *b,int kind){
	if(kind<4){
		int tmp=b[rotation[to[kind]][0]];
		for(int i=0;i<6;i++)
			b[rotation[to[kind]][i]]=b[rotation[to[kind]][i+1]];
		b[rotation[to[kind]][6]]=tmp;
	}
	else{
		int tmp=b[rotation[to[kind]][6]];
		for(int i=6;i>0;i--)
			b[rotation[to[kind]][i]]=b[rotation[to[kind]][i-1]];
		b[rotation[to[kind]][0]]=tmp;
	}
}
void IDAstar(int *b,int tmp_depth,int father){   //当前序列，当前深度，父节点
	if(get_h(b)>tmp_depth)    //这就是利用估价函数的剪枝，h的值表示至少还需要多少步，如果在当前深度完成不了就剪掉
		return;
	if(flag)    //如果已经有解就退出
		return;
	if(tmp_depth==0&&get_h(b)==0){   //深度为0，且为目标状态
		flag=true;
		for(int j=depth;j>0;j--)
			printf("%c",ope[j]+'A');
		printf("\n%d\n",b[6]);
		return;
	}
	for(int i=0;i<8;i++){
		int tmp[24];
		if(rev[i]==father)   //避免死循环，相反操作两次则抵消
			continue;
		for(int i=0;i<24;i++)
			tmp[i]=b[i];
		change(tmp,i);
		ope[tmp_depth]=i;
		dfs(tmp,tmp_depth-1,i);
	}
}
int main(){
	while(scanf("%d",&a[0])!=EOF&&a[0]){
		for(int i=1;i<24;i++)
			scanf("%d",&a[i]);
		if(get_h(a)==0){    
			printf("No moves needed\n%d\n",a[6]);  //wa两次，不需要操作也需要输出中心数字
			continue;
		}
		flag=false;
		for(depth=get_h(a);;depth++){   //迭代加深，至少需要h(a)步，很好理解
			dfs(a,depth,-1);
			if(flag)   //有解则退出
				break;
		}
	}
	return 0;
}