#include<iostream>
#include<string>
#include<STDIO.H>
using namespace std;
void draw_c(void)
{
     cout<<"-";
}
void draw_r(int n)
{
    cout<<"|";
    for(int i=0;i<n;i++)
        cout<<" ";
    cout<<"|"<<endl;
}
void draw_c_com(int n)
{
    cout<<"+";
    for(int i=0;i<n;i++)
    {
        draw_c();
    }
    cout<<"+"<<endl;
}
void drwa_r_com(int m,int n)
{
    for(int i=0;i<m;i++)
    {
        draw_r(n);
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
           draw_c_com( n);
           drwa_r_com(m,n);
           draw_c_com( n);
           cout<<endl;
    }
    return 0;
}