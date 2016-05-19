#include <stdio.h>  
#include <string.h>  
#include <queue>  
using namespace std;  
inline int Max(int a,int b){return a>b?a:b;}  
inline int Min(int a,int b){return a>b?b:a;}  
int ANS;  
  
  
#define N 5110000  
#define maxnode 250100  
#define sigma_size 26  
  
struct Trie{  
    int ch[maxnode][sigma_size];  
    int val[maxnode];  
    int last[maxnode];  
    int f[maxnode];  
    int sz;  
    void init(){  
        sz=1;  
        memset(ch,0,sizeof(ch));  
        memset(val, 0, sizeof(val));  
        memset(f,0,sizeof(f));  
        memset(last,0,sizeof(last));  
    }  
    int idx(char c){  
        return c-'A';  
    }  
    void print(int j){  
        if(j){  
            printf("%d: %d\n", j, val[j]);  
            print(last[j]);  
        }  
    }  
  
    void Creat(char *s){    
        int u = 0, len = strlen(s);    
        for(int i = 0; i < len; i++){    
            int c = idx(s[i]);    
            if(!ch[u][c])  ch[u][c] = sz++;    
            u = ch[u][c];          
        }    
        val[u]  ++ ; //u若是单词结尾则为 +1  
    }    
  
    void find(char *T){  
        int len = strlen(T);  
        int j = 0;  
        for(int i = 0; i < len; i++){  
            int c = idx(T[i]);  
  
            j = ch[j][c];  
                       int temp = j;  
             while(temp && val[temp]) { ANS += val[temp];  val[temp] = 0;  }      
        }  
  
    }  
  
    void getFail(){  
        queue<int> q;  
        f[0] = 0;  
        //初始化队列  
        for(int c = 0; c < sigma_size; c++)  
            if(ch[0][c])q.push(ch[0][c]);  
  
        while(!q.empty()){  
            int r = q.front(); q.pop();  
            for(int c = 0; c < sigma_size; c++){  
                int u = ch[r][c];  
                if(!u){ ch[r][c] = ch[f[r]][c]; continue; }  
                q.push(u);  
                int v = f[r];  
                while(v && !ch[v][c]) v = f[v]; //沿失配边追溯到可以匹配的(非原点)位置  
                f[u] = ch[v][c];  
                last[u] = val[f[u]] ? f[u] :  last[f[u]];  
            }  
        }  
    }  
};  
Trie ac;  
char S1[N],S2[N];  
int Slen;  
  
void InputString(){  
    char c = getchar();  
    Slen = 0;  
  
    while(c=getchar() , c!='\n')  
        if(c!='[')S1[Slen++] = c;  
        else {  
            int x;  
            scanf("%d",&x);  
            c=getchar();  
            while( x-- )S1[Slen++]=c;  
            getchar();  
        }     
        S1[Slen]='\0';  
}  
int main(){  
  
    int T,i,j,n;scanf("%d",&T);  
  
    while(T--){  
        ac.init();  
        scanf("%d",&n);  
        for(i=0;i<n;i++){  
            scanf("%s",S1);  
            ac.Creat(S1);  
        }  
        ac.getFail();  
        InputString();  
        for(i=0;i<Slen;i++)S2[Slen - i -1] = S1[i];  
        S2[Slen]='\0';  
  
        ANS = 0;  
        ac.find(S1);  
        ac.find(S2);  
  
        printf("%d\n",ANS);  
  
    }  
    return 0;  
}  
/*  
99  
  
3  
GGJ  
G  
GG  
GGGJ  
  
3  
GGJ  
G  
GG  
GGJ  
  
ans:  
3  
3  
  
  
*/  
