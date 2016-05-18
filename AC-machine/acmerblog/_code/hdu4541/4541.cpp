#include<stdio.h>
#include<algorithm>
using namespace std;
int a[10][111],ct[10];
const int mmax=99999999;
struct haha
{
    int cnt;//位数
    int num;//数值
    int flag;//标记是小于10 还是大与10
}b[20000];
int main()
{
    int i,j,k=0,cas,c=0;
    scanf("%d",&cas);
    for(i=0;i<10;i++)  ct[i]=0;
    for(i=0;i<=9;i++)
    {
        b[c].num=i;b[c].flag=1;
        c++;
    }
	b[c].num=10;b[c].flag=2;
	c++;
    b[1].cnt=b[2].cnt=b[6].cnt=b[10].cnt=3;
    b[0].cnt=b[4].cnt=b[5].cnt=b[9].cnt=4;
    b[3].cnt=b[7].cnt=b[8].cnt=5;
    for(i=2;i<=9;i++)
    {
        b[c].num=i*10;b[c].flag=3;
        c++;
    }
    b[11].cnt=b[12].cnt=6;b[13].cnt=5;b[14].cnt=5;
    b[15].cnt=5;b[16].cnt=7;b[17].cnt=6;b[18].cnt=6; 
	//printf("c=%d",c);
    for(i=11;i<=19;i++)
    {
        b[c].num=i;
        b[c].flag=2;
        c++;
    }
    
    b[19].cnt=b[20].cnt=6;
    b[21].cnt=b[22].cnt=8;
    b[23].cnt=b[24].cnt=7;
    b[25].cnt=9;
    b[26].cnt=b[27].cnt=8;
    for(i=0;i<c;i++)
    {
        int cnt=b[i].cnt;
        int num=b[i].num;
        a[cnt][ct[cnt]++]=num;
    }
    for(i=0;i<c;i++)
        for(j=0;j<c;j++)
        {
            if(b[i].flag==3&&b[j].flag==1)
            {
                int num;
				if(b[j].num==0) continue;
                int cnt=b[i].cnt+b[j].cnt;
                if(cnt>9) continue;
                  num=b[i].num+b[j].num;
                a[cnt][ct[cnt]++]=num;
            }
        }
    for(i=3;i<=9;i++)
    {
        sort(a[i],a[i]+ct[i]);
    }
/*	for(i=3;i<=9;i++)
	{
		for(j=0;j<ct[i];j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
*/
    while(cas--)
    {
        int n,m;
        k++;
        scanf("%d %d",&n,&m);
        printf("Case #%d: ",k);
        if(n==9&&m==ct[n]+1) {printf("10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n");continue;}
   else if(n==9&&m==ct[n]+2) {printf("20000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n");continue;}
   else if(n==9&&m==ct[n]+3) {printf("60000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n");continue;}
   else if(n==9&&m==ct[n]+4) {printf("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n");continue;}	
   if(ct[n]<m) {printf("-1\n");continue;}
        printf("%d\n",a[n][m-1]);

    }
    return 0;
}


