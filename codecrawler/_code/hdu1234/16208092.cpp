#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string id, start, end;
        cin >> id >> start >> end;
        string idstart, idend, startmin, endmax;
        idstart = id;
        idend = id;
        startmin = start;
        endmax = end;

        for(int i = 1; i < n; i++)
        {
            cin >> id >> start >> end;
            if(start < startmin)
            {
                startmin = start;
                idstart = id;
            }
            if(end > endmax)
            {
                endmax = end;
                idend = id;
            }
        }
        cout << idstart << " " << idend << endl;
    }
    return 0;
}