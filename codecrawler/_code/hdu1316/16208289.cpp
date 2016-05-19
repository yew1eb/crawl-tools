#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

string add(string s1,string s2)
{
     if(s1.length()<s2.length())
     {
          string temp=s1;
          s1=s2;
          s2=temp;
     }
     for(int i=s1.length()-1,j=s2.length ()-1;i>=0;i--,j--)
     {
          s1[i]=char(s1[i]+(j>=0?s2[j]-'0':0));
          if(s1[i]-'0'>=10)
          {
              s1[i]=char((s1[i]-'0')%10+'0');
              if(i)
                   s1[i-1]++;
              else
                   s1='1'+s1;
          }
     }
     return s1;
}

string str[1005],a,b;

int main()
{
    int i;
    str[1] = "1";
    str[2] = "2";
    for(i = 3;i<1005;i++)
    {
        str[i] = add(str[i-2],str[i-1]);
        //printf("%s\n",str[i]);
    }
    while(cin >> a >> b)
    {
        if(a=="0" && b == "0")
        break;
        int head,end,cnt = 0,len_a,len_b,len;
        len_a = a.length();
        len_b = b.length();
        for(i = 1;i<1005;i++)
        {
            len = str[i].length();
            if(len<len_a)
            continue;
            else if(len == len_a && str[i]>=a)
            {
                head = i;
                break;
            }
            else if(len > len_a)
            {
                head = i;
                break;
            }
        }
        for(i = 1004;i>=1;i--)
        {
            len = str[i].length();
            if(len>len_b)
            continue;
            else if(len == len_b && str[i]<=b)
            {
                end = i;
                break;
            }
            else if(len < len_b)
            {
                end = i;
                break;
            }
        }
        printf("%d\n",end-head+1);
    }

    return 0;
}
