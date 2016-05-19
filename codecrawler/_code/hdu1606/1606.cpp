#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
struct Info
{
    string s;
    int n;
};
bool comp(const Info &a,const Info &b)
{
    if(a.n!=b.n) return a.n>b.n;
    else return a.n>b.n;
}
int main()
{
    vector<string>v;//保存关键词
    vector<Info>vv;//保存语句行结构体
    char ss[71];
    string s,t;
    int n,m,line=0;
    Info info;
    while(cin>>m>>n)
    {
        v.clear();
        vv.clear();
        line++;//案例号
        //读入关键词
        for(int i=0;i<m;i++)
        {
            cin>>s;
            v.push_back(s);
        }
        //忽略空行，这句至关重要
        //因为cin读入单项后，仍然有一个回车符留在本行
        //这样，直接转入cin.getline()读入一整行，第一次读入的是一个空行
        cin.getline(ss,71);
        for(int i=0;i<n;i++)
        {
            cin.getline(ss,71);
            s=ss;
            //如果是大写字母则转换为小写字母
            for(int j=0;j<s.size();j++)
                if(s[j]>='A'&&s[j]<='Z')
                    s[j]+=32;
            info.n=0;
            for(int j=0;j<v.size();j++)
                for(int k=0;k<s.size()-v[j].size();k++)
                {
                    //取出一个字串
                    t="";
                    int p;
                    for(p=k;p<k+v[j].size();p++)
                        t+=s[p];
                    //如果子串在最开头，子串后一位置都不能是字母
                    if(k==0&&t==v[j]&&(s[p]<'a'||s[p]>'z'))
                        info.n++;
                    //如果子串出现在其他位置，前后位置不能是字母
                    else if(t==v[j]&&(s[p]<'a'||s[p]>'z')&&(s[k-1]<'a'||s[k-1]>'z'))
                        info.n++;
                }
            info.s=ss;
            vv.push_back(info);
        }
        sort(vv.begin(),vv.end(),comp);
        cout<<"Excuse Set #"<<line<<endl;
        for(int i=0;i<vv.size();i++)
        {
            if(i!=0&&vv[i].n<vv[i-1].n) break;
            else cout<<vv[i].s<<endl;
        }
        cout<<endl;
    }
    return 0;
}