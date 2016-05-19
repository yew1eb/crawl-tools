#include <iostream>
#include <string>
using namespace std;

int n,sum;

class dynamicArray
{
private:
    int num;
public:
    dynamicArray *next;
    //    构造函数
    dynamicArray():num(0),next(0)
    {
    }
    dynamicArray(int n):num(n),next(0)
    {
    }
    //    添加数字
    void addNum(int n)
    {
        dynamicArray *p=this;
        while(p->next)
            p=p->next;
        p->next=new dynamicArray(n);
    }
    //    获取数字
    int getNum()
    {
        return num;
    }
    //    获取Next地址
    dynamicArray* getNext()
    {
        return next;
    }
    //    清空
    void clean()
    {
        dynamicArray *p=this;
        if(p->next)
        {
            p->next->clean();
            delete p->next;
            p->next=0;
        }
    }
};

struct sword
{
    string name;
    int value;
    int num;
    dynamicArray a;
} s[100];

int find(string &str)
{
    int i;
    for(i=0;i<n;i++)
        if(s[i].name==str)
            return i;
    return -1;
}

void getValue(int t,int num)
{
    dynamicArray *p;
    if(s[t].num>=num)
        s[t].num-=num;
    else
    {
        num-=s[t].num;
        s[t].num=0;
        if(s[t].value==0)
        {
            p=s[t].a.next;
            while(p)
            {
                getValue(p->getNum(),num);
                p=p->next;
            }
        }
        else
            sum+=s[t].value*num;
    }
}

int main()
{
    char ch;
    string str;
    int m,i,j,t,num;
    dynamicArray a,*p;
    while(cin>>n)
    {
        sum=0;
        memset(s,0,sizeof(s));
        for(i=0;i<n;i++)
        {
            cin>>s[i].name;
            cin>>s[i].value;
        }
        cin>>m;
        for(i=0;i<m;i++)
        {
            cin>>str>>num;
            if((t=find(str))==-1)
            {
                s[n].name=str;
                s[n++].num=num;
            }
            else
            {
                s[t].num=num;
            }
        }
        cin>>m;
        for(i=0;i<m;i++)
        {
            a.clean();
            while(cin>>str>>ch)
            {
                a.addNum(find(str));
                if(ch=='=')
                {
                    cin>>str;
                    if((t=find(str))==-1)
                    {
                        s[n].name=str;
                        t=n++;
                    }
                    s[t].a.next=a.getNext();
                    a.next=0;
                    break;
                }
            }
        }
        cin>>m;
        for(i=0;i<m;i++)
        {
            cin>>str>>num;
            t=find(str);
            getValue(t,num);
        }
        cout<<sum<<endl;
    }
}