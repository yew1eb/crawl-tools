#include <iostream>
#include <cmath> 
#include <set>
using namespace std;
int main()
{
    int n,k,tmp,ans;
    while(scanf("%d",&n)!=EOF)
    {
        set <int> store;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&tmp);
            store.insert(tmp);
        }
        scanf("%d",&k);
        if(n==store.size())
        {
            ans=n-k;//åå¥½ï¼å°±ç´æ¥å 
        }
        else
        {
            tmp=n-store.size();//å¯ä»¥ä¸åå°çåæä¸ï¼æä¾çæå¤§æ°é 
            if(tmp>=k)//å¤åï¼ï¼æ°éä¸å 
            ans=store.size();
            else      //ä¸å¤åï¼åå»å¤ä½çåï¼ååç§ç±»æ° 
            ans=store.size()-(k-tmp);
        }
        printf("%d\n",ans);
    }
    return 0;
}