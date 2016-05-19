#include <iostream>
using namespace std;

const int SIZE=300;//µ±ÊäÈë´ïµ½ÉÏÏÞ5.20Ê±£¬SIZE×î´óÎª276 
double length[SIZE]={0.0};
int main()
{
    double len;
    int i;
    while(cin>>len,len){
        for(i=1; ;i++)
        {
            if(! length[i])
                length[i] = length[i-1] +1.0/(i+1.0);
            if(length[i]>=len) break;
        }
        cout<<i<<" card(s)"<<endl; 
    }
    double s;
    
}