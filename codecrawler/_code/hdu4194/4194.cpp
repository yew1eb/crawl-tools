#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
#define MAXN 1010
#define INF 0x7fffffff
#define eps 1e-10
#define MAX(x,y) ((x)>(y)? (x):(y))
#define MIN(x,y) ((x)<(y)? (x):(y))
#define MEM(a) (memset((a),0,sizeof(a)))
#define FRE freopen("input.txt","r",stdin)
using namespace std;


string name[MAXN];
int num[MAXN],k,n;
vector <int> review[MAXN];
bool ok[MAXN];

int main()
{
    while(scanf("%d%d",&k,&n) && n)
    {
        memset(ok,0,sizeof(ok));
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++)
            review[i].clear();
        for(int i=1;i<=n;i++)
        {
            char temp[20];
            scanf("%s",temp);
            name[i]=temp;
            for(int j=0;j<k;j++)
            {
                int tmp;
                scanf("%d",&tmp);
                review[i].push_back(tmp);
            }
        }
        for(int i=1;i<=n;i++)
            sort(review[i].begin(),review[i].end());
        for(int i=1;i<=n;i++)
            for(int j=0;j<k;j++)
            {
                if(j!=0 && (review[i][j]==review[i][j-1])) //重复票判problem
                {
                    ok[review[i][j]]=1;
                    continue;
                }
                if(name[i]==name[review[i][j]]) //同组织判problem
                    ok[review[i][j]]=1;
                else
                    num[review[i][j]]+=1; 
            }
        int ans=0;
        for(int i=1;i<=n;i++)
            if(ok[i]) ans++;
            else
            {
                if(num[i]!=k) ans++; 
            }
        if(ans==0)
            printf("NO PROBLEMS FOUND\n");
        else
            printf("%d PROBLEMS FOUND\n",ans);
    }
    return 0;
}
