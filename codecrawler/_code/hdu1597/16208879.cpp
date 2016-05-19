#include <cstdlib>
#include <iostream>

using namespace std;

long long nct[70000];

long long n;
long long w;
void my_search(int l, int r)
{
     int m;
     m = (l + r) / 2;
     if (nct[m] < n && nct[m + 1] >= n)
     {
       w = m;
       return ;
     }
     if (nct[m] >= n) my_search(l, m - 1);
     if (nct[m + 1] < n) my_search(m + 1, r);     
}

int main(int argc, char *argv[])
{
    
    int i, j;
    int T;
    int t;
    for (i = 1; i <= 65540; i++)
      nct[i] = nct[i - 1] + i;
    //cout << nct[65536] << endl;
    cin >> T;
    while (T--)
    {
      cin >> n;
      w = -1;
      my_search(1, 65536);
      t = n - nct[w];
      t = t % 9;
      if (t == 0) t = 9;
      cout << t << endl;
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
