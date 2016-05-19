/*
  处理字符串，正负号以及小数点的位置，
  字符指针以字符串数组间的传递问题，
  字符串的结束标志是NULL，处理到后
  即停止
*/
#include<iostream>
#include<string>
using namespace std;

#define N 1000000
char a[N],b[N];

bool judge_p_m(char c[],char d[])   //正负号的处理
{
    if((c[0]=='-' && d[0]=='-') || (c[0]!='-' && d[0]!='-'))
        return true;
    else
        return false;
}

char* judge_dec(char e[])
{
    int i,len,rem=-1;

    if( e[0]=='+' || e[0]=='-' ) //首字符是+或-时，要去掉
        e++;

    len=strlen(e);

    for(i=0;i<len;i++)    //搜索小数点位置
        if(e[i]=='.')
        {
            rem=i;
            break;
        }

    if(rem==-1)         //无小数点
    {
        for(i=0;i<len;i++)
            if(e[i]=='0')
            {
                e[i]=NULL;
            }
            else
                break;
    }
    else if(rem==0)    //小数点在最前面
    {        
        for(i=len-1;i>=0;i--)
            if(e[i]=='0' || e[i]=='.')
                e[i]=NULL;
            else
                break;

        if(e[0]=='.')
        {
            for(i=strlen(e);i>0;i--)
                e[i]=e[i-1];
                
            e[0]='0';
            e[strlen(e)+1]=NULL;
        }
    }
    else if(rem==len-1)   //小数点在最后面
    {
        e[rem]=NULL;

        for(i=0;i<len-1;i++)
            if(e[i]=='0')
            {
                e[i]=NULL;
            }
            else
                break;
    }
    else       //小数点在中间
    {
        for(i=0;i<rem-1;i++)
        {
            if(e[i]=='0')
            {
                e[i]=NULL;
            }
            else
                break;
        }

        for(i=len-1;i>=rem;i--)
        {
            if(e[i]=='0' || e[i]=='.')
                e[i]=NULL;
            else
                break;
        }

        if( e[rem]==NULL && e[rem-2]==NULL && e[rem-1]=='0' )
            e[rem-1]=NULL;
    }

    for(i=0;i<len;i++)   //搜索字符串第一个非NULL字符的位置
        if(e[i]!=NULL)
        {
            e=e+i;
            break;
        }

    return e;
}

int main()
{
    while(cin>>a>>b)
    {
        if( judge_p_m(a,b) )
        {
            if( strcmp( judge_dec(a), judge_dec(b) )==0 )  
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else
        {
            if( strlen( judge_dec(a) )==0 && strlen( judge_dec(b) )==0 )
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }

    return 0;
}