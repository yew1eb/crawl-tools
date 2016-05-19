#include<stdio.h>
#include<string.h>
#define MAX 1002
#define max 99999
int map[MAX][MAX],used[MAX],f[MAX];
int main()
{
int n,i,j,k,m,a,b,min,sum;
while(scanf("%d",&n)!=EOF)
{
memset(used,0,sizeof(used));
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&map[i][j]);
scanf("%d",&m);
for(i=1;i<=m;i++)
{
   scanf("%d %d",&a,&b);
   map[a][b]=map[b][a]=0;
}
for(i=1;i<=n;i++)
f[i]=map[1][i];
f[1]=0;sum=0;
for(i=1;i<=n;i++)
{
   min=max;
   for(j=1;j<=n;j++)
   if(!used[j]&&f[j]<min)
   {min=f[j];k=j;}
   if(min==max)break;
   used[k]=1;
   sum+=f[k];
   for(j=1;j<=n;j++)
   if(!used[j]&&f[j]>map[k][j]) （离树最近）
   f[j]=map[k][j];
}
printf("%d\n",sum);
}
}
in=max;
   for(j=1;j<=n;j++)
   if(!used[j]&&f[j]<min)
   {min=f[j];k=j;}
   if(min==max)break;
   used[k]=1;
   sum+=f[k];
   for(j=1;j<=n;j++)
   if(!used[j]&&f[j]>map[k][j]) （离树最近）
   f[j]=map[k][j];
}
printf("%d\n",sum);
}
}