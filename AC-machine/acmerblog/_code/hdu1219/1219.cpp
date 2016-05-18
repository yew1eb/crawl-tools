#include <iostream>
using namespace std;
int main()
{
	char buf[100010]; 
	int n[26];
	//freopen("G:/in.txt", "r", stdin);
	while(gets(buf)){
		memset(n,0,sizeof(n));
		int len=strlen(buf);
		for(int i=0;i<len;i++){
			int k=0;
			if(buf[i]>='a'&&buf[i]<='z'){				
				while(buf[i]!=char('a'+k))
					k++;
				n[k]++;
			}
		}
		for(int i=0;i<26;i++)
			cout<<char('a'+i)<<":"<<n[i]<<endl;
		cout<<endl;
	}
	return 0;
}