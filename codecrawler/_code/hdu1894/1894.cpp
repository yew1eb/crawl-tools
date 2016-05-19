#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int T,N;
string strcin[50005];

bool isPrefix(string s1,string s2)
{
    int len1,len2,i;
    string str;

    len1=s1.length();
    len2=s2.length();
    if(len1>len2)
    {
        str=s1;
        s1=s2;
        s2=str;
    }
    else if(len1==len2)  //There are no same words in two different lines.
    {
        return false;
    }
    else
    {}
    for(i=0;i<(int)s1.length();i++)
    {
        if(s1[i]!=s2[i])
            return false;
    }
    return true;
}

bool cmp(string s1,string s2)
{
    if(s1.compare(s2)<0)
        return true;
    return false;
}

int main()
{
    int i,j,count;
    while(cin>>T)
    {
        while(T--)
        {            
            cin>>N;
            for(i=0;i<N;i++)
            {
                cin>>strcin[i];
            }
            sort(strcin,strcin+N,cmp);
            count=0;
            for(i=0;i<N-1;i++)
            {
                for(j=i+1;j<N;j++)
                {
                    if(isPrefix(strcin[i],strcin[j]))
                        count++;
                    else
                        break;
                }
            }
            if(count>11519)
                count=count%11519;

            cout<<count<<endl;
        }
    }

    return 0;
}