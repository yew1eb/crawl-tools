#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char w[10005],t[1000005];
int next[10005];
int N,M;
void get_next()
{
    int i=0,j=next[0]=-1;
    while(i<M)
    {
        if(j==-1||w[i]==w[j])
        {
            i++,j++;
            next[i]=j;
        }
        else j=next[j];
    }
}

int kmp()
{
    int i=0,j=0;
    int num=0;
    while(i<N)
    {
        if(j==-1||t[i]==w[j])
        {
            i++,j++;
        }
        else j=next[j];
        if(j==M)
        {
            num++;
            j=next[j];
        }

    }
  cout<<num<<endl;
}
int main()
{
    int c,h,i;
    while(cin>>c)
    {
        while(c--)
        {
            scanf("%s",w);
        scanf("%s",t);
        N=strlen(t);
        M=strlen(w);
        get_next();
        kmp();
        }
    }
}