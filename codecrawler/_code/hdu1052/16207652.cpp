#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int a[1200],b[1200];
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        sort(a+1,a+1+n,cmp);
        sort(b+1,b+1+n,cmp);
        /*for(int i=1;i<=n;i++)
            printf("%d  ",a[i]);
        printf("\n");
        for(int i=1;i<=n;i++)
            printf("%d   ",b[i]);
        printf("\n");*/
    
        int h1,h2,t1,t2;
        int w=0,l=0;
        h1=1,h2=1,t1=n,t2=n;
        for(int i=1;i<=n;i++)
        {
            if(a[h1]>b[h2])
            {
                w++;
                h1++;
                h2++;
            }
            /*else if(a[h1]==b[h2])
            {
                
            }*/
            else
            {
                if(a[t1]>b[t2])//ææ¢çåææ¢çæ¯è¾
                {
                    w++;
                    t1--;
                    t2--;
                }
                else//ææ¢çåæå¿«çæ¯è¾a[t1]ä¸b[h2]æ¯è¾
                {
                    if(a[t1]==b[h2])
                        ;
                    else
                       l++;
                    t1--;
                    h2++;
                }
            }
        }
        printf("%d\n",(w-l)*200);
    }//
    system("pause");
    return 0;
}

/*æè¿ç§çææ³æ¯ï¼åååºæåï¼ç¨ç°ææ¢çé©¬åé½çææ¢çæ¯è¾ï¼å¦å¿« ç´æ¥æ¯æï¼è¥æ¢ï¼å°±åé½çæå¿«çæ¯æ
å¦ç¸ç­ï¼çä¸ä¸å¯¹ï¼ï¼ï¼
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cmp(int x,int y)
{
    return x<y;
}
int main()
{
    int a[1200],b[1200];
    int  vis[1200];
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        sort(a+1,a+1+n,cmp);
        sort(b+1,b+1+n,cmp);
        /*for(int i=1;i<=n;i++)
            printf("%d  ",a[i]);
        printf("\n");
        for(int i=1;i<=n;i++)
            printf("%d   ",b[i]);
        printf("\n");
        memset(vis,0,sizeof(vis));
        int win=0,l=0,tail=n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(vis[j]==0)
                {
                    if(a[i]>b[j])
                    {
                        win++;
                        vis[j]=1;
                    }
                    else
                    {
                        /*
                        if(a[i]<b[tail] && vis[tail]==0)//å°äºç­äºå°±è®©ç°è¾æãããæ¯éç
                        {                               //5ï¼1 2  2 4 5 ï¼2 2 3 3 4
                            l++;
                        }
                        vis[tail]=1; 
                        tail--;
                        //break;æ¾éä½ç½®äº

                        if(a[i]==b[j] && i+1<=n && j+1<=tail && a[i+1]!=b[j+1])//è¿ä¸å±å¹³äº
                        {
                            vis[j]=1;
                            break;
                        }
                        if(a[i]<b[j]&&vis[tail]==0)//è¾æ
                        {
                            l++;
                            vis[tail]=1;
                            tail--;
                        }
                    }
                    break;
                }
    //printf("w=%d   l=%d\n",win,l);
    int ans=(win-l)*200;
    printf("%d\n",ans);
    }
    system("pause");
    return 0;
}
*/
/*
3
15 12 9
16 13 9
********
5
7 8 9 12 15
7 8 9  13 16
***************
4
1 2 4 5
2 3 3 4
200è¿ç»æ°æ®å¾å¥½....


*/

/*
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[1005],b[1005];
    int i,n,sum,aa,ab,ba,bb;
    while(cin>>n&&n)
    {
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
            cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
        aa=0;ab=n-1;ba=0;bb=n-1;
        sum=0;
        for(i=0;i<n;i++)
        {
            if(a[ab]>b[bb]) {ab--;bb--;sum++;continue;}
            if(a[aa]<b[ba]) {aa++;bb--;sum--;continue;}
            if(a[aa]>b[ba]) {aa++;ba++;sum++;continue;}
            if(a[aa]==b[ba])
            {
                if(a[aa]<b[bb])
                    sum--;
                else
                {
                    if(a[aa]>b[bb])
                        sum++;
                }
                aa++;bb--;
            }
        }
        sum=sum*200;
        cout<<sum<<endl;
    }
    return 0;
}
*/