#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const double pi= acos(-1.0);
const double esp=1e-6;
using namespace std;
struct node
{
    char name[110];
    int y;
}q[110];
int cmp(struct node a,struct node b)
{
    return a.y>b.y;
}
int main()
{
    int T,n,i;
    char str[110];
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        getchar();
        for(i=0;i<n;i++){
            cin.getline(str,110);
            int len=strlen(str);
            q[i].y=str[len-4]*1000+str[len-3]*100+str[len-2]*10+str[len-1];
            len=len-5;
            str[len]='\0';
            strcpy(q[i].name,str);
        }
        sort(q,q+n,cmp);
        for(i=0;i<n;i++)
            printf("%s\n",q[i].name);
    }
    return 0;
}