#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
#define re(x,y) memset(x,y,sizeof(x))
#define rep(x,s,e) for(int x=s;x<e;x++)
#define scan1(x) scanf("%d",&x)
#define scan2(x,y) scanf("%d%d",&x,&y)
#define scan3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define lson i<<1,L,mid
#define rson i<<1|1,mid+1,R
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxx=100010;
//100000
int mx[]= {-1,1,0,0},my[]= {0,0,-1,1};
// 33 126

char ch[maxx];
char  ans[10][maxx];
int time;
void pri(int a,int &k)
{
    if(a>=0&&a<=25)ans[time][k++]='A'+a;
    else if(a<=51)ans[time][k++]='a'+a-26;
    else if(a<=61)ans[time][k++]='0'+a-52;
    else if(a==62)ans[time][k++]='+';
    else ans[time][k++]='/';
}
int main()
{
    int n;
    int cas=1;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scan1(n);
        scanf("%s",ch);
        printf("Case #%d: ",cas++);
        time=0;
        int k;
        while(time<n)
        {
            k=0;
            int l=strlen(ch);
            int tmp1,tmp2,tmp3,tmp4;
            int i;
            int k=0;
            for( i=0; i<l&&i+2<l; i+=3)
            {
            //ä¸æ°è¿æ¥å¨ä¸èµ· ï¼ç¬¬ä¸ä¸ªæ°å·¦ç§»16ä½  ç¬¬äºä¸ªæ°å·¦ç§»8ä½
                int a=(((int)ch[i])<<16)+(((int)ch[i+1])<<8)+((int)ch[i+2]);
            //åæ4ç»
                tmp1=(a>>18);
                tmp2=((a-(tmp1<<18))>>12);
                tmp3=((a-(tmp1<<18)-(tmp2<<12))>>6);
                tmp4=a-(tmp1<<18)-(tmp2<<12)-(tmp3<<6);
                //cout<<tmp1<<" "<<tmp2<<" "<<tmp3<<" "<<tmp4<<endl;
                pri(tmp1,k);
                pri(tmp2,k);
                pri(tmp3,k);
                pri(tmp4,k);
            }
            if(i+1==l)
            {
                int a=(((int)ch[i])<<16);//å¨åé¢è¡¥0
                tmp1=(a>>18);
                tmp2=((a-(tmp1<<18))>>12);
                tmp3=((a-(tmp1<<18)-(tmp2<<12))>>6);
                tmp4=a-(tmp1<<18)-(tmp2<<12)-(tmp3<<6);
                pri(tmp1,k);
                pri(tmp2,k);
                ans[time][k++]='=';
                ans[time][k++]='=';
            }
            else if(i+2==l)
            {
                int a=(((int)ch[i])<<16)+(((int)ch[i+1])<<8);
                tmp1=(a>>18);
                tmp2=((a-(tmp1<<18))>>12);
                tmp3=((a-(tmp1<<18)-(tmp2<<12))>>6);
                tmp4=a-(tmp1<<18)-(tmp2<<12)-(tmp3<<6);
                pri(tmp1,k);
                pri(tmp2,k);
                pri(tmp3,k);
                ans[time][k++]='=';
            }
            ans[time][k]='\0';
            strcpy(ch,ans[time]);
            time++;
        }
        printf("%s\n",ans[time-1]);
    }
}