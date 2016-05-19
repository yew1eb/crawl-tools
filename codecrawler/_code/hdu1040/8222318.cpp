#include <stdio.h>
#define N 1000
int data[N];

void MaxHeapify(int* data, int i, int size) {
    int p = 2*i + 1, temp;
    while(p<size) {
        if(p+1<size&& data[p]<data[p+1])
            ++p;
        if(data[i]<data[p]) {
            temp = data[i],data[i] = data[p], data[p] = temp;
            i = p;
            p = 2*i+1;
        } else break;
    }
}
int main() {
    int T, n, i, temp;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(i=0; i<n; ++i)
            scanf("%d",&data[i]);
        for(i=n/2; i>=0; --i)
            MaxHeapify(data,i,n);
        for(i=n-1; i>=1; --i) {
            temp = data[0],data[0] = data[i],data[i] = temp;
            MaxHeapify(data,0,i);
        }
        for(i=0; i<n-1; ++i)
            printf("%d ",data[i]);
        printf("%d\n",data[i]);
    }
    return 0;
}
