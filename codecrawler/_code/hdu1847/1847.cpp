#include <map>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int sg[1001];
int num[]={10,1,2,4,8,16,32,64,128,256,512};
bool hash[1001];

void init()
{
    int i,j;
    memset(sg,0,sizeof(sg));
    sg[0]=0;
    for(i=1;i<=1000;i++)
    {
        memset(hash,0,sizeof(hash));
        for(j=1;j<=num[0];j++)
        {
            if(i<num[j])
                break;
            hash[sg[i-num[j]]]=1;
        }
        for(j=0;j<=1000;j++)
        {
            if(!hash[j])
            {
                sg[i]=j;
                break;
            }
        }
    }
}

int main()
{
    init();
//    for(int i=0;i<=20;i++)
//        printf("i:%d  sg:%d\n",i,sg[i]);
    int n;
    while(cin>>n)
    {
        if(!sg[n])
            cout<<"Cici"<<endl;
        else
            cout<<"Kiki"<<endl;
    }
    return 0;
}