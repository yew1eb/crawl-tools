/**
 * ID: ping128
 * LANG: C++
 */

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <math.h>
#include <algorithm>
#include <map>
#include <string.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;
typedef pair<PII, int>PII2;

string name[30];
int n, m;
set<string>S;
class Solve
{
 public:
 void main2()
 {
 cin >> n;
 for(int i = 0; i < n; i++ ) cin >> name[i];
 cin >> m;
 string s;
 S.clear();
 getline(cin, s);
 for(int i = 0; i < m; i++ ) 
 {
 getline(cin, s);
 istringstream iss(s);
 while(iss >> s)
 {
 S.insert(s);
 }
 }
 
 for(int i = 0; i < n; i++ )
 {
 cout << name[i] << " is "; 
 if(S.find(name[i]) != S.end()) 
 {
 cout << "present" << endl;
 }
 else
 {
 cout << "absent" << endl;
 }
 }
 
 }
};

int main()
{
 // freopen("b.in", "r", stdin);
 // freopen(".out", "w", stdout);

 int Test;
 scanf("%d", &Test);
 for(int t = 1; t <= Test; t++ )
 {
 Solve ___test;
 printf("Test set %d:\n", t);
 ___test.main2();
 
 printf("\n");
 
 }
//while(1);
return 0;
}