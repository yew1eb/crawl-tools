#include <iostream>
#include <stdio.h>
#include <string.h>
#include <set>
#include <string>
using namespace std;
string s1;
string s2;
char a[30];//鍘熸潵鐨�'a'鍙樻垚浜嗕粈涔�
char b[30];//鐜板湪鐨勨�榓鈥欐槸璋�
int main ()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin >> s1 >> s2;
		for(int i=0;i<s1.size();i++)
		{
			a[i] = s1[i];
			b[s1[i]-'a'] = i + 'a';
		}
		char s ;
        s = b[s2[0]-'a'];
		int i;
		int l = s2.size();
		for(i=(s2.size() + 1)/2;i<s2.size();i++)
		{
				bool flag = false;
				int j;
				for(j=i;j<s2.size();j++)
				{
					if(b[s2[j-i]-'a'] != s2[j]){
						flag = true;
						break;
					}
				}
				if(flag == false)
				{
					l = i;				
					break;					
				}
		}
		for(int i=0;i<l;i++)
		{
			cout << s2[i];
		}
		for(int i=0;i<l;i++)
		{
			cout << b[s2[i]-'a'];
		}
		cout << endl;
	}
      return 0;
}