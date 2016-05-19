#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long long maxs = 2147483647;

long long r[101];
int n;

long long left(long long a){
    if(r[a] == r[0])
        return r[n-1];
    else{
        if(r[a] != r[a-1])
            return r[a-1];
        else
            return left(a-1);
    }
}

long long right(long long a){
    if(r[a] == r[n-1])
        return r[0];
    else{
        if(r[a] != r[a+1])
            return r[a+1];
        else
            return right(a+1);
    }
}


int main()
{

    int cases = 1;
    while(cin >> n){
        memset(r,0,sizeof(r));
        int counts = 0;
        for(int i = 0; i < n; i++){
            cin >> r[i];
        }
        sort(r,r+n);
        if(r[0] == r[n-1]){
            cout << "Case #" << cases++ << ": " << -1 << endl;
            continue;
        }
        for(int i = 0; i < n; i++){
            if((left(i)+r[i]) % maxs == right(i))
                ++counts;
        }
        cout << "Case #" << cases++ << ": " << counts << endl;
    }
    return 0;
}
