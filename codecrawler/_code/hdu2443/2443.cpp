/*
 * hdu2443.cpp
 *
 *  Created on: 2010-12-4
 *      Author: caiweiwen
 */
#include <cstdio>
const int MAXN=100000;
typedef long long arr[MAXN+1];

arr sum,tmp;
int t,n,a,score;

long long merge(int l,int m,int r){
    int h1,h2,tmp_h,i;
    long long count=0;

    h1=l;h2=m+1;tmp_h=l;
    while (h1<=m && h2<=r)
        if (sum[h2]>sum[h1]){
            tmp[tmp_h++]=sum[h1];
            h1++;
            count+=r-h2+1;
        }
        else{
            tmp[tmp_h++]=sum[h2];
            h2++;
        }
    while (h1<=m) tmp[tmp_h++]=sum[h1++];
    while (h2<=r) tmp[tmp_h++]=sum[h2++];
    for (i=l;i<=r;i++)
        sum[i]=tmp[i];
    return count;
}

long long merge_sort(int l,int r){
    long long tot=0;

    if (l!=r){
        tot=merge_sort(l,(l+r)/2);
        tot+=merge_sort((l+r)/2+1,r);
        tot+=merge(l,(l+r)/2,r);
        return tot;
    }
    else
        return 0;
}

int main(){
    int i,j;

    scanf("%d",&t);
    sum[0]=0;
    for (i=0;i<t;i++){
        scanf("%d %d",&n,&a);
        for (j=1;j<=n;j++){
            scanf("%d",&score);
            sum[j]=sum[j-1]+(score-a);
        }
        printf("%I64d\n",merge_sort(0,n));
    }
    return 0;
}
/*
 * 在最后输入要用%I64d，如果用%lld 会WA
 * 先把问题转换成求“正序对"问题（”正序对“方法类似于逆序对--算法导论P24思考题)
 * 题目要求的是给出n个数，问有多少个区间，使得区间的平均值大于a
 * 如果用一般的枚举，时间复杂度为O（n^2），由于n<=100000,因此肯定超时。
 * 设sum[i]=sum[i-1]+score[i]-i*a;
 *    如果sum[i]-sum[j]>0 （i>j),即sum[i]>sum[j] (i>j) 那么区间[i,j]就满足条件
 *    sum[i]>sum[j] (i>j)就类似于求逆序对a[i]>a[j] 且 i<j
 *    然后用那个类似于合并排序的算法来求“正序对”个数，时间复杂度为O（nlgn）
 *
 *    类似与合并排序求逆序对的算法：
 *     利用分治法
 *     分解：含有n个数的序列分解成各含有n/2个数的子序列；
 *     解决：用类似于合并排序对两个子序列递归排序，并求逆序对数；
 *     合并：合并两个 已求出逆序对个数 且 已排序 的子序列，得到 一个子序列对于另一个子序列的逆序对个数 和 该序列的排序结果，那么 两个子序列逆序对的个数 加上 两个子序列之间逆序对个数 就是该序列逆序对的个数。
 *
 */