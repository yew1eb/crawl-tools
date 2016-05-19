#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<map>
#include<set>
#include<sstream>
#include<list>
#include<deque>
#include<stack>
#include<bitset>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iomanip>
#include<algorithm>
#include<limits>
#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
#include<queue>
using namespace std;
#define max(a,b) ((a>b)?a:b) //finding max
#define min(a,b) ((a<b)?a:b) //finding min
#define Max(a,b,c) max(a,max(b,c)) //finding max between 3 numbers
#define Min(a,b,c) min(a,min(b,c)) //finding min between 3 numbers
#define Pi acos(-1.0) //defining Pi for mathematical uses
#define Clear(a) memset(a,0,sizeof(a)) //clearing memory of an array
#define setfalse(a) memset(a,false,sizeof(a)) //setting the array into false
#define settrue(a) memset(a,true,sizeof(a)) //setting the array into true
#define clrstr(a) memset(a,'\0',sizeof(a)) //setting string array to null
#define open freopen("input.txt","r",stdin) //opening input file
#define close freopen ("output.txt","w",stdout) //opening output file
#define Case(a) printf("Case %d: ",a) //printing case number
#define caseh(a) printf("Case #%d: ",a) //printing case number having '#'
#define getcase(a) scanf("%d",&a) //scanning case number
#define caseloop(a,b) for(a=1;a<=b;a++) //making case loop
#define EPS 1e-9 //small value for avoiding preccesion error
#define LL long long //__int64 //long long short form
#define MX 50000 //MAX size/value
#define PB(x) push_back(x) //push in vector/string
#define PP pop_back() //pop from vector
#define PF(x) push_front(x) //push in vector/string/deque from front
#define PPF(x) pop_front() //pop from vector/deque from front
#define IN(x) insert(x) //insert element in set
#define PS(x) push(wax) //push element in stack/queue
#define P(x) pop() //pop element from stack/queue
template<class T>inline void checkmin(T &a,T b)
{
 if(b<a)a=b;
}
template<class T>inline void checkmax(T &a,T b)
{
 if(b>a)a=b;
}
const double eps=1e-11;
const double pi=acos(-1.0);
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containm(S,X) (((S)&twoL(X))!=0)
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define MUL(a,b) (int)(((int64)a*b%MOD))
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
typedef pair<int,int>ipair;
#define MOD (1000000007)
const int size=305;
int a[size*size],id,res,c[size*size];
void res_ord(int l,int r)
{
 int mid,i,j,tmp;
 if(r>l+1)
 {
 mid=(l+r)/2;//
 res_ord(l,mid);
 res_ord(mid,r);
 tmp=l;
 for(i=l,j=mid; i<mid&&j<r;)
 {
 if(a[i]>a[j])
 {
 c[tmp++]=a[j++];
 res+=mid-i;
 }
 else
 c[tmp++]=a[i++];
 }
 if(j<r)
 {
 for(; j<r; j++)
 c[tmp++]=a[j];
 }
 else
 {
 for(; i<mid; i++)
 c[tmp++]=a[i];
 }
 for(i=l; i<r; i++)
 a[i]=c[i];
 }
}
int main()
{
 int i,j,n,zero;
 while(cin>>n,n)
 {
 id=res=0;
 for(i=0; i<n; i++)
 for(j=0; j<n; j++)
 {
 scanf("%d",&a[id]);
 if(a[id]==0)
 zero=i;
 else
 id++;
 }
 zero=n-1-zero;
 res_ord(0,id);
 if((n&1)==0)
 {
 //cout<<"fuck"<<endl;
 if((((zero&1)==1)&&((res&1)==1))||
 (((zero&1)==0)&&((res&1)==0))){

 //cout<<res<<endl;
 //cout<<zero<<endl;
 cout<<"YES"<<endl;
 }
 else
 cout<<"NO"<<endl;
 }
 else
 {
 //cout<<(n&1)<<" ---- "<<endl;
 if(res&1)
 cout<<"NO"<<endl;
 else
 cout<<"YES"<<endl;
 }
 }
 return 0;
}