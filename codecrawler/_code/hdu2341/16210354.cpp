#include<iostream>
#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
const int MOVE=10;//åéæºç§»å¨ä¸å±ç¨æ¶ 
const int ROTATE=5;//ä¼ éå¸¦ç§»å¨ä¸ä¸ªè½¦ä½ç¨æ¶ 
pii loc[2510];//è®°å½æ¯è¾è½¦çä½ç½® 
int car[50][50];
int p[50];//è®°å½ä¼ éå¸¦çä½ç½® 
int h,l;
int cnt;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%d%d",&h,&l);
        for(int i=0;i<h;i++)
            for(int j=0;j<l;j++)
            {
                scanf("%d",&car[i][j]),cnt=max(cnt,car[i][j]);//ç»è®¡éè¦ååºçè½¦çæ°é 
                if(car[i][j]!=-1)//è®°å½è½¦çä½ç½® 
                    loc[car[i][j]].first=i,loc[car[i][j]].second=j;
            }
        for(int i=0;i<h;i++)//åå§ç¶æä¼ éå¸¦ä½äºç¬¬0ä¸ªè½¦ä½ 
            p[i]=0;
        int tot=0;//åå§åæ»ç¨æ¶ 
        for(int c=1;c<=cnt;c++)
        {
            int i=loc[c].first;
            int j=loc[c].second;
            tot+=2*i*MOVE;//åéç¨æ¶ 
            tot+=ROTATE*min((p[i]-j+l)%l,(j-p[i]+l)%l);//ä¼ éå¸¦å¯é¡ºæ¶éä¹å¯éæ¶é,ç®åºæç­è·ç¦» 
            p[i]=j;//è®°å½ä¼ éå¸¦ä½ç½®= 
        }
        printf("%d\n",tot);
    }
    return 0;
}