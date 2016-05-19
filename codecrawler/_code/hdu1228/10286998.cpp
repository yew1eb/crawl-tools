#include<iostream>
#include<string>
using namespace std;
int trans(string a)
{
        string digital_name[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
        for(int i=0;i<10;i++)
        {
                if(a==digital_name[i])
                {
                        return i;
                }
        }
}

int main()
{
        int a,b;
        string buffer;
        do{
                a=0;
                b=0;
        while(cin>>buffer&&buffer!="+")
                a=a*10+trans(buffer);
        while(cin>>buffer&&buffer!="=")
                b=b*10+trans(buffer);
        if(a+b!=0)
        cout<<a+b<<endl;
        else
                ;
        
        }while(a+b!=0);
        system("pause");
        return 0;
}