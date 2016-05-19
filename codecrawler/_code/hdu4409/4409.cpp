#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
using namespace std;
#define M 30005
map<int,string> hasht;
map<string,int> hashx;
struct cmp//排序
{
    bool operator()(const int &a, const int &b)
    {
        return hasht.find(a)->second<hasht.find(b)->second;
    }
};
struct point
{
    int pre;//父结点的位置
    set<int,cmp> son;//子结点的位置
    string name;//当前结点的名字
}node[M];
struct px
{
    int idx,len;//结点的位置，结点的辈分
} temp;
int cnt;
stack<struct px> father;
void dfs(int idx,int len)//递归输出族谱
{
    for(int i=0; i<len; ++i) printf(".");
    printf("%s\n",node[idx].name.c_str());
    for(set<int,cmp>::iterator it=node[idx].son.begin(); it!=node[idx].son.end(); ++it)
        dfs(*it,len+1);
}
void out_all()//Print the family list
{
    dfs(0,0);
}
void out_child()//Print out how many brothers does "name" have, including "name" himself.
{
    char s[70];
    scanf("%s",s);
    if(hashx.count(string(s))==0)
    {
        printf("0\n");
        return;
    }
    if(string(s)==node[0].name)
    {
        printf("1\n");
        return;
    }
    int idx=hashx.find(string(s))->second;
    printf("%d\n",node[node[idx].pre].son.size());
}
void out_pre()//Print out the closest common ancestor of "name1" and "name2".
{
    char a[70],b[70];
    scanf("%s%s",a,b);
    set<int> ax;
    int ida=hashx.find(string(a))->second;
    int idb=hashx.find(string(b))->second;
    for(; ida!=-1;)
    {
        ida=node[ida].pre;
        ax.insert(ida);
    }
    for(; idb!=-1;)
    {
        idb=node[idb].pre;
        if(ax.count(idb)!=0) break;
    }
    printf("%s\n",node[idb].name.c_str());
}
int main()
{
    int n,m,pre;
    char s[70],c,ord[10];
    string sx;
    for(; scanf("%d",&n),n;)
    {
        for(int i=0; i<=n; ++i)
        {
            node[i].pre=-1;
            node[i].son.clear();
        }
        hashx.clear();
        hasht.clear();
        for(; !father.empty(); father.pop());
        cnt=0;
        temp.idx=0;
        temp.len=0;
        scanf("%s",s);
        sx=string(s);
        node[cnt++].name=sx;
        hashx.insert(make_pair(sx,0));
        hasht.insert(make_pair(0,sx));
        father.push(temp);
        for(int i=1; i<n; ++i)
        {
            for(; getchar()!='.';);
            int ll=1;
            for(; (c=getchar())=='.'; ++ll);
            s[0]=c;
			int llt;
            for(llt=1;(s[llt]=getchar())!='\n';++llt);
			s[llt]='\0';
            temp.len=ll;
            temp.idx=cnt;
            for(;;)
            {
                struct px tx=father.top();
                if(tx.len>=temp.len)
                    father.pop();
                else
                    break;
            }
            sx=string(s);
            int tx=father.top().idx;
            node[cnt].pre=tx;
            node[cnt].name=sx;
            hasht.insert(make_pair(cnt,sx));
            hashx.insert(make_pair(sx,cnt));
            node[tx].son.insert(cnt);
            cnt++;
            father.push(temp);
        }
        scanf("%d",&m);
        for(; m--;)//处理查询
        {
            scanf("%s",ord);
            if(ord[0]=='L')
                out_all();
            else if(ord[0]=='b')
                out_child();
            else if(ord[0]=='c')
                out_pre();
        }
    }
    return 0;
}
