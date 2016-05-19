#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int n,i,j,k;
    bool t[1010];//å­è¿åºæ æåµ
    char a[1010],b[1010];
    while(cin>>n>>a>>b)
    {
        stack<char>train;
        i=j=k=0;
        while(i<n)
        {    
        //æ ç©ºï¼æ é¡¶ï¼=b[i]ï¼j<nï¼åæ     
            if(train.empty()||train.top()!=b[i]&&j<n)        
            { 
                train.push(a[j++]);
                t[k++]=1;
            }
            else if(train.top()==b[i])
            {
                train.pop();
                t[k++]=0;
                i++;
            }
            else   break;//æ­¤æ¶jä¸å®==n
        }    
        if(train.empty())
        {
            cout<<"Yes."<<endl;
            for(i=0;i<k;i++)                
                if(t[i]) cout<<"in"<<endl;
                else cout<<"out"<<endl;
        }
        else cout<<"No."<<endl;
        cout<<"FINISH"<<endl;
    }
    return 0;
}