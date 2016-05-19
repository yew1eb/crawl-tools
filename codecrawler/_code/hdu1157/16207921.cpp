#include <iostream>
#include <cstdio>
using namespace std;
const int N=100005;
int num[N];
int partition(int low,int high){
  int i=low,j=high,key=num[low];
  while(i<j){
    while(i<j&&num[j]>=key) --j;
    int t=num[i];num[i]=num[j];num[j]=t;
    while(i<j&&num[i]<=key) ++i;
    t=num[i];num[i]=num[j];num[j]=t;
  }
  return i;
}
void quick_sort(int low,int high){
    if(low<high){
      int x=partition(low,high);
      quick_sort(low,x-1);
      quick_sort(x+1,high);
    }
}
int main(){
 // freopen("11.txt","r",stdin);
  int n;
  while(~scanf("%d",&n)){
    for(int i=0;i<n;++i)
        scanf("%d",&num[i]);
    quick_sort(0,n-1);
    printf("%d\n",num[n/2]);
  }
  return 0;
}