/*
* hdu acm step Â°ÃÂ²Â½Â´Â©ÃÃ®
* date 2014/5/10
* state AC
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

//const int MAXN=30;
//int A[50];
//int B[50];
struct Arrow
{
    int len;
    int num;
};
//Arrow arrows[50];
vector<Arrow> vectorArrow;

bool Comp(const Arrow& a,const Arrow& b)
{
    if(a.len!=b.len)return a.len<b.len;
    else return a.len<b.len;
}

void drawArrows(int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<vectorArrow[i].num;j++)
        {
            //for(int k=0;k<vectorArrow[i].len;k++)
            //    cout<<
            cout<<">+";
            for(int k=0;k<vectorArrow[i].len-2;k++)
            {
                cout<<"-";
            }
            cout<<"+>";
            cout<<endl;
        }
        cout<<endl;
    }
}

int main()
{
    //cout << "Hello world!" << endl;
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        vectorArrow.clear();
        int N;
        cin>>N;
        //cout<<N<<endl;
        for(int j=0;j<N;j++)
        {
            //cin>>arrows[j].len>>arrows[j].num;
            Arrow arr;
            cin>>arr.len>>arr.num;
            vectorArrow.push_back(arr);
        }
        //compare
        sort(vectorArrow.begin(),vectorArrow.end(),Comp);
        drawArrows(N);
        //cout<<endl;
    }
    return 0;
}
