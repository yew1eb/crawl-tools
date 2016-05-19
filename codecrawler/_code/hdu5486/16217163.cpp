#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;


struct EDGE
{
    int to,next;
    EDGE(int a,int b)
    {
        to=a;
        next=b;
    }
};

vector<EDGE> edge;
pair<int,int> node[1000010];
int du[2000010];
int n,ne=0;
int num[1000010],num2[1000010];
int head[2000010];


void addedge(int u,int v)
{
    //cout<<u<<" "<<v<<endl;
    edge.push_back(EDGE(v,head[u]));
  //  edge[ne].to=v;
//    edge[ne].next=head[u];
    head[u]=ne++;
}

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}

int uni()
{
    int len=0;
    sort(node,node+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(i==n-1||node[i].first!=node[i+1].first||node[i].second!=node[i+1].second)
            node[len++]=node[i];
    }
    return len;
}


int main()
{
  //  freopen("D:\\in.txt","r",stdin);
    int T,i,j,cnt=1;
    cin>>T;
    while(T--)
    {
        memset(du,0,sizeof(du));
        ne=0;
        edge.clear();
        memset(head,-1,sizeof(head));
        cin>>n;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&node[i].first,&node[i].second);
            num[i]=node[i].first;
            num2[i]=node[i].second;
        }
        sort(num,num+n);
        sort(num2,num2+n);
        int len=unique(num,num+n)-num;
        int len2=unique(num2,num2+n)-num2;
        map<int,int> lst,lst2;
        for(i=1;i<=len;i++) lst[num[i-1]]=i;
        for(i=1;i<=len2;i++) lst2[num2[i-1]]=i+len;
        int len3=uni();
        for(i=0;i<len3;i++)
        {
            int x=lst[node[i].first],y=lst2[node[i].second];
       //     cout<<x<<" "<<y<<endl;
            du[x]++,du[y]++;
            addedge(x,y);
            addedge(y,x);
        }
        //cout<<"ok\n";
        int ans1=0,ans2=0,ans3=0;
        for(i=1;i<=len;i++)
        {
            if(du[i]==1)
            {
                int to=edge[head[i]].to;
        //        cout<<to<<endl;
                if(du[to]==1) ans3++;
            }
            else if(du[i]>1)
            {
                int flag=1;
                for(int t=head[i];t!=-1;t=edge[t].next)
                {
                    if(du[edge[t].to]>1)
                    {
                        flag=0;
                        break;
                    }
                }
         //       cout<<flag<<" "<<i<<endl;
                if(flag) ans1++;
            }
        }
        for(i=len+1;i<=len+len2;i++)
        {
            if(du[i]>1)
            {
                int flag=1;
                for(int t=head[i];t!=-1;t=edge[t].next)
                {
                    if(du[edge[t].to]>1)
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag) ans2++;
            }
        }
        printf("Case #%d: %d %d %d\n",cnt++,ans1,ans2,ans3);
    }
}