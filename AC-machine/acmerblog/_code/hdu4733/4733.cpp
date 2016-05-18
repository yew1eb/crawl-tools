#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<cmath>
#include<cassert>
#include<cstring>
#include<iomanip>
using namespace std;
#ifdef _WIN32
#define i64 __int64
#define out64 "%I64d\n"
#define in64 "%I64d"
#else
#define i64 long long
#define out64 "%lld\n"
#define in64 "%lld"
#endif
/************ for topcoder by zz1215 *******************/
#define foreach(c,itr)  for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define FOR(i,a,b)      for( int i = (a) ; i <= (b) ; i ++)
#define FF(i,a)         for( int i = 0 ; i < (a) ; i ++)
#define FFD(i,a,b)      for( int i = (a) ; i >= (b) ; i --)
#define S64(a)          scanf(in64,&a)
#define SS(a)           scanf("%d",&a)
#define LL(a)           ((a)<<1)
#define RR(a)           (((a)<<1)+1)
#define pb              push_back
#define pf              push_front
#define X               first
#define Y               second
#define CL(Q)           while(!Q.empty())Q.pop()
#define MM(name,what)   memset(name,what,sizeof(name))
#define MC(a,b)         memcpy(a,b,sizeof(b))
#define MAX(a,b)        ((a)>(b)?(a):(b))
#define MIN(a,b)        ((a)<(b)?(a):(b))
#define read            freopen("in.txt","r",stdin)
#define write           freopen("out.txt","w",stdout)

const int inf = 0x3f3f3f3f;
const i64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const double oo = 10e9;
const double eps = 10e-9;
const double pi = acos(-1.0);
const int maxn = 100111;
const int mod = 1000000007;

int f[maxn];
int T;
char s[maxn];
string a,b;
int pos;
int num[maxn];

void init()
{
	f[0]=1;
	for(int i=1;i<maxn;i++)
	{
		f[i] = f[i-1]*2;
		f[i] %= mod;
	}
	return ;
}

int have()
{
	int re = 0;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]!='?' && b[i]!='?')
		{
			if(a[i]!=b[i])
			{
				re++;
				pos = i;
			}
		}
	}
	return re;
}

bool can()
{
	if(pos+1<a.length())
	{
		if(a[pos+1] == '0' || b[pos+1]=='0')
		{
			return false;
		}
		else
		{
			a[pos+1] = b[pos+1] = '1';
		}
	}
	for(int i=pos+2;i<a.length();i++)
	{
		if(a[i] == '1' || b[i] == '1')
		{
			return false;
		}
		else
		{
			a[i] = b[i] = '0';
		}
	}

	return true;
}

int gao()
{
	int temp = 0;
	for(int i=0;i<pos;i++)
	{
		if(a[i] == '?' && b[i] == '?')
		{
			temp++;
		}
		else if(a[i]=='?')
		{
			a[i] = b[i];
		}
		else if(b[i] == '?')
		{
			b[i] = a[i];
		}
	}
	return f[temp];
}



