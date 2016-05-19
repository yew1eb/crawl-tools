#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int get_sum(int n, int p){
  // æ¢æpè¿å¶çå
  int x = n;
  int sum = 0;
  while(x){
    sum += x%p;
    x = x/p;
  }
  return sum;
}

int main()
{
  int n;
  while(scanf("%d", &n) != EOF){
    if(n == 0) break;
    int x1 = get_sum(n, 10);
    int x2 = get_sum(n, 12);
    int x3 = get_sum(n, 16);
    //cout << x1 << x2 << x3 << endl;
    if(x1 == x2 && x2 == x3) printf("%d is a Sky Number.\n", n);
    else printf("%d is not a Sky Number.\n", n);
  }
  return 0;
}
