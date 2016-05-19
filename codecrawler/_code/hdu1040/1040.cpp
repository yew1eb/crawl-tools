
/**

排序模板题: 快排是比较快速的算法~

分治的思想, 把每个元素放到合适的位置

*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
//#include "myAlgorithm.h"
#define MAXL 100005
#define INF 1e8
using namespace std;
int n;
int a[MAXL];
int partion(int low, int high){
int key = a[low];
while(low < high){
while(low < high && key <= a[high]){
high--;
}
swap(a[low], a[high]);
while(low < high && key >= a[low]){
low ++;
}
swap(a[low], a[high]);
}
return low;
}

void quickSort(int low, int high){
if(low < high){
int mid = partion(low, high);
quickSort(low, mid -1);
quickSort(mid + 1, high);
}
}

int main()
{
///freopen("in.txt","w",stdout);
int k;
cin>>k;
while(k--){
cin>>n;
for( int i = 0; i < n; i++){
cin>>a[i];
}
quickSort(0, n - 1);
for( int i = 0; i < n - 1; i++){
cout<<a[i]<<" ";
}cout<<a[n-1]<<endl;
}
return 0;
}
