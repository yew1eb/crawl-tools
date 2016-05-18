#include <iostream>
#include <map>
#include <memory.h>
using namespace std;

const int maxn = 10000;
map<string,int> name;
string Erdos = "Erdos, P.";
int relation[maxn][maxn];
int mark[maxn];
int pr=0;
int people=0;

void build(string paper)
{
    string tmp;
    int org=0;
    int rec[maxn]={0};
    int prec=0;
    for(int i=0;i<paper.size();i++)
    {
        if(paper[i]==':')break;
        if(paper[i]=='.'&&paper[i+1]==',' || paper[i]=='.'&&paper[i+1]==':')
        {
            tmp = paper.substr(org,i-org+1);
            org = i+3;
            if(name.find(tmp)==name.end())
            {
                name.insert(make_pair(tmp,pr++));
                rec[prec++]=pr-1;
                people++;
            }
            else
            {
                int num = name.find(tmp)->second;
                rec[prec++]=num;
            }
        }
    }
    for(int i=0;i<prec;i++)
    {
        for(int j=0;j<prec;j++)
        {
            if(rec[i]==rec[j])continue;
            else
                relation[rec[i]][rec[j]]=relation[rec[j]][rec[i]]=1;
        }
    }

    return ;
}

void bfs()
{
    int quee[maxn]={0};
    int fr=0,ed=1;
    quee[fr] = name.find(Erdos)->second;
    mark[quee[fr]]=0;
    int vis[maxn]={0};
    while(fr<ed)
    {
        for(int i=0;i<people;i++)
        {
            if(quee[fr]==i)continue;
            if(relation[quee[fr]][i]==1&&vis[i]==0)
            {
                mark[i]=mark[quee[fr]]+1;
                quee[ed++] = i;
                vis[i]=1;
            }
        }
        fr++;
    }
}
int main()
{
    int tst,book,query;
    cin>>tst;
    int test=1;
    while(tst--)
    {
        cout<<"Scenario "<<test++<<endl;
        cin>>book>>query;
        cin.ignore();
        for(int i=0;i<book;i++)
        {
            string paper;
            getline(cin,paper);
            build(paper);
        }
        bfs();
        for(int i=0;i<query;i++)
        {
            string que;
            getline(cin,que);
            if(name.find(que)==name.end())
            {
                cout<<que<<" infinity"<<endl;
                continue;
            }
            int qq = name.find(que)->second;
            if(mark[qq]==0)
                cout<<que<<" infinity"<<endl;
            else
                cout<<que<<" "<<mark[qq]<<endl;
        }
        name.clear();
        for(int i=0;i<people;i++)
        {
            for(int j=0;j<people;j++)
            {
                relation[i][j]=0;
            }
            mark[i]=0;
        }
        pr=0;
        people=0;
    }
}