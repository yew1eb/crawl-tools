#include <stack>
#include <cstdio>
#include <cstring>
using namespace std;
bool check(char,char);
void solve();
char str[205],ch;
double tmp,a,b;
int i,len;
stack<double> v;
stack<char> c;
int main()
{
    while(gets(str)!=NULL)
    {
        if(!strcmp(str,"0"))
        {
            break;
        }
        solve();
    }
    return 0;
}
void solve()
{
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]==' ')
        {
            continue;
        }
        if(str[i]>='0' && str[i]<='9')
        {
            tmp=0;
            while(str[i]>='0' && str[i]<='9')
            {
                tmp*=10;
                tmp+=str[i]-'0';
                i++;
            }
            v.push(tmp);
        }
        if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/')
        {
            if(c.empty())
            {
                c.push(str[i]);
            }else{
                ch=c.top();
                while(check(ch,str[i]))
                {
                    a=v.top();
                    v.pop();
                    b=v.top();
                    v.pop();

                    c.pop();

                    switch(ch)
                    {
                        case '+':
                            v.push(a+b);
                            break;
                        case '-':
                            v.push(b-a);
                            break;
                        case '*':
                            v.push(a*b);
                            break;
                        case '/':
                            v.push(b/a);
                            break;
                    }

                    if(c.empty())
                    {
                        break;
                    }else{
                        ch=c.top();
                    }
                }
                c.push(str[i]);
            }
        }
    }
    while(!c.empty())
    {
        a=v.top();
        v.pop();
        b=v.top();
        v.pop();

        ch=c.top();
        c.pop();

        switch(ch)
        {
            case '+':
                v.push(a+b);
                break;
            case '-':
                v.push(b-a);
                break;
            case '*':
                v.push(a*b);
                break;
            case '/':
                v.push(b/a);
                break;
        }
    }

    printf("%.2f\n",v.top());
    v.pop();
}
bool check(char ch1,char ch2)
{
    if(ch1=='*'||ch1=='/')
    {
        return true;
    }
    if(ch2=='+'||ch2=='-')
    {
        return true;
    }
    return false;
}
