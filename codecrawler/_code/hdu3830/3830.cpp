#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define ll __int64

struct State
{
    ll x,y,z;
    ll dep;
};
State S,T;

inline bool cmp_state(State a , State b)
{
    if(a.x == b.x && a.y == b.y && a.z == b.z) 
        return true;
    return false;
}

inline ll Abs(ll x)
{
    return x > 0LL ? x : -x;
}

inline void SORT(State &a)
{
    if(a.y < a.x) swap(a.x , a.y);
    if(a.z < a.x) swap(a.x , a.z);
    if(a.y > a.z) swap(a.y , a.z);
}

State Root(State &a)
{
    State tmp = a;
    tmp.dep = 0;
    ll dep = 0;
    while(Abs(tmp.x - tmp.y) != Abs(tmp.y - tmp.z))
    {
        ll len = Abs(tmp.x - tmp.y);
        ll __len = Abs(tmp.y- tmp.z);
        if(__len > len)
        {
            ll c = (__len - 1)/ len; //巧妙，避开判断
            dep += c;
            tmp.y += c * len;
            tmp.x += c * len;
        }
        else
        {
            ll c = (len - 1) / __len;
            dep += c;
            tmp.y -= c * __len;
            tmp.z -= c * __len;
        }
//        printf("%d  %d  %d\n",tmp.x , tmp.y , tmp.z);
    }
    a.dep = dep;
    return tmp;
}

void updata(State &a ,ll delta)
{
    ll count = 0;
    while(count < delta)
    {
        ll len = Abs(a.x - a.y);
        ll __len = Abs(a.y - a.z);
        ll k = Abs(count - delta); //还差多少步
        if(len < __len)
        {
            ll c = (__len - 1) / len; //将要移动多少步
            ll Min = min(k , c);
            a.x += Min * len;
            a.y += Min * len;
            count += Min;
            if(Min == k) break;
        }
        else
        {
            ll c = (len - 1) / __len;
            ll Min = min(k , c);
            a.y -= Min * __len;
            a.z -= Min * __len;
            count += Min;
            if(Min == k) break;
        }
    }
    a.dep -= delta;
}

ll solve()
{
    State tS,tT;
    ll low = 0 , high = S.dep;
    while(low <= high)
    {
        ll mid = (low + high) >> 1;
        ll delta = S.dep - mid;
        tS = S; tT = T;
        updata(tS , delta); //SORT(tS);
        updata(tT , delta); //SORT(tT);
        if(!cmp_state(tS , tT))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 2 * (S.dep - high);
}

int main()
{ 
    //while(cin >> S.x >> S.y >> S.z >> T.x >> T.y >> T.z)
    while( scanf("%I64d%I64d%I64d",&S.x,&S.y,&S.z) != EOF)
    {
        scanf("%I64d%I64d%I64d",&T.x,&T.y,&T.z);
        S.dep = T.dep = 0;
        SORT(S); SORT(T);
        State RS = Root(S);
        State RT = Root(T);

//        printf("%d  %d  %d  %d\n",RS.x , RS.y , RS.z , RS.dep);
//        printf("%d  %d  %d  %d\n",RT.x , RT.y , RT.z , RT.dep);

        if(!cmp_state(RS,RT)) 
        {
            //cout << "N0" << endl;
            printf("NO\n");
            continue;
        }
        ll tmpr = Abs(S.dep - T.dep); //调整的步数记得记录
        if(S.dep > T.dep)
            updata(S , S.dep - T.dep);
        else
            updata(T , T.dep - S.dep);
        
//        printf("%d  %d  %d  %d\n",S.x , S.y , S.z , S.dep);
//        printf("%d  %d  %d  %d\n",T.x , T.y , T.z , T.dep);

        ll res = solve();
        //cout << "YES" << endl;
        //cout << tmpr + res << endl;
        printf("YES\n");
        printf("%I64d\n",res + tmpr);
    }
    return 0;
}