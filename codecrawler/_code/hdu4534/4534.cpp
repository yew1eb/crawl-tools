#include<iostream>    
#include<cstdio>    
#include<map>    
#include<cstring>    
#include<cmath>    
#include<vector>    
#include<algorithm>    
#include<set>    
#include<stack>  
#include<string>    
#include<ctime>  
#include<queue>    
#include<cassert>  
#define inf 0x11111111
#define maxn 210005    
#define eps 1e-8  
#define zero(a) fabs(a)<eps    
#define Min(a,b) ((a)<(b)?(a):(b))    
#define Max(a,b) ((a)>(b)?(a):(b))    
#define pb(a) push_back(a)    
#define mp(a,b) make_pair(a,b)    
#define mem(a,b) memset(a,b,sizeof(a))    
#define LL long long    
#define MOD 1000000007  
#define sqr(a) ((a)*(a))    
#define Key_value ch[ch[root][1]][0]    
#define test puts("OK");    
#define pi acos(-1.0)  
#define lowbit(x) ((-(x))&(x))  
#pragma comment(linker, "/STACK:1024000000,1024000000")    
using namespace std; 
const int M=1610;
struct Trie  {  
    Trie *next[26];  
    Trie *fail;  
    int must,canot;
    int val,word,kind;
};  
Trie *que[M],s[M];  
int idx,tot,pre[105];
Trie *NewNode()  {  
    Trie *tmp=&s[idx];  
    mem(tmp->next,NULL);  
    tmp->must=tmp->canot=tmp->val=0;
    tmp->fail=NULL; 
    tmp->kind=idx++;
    return tmp;  
}  
void Insert(Trie *root,char *s,int len,int k,int val)  {  
    Trie *p=root;  
    for(int i=0; i<len; i++){  
        if(p->next[s[i]-'a']==NULL) p->next[s[i]-'a']=NewNode();  
        p=p->next[s[i]-'a'];  
    }  
    if(val==999) {p->must|=1<<tot;tot++;}
    else if(val==-999) p->canot|=1;
    else p->val+=val; 
}  
void Bulid_fail(Trie *root)  {  
    int head=0,tail=0;  
    que[tail++]=root;  
    root->fail=NULL;  
    while(head<tail){  
        Trie *tmp=que[head++];  
        for(int i=0; i<26; i++){  
            if(tmp->next[i]){  
                if(tmp==root) tmp->next[i]->fail=root;  
                else{  
                    Trie *p=tmp->fail;  
                    while(p!=NULL){  
                        if(p->next[i]){  
                            tmp->next[i]->fail=p->next[i];  
                            break;  
                        }  
                        p=p->fail;  
                    }  
                    if(p==NULL) tmp->next[i]->fail=root;  
                }  
                if(tmp->next[i]->fail->val) tmp->next[i]->val+=tmp->next[i]->fail->val;  
                if(tmp->next[i]->fail->must) tmp->next[i]->must|=tmp->next[i]->fail->must;
                if(tmp->next[i]->fail->canot) tmp->next[i]->canot|=1;
                que[tail++]=tmp->next[i];  
            }  
            else if(tmp==root) tmp->next[i]=root;  
            else tmp->next[i]=tmp->fail->next[i];  
        }  
    }  
}  
char str[105];
int del[2][M][1<<8];
int pot[2][M][1<<8];
void slove(){
    int l=strlen(str);
    mem(del[1],0x11);
    mem(pot[1],0x8f);
    del[1][0][0]=0;
    pot[1][0][0]=0;
    for(int i=0;i<l;i++){
        mem(del[i&1],0x11);
        mem(pot[i&1],0x8f);
        for(int j=0;j<idx;j++){
            for(int k=0;k<(1<<tot);k++){
                if(del[(i+1)&1][j][k]>=inf) continue;
                if(del[i&1][j][k]>del[(i+1)&1][j][k]+1){
                    del[i&1][j][k]=del[(i+1)&1][j][k]+1;
                    pot[i&1][j][k]=pot[(i+1)&1][j][k];
                }
                else if(del[i&1][j][k]==del[(i+1)&1][j][k]+1&&pot[i&1][j][k]<pot[(i+1)&1][j][k]){
                    del[i&1][j][k]=del[(i+1)&1][j][k]+1;
                    pot[i&1][j][k]=pot[(i+1)&1][j][k];
                }
                int id=str[i]-'a';
                if(s[j].next[id]==NULL) continue;
                int cur=s[j].next[id]->kind;
                if(s[cur].canot) continue;
                int val=s[cur].val;
                int curk=k|s[cur].must; 
                if(del[i&1][cur][curk]>del[(i+1)&1][j][k]){
                    del[i&1][cur][curk]=del[(i+1)&1][j][k];
                    pot[i&1][cur][curk]=pot[(i+1)&1][j][k]+val;
                }
                else if(del[i&1][cur][curk]==del[(i+1)&1][j][k] && pot[i&1][cur][curk]<pot[(i+1)&1][j][k]+val){
                    del[i&1][cur][curk]=del[(i+1)&1][j][k];
                    pot[i&1][cur][curk]=pot[(i+1)&1][j][k]+val;
                }
            }
        }
    }
    int a1=inf,a2;
    int full=(1<<tot)-1,num=(l+1)&1;
    for(int i=0;i<idx;i++){
        if(del[num][i][full]<a1){
            a1=del[num][i][full];
            a2=pot[num][i][full];
        }
        else if(del[num][i][full]==a1&&pot[num][i][full]>a2){
            a1=del[num][i][full];
            a2=pot[num][i][full];
        }
    }
    if(a1>=inf) puts("Banned");
    else printf("%d %d\n",a1,a2);
}
int n,val;
int main(){
    // freopen("input.txt","r",stdin);
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        idx=0;tot=0;
        scanf("%d",&n);
        Trie *root=NewNode();
        for(int i=0;i<n;i++){
            scanf("%s%d",str,&val);
            Insert(root,str,strlen(str),i,val);
        }
        Bulid_fail(root);
        scanf("%s",str);
        printf("Case %d: ",++cas);
        slove();
    }
    return 0;
}
