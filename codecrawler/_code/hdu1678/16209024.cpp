#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
int price[20005];

int comp(const void *a, const void *b)
{
 return *(int *)b - *(int *)a;
}
int main()
{
 int sum, n, i, T;

 scanf("%d", &T);
 while(T--)
 {
  scanf("%d", &n);
  for(i = 0; i < n; i++)
  {

   scanf("%d", &price[i]);
  }
  qsort(price, n, sizeof(price[0]), comp);
  sum=0;
  for(i = 2;i < n; i+= 3)
  {
   sum += price[i];
  }
  printf("%d\n", sum);
 }
 return 0;
}
