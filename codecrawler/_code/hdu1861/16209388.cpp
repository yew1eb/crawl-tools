//hdu_1861
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef struct _rent
{
    int cnt;
    int stim;
    int etim;
    int ttim;
    bool flag;
}rent;

rent rt[101];

int main()
{
//    freopen("input.in", "r", stdin);
    int bnum, i, ttime, cnt;
    char op;
    int timh, timm;
    memset(rt, 0, sizeof(rt));
    while(scanf("%d", &bnum)!=EOF){
        if(bnum == -1)break;
        if(bnum == 0){
            scanf(" %c %d:%d", &op, &timh, &timm);
            ttime = cnt = 0;
            for(i = 1; i < 101; i ++){
                cnt += rt[i].cnt;
                ttime += rt[i].ttim;
            }
            printf(ttime == 0 ? "0 0\n" : "%d %d\n", cnt,
                   (int)(1.0*ttime / cnt + 0.5));
            memset(rt, 0, sizeof(rt));
        }
        else{
            scanf(" %c %d:%d", &op, &timh, &timm);
            if(op == 'S'){
                rt[bnum].stim = timh*60 + timm;
                rt[bnum].flag = 1;
            }
            if(op == 'E'){
                rt[bnum].etim = timh * 60 + timm;
                if(rt[bnum].flag != 0){
                    rt[bnum].cnt ++;
                    rt[bnum].ttim += rt[bnum].etim - rt[bnum].stim;
                    rt[bnum].flag = 1;
                }
            }
        }
    }
    return 0;
}
