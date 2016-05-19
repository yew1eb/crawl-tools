#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int d[8111111],q[1111];
int main()
{
     int i,j,m,n,k,t;
     float f;
     while(cin>>f>>n,n) {
          int sum=f*100;
          memset(d,0,sizeof(d));
          for(i=1; i<=n; i++) {
               cin>>t;
               int flag=1,a,b,c;
               a=b=c=0;
               while(t--) {
                    getchar();
                    char tempc;
                    float tempf;
                    int tempd;
                    scanf("%c:%f",&tempc,&tempf);
                    tempd=tempf*100;
                    //      cout<<"1111  "<<tempc<<' '<<tempd<<endl;
                    if(tempc=='A')
                         a+=tempd;
                    else if(tempc=='B')
                         b+=tempd;
                    else if(tempc=='C')
                         c+=tempd;
                    else
                         flag=0;
               }
               if(a>60000||b>60000||c>60000||a+c+b>100000)
                    flag=0;
               if(flag==1) {
                    q[i]=a+b+c;
               } else
                    q[i]=0;
          }
          for(i=1; i<=n; i++)
               for(j=sum; j>=q[i]; j--)
                    d[j]=max(d[j],d[j-q[i]]+q[i]);
          for(j=1,i=d[1]; j<=sum; j++)
               if(i<d[j])
                    i=d[j];
          f=(float)i/100;
          printf("%.2f\n",f);
     }
}

