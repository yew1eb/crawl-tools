#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<cstdlib>
using namespace std;
const int MAX=5010;
typedef long long ll;
map<int,bool> vis;
struct Girl{
    int prior;//ä¼åçº§
    ll word;//CLJè·å¥¹è¯´äºå¤å°è¯
}que[MAX];
int tail,top;
int ATop;
void init(){
    vis.clear();
    tail=0;top=-1;
    ATop=-1;
}
void Add(int u){
    if(vis[u]){
        printf("same priority.\n"); return;
    }
    printf("success.\n");
    vis[u]=1;
    que[tail].prior=u;
    que[tail++].word=0;
}
void Close(int u){
    if(!vis[u]) {printf("invalid priority.\n");return;}
    vis[u]=0;
    int x=0;
    for(int i=0;i<tail;i++){
        if(que[i].prior==u){x=i;break;}
    }
    if(que[x].prior==ATop){
        ATop=-1;
    }
    printf("close %d with %I64d.\n",que[x].prior,que[x].word);
    for(int i=x;i<tail;i++) que[i]=que[i+1];
    tail--;
}
void Chat(int u){//u the number of words
    if(tail==0){printf("empty.\n");return;}
    printf("success.\n");
    if(ATop!=-1){
        for(int i=0;i<tail;i++){
            if(que[i].prior==ATop){
                que[i].word+=u;
                break;
            }
        }
    }
    else que[0].word+=u;
}
void Rotate(int u){
    if(u>=1&&u<=tail){
        u--;
        while(u){swap(que[u],que[u-1]);u--;}
        printf("success.\n");
    }
    else{
        printf("out of range.\n");
    }
}
void Choose(int u){
    if(!vis[u]){
        printf("invalid priority.\n");return;
    }
    else{
        printf("success.\n");
        int x=0;
        for(int i=0;i<tail;i++){
            if(que[i].prior==u){
                x=i;break;
            }
        }
        while(x){swap(que[x],que[x-1]);x--;}
    }
}
void Top(int u){
    if(!vis[u]){
        printf("invalid priority.\n");return;
    }
    else{
        printf("success.\n");
        ATop=u;
    }
}
void Untop(){
    if(ATop==-1){
        printf("no such person.\n");
        return;
    }
    printf("success.\n");
    ATop=-1;return;
}
void Prior(){
    if(tail==0){
        printf("empty.\n");return;
    }
    printf("success.\n");
    int x=0;
    for(int i=0;i<tail;i++){
        if(que[i].prior>que[x].prior){
            x=i;
        }
    }
    while(x){swap(que[x],que[x-1]);x--;}
}
int main(){
   // freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);

    char ord[10];
    int u;
    while(T--){
        init();
        int NN;scanf("%d",&NN);
        int nkase=0;
        while(NN--){
            printf("Operation #%d: ",++nkase);
            scanf("%s",ord);
            if(strcmp(ord,"Untop")==0){
                Untop();
            }
            else if(strcmp(ord,"Prior")==0){
                Prior();
            }
            else{
                scanf("%d",&u);
             //   cout<<"ss"<<endl;
              //  cout<<u<<endl;
                if(strcmp(ord,"Add")==0){
                      //  cout<<"sss"<<endl;
                    Add(u);
                }
                else if(strcmp(ord,"Close")==0){
                    Close(u);
                }
                else if(strcmp(ord,"Chat")==0){
                    Chat(u);
                }
                else if(strcmp(ord,"Rotate")==0){
                    Rotate(u);
                }
                else if(strcmp(ord,"Choose")==0){
                    Choose(u);
                }
                else if(strcmp(ord,"Top")==0){
                    Top(u);
                }
            }

        }
             if(ATop!=-1){
                int x=0;
                for(int i=0;i<tail;i++){
                    if(que[i].prior==ATop){
                        x=i;break;
                    }
                }
                if(que[x].word>0){
                    printf("Bye %d: %I64d\n", que[x].prior, que[x].word);
                }
            }
            for(int i=0;i<tail;i++){
                if(que[i].word&&que[i].prior!=ATop){
                    printf("Bye %d: %I64d\n", que[i].prior, que[i].word);
                }
            }
    }
    return 0;
}
