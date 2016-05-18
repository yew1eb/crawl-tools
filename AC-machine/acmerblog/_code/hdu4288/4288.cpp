#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 100010
#define lson u<<1
#define rson u<<1|1
typedef long long LL;

int dat[MAXN],tmp[MAXN];
char cmd[MAXN][5];

struct Node{
	int lef,rig;
	LL sum[5];
	int cnt;
}T[MAXN<<2];

void Build(int u,int l,int r){
	T[u].lef=l;
	T[u].rig=r;
	T[u].cnt=0;
	for(int i=0;i<5;i++)T[u].sum[i]=0;
	if(l==r)return;
	int mid=(l+r)>>1;
	Build(lson,l,mid);
	Build(rson,mid+1,r);
}

void PushUp(int u){
	for(int i=0;i<5;i++)T[u].sum[i]=T[lson].sum[i]+T[rson].sum[((i-T[lson].cnt)%5+5)%5];
}

void Update(int u,int pos,int val,int op){
	T[u].cnt+=op;
	if(T[u].lef==T[u].rig){
		T[u].sum[0]+=val;return;
	}
	else {
		if(pos<=T[lson].rig)Update(lson,pos,val,op);
		else Update(rson,pos,val,op);
		PushUp(u);
	}
}

int main(){
	int n;
	while(scanf("%d",&n)==1){

		int num=0;
		for(int i=0;i<n;i++){
			scanf("%s",cmd[i]);
			if(cmd[i][0]!='s'){scanf("%d",&dat[i]);tmp[num++]=dat[i];}
		}

		sort(tmp,tmp+num);
		num=unique(tmp,tmp+num)-tmp;

		Build(1,1,num);
		for(int i=0;i<n;i++){
			int pos=lower_bound(tmp,tmp+num,dat[i])-tmp;
			if(cmd[i][0]=='a')Update(1,pos,dat[i],1);
			else if(cmd[i][0]=='d')Update(1,pos,-dat[i],-1);
			else printf("%I64d\n",T[1].sum[2]);
		}
	}

}
