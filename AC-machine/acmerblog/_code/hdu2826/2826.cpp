#include<cstdio> 
int main() 
{ 
 int a[301][3],b[300][3]; 
 int i,j,n,k,flag; 
 double c[301]; 
 while(scanf("%d",&n)!=EOF) 
 { 
 flag=0; 
 k=0; 
 for(i=0;i<n;i++) 
 scanf("%d%d",&a[i][0],&a[i][1]); 
 for(i=0;i<n;i++) 
 scanf("%d%d",&b[i][0],&b[i][1]); 
 for(i=0;i<n;i++) 
 { 
 for(j=0;j<2;j++) 
 { 
 if(a[i][j]==0&&b[i][j]!=0) flag=1; 
 if(a[i][j]!=0&&b[i][j]==0) flag=1; 
 if(a[i][j]!=0&&b[i][j]!=0) 
 c[k++]=(double)a[i][j]/(double)b[i][j]; 
 } 
 } 
 for(i=0;i<k-1;i++) 
 if(c[i]!=c[i+1]) {flag=1;break;} 
 if(flag) 
 printf("No\n"); 
 else 
 printf("Yes\n"); 
 } 
 return 0; 
}