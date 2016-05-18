#include <cstdio>  
#include <iostream>  
#include <cstring>  
#include <cmath>  
#include <algorithm>  
using namespace std;  
int getHP(string a)  
{  
    int ans=0;  
    for(int i=0;i<a.length();i++)  
    {  
        ans+=(83-a[i])*(83-a[i]);  
        ans%=97;  
    }  
    return 300-ans;  
}  
int getSTR(string a)  
{  
    int ans=1;  
    for(int i=0;i<a.length();i++)  
    {  
        ans*=a[i];  
        ans%=79;  
    }  
    return 22+ans;  
}  
int getSPD(string a)  
{  
    int ans=0;  
    for(int i=0;i<a.length();i++)  
        for(int j=i+1;j<a.length();j++)  
        {  
            ans+=a[i]*a[j];  
            ans%=11;  
        }  
    return ans;  
}  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    while(t--)  
    {  
        string a,b;  
        cin>>a>>b;  
        int a_HP=getHP(a);  
        int b_HP=getHP(b);  
        int a_STR=getSTR(a);  
        int b_STR=getSTR(b);  
        int a_SPD=getSPD(a);  
        int b_SPD=getSPD(b);  
  
        int a_atk=a_HP/b_STR,b_atk=b_HP/a_STR;  
        if(a_HP%b_STR!=0)  
            a_atk++;  
        if(b_HP%a_STR!=0)  
            b_atk++;  
  
        a_atk*=(20-b_SPD); // 被搞死的时间  
        b_atk*=(20-a_SPD);  
  
        if(a_atk<b_atk)  
            printf("lose\n");  
        else if(a_atk==b_atk)  
            printf("tie\n");  
        else  
            printf("win\n");  
    }  
    return 0;  
}  