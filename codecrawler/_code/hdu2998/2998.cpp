#include<iostream>
#include<stdio.h>

using namespace std;

int a[10005],idx=0;

int search(int init,int fin){
    for(int i=init; i<=fin; i++){
        if(a[i]>a[init-1]) return i-1;
    }
    return fin;
}

void code(int init, int fin){
    if(init>=idx || fin>=idx) return;
    if(init==fin){
        cout<<a[init]<<endl;
        return;
    }
    if(init<fin){
        int mid = search(init+1,fin);
        code(init+1,mid);
        code(mid+1,fin);
        cout<<a[init]<<endl;
    }
}

int main(){
    int num;
    while(cin>>num){
        a[idx++] = num;
    }
    code(0,idx-1);
}