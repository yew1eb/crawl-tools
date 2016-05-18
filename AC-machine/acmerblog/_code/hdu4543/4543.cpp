#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m;

struct Node{
	int x,y,dis;
	Node(){}
	Node(int xx,int yy,int d){x=xx,y=yy,dis=d;}
}que[10300],dic[5300];
int cd,head,tail;
char s[100];
int dir[4][2]={
	{0,1},
	{0,-1},
	{1,0},
	{-1,0}
};


int cal(int i,int j,int x,int y){
	return abs(i-x)+abs(j-y);
}

int map[80][80];

int uslove(){/*
	int ans=1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				int t=min(cal(0,i,j,m-1),cal(j,m-1,n-1,k));
				ans=max(ans,min(cal(0,i,n-1,k),t));
			}
			for(int k=0;k<n;k++){
				int t=min(cal(0,i,j,m-1),cal(j,m-1,k,0));
				ans=max(ans,min(cal(0,i,k,0),t));
			}
		}
	}
//	printf("%d\n",ans);*/
//	return ans;
	 if(n == 1) return m / 3;
	 if(m == 1) return n / 3; 
     return (2*n + 2*m - 4)/3;
}

bool cmp(Node a,Node b){
	if(a.dis<b.dis) return true;
	return false;
}

bool check(int x,int y){
	if(x>=0&&x<n&&y>=0&&y<m&&map[x][y]==0) return true;
	return false;
}

void BFS(){
/*	for(int i=0;i<cd;i++){
		dic[i].dis=200;
		for(int j=0;j<co;j++){
			dic[i].dis=min(dic[i].dis,cal(dic[i].x,dic[i].y,occ[j].x,occ[j].y));
	//		cout<<dis[i]<<endl;
		}
	}*/
	Node p,tmp;
	while(head<tail){
		p=que[head++];
		for(int i=0;i<4;i++){
			tmp.x=p.x+dir[i][0];
			tmp.y=p.y+dir[i][1];
			if(check(tmp.x,tmp.y)){
				tmp.dis=p.dis+1;
				map[tmp.x][tmp.y]=tmp.dis;
				dic[cd++]=Node(tmp.x,tmp.y,p.dis);
				que[tail++]=tmp;
			}
		}
	}
}

void slove(){
	/*
	int ans=-1;
	int t;
	for(int i=0;i<cd;i++){
		if(dis[i]<ans) continue;
		for(int j=i+1;j<cd;j++){
			t=min(dis[j],dis[i]);
			if(t<ans) continue;
			for(int k=j+1;k<cd;k++){
				int t1=min(dis[k],t);
				if(t1<ans) continue;
				t1=min(t1,cal(dic[i].x,dic[i].y,dic[j].x,dic[j].y));
				t1=min(t1,cal(dic[i].x,dic[i].y,dic[k].x,dic[k].y));
				t1=min(t1,cal(dic[j].x,dic[j].y,dic[k].x,dic[k].y));
				ans=max(t1,ans);
			}
		}
	}
	printf("%d\n",ans);*/
	sort(dic,dic+cd,cmp);
	int q=0,d=1;
	while(q<cd){
		bool flag=false;
		for(int i=q;i<cd;i++){
			for(int j=i+1;j<cd;j++){
				if(cal(dic[i].x,dic[i].y,dic[j].x,dic[j].y)<d) continue;
				for(int k=j+1;k<cd;k++){
					if(cal(dic[i].x,dic[i].y,dic[k].x,dic[k].y)>=d&&cal(dic[k].x,dic[k].y,dic[j].x,dic[j].y)>=d){
						flag=true;
						break;
					}
				}
				if(flag) break;
			}
			if(flag) break;
		}
		if(!flag) break;
		d++;
		while(q<cd&&dic[q].dis<d)
		q++;
	}
	printf("%d\n",d-1);
}

int main(){
	int T,icase=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		cd=0; int cc=0;
		head=tail=0;
		memset(map,0,sizeof(map));
		for(int i=0;i<n;i++){
			scanf("%s",s);
			for(int j=0;j<m;j++){
				if(s[j]=='F'){
					map[i][j]=1;
					que[tail++]=Node(i,j,1);
				}
				else cc++;
			}
		}
		printf("Case %d: ",++icase);
		if(cd==n*m){
			printf("%d\n",uslove());
		}
		else{
			BFS();
			slove();
		}
	}
	return 0;
}
