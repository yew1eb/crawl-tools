#include "iostream"
using namespace std;
#define MaxLength 200002
char s[MaxLength];
int b[MaxLength];
int main()
{
    int t,n,i,j,k,q,l;
    cin>>t;
    while (t--)
    {
        cin>>n>>s;k=0;q=0;
        //memset(b,'/0',sizeof(b));
        for (i=0;i<n;i++)
        {
            if (s[i]==s[0])
            {
                b[k++]=i+1;q++;
            }
        }
        q%=10007;        
        for (i=1;i<n;i++)
        {
            l=k;k=0;
            for (j=0;j<l;j++)
            {
                if (s[i]==s[b[j]])
                {b[k++]=b[j]+1;q++;}
            }
            b[k]='/0';q%=10007;
        }
        cout<<q%10007<<endl;
    }
    return 0;
}