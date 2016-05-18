#include<iostream>  
    #include<cstdio>  
    #include<cstring>  
    #include<cmath>  
    #include<algorithm>  
    #include<queue>  
    #include<vector>  
    #include<stack>  
    #include<map>  
    #define MAX 20500  // 点的最大数量  
    #define MAXE 50500// 边的最大数量  
    using namespace std;  
    // 假设对边u-->v  
    struct EDGE  
    {  
        int v; // 从u点出发能到达的点v  
        int next; // 从u点出发能到达的下一条边的编号  
    }edge[MAXE];  
    int first[MAX];   // first[u] = e：从点u出发的最后一条边的编号是e(“最后”是指最后输入)  
    int dfn[MAX];  // dfn[u]：节点u搜索的次序编号(时间戳)  
    int low[MAX];// low[u]：是u或u的子树能够追溯到的最早的栈中节点的次序号  
    int ins[MAX];// 是否在栈中  
    //int scc[MAX]; // scc[i] = j：第i个点所在的强连通分量的编号  (此题可有可无)
    int out[MAX];  
    int in[MAX];// 强连通分量的出度  
    int fa[MAX];//fa[i] 表示 i的前驱 （父亲节点）
    int n,m;  
    int num; // 强连通分量的数目  
    int index; // 次序编号  
    stack<int> s;  
    bool ok;//判断是否满足条件
    void sign(int v,int x)
    {
        while(fa[x]!=v)
        {
            out[x]++;//out[x] 表示被标记了几次
        //    cout<<x<<endl;
            if(out[x]>1)//超过2次 必定有边 同属于两个环
            {
                ok=false;
                return ;
            }
            x=fa[x];
        }
    }
    int DFS(int x)  
    {  
        if(!ok)return 0;
        low[x]=dfn[x]=index++;  
        s.push(x);  
        ins[x]=1;  
        // 枚举每一条边：u-->v  
        for(int k=first[x];k!=-1;k=edge[k].next)  
        {  
            int v=edge[k].v;  
            if(dfn[v]==0)  
            {  
                fa[v]=x;
                DFS(v);  
                low[x]=min(low[x],low[v]); 
            }  
            else if(ins[v])  
            {  
                low[x]=min(dfn[v],low[x]); 
                sign(v,x);	//由x沿路径返回并标记一直找到v
                if(ok==false)
                return 0;
            }  
        }  
         // 如果节点u是强连通分量的根  
        if(low[x]==dfn[x])  
        {  
            int v;  
            num++;  
        if(num>1){ok=false;return 0;}//出现两个强联通分量
            do{  
            v=s.top();  
            s.pop();  
            ins[v]=0;  
      //      scc[v]=num;  
            }while(v!=x);  
        }  
        return 1;
    }  
    
    void init()  
    {  
        memset(dfn,0,sizeof(dfn));  
        memset(low,0,sizeof(low));  
        memset(first,-1,sizeof(first));  
        memset(ins,0,sizeof(ins));  
        memset(out,0,sizeof(out));  
        memset(in,0,sizeof(in));  
     //   memset(scc,0,sizeof(scc));  
        index=1;  
        num=0;  
        ok=true;
        int a,b,e=0;  
        scanf("%d",&n);
        for(;;)  
        {  
            scanf("%d%d",&a,&b);
            if(a+b==0)break;    
            edge[e].v=b;  
            edge[e].next=first[a];  
            first[a]=e;  
            e++;  
        }  
      
    }  
    
    void solve()  
    {  
          // 求强连通分量  
        for(int i=0;i<n;i++)  
        {  
            if(dfn[i]==0)  
            {  
               DFS(i);
                if(ok==false)
                break;
            }  
        }  
        if(ok)
        printf("YES\n");
        else 
        printf("NO\n");
    }  
    int main()  
    {  
        int Case;
        scanf("%d",&Case);
        while(Case--)  
        {  
            init();  
            solve();  
        }  
    return 0;  
    }      