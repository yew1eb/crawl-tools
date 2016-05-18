#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
#define ll long long

struct Person{
 int id;
 ll maxm,out;
 bool operator<(const Person& p)const{
 if(maxm == p.maxm) return id < p.id;
 else return maxm > p.maxm;
 }
}p[1000010];
int n;
ll sum,tsum,aver;

bool cmp(Person p1,Person p2)
{
 return p1.id < p2.id;
}

int main()
{
 int test,i,j;
 scanf("%d",&test);
 while(test--){
 scanf("%I64d%d",&sum,&n);
 for(tsum=0,i=0; i<n; i++){
 scanf("%I64d",&p[i].maxm);
 p[i].id=i;
 tsum += p[i].maxm;
 }
 //printf("tsum = %I64d\tsum = %I64d\n",tsum,sum);
 if(tsum < sum) { puts("IMPOSSIBLE"); continue;}
 sort(p,p+n);
 for(i = n-1; i>=0; i--){
 aver = sum / (i+1);
 if(aver > p[i].maxm) aver = p[i].maxm;
 p[i].out = aver;
 sum -= aver;
 }
 sort(p,p+n,cmp);
 printf("%d",p[0].out);
 for(i=1; i<n; i++) printf(" %d",p[i].out);
 puts("");
 }
 return 0;
}