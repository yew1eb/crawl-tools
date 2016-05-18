#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 10010
#define MAXM 50010

struct ti //ʱ��
{
 int y,m,d,h,f,s;
};

struct eugin //Ԥ����op
{
 ti mytime;
 int ren,op;//op: -1==SYNC��-2==SUBMIT
};

struct job //��¼ÿ���˵Ĳ���
{
 map <int,int> h;
 vector <int> line;
 ti last;
 int sum;
};

struct cyr
{
 ti mytime;
 int ren,hang;
};

struct person
{
 char name[36];
 int p;//���ȼ�
};

map <int,int> hash; //�����Ӧ��int
person per[MAXN];
int up;//����hash���ֵ
int m,n;
cyr ans[MAXM];
eugin c[MAXM];
job dps[MAXN];

bool operator < (ti q,ti w)
{
 if (q.y<w.y) return true;
 if (q.y>w.y) return false;
 if (q.m<w.m) return true;
 if (q.m>w.m) return false;
 if (q.d<w.d) return true;
 if (q.d>w.d) return false;
 if (q.h<w.h) return true;
 if (q.h>w.h) return false;
 if (q.f<w.f) return true;
 if (q.f>w.f) return false;
 if (q.s<w.s) return true;
 if (q.s>w.s) return false;
 return false;
}

bool operator < (eugin q,eugin w)
{
 if (q.mytime<w.mytime) return true;
 return false;
}

bool operator < (cyr q,cyr w)
{
 if (q.hang<w.hang) return true;
 return false;
}

inline void work()
{
 int i,x,j,l;
 for (i=1;i<=m;i++) ans[i].ren=-1;
 for (i=1;i<=m;i++)
 {
 x=c[i].ren;
 if (c[i].op==-1)
 {
 dps[x].h.clear();
 dps[x].line.clear();
 dps[x].sum=0;
 dps[x].last=c[i].mytime;
 }
 else if (c[i].op==-2)
 {
 for (j=0;j<dps[x].line.size();j++)
 {
	l=dps[x].line[j];
	if (ans[l].ren==-1)
	{
	 ans[l].ren=x;
	 ans[l].mytime=c[i].mytime;
	}
	else if (per[ans[l].ren].p<per[x].p)
	{
	 ans[l].ren=x;
	 ans[l].mytime=c[i].mytime;
	}
	else if (ans[l].mytime<dps[x].last)
	{
	 ans[l].ren=x;
	 ans[l].mytime=c[i].mytime;
	}
 }
 dps[x].h.clear();
 dps[x].line.clear();
 dps[x].sum=0;
 dps[x].last=c[i].mytime;
 }
 else
 {
 int temp;
 if (dps[x].h[c[i].op]==0)
 {
	dps[x].sum++;
	dps[x].h[c[i].op]=dps[x].sum;
 dps[x].line.push_back(c[i].op);
 }
 else
 {
	temp=dps[x].h[c[i].op]-1;
	dps[x].line[temp]=c[i].op;
 }
 }
 }
}

inline void output()
{
 int i;
 ti t;
 sort(ans+1,ans+1+up);
 for (i=1;i<=up;i++)
 {
 if (ans[i].ren==-1) continue;
 if (ans[i].hang==-1) printf("0 ");
 else printf("%d ",ans[i].hang);
 t=ans[i].mytime;
 printf("[%d/%02d/%02d %02d:%02d:%02d] BY ",t.y,t.m,t.d,t.h,t.f,t.s);
 printf("%s\n",per[ans[i].ren].name);
 }
 puts("END");
}

int main()
{
 // freopen("a.txt","r",stdin);
 int i,x,j,temp;
 char e[10];
 ti t;
 scanf("%d",&n);
 while (n)
 {
 hash.clear();
 up=0;
 j=0;
 for (i=1;i<=n;i++)
 {
 scanf("%s %d %d",per[i].name,&per[i].p,&x);
 getchar();
 while (x--)
 {
	j++;
	scanf("[%d/%d/%d %d:%d:%d] %s",&t.y,&t.m,&t.d,&t.h,&t.f,&t.s,e);
	c[j].mytime=t;
	c[j].ren=i;
	if (e[1]=='Y')
	 c[j].op=-1;
	else if (e[1]=='U')
	 c[j].op=-2;
	else 
	{
	 scanf("%d",&c[j].op);
	 temp=c[j].op;
	 if (hash[temp]==0)
	 {
	 up++;
	 hash[temp]=up;
	 ans[up].hang=temp;
	 c[j].op=up;
	 }
	 else c[j].op=hash[temp];
	}
	getchar();
 }
 }
 sort(c+1,c+1+j);
 m=j;
 work();
 output();
 //-----
 scanf("%d",&n);
 }
 return 0;
}