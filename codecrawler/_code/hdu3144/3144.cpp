#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;
char ans[10][10];
char mat[10][10];
char input[10][10];
bool vis[10][10];
int tR, tC,N;
bool isin(int r,int c){
    return r>=0&&r<=N&&c>=0&&c<=N;
}
bool dfs(int r, int c) {
  if (vis[r][c]) return false;  
  if (r==tR && c==tC) return true;
  vis[r][c]=true;
  if (isin(r+1,c+1)&& ans[r][c]=='\\') if (dfs(r+1,c+1)) return true;
  if (isin(r-1,c-1)&& ans[r-1][c-1]=='\\') if (dfs(r-1,c-1)) return true;
  if (