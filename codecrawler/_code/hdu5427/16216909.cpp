#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

struct node{
    int year;
    string name;
}no[110];

bool cmp(node a,node b){
    return a.year > b.year;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        string strr;
        getchar();
        for(int i = 0; i < n; i++){
            getline(cin,strr);
            int l = strr.size();
            int year = 0;
            for(int j = l-4; j < l; j++)
                year = year*10+(strr[j]-'0');
            no[i].name = strr.substr(0,l-5);
            no[i].year = year;
        }
        sort(no,no+n,cmp);
        for(int i = 0; i < n; i++)
            cout<<no[i].name<<endl;
    }
    return 0;
}
