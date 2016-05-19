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
int main(){
	bool first=true;
	string s;
	while (getline(cin,s)){
		for (int i=0;i<s.size();i++)
		{
			if (i==0&&!first){
				while (i<s.size()&&(s[i]=='('||s[i]==')'))
					i++;
				s[i]=toupper(s[i]);
			}
			else if (s[i]=='.'||s[i]=='?'||s[i]=='!'){
				do{
					i++;
				}while (i<s.size()&&(s[i]==' '||s[i]=='('||s[i]==')'));
				if (i==s.size()) break;
				s[i]=toupper(s[i]);
			}
			else s[i]=tolower(s[i]);
		}
		first=false;
		cout<<s<<endl;
	}
	return 0;
}