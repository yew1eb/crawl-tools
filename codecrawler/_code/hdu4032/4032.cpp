#include<iostream>
#include<cstring>
using namespace std;//012345678901234
char translate[16] = "3456789TJQKA2BR";
char tot[16] =       "444444444444411";
int a[3][16];
int b[15];
int limit[5] = {0, 5, 3, 0, 0};
int big[5][16];//a[i][j] &plusmn;&iacute;&Ecirc;&frac34;&Iuml;&agrave;&Iacute;&not;&times;&Ouml;&Auml;&cedil;&Ecirc;&yacute;&Aacute;&iquest;&Icirc;&ordf;i?&not;&Aacute;&not;&Aring;&AElig;&Otilde;&Aring;&Ecirc;&yacute;&Icirc;&ordf;j&micro;&Auml;&times;&icirc;&acute;&oacute;&micro;&Auml;&AElig;&eth;&Ecirc;&frac14;&Icirc;&raquo;&Ouml;&Atilde; 
bool rocket;
int attach[16][3];//attach[i][j] &plusmn;&iacute;&Ecirc;&frac34;&Aacute;&not;&ETH;&oslash;i&cedil;&ouml;&Egrave;&yacute;&Otilde;&Aring;&Aring;&AElig;?&not;&acute;&oslash;j&Otilde;&Aring;&Aring;&AElig;&micro;&Auml;&times;&icirc;&acute;&oacute;&AElig;&eth;&Ecirc;&frac14;&Icirc;&raquo;&Ouml;&Atilde; 
int get(char c){
	for (int i = 0; i < 15; ++i)
		if (translate[i] == c) return i;
}
	 
