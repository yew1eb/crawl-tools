#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int MAXN = 500000 + 10;
int num[MAXN], n1[MAXN];

int main()
{
 int t, i, cut, n;
 char c, res[MAXN];
 scanf("%d", &t);
 while(t--)
 {
 scanf("%d", &n);
 for( i=1; i<=n; i++ )
 {
 res[i] = 0;
 scanf("%d", &num[i]);
 n1[num[i]] = i;
 }
 bool flag = true;
 n1[n+1] = -1;
 c = 'a';
 res[num[1]] = c;
 cut = n1[num[1] + 1];
 for( i=2; i<=n; i++ )
 {
 if(n1[(num[i] + 1)] > cut)
 {
 res[num[i]] = c;
 cut = n1[num[i] + 1];
 }
 else
 {
 c = c + 1;
 if(c > 'z')
 {
 flag = false;
 break;
 }
 res[num[i]] = c;
 cut = n1[num[i] + 1];
 //printf("cut : %d\n", cut);
 }
 }
 if(!flag)
 {
 printf("-1\n");
 continue;
 }
 for( i=1; i<=n; i++ ) printf("%c", res[i]);
 putchar('\n');
 }
 return 0;
}