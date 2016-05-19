#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 10010
#define PII pair<int,int>
#define Dot pair<double,double>
#define eps 1e-7

int n,i,j,t;
int h[N],sum[N],mark[N];
double alpha,ans;
double y,k,x,b;
PII srt[N];
Dot p;

double rad(double x) {
  return x*acos(-1.0)/180.0;
}

int main() {
  while (scanf("%d%lf",&n,&alpha)>=0) {
    memset(mark,ans=0,sizeof(mark));

    for (i=1;i<=n;i++)
      scanf("%d",alpha>0?h+n-i+1:h+i);
    if (alpha<0) alpha*=-1;
    alpha=rad(alpha);
    k=tan(alpha);

    for (i=1;i<=n;i++) {
      sum[i]=h[i]+sum[i-1];
      srt[i].first=-h[i];
      srt[i].second=i;
    }

    sort(srt+1,srt+n+1);
    for (int t=1;t<=n;t++)  //浠庨珮寰�浣�
      if (!mark[i=srt[t].second]) {
        x=i-1,y=h[i],b=y-k*x;

        for (j=i-1;j;j--) { //浠庨珮鏉垮乏绔偣鍚戝乏鍙戝皠绾�
          if (k*j+b<=h[j]+eps) {  //浜や簬宸︿晶鏈ㄦ澘鍙冲
            p.first=j;
            p.second=k*j+b;

            ans+=(i-1-j)*p.second;
            ans+=((i-1-p.first)*(h[i]-p.second))/2.0;
            ans-=sum[i-1]-sum[j];

            for (j++;j<=i;j++) mark[j]=1;
            break;
          }
          if (k*(j-1)+b<h[j]) { //浜や簬宸︿晶鏈ㄦ澘椤堕儴
            p.second=h[j];
            p.first=(p.second-b)/k;

            ans+=(i-1-j)*p.second;
            ans+=((i-1-p.first)*(h[i]-p.second))/2.0;
            ans-=sum[i-1]-sum[j];

            for (j++;j<=i;j++) mark[j]=1;
            break;
          }
        }

        if (!j) { j=1; //绗竴鍧楁澘鐗规畩澶勭悊锛屼粠宸﹀線鍙冲彂灏勭嚎
          Next:
          x=j-1,y=h[j],b=y-k*x;
          int t;
          for (t=j+1;t<=i;t++)
            if (k*(t-1)+b<=h[t]+eps) {
              p.first=t-1;
              p.second=k*(t-1)+b;

              ans+=(p.first-j)*h[j];
              ans+=((p.first-(j-1))*(p.second-h[j]))/2.0;
              ans-=sum[t-1]-sum[j];

              for (int i=j;i<=t;i++) mark[i]=1;
              break;
            }
          if (t<i) {
            j=t;
            goto Next;
          }
        }
      }
      printf("%.2lf\n",ans);
  }
  return 0;
}