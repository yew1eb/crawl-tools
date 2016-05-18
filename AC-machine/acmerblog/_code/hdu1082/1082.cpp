#include"stdio.h"
#include"string.h"
#include"stack"
using namespace std;

struct node
{
	int x,y;
}A[201];

int main()
{
	int n;
	int i;
	int f;
	char c;
	int ans;
	char s[1001];
	node t,tt;
	scanf("%d",&n);
	while(n--)
	{
		getchar();
		scanf("%c",&c);
		scanf("%d%d",&A[c].x,&A[c].y);
	}
	getchar();
	
	while(gets(s))
	{
		f=1;
		ans=0;
		stack<char>s1;
		stack<node>s2;
		for(i=0;s[i];i++)
		{
			if(s[i]=='(')
				s1.push(s[i]);
			else if(s[i]==')')
			{
				c=s1.top();
				s1.pop();
				s1.pop();
				while(!s1.empty()&&s1.top()!='(')
				{
					tt=s2.top();
					s2.pop();
					t=s2.top();
					if(t.y!=tt.x)
					{
						f=0;
						break;
					}
					ans+=t.x*t.y*tt.y;
					t.y=tt.y;
					s2.pop();
					s2.push(t);
					s1.pop();
				}
				s1.push(s[i]);
			}
			else
			{
				if(!s1.empty()&&s1.top()!='(')
				{
					t=s2.top();
					if(t.y!=A[s[i]].x)
					{
						f=0;
						break;
					}
					ans+=t.x*t.y*A[s[i]].y;
					t.y=A[s[i]].y;
					s2.pop();
					s2.push(t);
				}
				else
				{
					s2.push(A[s[i]]);
					s1.push('#');
				}
			}
		}
		if(f)printf("%d\n",ans);
		else printf("error\n");
	}
	return 0;
}