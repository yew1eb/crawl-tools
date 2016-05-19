#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

typedef struct Record{
    int m;
    int n;
}Record;

Record r[100];
vector<Record> stk;

void Init();
void Caculate(char* buf);

int main(){
    Init();
    char buf[10000];
    while(scanf("%s", buf) != EOF){
        Caculate(buf);
    }
}

void Init(){
    int len;
    scanf("%d", &len);
    char c;
    for(int i = 0; i < len; ++i){
        scanf("%c %c", &c, &c);
        c -= 'A';
        scanf("%d %d", &r[c].m, &r[c].n);
    }
}

void Caculate(char* buf){
    int l = 0, r = 0, result = 0, len = strlen(buf);
    stk.clear();
    char c;
    for(int i = 0; i < len; ++i){
        c = buf[i];
        if(c == '('){
            ++l;
        }else if(c == ')'){
            --l;
            if(stk.size() >= 2){
                Record lr = stk.back();
                stk.pop_back();
                Record ll = stk.back();
                stk.pop_back();
                if(lr.m != ll.n){
                    printf("error\n");
                    return;
                }else{
                    Record r;
                    r.m = ll.m;
                    r.n = lr.n;
                    result += ll.m * ll.n * lr.n;
                    stk.push_back(r);
                }
            }else if(stk.size() == 1){
                //do nothing
            }else{//0
                printf("error\n");
                return;
            }
        }else{//push stack
            stk.push_back(::r[c-'A']);
        }
    }
    Record lr;//= stk.back();
    //stk.pop_back();
    Record ll;// = stk.back();
    //stk.pop_back();
    Record rr;
    while(stk.size() > 1){
        lr = stk.back();
        stk.pop_back();
        ll = stk.back();
        stk.pop_back();
        if(ll.n != lr.m){
            printf("error\n");
            return;
        }else{
            rr.m = ll.m;
            rr.n = lr.n;
            stk.push_back(rr);
            result += ll.m * ll.n * lr.n;
        }
    }
    printf("%d\n", result);
}

