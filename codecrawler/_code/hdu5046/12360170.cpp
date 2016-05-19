#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define eps 1e-8
#define N 200
#define V 80000
long long int n,m,K;//nÐÐ mÁÐ KÏÞÖÆÌõ¼þ£¬×î¶àÓÃKÐÐ(½öÏÞÓÚ´ËÌâ)
long long int L[V],R[V];
long long int D[V],U[V];
long long int C[V];
long long int S[N],H[N];
long long int ak,size;//ak ×îÉÙ¶àÉÙÐÐ¿ÉÒÔ¸²¸ÇËùÓÐÁÐ(¿ÉÖØ¸´)
long long int abs(long long int a,long long int b)
{
    if(a>b) return a-b;
    else return b-a;
}
long long int dis(long long int x1,long long int y1,long long int x2,long long int y2)
{
    return abs(x1-x2)+abs(y1-y2);
}
void Link(long long int r,long long int c)
{
    S[c]++;C[size]=c;
    U[size]=U[c];D[U[c]]=size;
    D[size]=c;U[c]=size;
    if(H[r]==-1) H[r]=L[size]=R[size]=size;
    else
    {
        L[size]=L[H[r]];R[L[H[r]]]=size;
        R[size]=H[r];L[H[r]]=size;
    }
    size++;
}
void remove(long long int c)
{
    long long int i;
    for(i=D[c];i!=c;i=D[i])
        L[R[i]]=L[i],R[L[i]]=R[i];
}
void resume(long long int c)
{
    long long int i;
    for(i=U[c];i!=c;i=U[i])
        L[R[i]]=R[L[i]]=i;
}
long long int h()
{
    long long int i,j,k,count=0;
    bool visit[N];
    memset(visit,0,sizeof(visit));
    for(i=R[0];i;i=R[i])
    {
        if(visit[i]) continue;
        count++;
        visit[i]=1;
        for(j=D[i];j!=i;j=D[j])
        {
            for(k=R[j];k!=j;k=R[k])
                visit[C[k]]=1;
        }
    }
    return count;
}
void Dance(long long int k)
{
    long long int i,j,c,Min,ans;
    ans=h();
    if(k+ans>K) return ;//½öÏÞÓÚ´ËÌâ
    if(k+ans>=ak) return;
    if(!R[0])
    {
        if(k<ak) ak=k;
        return;
    }
    for(Min=N,i=R[0];i;i=R[i])
        if(S[i]<Min) Min=S[i],c=i;
    for(i=D[c];i!=c;i=D[i])
    {
        remove(i);
        for(j=R[i];j!=i;j=R[j])
            remove(j);
        Dance(k+1);
        for(j=L[i];j!=i;j=L[j])
            resume(j);
        resume(i);
    }
    return;
}
long long int d[100][100];
long long int dl[10000];
int main()
{
    long long int i,j,ncase;
    long long int x[N],y[N];
    long long int left,right,mid;
    long long int ans;
    scanf("%I64d",&ncase);
    long long int ni=0;
    while(ncase--)
    {
        ni++;
        long long int tn;
        //´å×¯µ±³ÉÁÐtn,¾È»ðÕ¾µ±³ÉÐÐtn  ×î¶àÓÃK¸ö¾È»ðÕ¾
        scanf("%I64d%I64d",&tn,&K);
        n=m=tn;
        for(i=1;i<=m;i++)
            scanf("%I64d%I64d",&x[i],&y[i]);
        long long int num = 0;
for (i = 1; i <= n; ++i) {
for (j = i; j <= m; ++j) {
d[i][j] = d[j][i] = dl[num++] = dis(x[i],y[i],x[j], y[j]);
}
}
//¶þ·Ö´ð°¸ÕâÀïÒª×¢Òâ:Èç¹ûÖ±½Óleft=0,right=(1<<30)Ö±½Ó¶þ·Ö »á³¬Ê±
//ÕâÀïÒª°ÑËùÓÐ¾àÀëÏÈÅÅÐò ¶þ·ÖÃ¶¾ÙÕâÐ©¾àÀë  AC
sort(dl, dl + num);
num = unique(dl, dl + num) - dl;
        left=0;
        right= num-1;
        ans=dl[right];
        while(left<right)
        {
            //DLX
            for(i=0;i<=m;i++)
            {
                S[i]=0;
                U[i]=D[i]=i;
                L[i+1]=i;R[i]=i+1;
            }R[m]=0;
            memset(H,-1,sizeof(H));
            size=m+1;
            mid=(left+right)/2;
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=m;j++)
                    if(dl[mid]>=d[i][j])  Link(i,j);
            }
            ak=N;
            Dance(0);
            //......
            if(ak<=K) {ans=min(ans,dl[mid]);right=mid;}
            else left=mid+1;
        }
        printf("Case #%I64d: ",ni);
        printf("%I64d\n",ans);
    }
    return 0;
}