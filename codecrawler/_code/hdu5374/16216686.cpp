#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#define pb push_back
#define debug puts("=====================");
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef long long ll;
int t;
int Map[20][20];     //è®°å½æ´ä½
int updata[20][20];  //è®°å½å½åæè½æ¹å
char ch[1111];
int a[1111];
int n;
int chong()        //å¤æ­æ¯å¦æéæ³æä½
{
    int sum = 0;
    for(int i=1; i<=12; i++)
        for(int j=1; j<=9; j++)
            if(updata[i][j]) sum++;
    if(sum!=4)
        return 0;
    for(int i=1; i<=12; i++)
        for(int j=1; j<=9; j++)
            if(updata[i][j]+Map[i][j]>1)
                return 0;
    return 1;
}
int zhuan(int type,int x,int y)  //æè½¬
{
    if(type==1)
    {
        swap(updata[x-1][y],updata[x][y+1]);
        swap(updata[x-2][y],updata[x][y+2]);
        swap(updata[x-3][y],updata[x][y+3]);
        if(!chong())                          //å¦æéæ³ï¼åè½¬åæ¥
        {
            swap(updata[x-1][y],updata[x][y+1]);
            swap(updata[x-2][y],updata[x][y+2]);
            swap(updata[x-3][y],updata[x][y+3]);
        }
    }
    else if(type==2)
    {
        if(updata[x][y]==0)   ///3->4
        {
            swap(updata[x-1][y],updata[x-2][y+1]);
            swap(updata[x-1][y+2],updata[x][y+1]);
            swap(updata[x][y+2],updata[x][y]);
            if(!chong())
            {
                swap(updata[x-1][y],updata[x-2][y+1]);
                swap(updata[x-1][y+2],updata[x][y+1]);
                swap(updata[x][y+2],updata[x][y]);
            }
        }
        else
        {
            if(updata[x-1][y]&&updata[x][y+1]) ///1->2
            {
                swap(updata[x][y+1],updata[x-2][y]);
                swap(updata[x][y+2],updata[x-2][y+1]);
                if(!chong())
                {
                    swap(updata[x][y+1],updata[x-2][y]);
                    swap(updata[x][y+2],updata[x-2][y+1]);
                }
            }
            else if(updata[x-1][y]&&!updata[x][y+1]) ///2->3
            {
                swap(updata[x][y],updata[x-1][y+1]);
                swap(updata[x-2][y],updata[x-1][y+2]);
                swap(updata[x-2][y+1],updata[x][y+2]);
                if(!chong())
                {
                    swap(updata[x][y],updata[x-1][y+1]);
                    swap(updata[x-2][y],updata[x-1][y+2]);
                    swap(updata[x-2][y+1],updata[x][y+2]);
                }
            }
            else if(!updata[x-1][y]&&updata[x][y+1]) ///4->1
            {
                swap(updata[x-1][y+1],updata[x-1][y]);
                swap(updata[x-2][y+1],updata[x][y+2]);
                if(!chong())
                {
                    swap(updata[x-1][y+1],updata[x-1][y]);
                    swap(updata[x-2][y+1],updata[x][y+2]);
                }
            }
        }
    }
}
int  ctrl(char lei,int type)    //æ§å¶ä¸ä¸å·¦å³
{
    if(lei=='w')
    {
        if(type==0)
            return 0;
        int xx,yy;
        xx = -9999;
        yy = 9999;
        for(int i=1; i<=12; i++)
            for(int j=1; j<=9; j++)
                if(updata[i][j])
                    xx = max(xx,i),yy = min(yy,j);   //æ¾å°ç»¿è²çç¹ï¼ä»¥è¿ä¸ªç¹ä¸ºåºå
        zhuan(type,xx,yy);
    }
    else if(lei=='a')
    {
        for(int i=1; i<=12; i++)
            for(int j=0; j<=10; j++)
                if(updata[i][j]) swap(updata[i][j],updata[i][j-1]);
        if(!chong())                                //å¦æéæ³ï¼åç§»åæ¥
        {
            for(int i=1; i<=12; i++)
                for(int j=10; j>=0; j--)
                    if(updata[i][j]) swap(updata[i][j],updata[i][j+1]);
        }
    }
    else if(lei=='d')
    {
        for(int i=1; i<=12; i++)
            for(int j=10; j>=0; j--)
                if(updata[i][j])  swap(updata[i][j],updata[i][j+1]);
        if(!chong())
        {
            for(int i=1; i<=12; i++)
                for(int j=0; j<=10; j++)
                    if(updata[i][j])  swap(updata[i][j],updata[i][j-1]);
        }
    }
    else if(lei=='s')
    {

        for(int i=13; i>=1; i--)
            for(int j=1; j<=9; j++)
                if(updata[i][j]) swap(updata[i][j],updata[i+1][j]);
        if(!chong())
        {
            for(int i=1; i<=13; i++)
                for(int j=1; j<=9; j++)
                    if(updata[i][j]) swap(updata[i][j],updata[i-1][j]);
        }
    }
    return 1;
}
int score,tmp,jj,len;
int di()            //å¤æ­æ¯å¦å¯ä»¥åå¹¶ãæ¶é¤
{
    int go = 1;
    for(int i=1; i<=11; i++)
        for(int j=1; j<=9; j++)
        {
            if(updata[i][j]&&updata[i+1][j]==0)
            {
                if(Map[i+1][j])
                    go = 0;
            }
        }
    for(int j=1; j<=9; j++)
    {
        if(updata[12][j])
            go = 0;
    }
    if(go)
        return 0;
    for(int i=1; i<=12; i++)
        for(int j=1; j<=9; j++)
        {
            if(updata[i][j])
                Map[i][j]  = updata[i][j];
        }
    while(1)
    {
        int flag = 0;
        int hang = 12;
        for(int i=1; i<=12; i++)
        {
            int sum = 0;
            if(Map[i][1])
            {
                for(int j=1; j<=9; j++)
                    sum+=Map[i][j];
            }
            if(sum==9)
            {
              //  cout<<"--------\n";
                hang = i;
                flag = 1;
                score++;
                for(int j=1; j<=9; j++)
                    Map[i][j] = 0;
                break;
            }
        }
        if(flag)
        {
            for(int i=hang-1; i>=1; i--)
                for(int j=1; j<=9; j++)
                    if(Map[i][j]&&Map[i+1][j]==0)
                        swap(Map[i][j],Map[i+1][j]);
        }
        else
            break;
    }
    return 1;
}

