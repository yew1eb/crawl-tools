#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string,int> smp;
int ans;

void init(){
    smp["h"] = 0;
    smp["ha"] = 0;
    smp["hap"] = 0;
    smp["happ"] = 0;
    ans = 0;
}

inline bool yes(char c){
    if (c == 'a' || c == 'h' || c == 'p' || c == 'y')return true;
    return false;
}

inline void add(char c){
    if (c == 'h'){
        ++smp["h"];
    }
    else if (c == 'a' && smp["h"]>0){
        --smp["h"];
        ++smp["ha"];
    }
    else if (c == 'p'){
        if (smp["hap"] > 0){
            --smp["hap"];
            ++smp["happ"];
        }
        else if (smp["ha"] > 0){
            --smp["ha"];
            ++smp["hap"];
        }
        
    }
    else if (c == 'y' && smp["happ"] > 0){
        ++ans;
        --smp["happ"];
    }
}

void solve(string str){
    int len = str.length();

    for (int i = 0; i < len; ++i){
        if (yes(str[i])){
            add(str[i]);
        }
    }
}

int main(){
    string str;

    while (getline(cin, str)){
        init();
        solve(str);

        cout << ans << endl;
    }
    return 0;
}