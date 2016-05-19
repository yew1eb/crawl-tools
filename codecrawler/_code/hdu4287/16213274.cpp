#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
char ch[30]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'};
string numx[5005];
map<string,int> mat;
int main()
{
    int cas,n,m;
    char sx[10];
    scanf("%d",&cas);
    for(;cas--;)
    {
        mat.clear();
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)
        {
            scanf("%s",sx);
            numx[i]=string(sx);
            mat.insert(make_pair(numx[i],0));
        }
        for(int i=0;i<m;++i)
        {
            scanf("%s",sx);
            for(int j=0;j<strlen(sx);++j)
                sx[j]=ch[sx[j]-'a'];
            if(mat.count(string(sx))!=0)
                (mat.find(string(sx))->second)++;
        }
        for(int i=0;i<n;++i)
            printf("%d\n",mat.find(numx[i])->second);
    }
    return 0;
}
