    #include <iostream>
    #include <cstdio>
    #include <cstring>
    #include <vector>
    #include <string>
    #include <algorithm>
    #include <queue>
    using namespace std;
    const int maxn = 100000+10;
    vector<int> val,cnt;
    int res[maxn][20];
    int num[maxn],lft[maxn],rgt[maxn];
    int n,q;
    void init_RMQ(){
        int nt = cnt.size();
        for(int i = 0; i < nt; i++) res[i][0] = cnt[i];
        for(int j = 1; (1<<j) <= nt; j++){
            for(int i = 0; i+(1<<j)-1 < nt; i++)
                res[i][j] = max(res[i][j-1],res[i+(1<<(j-1))][j-1]);
        }
    }
    int RMQ(int L,int R){
        int k = 0;
        while((1<<(k+1)) <= R-L+1) k++;
        return max(res[L][k],res[R-(1<<k)+1][k]);
    }
    int main(){

        int t,now;
        while(cin >> n &&n){
            cin >> q;
            val.clear();
            cnt.clear();
            scanf("%d",&now);
            cnt.push_back(1);
            for(int i = 1; i < n; i++){
                int t;
                scanf("%d",&t);
                if(t==now)
                    cnt[cnt.size()-1]++;
                else{
                    now = t;
                    cnt.push_back(1);
                }
            }
            init_RMQ();
            int cur = 0;
            for(int i = 0; i < cnt.size(); i++){
                int tl = cur,tr = cur+cnt[i]-1;
                for(int j = 0; j < cnt[i]; j++){
                    num[cur] = i;
                    lft[cur] = tl;
                    rgt[cur++] = tr;
                }
            }

            while(q--){
                int L,R;
                scanf("%d%d",&L,&R);
                if(L > R) swap(L,R);
                L--;R--;
                int sta = num[L],ed = num[R];
                if(sta==ed){
                    printf("%d\n",R-L+1);
                    continue;
                }
                int ans = max(rgt[L]-L+1,R-lft[R]+1);
                sta++;
                ed--;
                if(sta<=ed)
                    ans = max(ans,RMQ(sta,ed));
                printf("%d\n",ans);
            }
        }
        return 0;
    }
