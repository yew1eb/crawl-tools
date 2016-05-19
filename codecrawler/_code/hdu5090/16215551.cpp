/*é¢æï¼ç»åºnä¸ªæ°åä¸ä¸ªæ´æ°Kï¼é£nä¸ªæ°æ¯ä¸ªåªè½å ä¸kçæ­£åæ°æèä¸å ï¼é®è½å¦ä½¿åºååæ1~nçåºåã

ç±äºæ°æ®éè¾å°ï¼æä»¥å¯ä»¥ç´æ¥æ´åäºãå·ä½è¿ç¨ç´æ¥çä»£ç å§ï¼è¾å®¹æçæææçã*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include<climits>
#include<string>
#include<vector>
using namespace std;
vector<int>vec;
vector<int>::iterator it;
int a[105];

int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        vec.clear();
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        bool flag=1;
        for(int i=n;i>=1;i--) vec.push_back(a[i]);
        for(int i=n;i>=1;i--) 
        {
            
                flag=0;
                it=vec.begin();
                while(it!=vec.end())
                {
                    int val=(*it);
                    if((i-val)%k==0&&i>=val) { flag=1;it=vec.erase(it);break;}
                    it++;
                }
                if(!flag) break;
        }
        if(flag) printf("Jerry\n");
        else printf("Tom\n");
    }
    return 0;
}