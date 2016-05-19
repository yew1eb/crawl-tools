#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 10000;
int n;
int temp[MAX_N];

int main()
{
    while(cin >> n)
    {
        int k = 0;
        bool flag = false;
        int height;
        cin >>height;
        temp[0] = height;
        k++;
        for(int i = 1;i < n;i++)
        {
            flag = false;
            cin >> height;
            //sort(temp,temp + k);
            for(int j = 0;j < k;j++)
            {
                if(temp[j] > height)
                {
                    temp[j] = height;
                    flag = true;
                    break;
                }
            }
            if(!flag)
                temp[k++] = height;
        }
        cout << k << endl;
    }
    return 0;
}
