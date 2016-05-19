#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
using namespace std;
int n,m;

map<string,int>vis_str;
map<string,int>sg;
string s;
void add(int a[][50])//æç©éµè½¬åä¸ºä¸ä¸ªå­ç¬¦ä¸²
{
    int i,j;
    s="";
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
          s+=a[i][j]+'0';
}

int mex(int a[][50])
{
    int i,j,k;
    int vis_sg[100];//è¿éè¦ææåç½®æ°ç» ä¸è½ææå¨å±
    memset(vis_sg,0,sizeof(vis_sg));
    add(a);
    vis_str[s]=1;
    for(i=1;i<n;i++)
        for(j=1;j<m;j++)
        {
            if(a[i][j]==0&&a[i-1][j]==0&&a[i][j-1]==0&&a[i-1][j-1]==0)
            {
            a[i][j]=a[i-1][j]=a[i][j-1]=a[i-1][j-1]=1;
                add(a);
                if(vis_str[s])
                    k=sg[s];
                else
                    k=mex(a);
                vis_sg[k]=1;
            a[i][j]=a[i-1][j]=a[i][j-1]=a[i-1][j-1]=0;
            }
        }
        for(i=0;;i++)
        {
            if(!vis_sg[i]) {  add(a); sg[s]=i; return i;}
        }
}
int main()
{
    int i,j,a[50][50],t,ans;
    while(scanf("%d",&t)!=EOF)
     {
          ans=0;
         while(t--)
         {
            scanf("%d %d",&n,&m);
            for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%1d",&a[i][j]);
           // sg.clear();å ä¸è¿2å¥å°±è¶æ¶ å¥½å¥è© æ±è§£ç­
           // vis_str.clear();
            ans=ans^mex(a);
        }
             if(ans) printf("Yes\n");
             else  printf("No\n");
     }

    return 0;
}
