#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <cctype>
#include <list>
#include <hash_map>
#include <stack>
#include <hash_set>
#include <hash_map>
#include <sstream>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <hash_map>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define mset(a) memset(a,0,sizeof(a))
#define mmset(a) memset(a,-1,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
const int inf=1e9+7;
const long long linf=1e18;
typedef long double lf;
typedef vector <int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long double,long double> pdd;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
double a[10],b[10];
int main(){
	double n,m;
	scanf("%lf%lf\n",&n,&m);
	int cnt1=0,cnt2=0;
	for (int i=0;i<20;i++){
		char ch;
		cin>>ch;
		ch=toupper(ch);
		if (ch=='A') scanf("%lf",&a[cnt1++]);
		else scanf("%lf",&b[cnt2++]);
	}
	double ans=0;
	for (int i=0;i<10;i++)
		ans+=a[i];
	ans=n*10/ans;
	printf("Method 1\n");
	printf("African: %.2f furlongs per hour\n",ans);
	ans=0;
	for (int i=0;i<10;i++)
		ans+=b[i];
	ans=m*10/ans;
	printf("European: %.2f furlongs per hour\n",ans);
	printf("Method 2\n");
	ans=0;
	for (int i=0;i<10;i++)
		ans+=(n/a[i]);
	ans=ans/10;
	printf("African: %.2f furlongs per hour\n",ans);
	ans=0;
	for (int i=0;i<10;i++)
		ans+=(m/b[i]);
	ans=ans/10;
	printf("European: %.2f furlongs per hour\n",ans);
	//system("pause");
	return 0;
}