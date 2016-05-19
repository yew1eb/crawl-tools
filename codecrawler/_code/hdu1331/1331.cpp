#include"iostream"
using namespace std;

int f[25][25][25];

void w(int a,int b,int c)
{
    if(a<=0||b<=0||c<=0)
    {
        f[a][b][c]=1;
    }
    else if(a<b&&b<c)
    {
        f[a][b][c]=f[a][b][c-1]+f[a][b-1][c-1]-f[a][b-1][c];
    }
    else
    {
        f[a][b][c]=f[a-1][b][c]+f[a-1][b-1][c]+f[a-1][b][c-1]-f[a-1][b-1][c-1];
    }
}

int main()
{
    int a,b,c;
    int i,j,k;
    for(i=0;i<21;i++)
        for(j=0;j<21;j++)
            for(k=0;k<21;k++)
                w(i,j,k);
    while(cin>>a>>b>>c)
    {
        if(a==-1&&b==-1&&c==-1)
            break;
        if(a<=0||b<=0||c<=0)
        {
            cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<1<<endl;
            continue;
        }
        else if(a>20||b>20||c>20)
        {
            cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<f[20][20][20]<<endl;
            continue;
        }
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<f[a][b][c]<<endl;
    }
    return 0;
}