/*
hdu 1107
http://acm.hdu.edu.cn/showproblem.php?pid=1107
Exe.Time    Exe.Memory        Code Len.    Language 
0MS            300K            4146 B        C++ 
Author:WonderCoder
Email:wuguojian@163.com
*/
#include <iostream>
#include <fstream>
using namespace std;
int N,num,X[13][13];

struct persion
{
    char v;        //é¨æ´¾
    int x,y;    //åæ 
    int MP;        //åå
    int DP;        //æ­¦å
    int HP;        //çå½
    bool isF;    //æ¯å¦æ ¼æè¿
    int dir;    //æ¹å1ä¸ºæ­£æ¹åï¼0ä¸ºåæ¹å  å°æçæ­£æ¹åæ¯ä¸ æ­¦å½çæ­£æ¹åæ¯å³ï¼å³¨ççæ­£æ¹åæ¯å³ä¸
}p[1000];

//æ¾ç¤ºæ ¼æè¿åä¸ªé¨æ´¾çç»æ
void ShowRest()
{
    int ss,sw,se,hs,hw,he;
    ss = sw = se = hs = hw = he =0;
    for(int i=0;i<num;i++)
    {
        switch(p[i].v)
        {
        case 'S':
            if(p[i].HP>0)    //å¦æçå½å¼ä¸ºå°äºæç­äº0ï¼è¯´ææ­»äº
            {ss++; hs+=p[i].HP;}break;
        case 'W':
            if(p[i].HP>0)
            {sw++; hw+=p[i].HP;}break;
        case 'E': 
            if(p[i].HP>0)
            {se++; he+=p[i].HP;}break;
        }
    }
    cout<<ss<<" "<<hs<<endl;    //å°æ
    cout<<sw<<" "<<hw<<endl;    //æ­¦å½
    cout<<se<<" "<<he<<endl;    //å³¨ç
    cout<<"***"<<endl;
}

//è¿åä¼¤å®³å¼
int getDPS(int i)
{
    int DPS = 0;
    switch(p[i].v)
    {
    case 'S':DPS = (0.5*p[i].MP+0.5*p[i].DP)*(p[i].HP+10)/100;
                 break;
    case 'W':DPS = (0.8*p[i].MP + 0.2*p[i].DP)*(p[i].HP+10)/100;
        break;
    case 'E':DPS = (0.2*p[i].MP + 0.8*p[i].DP)*(p[i].HP+10)/100;
        break;
    }
    return DPS;
}

//ç§»å¨
void move()
{
    int i;
    for(i=0;i<num;i++)
        {
            p[i].isF = false;
            X[p[i].y][p[i].x]--;                    //å½åä½ç½®çäººæ°-1ï¼å ä¸ºè¿ä½å¤§ä¾ è¦èµ°äºãã
            switch(p[i].v)
            {
            case 'S':
                if(p[i].y >10) p[i].dir = 0;        //å°åºï¼åä¸è¿å¨äºãã
                if(p[i].y <1) p[i].dir = 1;            //å°é¡¶äºï¼æ¹åæ¹å
                if(!p[i].dir)        p[i].y--;
                else           p[i].y++;
                break;
            case 'W':
                if(p[i].x >10) p[i].dir = 0;        //è¾¾å°æå³è¾¹ï¼æ¹åæ¹åï¼åå·¦è¿å¨
                if(p[i].x <1) p[i].dir = 1;            //è¾¾å°æå·¦è¾¹ï¼æå³è¿å¨
                if(!p[i].dir)   p[i].x--;            
                else        p[i].x++;
                break;
            case 'E':
                if(p[i].y == 11||p[i].x == 11)        //å°è¾¾å³è¾¹æä¸è¾¹ï¼åååè¿å¨
                    p[i].dir = 0;
                if(p[i].y == 0||p[i].x == 0)        //å°è¾¾å·¦è¾¹æä¸è¾¹ï¼æ¹åæ¹åï¼åæ­£æ¹åè¿å¨
                    p[i].dir = 1;
                if((p[i].y==0&&p[i].x==11)||(p[i].y==11&&p[i].x==0))
                    break;
                else
                {
                    if(!p[i].dir)
                    {   p[i].y--;   p[i].x--;     }
                    else
                    {   p[i].y++;   p[i].x++;     }
                }
                break;
            }
            X[p[i].y][p[i].x]++;                //è¿ä½å¤§ä¾ æ¥å°äºæ°çä½ç½®ï¼å¨è¯¥ä½ç½®çäººæ°éå 1
        }
}

//å¼å§æ ¼æ
void fight()
{
    int i,j,DPS1,DPS2;
    while(N--)
    {
        for(i=0;i<num;i++)
        {
            DPS1 = DPS2 = 0;
            if(X[p[i].y][p[i].x]==2&&!p[i].isF&&p[i].HP>0)        //å½åä½ç½®åªæ2ä¸ªäººãåæ¶å¤§ä¾ iå¨æ¬åååæ²¡ææ ¼æè¿ï¼å°ç¶å¤§ä¾ iè¿ä¸è½æ­»ãã
            {
                
                for(j=0;j<num;j++)
                {
                    if((p[i].y==p[j].y)&&(p[i].x==p[j].x)&&(p[i].v!=p[j].v)&&p[j].HP>0)        //å¯»æ¾å¤§ä¾ iæå¨ä½ç½®çå¶ä»æ­¦æäººå£«ï¼è¿ä½æ­¦æäººå£«è¿æ²¡æ­»å¦ï¼ãé¨æ´¾ä¸è½åå¤§ä¾ iç¸åï¼
                    {
                        DPS1 = getDPS(i);        //è®¡ç®ä¼¤å®³å¼
                        DPS2 = getDPS(j);    
                        p[i].HP -=DPS2;        //æ ¼æäºï¼æåçå½å - å¯¹æ¹æ»å»å
                        p[j].HP -=DPS1;
                        p[i].isF = true;    //æ è®°æ¬ååå·²ç»æ ¼æè¿ã
                        p[j].isF = true;    
                    }
                }
            }
        }
        //ä¸ååè¿å»äºï¼åä½æ­¦æé«æå¼å§ç§»å¨ãã
        move();
    }
}
int main()
{
    //ifstream cin("a.txt");
    int a;
    while(cin>>a)
    {
        while(a--)
        {
            //åå§åå°å¾ããã
            for(int i=0;i<12;i++)
            {
                for(int j=0;j<12;j++)
                    X[i][j] = 0;
            }
            num = 0;
            cin>>N;
            while(cin>>p[num].v&&p[num].v!='0')
            {
                cin>>p[num].y>>p[num].x>>p[num].MP>>p[num].DP>>p[num].HP;
                p[num].y--;                //å¤§ä¾ çä½ç½®ä»0.0ä½ç½®å¼å§è®¡ç®ï¼æä»¥Xï¼Yé½å1
                p[num].x--;
                p[num].isF = false;        //åå§åï¼æ²¡æææè¿ã
                p[num].dir = 1;            //åå§åæ¹åä¸ºæ­£
                X[p[num].y][p[num].x]++;
                num++;
            }
            fight();
            ShowRest();
        }
    }
    return 0;
}