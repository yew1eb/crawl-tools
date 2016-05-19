/*
HDU 5124 æå¤§åºé´éå ç¹ï¼ç¦»æ£åï¼ 
æä»¬å¯ä»¥å°ä¸æ¡çº¿æ®µ [xi,yi]åä¸ºä¸¤ä¸ªç«¯ç¹xiå(yi)+1ï¼å¨xiæ¶è¯¥ç¹ä¼æ°å å¥ä¸æ¡çº¿æ®µï¼
åæ ·çï¼å¨ (yi)+1æ¶è¯¥ç¹ä¼åå°ä¸æ¡çº¿æ®µï¼å æ­¤å¯¹äº2nä¸ªç«¯ç¹è¿è¡æåºï¼
ä»¤xiä¸ºä»·å¼1ï¼yiä¸ºä»·å¼-1ï¼é®é¢è½¬åæäºæå¤§åºé´åï¼å ä¸º1ä¸å®å¨-1ä¹åï¼
å æ­¤é®é¢åææå¤§åç¼åï¼æä»¬å¯»æ¾æå¤§å¼å°±æ¯ç­æ¡
5
1 2 
2 2
2 4
3 4

1 1
2 1
2 1
3 -1
3 -1
3 1
5 -1
5 -1
ä¸º3 
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector< pair<int,int> > v;
int main()
{
    int t,n,i,x,max,ans;
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        scanf("%d",&n); 
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            v.push_back(make_pair(x,1));
            scanf("%d",&x);
            v.push_back(make_pair(x+1,-1));
        }
        sort(v.begin(),v.end());
        ans=0;
        max=0;
        for(i=0;i<v.size();i++)
        {
            ans+=v[i].second;
            if(ans>max)
                max=ans;
        }
        printf("%d\n",max);
    }
    return 0;
} 