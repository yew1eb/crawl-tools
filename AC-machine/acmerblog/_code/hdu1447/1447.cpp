#include <iostream>
#include <string>
using namespace std;
string a[105];
string b[105];
string c[105];
int dp[105][105];
int d[105][105]; //记录路径
int len1,len2;
int main(){
	while(cin>>a[1]){
		len1 = 2;
		while(a[len1 - 1] != "#")
			cin>>a[len1++];
		len1 -= 2;
		cin>>b[1];
		len2 = 2;
		while(b[len2 - 1] != "#")
			cin>>b[len2++];
		len2 -= 2;
		memset(dp,0,sizeof(dp));
		memset(d,0,sizeof(d));
		for(int i = 1; i <= len1; i++)
			for(int j = 1; j <= len2; j++){
				if(a[i] == b[j])
					dp[i][j] = dp[i - 1][j - 1] + 1,d[i][j] = 1;
				else{
					if(dp[i -1][j] > dp[i][j - 1])
						dp[i][j] = dp[i - 1][j],d[i][j] = 2;
					else
						dp[i][j] = dp[i][j - 1],d[i][j] = 3;
				}
			}
		int n = dp[len1][len2];
		int i = len1;
		int j = len2;
		while(n){
			while(d[i][j] != 1){
				if(d[i][j] == 2)
					i--;
				else
					j--;
			}
			n--;
			c[n] = a[i];
			i--;
			j--;
		}
		cout<<c[0];
		for(int i =1; i < dp[len1][len2]; i++)
			cout<<" "<<c[i];
		cout<<endl;
	}
	return 0;
}