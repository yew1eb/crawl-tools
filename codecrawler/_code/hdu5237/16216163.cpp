/**
HDU 5237 Base64
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#define maxn 3005
#define INF 0x3fffffff
#define ll __int64
using namespace std;
char ch[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};
string base64(string s){
    string ans;
    ll temp=0;
    if(s.size()==3){
        for(int i=0;i<3;i++){
            temp<<=8;
            temp+=s[i];
        }
        for(int i=0;i<4;i++){
            ans=ch[temp%64]+ans;
            temp>>=6;
        }
    }
    else if(s.size()==2){
        for(int i=0;i<2;i++){
            temp<<=8;
            temp+=s[i];
        }
        temp<<=2;
        for(int i=0;i<3;i++){
            ans=ch[temp%64]+ans;
            temp>>=6;
        }
        ans+='=';
    }
    else{
        for(int i=0;i<1;i++){
            temp<<=8;
            temp+=s[i];
        }
        temp<<=4;
        for(int i=0;i<2;i++){
            ans=ch[temp%64]+ans;
            temp>>=6;
        }
        ans+="==";
    }
    return ans;
}
int main(){
    int T,k;
    string s,temp,t;
    cin>>T;
    for(int h=1;h<=T;h++){
        cin>>k>>s;
        while(k--){
            temp="";
            for(int i=0;i<s.size();i+=3){
                if(i+3<s.size())
                    t=s.substr(i,3);
                else
                    t=s.substr(i,s.size()-i);
                temp+=base64(t);
            }
            s=temp;
        }
        printf("Case #%d: ",h);
        cout<<s<<endl;
    }
    return 0;
}