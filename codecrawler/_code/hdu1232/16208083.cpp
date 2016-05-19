#include<iostream>
using namespace std;

const int MAX=1000;
int father[MAX];

void initial(int n)    //åå§å
{
    for(int i=1;i<=n;i++)
        father[i]=i;
}

int find(int x)    //æ¥æ¾
{
    while(father[x]!=x)
        x=father[x];

    return x;
}

void combine(int a,int b)   //åå¹¶
{
    int tmpa=find(a);
    int tmpb=find(b);

    if(tmpa!=tmpb)
        father[tmpa]=tmpb;
}

int main()
{
    int i,n,m,a,b,tmp;

    while(cin>>n,n)
    {
        initial(n);

        cin>>m;

        for(i=1;i<=m;i++)
        {
            cin>>a>>b;
            combine(a,b);
        }

        tmp=0;
        for(i=1;i<=n;i++)   //ç¡®å®è¿éåéä¸ªæ°
        {
            if(father[i]==i)
                tmp++;
        }

        cout<<tmp-1<<endl;
    }

    return 0;
}