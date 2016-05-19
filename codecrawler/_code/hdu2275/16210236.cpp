
#include<set>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n;
multiset<int>st;

void solve(int x){
    if(st.empty() || x < *(st.begin())){
        puts("No Element!");
        return;
    }
    multiset<int>::iterator it;
    it = st.find(x);
    if(it != st.end()){
        printf("%d\n" , *it);
        st.erase(it);
    }
    else{
        multiset<int>::iterator it2;
        st.insert(x);
        it = it2 = st.find(x);
        it2--;
        printf("%d\n" , *it2);
        st.erase(it);
        st.erase(it2);
    }
}

int main(){
    char str[10];
    int x;
    while(scanf("%d%*c" , &n) != EOF){
        st.clear();
        while(n--){
            scanf("%s %d%*c" , str , &x); 
            if(!strcmp(str,"Push"))
                st.insert(x); 
            else
                solve(x);
        } 
        puts("");
    }
    return 0;
}
