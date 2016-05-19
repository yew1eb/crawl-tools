#include"iostream"
using namespace std;
int main()
{
    int n;
    char ch[1000];
    int i;
    scanf("%d\n",&n); // cin>>n;cout<<endl;
    while(n--)
    {
       gets(ch);
       int count=0;
           if(!(ch[0]>='a'&&ch[0]<='z')&&ch[0]!='_'&&!(ch[0]>='A'&&ch[0]<='Z'))  count=1;
        else
        {
         for(i=0;i<strlen(ch);i++)
         {
            if(!(ch[i]>='a'&&ch[i]<='z')&&!(ch[i]>='0'&&ch[i]<='9')&&ch[i]!='_'&&!(ch[i]>='A'&&ch[i]<='Z'))
            {
                count=1; break;
            }
         }
        }
    
           if(count==0) cout<<"yes"<<endl;
              else cout<<"no"<<endl;
    }
    return 0;
}