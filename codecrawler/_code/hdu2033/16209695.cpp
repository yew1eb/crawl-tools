#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    int AH,AM,AS,BH,BM,BS;
    int S,M,H;
    cin>>n;
    while(n--){
        cin>>AH>>AM>>AS>>BH>>BM>>BS;
        S=(AS+BS)%60;
        M=(AM+BM+(AS+BS)/60)%60;
        H=AH+BH+((AS+BS)/60+AM+BM)/60;
        cout<<H<<" "<<M<<" "<<S<<endl;
    }
    return 0;
}