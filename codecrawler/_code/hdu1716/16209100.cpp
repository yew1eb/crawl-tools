#include <iostream>
#include <algorithm>
using namespace std;
int flag,flag_fir;
void print_permutation(int n,int *P,int *A,int cur){
    int i,j;
    if(cur==n){
        if(A[0]){                
            if(A[0]!=flag){    
                if(!flag_fir)        
                    cout<<endl;
                flag_fir=0; 
                flag=A[0];
            }
            else cout<<" ";        
            for(i=0;i<n;i++) 
            cout<<A[i];
        }
    }
    else for(i=0;i<n;i++)
        if(!i||P[i]!=P[i-1]){
        int c1=0,c2=0;
        for(j=0;j<cur;j++) if(A[j]==P[i]) c1++;
        for(j=0;j<n;j++) if(P[j]==P[i]) c2++;
        if(c1<c2){
            A[cur]=P[i];
            print_permutation(n,P,A,cur+1);
        }
    }
}
int main()
{
    int n,A[4],cur;
    int P[4];
    int flag_shit=1;//è¿éé¢æ ¼å¼å¤ªshitäºï¼ï¼ï¼ 
    int S[1000][4];
    int i;
    for(i=0;;i++){
        cin>>S[i][0]>>S[i][1]>>S[i][2]>>S[i][3];
        if(!(S[i][0]||S[i][1]||S[i][2]||S[i][3]))
        break;
    }
    for(int k=0;k<i;k++)
     {
        P[0]=S[k][0];
         P[1]=S[k][1];
        P[2]=S[k][2];
        P[3]=S[k][3];
         flag=-1;
         flag_fir=1;
         sort(P,P+4);    
        cur=0;
        print_permutation(4,P,A,cur);
        cout<<endl;    
        if(k!=i-1) cout<<endl;
     }
    return 0;
}