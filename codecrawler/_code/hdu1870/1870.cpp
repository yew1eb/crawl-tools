#include<iostream>
#include<stack>
using namespace std;

const int Maxn=1000+10;
char target[Maxn];

int main()
{
    stack<char> s;
    int count,len,i;
    while(~scanf("%s",target))
    {
        while(!s.empty ())//清空栈
            s.pop ();
        len=strlen(target);
        i=0;
        count=0;
        while(i<len)
        {
            if(target[i]=='(')
            {
                s.push (target[i]);//入栈
                i++;
                count++;
            }
            else
            {
                if(target[i]==')')
                {
                    s.pop ();//释放空间
                    count--;
                    i++;
                }
                else//'B'
                    break;
            }
        }
        if(!s.empty ())//若栈不为空，则说明有盒子包装
            printf("%d",count);
        else
            printf("0");
        printf("\n");
    }
    return 0;
}