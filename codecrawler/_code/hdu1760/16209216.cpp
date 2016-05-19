#include<map>
#include<string>
#include<iostream>
#include<stdio.h>

using namespace std;

//ä¸ä¸ªç¶æè¥æä¸ä¸ªå­ç¶æä¸ºå¿è´¥æï¼åæ­¤ç¶æä¸ºå¿èæ
//dfs
map<string,int>sg;//0è¡¨ç¤ºä¸å­å¨ï¼å­å¨åè¿åvalue
map<string,bool>is;//1è¡¨ç¤ºå­å¨ 0è¡¨ç¤ºä¸å­å¨
int n,m;

bool judge(string str,int i,int j)
{
    if(str[i * m + j] == '1' || str[i * m + j + 1] == '1' || str[i * m + m + j] == '1' || str[i * m + m + j + 1] == '1')
        return false;
    return true;
}
void input(string &str,int i,int j)
{
    str[i * m + j]=str[i * m + j + 1]=str[i * m + m + j] = str[i * m + m + j + 1] = '1';
}
int DFS(string str)
{
    //è¥å­å¨
    if(is[str])
    return sg[str];
    //è¥ä¸å­å¨
    for(int i = 0;i < n - 1;i++)
    {
        for(int j = 0;j < m - 1;j++)
        {
            //å½åç¹å¯è¡
            if(judge(str,i,j))
            {
                //ä¸ä¸é¢å­
                string temp = str;
                input(temp,i,j);
                //å­ç¶æå­å¨å¿è´¥æ
                if(DFS(temp) == 0)
                {
                    //æ­¤ç¶æä¸ºå¿èç¶æï¼æ è®°
                    is[str] = 1;
                    sg[str] = 1;
                    return 1;
                }
            }
        }
    }
    //æ­¤ç¶æä¸ºå¿è´¥ç¶æï¼æ è®°
    is[str] = 1;
    sg[str] = 0;
    return 0;
}
int main()
{
    string str;
    string temp;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        str="";
        sg.clear();
        is.clear();
        for(int i = 0;i < n;i++)
        {
            cin >> temp;
            str += temp;
        }
        if(DFS(str))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return   0;
}
