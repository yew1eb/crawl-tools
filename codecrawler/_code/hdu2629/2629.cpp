#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char a[18];
    memset(a,0,sizeof(a));
    while(n--)
    {
        cin>>a;
        if(a[0]=='3' && a[1]=='3')
            cout<<"He/She is from Zhejiang,and his/her birthday is on "
            <<a[10]<<a[11]<<","<<a[12]<<a[13]<<","<<a[6]<<a[7]<<a[8]<<
            a[9]<<" "<<"based on the table.";
        if(a[0]=='1' && a[1]=='1')
            cout<<"He/She is from Beijing,and his/her birthday is on "
            <<a[10]<<a[11]<<","<<a[12]<<a[13]<<","<<a[6]<<a[7]<<a[8]<<
            a[9]<<" "<<"based on the table.";
        if(a[0]=='7' && a[1]=='1')
            cout<<"He/She is from Taiwan,and his/her birthday is on "
            <<a[10]<<a[11]<<","<<a[12]<<a[13]<<","<<a[6]<<a[7]<<a[8]<<
            a[9]<<" "<<"based on the table.";
        if(a[0]=='8' && a[1]=='1')
            cout<<"He/She is from Hong Kong,and his/her birthday is on "
            <<a[10]<<a[11]<<","<<a[12]<<a[13]<<","<<a[6]<<a[7]<<a[8]<<
            a[9]<<" "<<"based on the table.";
        if(a[0]=='8' && a[1]=='2')
            cout<<"He/She is from Macao,and his/her birthday is on "
            <<a[10]<<a[11]<<","<<a[12]<<a[13]<<","<<a[6]<<a[7]<<a[8]<<
            a[9]<<" "<<"based on the table.";
        if(a[0]=='5' && a[1]=='4')
            cout<<"He/She is from Tibet,and his/her birthday is on "
            <<a[10]<<a[11]<<","<<a[12]<<a[13]<<","<<a[6]<<a[7]<<a[8]<<
            a[9]<<" "<<"based on the table.";
        if(a[0]=='2' && a[1]=='1')
            cout<<"He/She is from Liaoning,and his/her birthday is on "
            <<a[10]<<a[11]<<","<<a[12]<<a[13]<<","<<a[6]<<a[7]<<a[8]<<
            a[9]<<" "<<"based on the table.";
        if(a[0]=='3' && a[1]=='1')
            cout<<"He/She is from Shanghai,and his/her birthday is on "
            <<a[10]<<a[11]<<","<<a[12]<<a[13]<<","<<a[6]<<a[7]<<a[8]<<
            a[9]<<" "<<"based on the table.";
        cout<<endl;
    }
    return 0;
}