int main()
{
    // freopen( "3.out","w",stdout );
    cin>>t;
    int cs =  1;
    while(t--)
    {
        score = 0;
        scanf("%d%s",&n,ch);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        memset(Map,0,sizeof(Map));
        memset(updata,0,sizeof(updata));
        jj  = 0;
        len=strlen(ch);
        for(int i=0; i<n; i++)    //ä¸è½çæ¹å
        {
            tmp = a[i];
            memset(updata,0,sizeof(updata));
            if(a[i]==0)
            {
                updata[4][4] = 1;
                updata[3][4] = 1;
                updata[4][5] = 1;
                updata[3][5] = 1;
            }
            else if(a[i]==1)
            {
                updata[4][4] = 1;
                updata[3][4] = 1;
                updata[2][4] = 1;
                updata[1][4] = 1;
            }
            else if(a[i]==2)
            {
                updata[4][4] = 1;
                updata[3][4] = 1;
                updata[4][5] = 1;
                updata[4][6]  = 1;
            }
            for( ; jj<len; jj++)    //æä½ç¼å·
            {
                if(ch[jj]!='p')
                    ctrl(ch[jj],tmp);
                 if(di())        //å¤æ­æ¯å¦è¿è¡åå¹¶ï¼æ¶é¤
                {
                    jj++;
                    break;
                }
               ctrl('s',tmp);  //æ¯æ¬¡èªç¶ä¸è½
            }
        }
        printf("Case %d: %d\n",cs++,score);
    }
    return 0;
}
