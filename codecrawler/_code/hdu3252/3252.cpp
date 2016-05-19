#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <set>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX=1005,INF=1<<30;
const string END="#CODE-END";

int len;
map<string,int> mymap;
map<string,int>::iterator ite;

vector<string> A,B;

int cnt;
int f[MAX][MAX];
int ma[MAX],mb[MAX];
vector<int> a,b;
int Test;

void read(vector<string> &t,vector<int> &arr){

    string s;
    while(getline(cin,s)){
        if(s==END)
            break;
        ite=mymap.find(s);
        if(ite==mymap.end())
            mymap[s]=len++;
//        cout<<"LEN: "<<s<<" "<<mymap[s]<<endl;

        t.push_back(s);
        arr.push_back(mymap[s]);
    }

//    for(int i=0;i<(int)arr.size();i++)
//        cout<<"T:  "<<arr[i]<<endl;


    return ;
}

void createM(){

    int n1=(int)a.size()-1,n2=(int)b.size()-1;
//    cout<<"n1:n2 "<<n1<<" "<<n2<<endl;
//    f[0][0]=0;
//    for(int i=0;i<=n1;i++) f[i][0]=0;
//    for(int i=0;i<=n2;i++) f[0][i]=0;
    memset(f,0,sizeof(f));

    for(int i=n1;i>=1;i--){
        for(int j=n2;j>=1;j--){
            if(a[i]==b[j])
                f[i][j]=f[i+1][j+1]+1;
            else
                f[i][j]=max(f[i+1][j],f[i][j+1]);
        }
    }

//    cout<<f[n1][n2]<<endl;
//    if(Test==0){
//        for(int i=0;i<=n1;i++)
//            cout<<"a: "<<a[i]<<endl;
//
//        for(int i=0;i<=n2;i++)
//            cout<<"b: "<<b[i]<<endl;
//    }

//    int i=1,j=1;
    int L=f[1][1];
    cnt=f[1][1];
//    while(L<f[1][1]){
////        if(i>n1||j>n2)
////            while(1) ;
//        if(a[i]==b[j]){
//            ma[L]=(i++)-1;
//            mb[L]=(j++)-1;
//            ++L;
//        }
//        else if(f[i+1][j]<f[i][j+1])
//            ++j;
//        else
//            ++i;
//    }

    int x = -1,c=0;
    for(int i = 1; i<=n1; i++)
    {
        for(int j = 1; j<= n2; j++)
        {
            if(a[i] == b[j] && f[i][j] == L && j > x)
            {
                x = j;
                L--;
//                record[cnt][0] = i, record[cnt][1] = j;
                ma[c]=i-1;
                mb[c]=j-1;
                x = j;
                c++;
                break;
            }
        }
    }
//    cout<<"DSA: "<<n1<<" "<<n2<<endl;
//    cout<<"ASD: "<<i<<" "<<j<<endl;

//    cout<<"CNTTTTTTTTTTTTT: "<<cnt<<endl;
//    for(int i=0;i<cnt;i++)
//        cout<<ma[i]<<" "<<mb[i]<<endl;

    return ;
}

struct DD{
    bool isM;
    int b,e;
};
DD DA[MAX*3],DB[MAX*3];

void cut(){
//    cout<<"CNT: "<<cnt<<endl;
    int front=0,rear=0;

    int len=0;
    for(int i=0;i<2*cnt;i++,len++){
        rear=ma[len];
        if(front<rear){
            DA[i].isM=0;
            DA[i].b=front;
            DA[i].e=rear-1;
        }
        else {
            DA[i].isM=0;
            DA[i].b=-1;
            DA[i].e=-1;
        }

        //plus M[];
        ++i;
        DA[i].isM=1;
        DA[i].b=ma[len];
        DA[i].e=ma[len];
        front=ma[len]+1;

    }
    rear=(int)A.size();

    if(front<rear){
        DA[cnt*2].isM=0;
        DA[cnt*2].b=front;
        DA[cnt*2].e=rear-1;
    }
    else {
        DA[cnt*2].isM=0;
        DA[cnt*2].b=-1;
        DA[cnt*2].e=-1;
    }

    front=rear=0;
    len=0;
    for(int i=0;i<2*cnt;i++,len++){
        rear=mb[len];
        if(front<rear){
            DB[i].isM=0;
            DB[i].b=front;
            DB[i].e=rear-1;
        }
        else {
            DB[i].isM=0;
            DB[i].b=-1;
            DB[i].e=-1;
        }

        //plus M[];
        ++i;
        DB[i].isM=1;
        DB[i].b=mb[len];
        DB[i].e=mb[len];
        front=mb[len]+1;

    }
    rear=(int)B.size();

    if(front<rear){
        DB[cnt*2].isM=0;
        DB[cnt*2].b=front;
        DB[cnt*2].e=rear-1;
    }
    else {
        DB[cnt*2].isM=0;
        DB[cnt*2].b=-1;
        DB[cnt*2].e=-1;
    }

//    cout<<"TES: "<<endl;
//    for(int i=0;i<2*cnt+1;i++){
//        cout<<DB[i].b<<" "<<DB[i].e<<" ";
//        if(DB[i].isM)
//            cout<<"YES"<<endl;
//        else
//            cout<<"NO"<<endl;
//
//    }

    return ;
}

void output(){

    for(int i=0;i<2*cnt+1;i++){

        if(DA[i].isM)
            cout<<A[DA[i].b]<<endl;
        else if(DA[i].b==-1&&DA[i].e==-1){
            if(DB[i].b==-1&&DB[i].e==-1)
                continue;
            else{
                for(int j=DB[i].b;j<=DB[i].e;j++){
                    cout<<B[j]<<endl;
                }
            }
        }
        else if(DB[i].b==-1&&DB[i].e==-1){
            if(DA[i].b==-1&&DA[i].e==-1)
                continue;
            else{
                for(int j=DA[i].b;j<=DA[i].e;j++){
                    cout<<A[j]<<endl;
                }
            }
        }
        else {
            cout<<"//**** CONFLICT STARTS ****//"<<endl
                <<"//code in A:"<<endl;
            for(int j=DA[i].b;j<=DA[i].e;j++){
                cout<<A[j]<<endl;
            }
            cout<<"//code in B:"<<endl;
            for(int j=DB[i].b;j<=DB[i].e;j++){
                cout<<B[j]<<endl;
            }
            cout<<"//***** CONFLICT ENDS *****//"<<endl;
        }

    }
    return ;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
#endif
//    freopen("comehome.in","r",stdin);
//    freopen("comehome.out","w",stdout);

    int test=1;
    cin>>Test;
    cin.ignore();
    while(Test--){

        cout<<"Case "<<test++<<":"<<endl;

        len=0;
        mymap.clear();
        A.clear();B.clear();
        a.clear();b.clear();
        a.push_back(-1);b.push_back(-1);

        read(A,a);
        read(B,b);

        createM();

        cut();

        output();
        cout<<endl;
    }
    return 0;
}