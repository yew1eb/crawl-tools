#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int next[500000][26];
int net[2000000],sora[2000000];
int rt[500000],l[500000],op[500000],ed[500000],tail[500000];
char ch[500000];
long long ans;
int n,m,ss,s1,cm,k,m1,w_time,top;
int b[1048576],t[1048576],s[1048576];
int q[500000];
void suffix_sam(int &last,int chr)
{
	int x,y;
	s1++,l[s1]=l[last]+1;
	for (x=last,last=s1;x && (!next[x][chr]);x=rt[x]) next[x][chr]=s1;
	y=next[x][chr];
	if (!y) next[x][chr]=s1,rt[s1]=0;
	else if (l[x]+1==l[y]) rt[s1]=y;
	else {
		s1++,l[s1]=l[x]+1;
		for (int j=0;j<='z'-'a';j++) next[s1][j]=next[y][j];
		rt[s1]=rt[y],rt[y]=s1,rt[last]=s1;
		for (;x && (next[x][chr]==y);x=rt[x]) next[x][chr]=s1;
		if (next[x][chr]==y) next[x][chr]=s1;
	}
}
void origin()
{
	for (int i=0;i<=s1;i++) {
		for (int j=0;j<='z'-'a';j++)
			next[i][j]=0;
	}
	for (int i=1;i<=m1+m1;i++) b[i]=t[i]=s[i]=0;
	s1=0,ss=0,m1=0;
}
void link(int x,int y)
{
	++ss,net[tail[x]]=ss,tail[x]=ss,sora[ss]=y,net[ss]=0;
}
void dfs(int s)
{
	++top,op[s]=top;
	for (int i=s,ne;net[i];) {
		i=net[i],ne=sora[i];
		dfs(ne);
	}
	ed[s]=top;
}
void change(int l,int r,int x)
{
	++w_time;
	l+=m1-1,r+=m1+1;
	for (;!((l^r)==1);l>>=1,r>>=1) {
		if ((l&1)==0) b[l+1]=x,t[l+1]=w_time;
		if ((r&1)==1) b[r-1]=x,t[r-1]=w_time;
	}
}
int ask(int x)
{
	int b1=0,t1=0;
	for (x+=m1;x;x>>=1)
		if (t[x]>t1) b1=b[x],t1=t[x];
	return b1;
}
void modify(int x)
{
	for (x+=m1;x;x>>=1) s[x]++;
}
int query(int l,int r)
{
	int sum=0;
	l+=m1-1,r+=m1+1;
	for (;!((l^r)==1);l>>=1,r>>=1) {
		if ((l&1)==0) sum+=s[l+1];
		if ((r&1)==1) sum+=s[r-1];
	}
	return sum;
}
void pushdown(int x)
{
	ans+=l[x]-l[rt[x]];
	for (int i=x,ne;net[i];) {
		i=net[i],ne=sora[i];
		int cnt=query(op[ne],ed[ne]);
		if (cnt>=k) pushdown(ne);
		else change(op[ne],ed[ne],ne);
	}
}
void doit(int x)
{
	modify(op[x]);
	int y=ask(op[x]);
	int cnt=query(op[y],ed[y]);
	if (cnt>=k) pushdown(y);
}
char c[20];
int main()
{
	for (;scanf("%d%d%d",&n,&m,&k)==3;) {
		origin();
		scanf("%s",ch+1);
		cm=0;
		for (int i=1;i<=m;i++) {
			scanf("%d",&q[i]);
			if (q[i]==1) {
				scanf("%s",c+1);
				++cm;
				ch[cm+n]=c[1];
			}
		}
		int last=0;
		for (int i=1;i<=n+cm;i++) suffix_sam(last,ch[i]-'a');
		ss=s1;
		for (int i=0;i<=s1;i++) tail[i]=i,net[i]=0;
		for (m1=1;m1<=s1+2;m1<<=1) ;
		for (int i=1;i<=s1;i++) {
			link(rt[i],i);
		}
		for (int i=0;i<=s1;i++) op[i]=ed[i]=0;
		top=0;
		dfs(0);
		int s=0;
		ans=0;
		w_time=0;
		for (int i=1;i<=n;i++) {
			s=next[s][ch[i]-'a'];
			doit(s);
		}
		cm=0;
		for (int i=1;i<=m;i++) {
			if (q[i]==2) {
				printf("%lld\n",ans);
			}
			else {
				cm++;
				s=next[s][ch[n+cm]-'a'];
				doit(s);
			}
		}
	}
	return 0;
} 