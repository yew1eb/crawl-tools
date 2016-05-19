#include<iostream>
using namespace std;

bool flag;
void DFS(int n,int *A,int *B,int *C){
    if(n==0){
        flag = true;
        return ;
    }
    if(B[0]&&n==B[1]){
        flag = false;
        return ;
    }
    if(A[0]&&n==A[1]){
        A[1]=A[0]-1;
        DFS(n-1,++A,C,B);
    }else if(C[0]&&n==C[1]){
        C[1]=C[0]-1;
        DFS(n-1,B,A,++C);
    }
}
int main(){
    int A[70],B[70],C[70];
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        cin>>A[0];
        for(int i=1;i<=A[0];i++)
            cin>>A[i];
        cin>>B[0];
        for(int i=1;i<=B[0];i++)
            cin>>B[i];
        cin>>C[0];
        for(int i=1;i<=C[0];i++)
            cin>>C[i];
        DFS(n,A,B,C);

        if(flag)
        cout<<"true"<<endl;
        else
        cout<<"false"<<endl;
    }
}
