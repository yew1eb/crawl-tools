#include<iostream>
#include<stdlib.h>
using namespace std;
int stores[25];
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int main(){
    int t;
    int n;
    cin>>t;
    while(t--){
        cin>>n;
        int i;
        for(i=0;i<n;i++)
            cin>>stores[i];
        qsort(stores,n,sizeof(int),cmp);
        cout<<(stores[n-1]-stores[0])*2<<endl;
    }
    return 0;
}