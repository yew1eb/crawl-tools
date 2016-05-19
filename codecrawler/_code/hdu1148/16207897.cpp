#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
using namespace std;
const int MAX=101;
int win[MAX],lost[MAX];
int cmp(string a,string b)
{
    if((a=="rock" && b=="scissors") ||
       (a=="scissors" && b=="paper") ||
       (a=="paper" && b=="rock"))
       return 1;
    else if((b=="rock" && a=="scissors") ||
       (b=="scissors" && a=="paper") ||
       (b=="paper" && a=="rock"))
       return -1;
    return 0;
}
int main()
{
    //fstream cin("d:\\test.txt");
    int N,K,i,j,res;
    string x,y;
    bool flag=true;
    while(cin>>N && N)
    {
        cin>>K;
        memset(win,0,sizeof(win));
        memset(lost,0,sizeof(lost));
        while(K--)
        {
            cin>>i>>x>>j>>y;
            res=cmp(x,y);
            if(res==1)
            {
                ++win[i];
                ++lost[j];
            }
            else if(res==-1)
            {
                ++win[j];
                ++lost[i];
            }
        }
        if(!flag)
            cout<<endl;
        flag=false;
        for(i=1;i<=N;++i)
        {
            if(win[i]+lost[i])
                cout<<fixed<<setprecision(3)<<win[i]*1.0/(win[i]+lost[i])<<endl;
            else
                cout<<'-'<<endl;
        }
    }
    return 0;
}
