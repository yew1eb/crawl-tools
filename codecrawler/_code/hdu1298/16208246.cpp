#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=100+10;
int m[10]={0,0,3,3,3,3,3,4,3,4};//è¡¨ç¤ºæé®iæå ä¸ªå­ç¬¦
char ch[10][5]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; 
char s[MAX];
string temp;
int sum;

struct TrieNode{
    int num;//åºç°é¢ç
    TrieNode *next[26];
    TrieNode(){
        num=0;
        memset(next,0,sizeof next);
    } 
}root;

void InsertNode(char *a,int num){
    int k=0;
    TrieNode *p=&root;
    while(a[k]){
        if(!p->next[a[k]-'a'])p->next[a[k]-'a']=new TrieNode;
        p=p->next[a[k++]-'a'];
        p->num+=num;
    }
}

void SearchTrie(int k,int len,TrieNode *p,string a){
    if(k == len){
        if(p->num > sum){
            sum=p->num;
            temp=a;
        }
    }
    int t=s[k]-'0';
    for(int i=0;i<m[t];++i){
        if(p->next[ch[t][i]-'a'])SearchTrie(k+1,len,p->next[ch[t][i]-'a'],a+ch[t][i]);
    }
}

void Free(TrieNode *p){
    for(int i=0;i<26;++i)if(p->next[i])Free(p->next[i]);
    delete p;
}

int main(){
    int t,n,num=0,w;
    cin>>t;
    while(t--){
        cout<<"Scenario #"<<++num<<":\n";
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>s>>w;
            InsertNode(s,w);
        }
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>s;
            int len=strlen(s);
            for(int j=1;j<len;++j){
                sum=0;
                SearchTrie(0,j,&root,"\0");
                if(sum)cout<<temp<<endl;
                else cout<<"MANUALLY"<<endl;
            }
            cout<<endl;
        }
        cout<<endl;
        for(int i=0;i<26;++i){
            if(root.next[i])Free(root.next[i]);
            root.next[i]=NULL;
        } 
    }
    return 0;
}