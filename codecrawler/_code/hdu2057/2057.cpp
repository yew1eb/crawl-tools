#include<iostream>
#include<string>
#include<algorithm>

struct num_t
{
	int flag;
	std::string str;
};
int conv(char c)
{
	if(c>='0'&&c<='9'){
		return c-'0';
	}else{
		return c-'A'+10;
	}
}
char r_conv(int n)
{
	if(n<10){
		return '0'+n;
	}else{
		return 'A'+n-10;
	}
}

bool cmp_str(const std::string& l,const std::string& r){
	if(l.size()>r.size()){
		return true;
	}else if(l.size()<r.size()){
		return false;
	}
	return l>r;
}
std::string plus(const num_t& l,const num_t & r)
{
	std::string res;
	int cap=0;
	char l_n,r_n;
	int tmp;
	int size=std::max(l.str.size(),r.str.size());
	if((l.flag==1&&r.flag==1)||(l.flag==-1&&r.flag==-1)){
		for(int i=0;i!=size;i++){
			l_n=i>l.str.size()-1?'0':l.str[l.str.size()-1-i];
			r_n=i>r.str.size()-1?'0':r.str[r.str.size()-1-i];
			tmp=conv(l_n)+conv(r_n)+cap;
			if(tmp>=16){
				res.insert(res.begin(),r_conv(tmp%16));
				cap=1;
			}else{
				res.insert(res.begin(),r_conv(tmp));
				cap=0;
			}
		}
		if(cap==1){
			res.insert(res.begin(),'1');
		}
		if(l.flag==-1){
			res.insert(res.begin(),'-');
		}
	}else{
		if(l.str==r.str){
			return "0";
		}
		bool flag=true;
		if(((cmp_str(l.str,r.str))&&l.flag==-1)||((!cmp_str(l.str,r.str))&&r.flag==-1)){
			flag=false;
		}
		std::string l_s,r_s;
		if(!cmp_str(l.str,r.str)){
			l_s=r.str;
			r_s=l.str;
			
		}else{
			l_s=l.str;
			r_s=r.str;
		}

		for(int i=0;i!=size;i++){
			l_n=i>l_s.size()-1?'0':l_s[l_s.size()-1-i];
			r_n=i>r_s.size()-1?'0':r_s[r_s.size()-1-i];
			tmp=conv(l_n)-cap-conv(r_n);
			if(tmp<0){
				res.insert(res.begin(),r_conv(16+tmp));
				cap=1;
			}else{
				res.insert(res.begin(),r_conv(tmp));
				cap=0;
			}
		}
		int  k=0;
		if(res[0]=='0'){
			for(k=1;k!=res.size();k++){
				if(res[k]!='0'){
					break;
				}
			}
		}
		res=res.substr(k);
		if(flag==false){
			res.insert(res.begin(),'-');
		}
	}

	return res;
}
num_t num[2];
std::string str[2];
int main()
{
	while (std::cin>>str[0]>>str[1]){
		for(int i=0;i!=2;i++){
			if(str[i][0]=='+'){
				num[i].flag=1;
				num[i].str.assign(str[i].substr(1));
			}else if(str[i][0]=='-'){
				num[i].flag=-1;
				num[i].str.assign(str[i].substr(1));
			}else{
				num[i].flag=1;
				num[i].str.assign(str[i]);
			}
		}
		std::cout<<plus(num[0],num[1])<<std::endl;
		memset(num,0,sizeof(num));
	}
}