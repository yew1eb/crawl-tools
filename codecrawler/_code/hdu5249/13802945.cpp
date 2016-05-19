#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
int main()
{
    int n,T=0;
    while(~scanf("%d",&n)){
        printf("Case #%d:\n",++T);
        deque<int> Q;
        int SZ=0;
        tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pp;
        while(n--){
            char str[10];
            int x;
            scanf("%s",str);
            if(str[0]=='i'){
                scanf("%d",&x);
                Q.push_back(x);
                pp.insert(x);
                SZ++;
            }
            else if(str[0]=='o'){
                pp.erase(Q.front());
                Q.pop_front();
                SZ--;
            }
            else if(str[0]=='q'){
                int ans=*pp.find_by_order(SZ/2);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}