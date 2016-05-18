#include <iostream>
#include <string>
using namespace std;
struct Team
{
    string Name;
    int C,P; //题目数，罚时
    Team():C(0),P(0){}
    Team operator=(const Team& rhs)
    {
        Name = rhs.Name;
        C = rhs.C;
        P = rhs.P;
        return *this;
    }
};
bool operator<(const Team& lhs,const Team& rhs)
{
    if(lhs.C != rhs.C) return lhs.C>rhs.C; //题目数从大到小
    else return lhs.P<rhs.P; //罚时从小到大
}
ostream& operator<<(ostream& out,const Team& lhs)
{
    out<<lhs.Name<<' '<<lhs.C<<' '<<lhs.P;
    return out;
}
int main()
{
    int N;
    int S[4],T[4]; //提交的次数，AC的时间
    while(cin>>N)
    {
        Team best;
        while(N--)
        {
            Team tmp;
            cin>>tmp.Name;
            for(int i=0;i<4;++i)
            {
                cin>>S[i]>>T[i];
                if(T[i])
                {
                    ++tmp.C;
                    tmp.P += (T[i]+(S[i]-1)*20);
                }
            }
            if(tmp<best) best = tmp;
        }
        cout<<best<<endl;
    }
    return 0;
}