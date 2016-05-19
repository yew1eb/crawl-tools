/*This Code is Submitted by billforum for Problem 2434 at 2012-01-30 17:11:48*/
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

struct point
{
        int length;//朋友的个数
        int step;
        bool visit;
        int f[1001];//存放朋友的号码
        int num;
};

point data[1001];
bool know[1001][1001];//标识两人认识不
int main(int args,char **argv)
{
        int g,n,gn,ntmp,ans=-1;
        int atmp[1001];
        
        while(cin>>g>>n)
        {
                if(g==0&&n==0) break;
//初始化
 for(int i=0;i<n;i++)
                {
                        data[i].length=0;
                        data[i].step=0;
                        data[i].visit=0;
                        data[i].num=i;
                        for(int j=0;j<1001;j++)
                                data[i].f[j]=-1;
                }
                ans=-1;
                for(int i=0;i<1001;i++)
                        for(int j=0;j<1001;j++)
                                know[i][j]=0;
//对输入数据进行处理，构造关系
 for(int i=0;i<g;i++)
                {
                        cin>>gn;
                        for(int j=0;j<gn;j++)
                                cin>>atmp[j];
                        for(int k=0;k<gn;k++)
                        {
                                int t=atmp[k];
                                for(int j=k+1;j<gn;j++)
                                {
                                        int s=atmp[j];
                                        if(!know[t][s])
                                        {
                                        data[t].length++;
                                        data[s].length++;
                                        data[t].f[data[t].length-1]=s;
                                        data[s].f[data[s].length-1]=t;
                                        know[t][s]=1;
                                        know[s][t]=1;
                                        }
                                }
                        }
                }
                queue<point> list;
                data[0].visit=1;
                list.push(data[0]);
                while(!list.empty())
                {
                        point tmp=list.front();
                        if(tmp.num==n-1)
                        {
                                ans=tmp.step;
                                break;
                        }
//广搜
 for(int k=0;k<tmp.length;k++)
                        {
                                int i=tmp.f[k];
                                if(data[i].visit) continue;
                                else
                                {
                                        data[i].visit=1;
                                        data[i].step=tmp.step+1;
                                        list.push(data[i]);
                                }
                        }
                        list.pop();
                }
                if(ans==-1) cout<<"I can never know wywcgs!"<<endl;
                else if(ans==1||ans==0) cout<<"I do know wywcgs!"<<endl;
                else
                {
                        cout<<"I can know wywcgs by at most "<<ans-1<<" person(s)!"<<endl;
                }
                
        }
        
        return 0;
}