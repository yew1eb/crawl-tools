#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n,Q;
struct Rec{
    int x1,x2,y1,y2;
}rec[30];
int s[(1 << 20) + 3], a[22],cnt,add,id;
Rec intersec(Rec a, Rec b){
    Rec ret;
    if(a.x2 <= b.x1 || b.x2 <= b.x1 || a.y2 <= b.y1 || b.y2 <= a.y1){
        ret.x1 = ret.y1 = ret.x2 = ret.y2 = 0;
        return ret;
    }
    ret.x1 = max(a.x1, b.x1);
    ret.y1 = max(a.y1, b.y1);
    ret.x2 = min(a.x2, b.x2);
    ret.y2 = min(a.y2, b.y2);
    return ret;
}
int Area(Rec r){
    if(r.x1 >= r.x2 || r.y1 >= r.y2)
        return 0;
    return (r.y2 - r.y1) * (r.x2 - r.x1);
}
int In_exclusion(int k, Rec r){
    if(Area(r) == 0) return 0;//
    int ret = 0;
    for(int i = k; i <= cnt; i ++){
        Rec tmp = intersec(rec[a[i]],r);
        ret += Area(tmp) - In_exclusion(i + 1,tmp);
    }
    return ret;
}
int main(){
    int k,ca = 1;
    while(~scanf("%d%d",&n,&Q) && (n || Q)){
        printf("Case %d:\n",ca ++);
        Rec total ;
        total.x1 = total.y1 = 0;
        total.x2 = total.y2 = 1000;
        memset(s,0,sizeof(s));
        for(int i = 1; i <= n; ++i){
            scanf("%d%d%d%d",&rec[i].x1,&rec[i].y1,&rec[i].x2,&rec[i].y2);
        }
        for(int qu = 1; qu <= Q; qu ++){
            scanf("%d",&k);
            cnt = 0, add = 0;
            memset(a,0,sizeof(a));
            while(k --){
                scanf("%d",&id);
                add = (add | (1 << (id - 1)));
                a[cnt ++] = id;
            }
            if(s[add] == 0)
                s[add] = In_exclusion(0,total);
            printf("Query %d: %d\n",qu, s[add]);
        }
        printf("\n");
    }
    return 0;
}
