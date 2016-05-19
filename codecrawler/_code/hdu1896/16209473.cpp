#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

typedef pair<int,int>mp;

struct cmp{
    bool operator()(mp a,mp b){//firstè¡¨ç¤ºä½ç½®,secondè¡¨ç¤ºè·ç¦»
        if(a.first == b.first)return a.second>b.second;//è·ç¦»ä»å°å°å¤§æåº
        return a.first>b.first;//ä½ç½®ä»å°å°å¤§æåº 
    }
};

priority_queue<mp,vector<mp>,cmp>oq;

int main(){//ä¼åéåæå¥å¤æåº¦logN 
    int t,n,a,b;
    cin>>t;
    while(t--){
        cin>>n;
        while(!oq.empty())oq.pop();
        for(int i=0;i<n;++i){
            cin>>a>>b;
            oq.push(mp(a,b));
        }
        int num=1;
        mp next;
        while(!oq.empty()){
            next=oq.top();
            oq.pop();
            if(num&1)oq.push(mp(next.first+next.second,next.second));
            ++num;
        }
        printf("%d\n",next.first);
    }
    return 0;
} 