int start()
{
	int all = 0;
	for(int i=0;i<a.length();i++)
	{
		if(a[i] == '?' && b[i] == '?')
		{
			all++;
		}
		else
		{
			if(a[i]!='?')
			{
				s[i]=a[i];
			}
			else if(b[i]!='?')
			{
				s[i]=b[i];
			}
			else s[i]=a[i];
		}
	}

	num[0]=0;
	for(int i=0;i<a.length();i++)
	{
		if(a[i] == '1')
		{
			num[i]=num[i-1]+1;
		}
		else
		{
			num[i] = num[i-1];
		}
	}


	int ans = 0;
	int pass = 0;
	bool ok = true;
	bool c0 = true;
	bool end = false;
	for(int i=int(a.length())-1; i>=0 ; i--)
	{
		if(a[i] == '?' && b[i] == '?')
		{
			pass++;
			if(ok)
			{
				ans+=f[all-pass];
				ans%=mod;
				pos=i;
			}
			if(end) break;
			ok = c0;
			c0 = true;
		}
		else if(a[i] == '?')
		{
			if(ok)
			{
				if(all>pass)
				{
					ans+=f[all-pass-1];
					pos=i;
					ans%=mod;
				}
				else if(all == pass)
				{
					if(b[i]=='1' && num[i]%2==0)
					{
						ans++;
						pos = i;
						ans%=mod;
					}
					else if(b[i]=='0' && num[i]%2==1)
					{
						ans++;
						pos = i;
						ans%=mod;
					}
				}
			}
			if(end) break;
			if(b[i]=='1' && c0)
			{
				ok = true;
			}
			else
			{
				ok = false;
			}
			c0 = bool(b[i]=='0');
			if(ok) end = true;
		}
		else if(b[i] == '?')
		{
			if(ok)
			{
				if(all>pass)
				{
					pos = i;
					ans+=f[all-pass];
					ans%=mod;
				}
				else if(all == pass)
				{
                    if(a[i]=='1' && num[i]%2==1)
					{
						ans++;
						pos = i;
						ans%=mod;
					}
					else if(a[i]=='0' && num[i]%2==0)
					{
						ans++;
						pos = i;
						ans%=mod;
					}
				}
			}
			if(end ) break;
			if(a[i]=='1' && c0)
			{
				ok = true;
			}
			else
			{
				ok = false;
			}
			c0 = bool(a[i]=='0');
			if(ok) end = true;
		}
		else if(a[i]=='0')
		{
			ok = false;
			c0 = true;
		}
		else if(a[i] == '1')
		{
			ok = true;
			end = true;
			c0 = false;
		}
	}
	return ans;
}

void ss()
{
	if(a[pos] == '?' && b[pos] == '?')
	{
		if(num[pos]%2==0)
		{
			a[pos] = '0';
			b[pos] = '1';
		}
		else
		{
			a[pos] = '1';
			b[pos] = '0';
		}
	}
	else if(a[pos] == '?')
	{
		if(b[pos] == '1') a[pos] = '0';
		if(b[pos] == '0') a[pos] = '1';
	}
	else if(b[pos] == '?')
	{
		if(a[pos] == '1') b[pos] = '0';
		if(a[pos] == '0') b[pos] = '1';
 	}
	if(pos+1<a.length())
	{
		a[pos+1] = b[pos+1] = '1';
	}
	for(int i=pos+2;i<a.length();i++)
	{
		a[i] = b[i] = '0';
	}
	for(int i=0;i<a.length();i++)
	{
		if(a[i] == '?')
		{
			a[i] = b[i];
		}
		else if(b[i] == '?')
		{
			b[i] = a[i];
		}
	}
	return ;
}

void out(string x)
{
	for(int i=0;i<x.length();i++)
	{
		s[i] = x[i];
	}
	s[x.length()] = '\0';
	printf("%s\n",s);
	return ;
}

int main()
{
	init();
	cin>>T;
	getchar();
	for(int tt=1;tt<=T;tt++)
	{
		cin.getline(s,100100);
		a=s;
		cin.getline(s,100100);
		b=s;
        cout<<"Case #"<<tt<<":"<<endl;
		int temp = have();
		if(temp >= 2)
		{
			cout<<"Impossible"<<endl;
		}
		else if(temp == 1)
		{
			if(!can())
			{
				cout<<"Impossible"<<endl;
			}
			else
			{
				int ans = gao();
				ans/=2;
				if(ans == 0)
				{
					for(int i=0;i<a.length();i++)
					{
                        if(a[i]!='?')
						{
							s[i]=a[i];
						}
						else if(b[i]!='?')
						{
							s[i]=b[i];
						}
						else
						{
							s[i]=a[i];
						}
					}
					int cx = 0;
					for(int i=0;i<=pos;i++)
					{
						if(s[i]=='1')
						{
							cx++;
						}
					}
					if(cx%2==0)
					{
						ans=1;
					}
				}
				if(ans == 1)
				{
					//cout<<a<<endl;
					//cout<<b<<endl;
					out(a);
					out(b);
				}
				else
				{
					cout<<"Ambiguous "<<ans<<endl;
				}
			}
		}
		else
		{
			int ans = start();
			if(ans == 0)
			{
                cout<<"Impossible"<<endl;
			}
			else if(ans == 1)
			{
				ss();
				//cout<<a<<endl;
				//cout<<b<<endl;
				out(a);
				out(b);
			}
			else
			{
                cout<<"Ambiguous "<<ans<<endl;
			}
		}

	}

	return 0;
}