void init(int i, string s){
	memset(a[i], 0, sizeof(a[i]));
	for (int j = 0; j < s.size(); ++j)
		++a[i][get(s[j])];
}
void init(int index){
	if (!index){
		memset(big, 255, sizeof(big));
		memset(attach, 255, sizeof(attach));
		rocket = false;
		return;
	}
	if (a[index][14]&&a[index][13]) rocket = true;
	int b[3] = {0, 0, 0};
	for (int i = 0; i < 15; ++i)
		for (int k = 1; k < 3; ++k)
			if (a[index][i] >= k) ++b[k];
	//cout<<b[1]<<' '<<b[2]<<endl;
	for (int i = 0; i < 15; ++i)
		for (int cardnumber = 1; cardnumber < 5; ++cardnumber)
			for (int len = 1; i + len <= 15; ++len){
				if ((len > 1)&&(i + len > 12)) break;
				int ok = true;
				if (a[index][i + len - 1] >= cardnumber){
					big[cardnumber][len] = max(big[cardnumber][len], i);
					if ((cardnumber == 3)&&(b[1] >= 2 * len))
						attach[len][1] = max(attach[len][1], i);
					if ((cardnumber == 3)&&(b[2] >= 2 * len))
						attach[len][2] = max(attach[len][2], i);
				}
				else break;
				//cout<<"___"<<i<<' '<<cardnumber<<' '<<len<<endl;
				}
}
bool dfs(int remain, int level, bool fail);
bool dfs(int cardnumber, int remain, int i, int len, int index, int begin, int fail){
	//cout<<cardnumber<<' '<<i<<' '<<len<<' '<<index<<' '<<begin<<endl;
	if (index == len){
		if ((len >= 2)&&(b[len - 1] + b[len - 2] == 27)) return false;
		return dfs(remain - (3 + cardnumber) * len, 4000 + i + len, fail);
	}
	for (int j = begin; j < 15; ++j){
		if (j == i) j = i + len;
		//cout<<a[0][j]<<endl;
		if (a[0][j] >= cardnumber){
			a[0][j] -= cardnumber;
			b[index] = j;
			if (dfs(cardnumber, remain, i, len, index + 1, j + 1,fail)) return true;
			a[0][j] += cardnumber;
		}
	}
	return false;
}
bool dfs(int remain, int level, bool fail){
	/*
	int tot = 0;
	cout<<a[4][1]<<endl;
	cout<<remain<<' '<<level<<' '<<fail<<endl;
	for (int i = 0; i < 15; ++i){
		for (int j = 0; j < a[0][i]; ++j)
			cout<<translate[i];
		tot += a[0][i];
	}
	cout<<"    "<<tot<<endl;
	*/
	if (remain == 0) return true;
	//rocket
	if (level == 0){
		if (a[0][14]&&a[0][13]){
			--a[0][14];
			--a[0][13];
			if (dfs(remain - 2, 1000, fail)) return true;
			++a[0][14];
			++a[0][13];
		}
		return dfs(remain, 1000, fail);
	}
	// bomb
	if (level / 1000 == 1){ 
		for (int i = level % 1000; i < 15; ++i)
			if (a[0][i] == 4){
				if (fail&&(i < big[4][1])) continue;
				a[0][i] -= 4;
				if (dfs(remain - 4, 1000 + i + 1, fail||(i < big[4][1]))) return true;
				a[0][i] += 4;
			}
		return dfs(remain, 2000, fail);
	}
	//cout<<remain<<' '<<level<<' '<<fail<<endl;
	if ((big[4][1] > -1)&&(fail)) return false;
	//cout<<remain<<' '<<level<<' '<<fail<<endl;
	//4 and 2
	if (level / 1000 == 2){
		for (int i = level % 1000; i < 15; ++i)
			if (a[0][i] == 4){
				a[0][i] -= 4;
				for (int p = 1; p <= 2; ++p)
				for (int j = 0; j < 13; ++j)
				if (a[0][j] >= p)
				for (int k = j + 1; k < 15; ++k)
				if (a[0][k] >= p){
					a[0][j] -= p;
					a[0][k] -= p;
					if (dfs(remain - 2 * p - 4, 2000 + i + 1, fail|(big[4][1] >= 0))) return true;
					a[0][k] += p;
					a[0][j] += p;
				}
				a[0][i] += 4;
			}
		return dfs(remain, 3000, fail);
	}
	//cout<<remain<<' '<<level<<' '<<fail<<endl;
	//&Euml;&sup3;&times;&Oacute; 
	if (level / 1000 == 3){
		//cout<<"_____"<<big[1][5]<<endl;
		for (int i = level % 100; i < 15; ++i)
		for (int cardnumber = 1; cardnumber < 4; ++cardnumber)
		for (int len = 1; len + i <= 16; ++len){
			//cout<<i<<len<<endl;
			if ((!((len > 1)&&(i + len > 12)))&&(a[0][i + len - 1] >= cardnumber)){
				//cout<<remain<<' '<<level<<' '<<fail<<endl;
				//cout<<i<<len<<endl;
				a[0][i + len - 1] -= cardnumber;
				if (((!(big[cardnumber][len] > i))||(!fail))&&((len >= limit[cardnumber])||(len == 1)))
					if (dfs(remain - cardnumber * len, 3000 + i, fail||(big[cardnumber][len] > i)))
						return true;
			}else{
				for (int j = 0; j < len - 1; ++j)
					a[0][i + j] += cardnumber;
				break;
			}
		}
		return dfs(remain, 4000, fail);
	}
	//attach
	for (int i = level % 1000; i < 15; ++i)
	for (int cardnumber = 1; cardnumber < 3; ++cardnumber)
	for (int len = 1; len + i <= 16; ++len){
		if ((!((len > 1)&&(i + len > 12)))&&(a[0][i + len - 1] >= 3)){
			a[0][i + len - 1] -= 3;
			if ((!(attach[len][cardnumber] > i))||(!fail)){
				if (dfs(cardnumber, remain, i, len, 0, 0, (attach[len][cardnumber] > i)||fail)) return true;
			}
		}else{
			for (int j = 0; j < len - 1; ++j)
				a[0][i + j] += 3;
			break;
		}
		
	}
	return false;
}
int main(){
	/*
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	*/
	int t, _t;
	for (scanf("%d ", &_t), t = 0; t < _t; ++t){
		for (int i = 0; i < 3; ++i){
			string s;
			cin>>s;
			//cout<<s<<endl;
			init(i, s);
			/*
			for (int j = 0; j < 15; ++j)
				if (a[i][j]) cout<<"("<<j<<")"<<translate[j]<<a[i][j]<<" ";
			cout<<endl;
			*/ 
		}
		for (int i = 0; i < 3; ++i)
			init(i);
		for (int i = 0; i < 15; ++i){
			//cout<<translate[i]<<' '<<a[0][i] + a[1][i] + a[2][i]<<endl;
			if (a[0][i] + a[1][i] + a[2][i] != tot[i] - '0') a[0][i] = a[0][i] / (a[0][i] - a[0][i]);
		}
		if (rocket) big[4][1] = 100;
		if (big[4][1] >= 0){
			for( int i = 1; i <= 3; ++i)
				for (int j = 1; j < 16; ++j)
					big[i][j]  = 100;
			for (int i = 1; i <= 2; ++i)
			for (int j = 0; j < 16; ++j)
				attach[j][i] = 100;
			}
		/* 
		for (int i = 1; i <= 4; ++i)
			for (int j = 1; j <=15; ++j)
				cout<<i<<' '<<j<<' '<<big[i][j]<<endl;
		for (int i =1; i <= 15; ++i)
			cout<<i<<' '<<attach[i][1]<<' '<<attach[i][2]<<endl;
			*/ 
		if (dfs(20, 0, 0)){
			printf("Case %d: Yes\n", t + 1);
		}else printf("Case %d: No\n", t + 1);
	}
}