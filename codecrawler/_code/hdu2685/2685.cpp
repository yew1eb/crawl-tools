#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
	int l,r,cl;
	bool lz;
}t[300009];
void build(int st,int ed,int cr){
	t[cr].r=ed;
	t[cr].l=st;
	t[cr].cl=2;
	t[cr].lz=1;
	if(st==ed)
		return ;
	build(st,(st+ed)/2,2*cr);
	build((st+ed)/2+1,ed,cr*2+1);
	return ;
}
void insert(int st,int ed,int cr,int incl){
	if(t[cr].r==ed&&t[cr].l==st){
		t[cr].cl=(1<<incl);
		t[cr].lz=1;
		return ;//不用再递归了，这样子已经足够了
	}
	if(t[cr].lz){
		t[cr].lz=0;//插入的不是当前线段，而是子线段，那么把这个线段破开。并把这个点信息给子线段
		t[cr*2+1].cl=t[cr*2].cl=t[cr].cl;
		t[cr*2+1].lz=t[cr*2].lz=1;
	}
	int mid=(t[cr].r+t[cr].l)>>1;
	if(ed<=mid){
		insert(st,ed,2*cr,incl);
	}else if(st>mid){
		insert(st,ed,2*cr+1,incl);
	}else{
		insert(st,mid,2*cr,incl);
		insert(mid+1,ed,2*cr+1,incl);
	}
	t[cr].cl=t[cr*2].cl|t[cr*2+1].cl;
	return ;
}
int query(int st,int ed,int cr){
	if((t[cr].lz)||(t[cr].r==ed&&t[cr].l==st)){
		return t[cr].cl;
	}
	int mid=(t[cr].l+t[cr].r)>>1;
	if(ed<=mid){
		return query(st,ed,cr*2);
	}else if(st>mid){
		return query(st,ed,cr*2+1);
	}else{
		return query(st,mid,cr*2)|query(mid+1,ed,cr*2+1);
	}
}
int main(){
	int L,T,O,A,B,C,ret,ans;
	char op;
	while(scanf("%d%d%d",&L,&T,&O)==3){
		build(1,L,1);
		while(O--&&scanf(" %c",&op)){
			if(op=='C'){
				scanf("%d%d%d",&A,&B,&C);
				if(A>B)swap(A,B);
				insert(A,B,1,C);
			}else{
				scanf("%d%d",&A,&B);
				if(A>B)swap(A,B);
				ret=query(A,B,1);
				ans=0;
				for(int i=0;i<32;i++)
					if(ret&(1<<i))
						ans++;
				printf("%d\n",ans);
			}
		}
	}
}