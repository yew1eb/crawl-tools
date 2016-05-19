#include <iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--){
        char x;
        int y;
        cin>>x>>y;
        if(x>='a'&&x<='z') cout<<y-(int)(x-'a'+1)<<endl;
        else if(x>='A'&&x<='Z') cout<<y+(int)(x-'A'+1)<<endl;
    }
    return 0;
}