#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    int t,n,nc;
    cin>>t;
    while(t--){
        string s;
        map<string,int> snum;
        cin>>n>>nc>>s;
        int k=0;
        int len=s.length();
        for(int i=0;i<=len-n;i++){
            string ss=s.substr(i,n);
            if(snum[ss]==0){
                k++;
                snum[ss]=1;
            }
        }
        cout<<k<<endl;
        if(t>1) cout<<endl;
    }
    return 0;
}
