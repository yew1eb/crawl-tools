1 #include<stdio.h>
 2 #include<string.h>
 3 struct s
 4 {
 5     int num;
 6     double mark;
 7 }a[1000],t;
 8 int main()
 9 {
10     int n,m,k,i,j,o,s;
11     double d;
12     while(~scanf("%d %d %d",&n,&m,&k))
13     {
14         for(i=0;i<m;i++)
15         {
16             a[i].mark=0;
17         }
18         while(n--)
19         {
20             for(i=0;i<m;i++)
21             {
22                 scanf("%lf",&d);
23                 a[i].mark+=d;
24                 a[i].num=i+1;
25             }
26         }
27         for(i=0;i<m-1;i++)
28         for(j=i+1;j<m;j++)
29         {
30             if(a[i].mark<a[j].mark)
31             {
32              t=a[i];a[i]=a[j];a[j]=t;
33             }
34         }
35         for(i=0;i<k-1;i++)
36         for(j=i+1;j<k;j++)
37         {
38             if(a[i].num<a[j].num)
39             {
40                 t=a[i];a[i]=a[j];a[j]=t;
41             }
42         }
43         for(i=0;i<k-1;i++)
44         {
45             printf("%d ",a[i].num);
46         }
47         printf("%d",a[i].num);
48         puts("");
49     }
50     return 0;
51 
52 }