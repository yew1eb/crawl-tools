#include <iostream>
using namespace std;
int main()
{
    int m,n,val;
    int a[100][100];
    while(cin>>m>>n){
        for(int x=1;x<=m;x++)
            for(int y=1;y<=n;y++){
                cin>>val;
                a[x][y]=val;    
            }
        int    maxx=1;
        int maxy=1;
        int max=0;
        for(int x=1;x<=m;x++)
            for(int y=1;y<=n;y++){
                if(abs(a[x][y])>abs(max)){
                    max=a[x][y];
                    maxx=x;
                    maxy=y;
                }
            }
        cout<<maxx<<" "<<maxy<<" "<<max<<endl;
    }
    return 0;
}