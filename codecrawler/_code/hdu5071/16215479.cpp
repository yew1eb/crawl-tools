#include<cstdio>
#include<cstring>
struct QQ{
    int len;
    int top;
    struct MM{
        int u;
        long long words;
        void init(int u){
            words = 0;
            this->u = u;
        }
    };
    MM m[5009];
    void init(){
        top = len = 0;
    }
    void add(int u){
        int i = 0;
        for(; i < len; i++){
            if(m[i].u == u) break;
        }
        if(i != len) printf("same priority");
        else{
            m[len++].init(u);
            printf("success");
        }
    }
    void close(int u){
        int i = 0;
        for(; i < len; i++){
            if(m[i].u == u) break;
        }
        if(i == len) printf("invalid priority");
        else{
            if(top == u) top = 0;
            printf("close %d with %I64d", m[i].u, m[i].words);
            for(int j = i; j < len-1; j++){
                m[j] = m[j+1];
            }
            len--;
        }
    }
    void chat(int w){
        if(!len) printf("empty");
        else{
            int d = 0;
            if(top){
                for(int i = 0; i < len; i++){
                    if(m[i].u == top){d = i;break;}
                }
            }
            m[d].words += w;
            printf("success");
        }
    }
    void rotate(int x){
        if(x < 1 || x > len) printf("out of range");
        else{
            up(x-1);
            printf("success");
        }
    }
    void up(int x){
        MM temp = m[x];
        for(int i = x-1; i >= 0; i--) m[i+1] = m[i];
        m[0] = temp;
    }
    void prior(){
        if(!len) printf("empty");
        else{
            int cur = 0;
            for(int i = 1; i < len; i++){
                if(m[i].u > m[cur].u) cur = i;
            }
            up(cur);
            printf("success");
        }
    }
    void choose(int u){
        int i = 0;
        for( ; i < len; i++){
            if(m[i].u == u) break;
        }
        if(i == len) printf("invalid priority");
        else{
            up(i);
            printf("success");
        }
    }
    void Top(int u){
        int i = 0;
        for( ; i < len; i++){
            if(m[i].u == u) break;
        }
        if(i == len) printf("invalid priority");
        else{
            top = u;
            printf("success");
        }
    }
    void untop(){
        if(!top) printf("no such person");
        else{
            top = 0;
            printf("success");
        }
    }
    void close_all(){
        int d = -1;
        if(top){
            for(int i = 0; i < len; i++){
                if(m[i].u == top && m[i].words) {d = i; break;}
            }
            if(d!=-1)printf("Bye %d: %I64d\n", top, m[d].words);
        }
        for(int i = 0; i < len; i++) if(i != d && m[i].words){
            printf("Bye %d: %I64d\n", m[i].u, m[i].words);
        }
    }
};
QQ qq;
int main(){
 //   freopen("1.txt","r",stdin);
    int T;scanf("%d", &T);
    while(T--){
        qq.init();
        int n;scanf("%d", &n);
        char s[15];
        int c;
        for(int i = 1; i <= n; i++){
            printf("Operation #%d: ", i);
            scanf("%s",s);
            if(strcmp(s,"Add") == 0){
                scanf("%d",&c);
                qq.add(c);
            }else if(strcmp(s,"Close") == 0){
                scanf("%d",&c);
                qq.close(c);
            }else if(strcmp(s,"Chat") == 0){
                scanf("%d",&c);
                qq.chat(c);
            }else if(strcmp(s,"Rotate") == 0){
                scanf("%d",&c);
                qq.rotate(c);
            }else if(strcmp(s,"Prior") == 0){
                qq.prior();
            }else if(strcmp(s,"Choose") == 0){
                scanf("%d", &c);
                qq.choose(c);
            }else if(strcmp(s,"Top") == 0){
                scanf("%d",&c);
                qq.Top(c);
            }else if(strcmp(s,"Untop") == 0){
                qq.untop();
            }
            printf(".\n");
        }
        qq.close_all();
    }
    return 0;
}
