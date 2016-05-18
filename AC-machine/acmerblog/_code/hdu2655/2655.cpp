/*This Code is Submitted by billforum for Problem 2655 at 2012-01-30 12:27:42*/
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

struct point
{
        int wei[4];//保存每位的数字
        int num;//四位数的具体值
        int step；//记录改变的步数
        bool visit;//标记是否入队列
};

int pow(int x,int y)
{
        int ans=1;
        for(int i=1;i<=y;i++)
                ans=ans*x;
        return ans;
}
int main(int args,char **argv)
{
        int pr[10001],pn=0;
        bool flag[10001];
        int test,fp,lp,ans;
        point data[9000];
        bool f_ans=0;
        memset(flag,0,sizeof(flag));
        memset(pr,0,sizeof(pr));
        //筛素
        for(int i=2;i<10001;i++)
        {
                if(!flag[i]) pr[pn++]=i;
                for(int j=0;(j<pn)&&(i*pr[j]<10001);j++)
                {
                        flag[i*pr[j]]=1;
                        if(i%pr[j]==0) break;
                }
        }
        
        cin>>test;
        while(test--)
        {
                cin>>fp>>lp;
                ans=0;
                f_ans=0;  
            //初始化   
 for(int i=0;i<9000;i++)
        {
                int tmp;
                data[i].num=i+1000;
                tmp=data[i].num;
                data[i].step=0;
                data[i].visit=0;
                for(int j=3;j>=0;j--)
                {
                        data[i].wei[j]=tmp%10;
                        tmp=tmp/10;
                }
        }
                point f,l;
                int ntmp;
                f.num=fp;
                f.step=0;
                f.visit=1;
                ntmp=fp;
                for(int j=3;j>=0;j--)
                {
                        f.wei[j]=ntmp%10;
                        ntmp=ntmp/10;
                }
                l.num=lp;
                ntmp=lp;
                l.step=0;
                l.visit=0;
                for(int j=3;j>=0;j--)
                {
                        l.wei[j]=ntmp%10;
                        ntmp=ntmp/10;
                }
                queue<point> list;
                list.push(f);
                while(!list.empty())
                {
                        point tmp=list.front();
                        if(tmp.num==l.num)
                        {
                                ans=tmp.step;
                                f_ans=1;
                                break;
                        }
//广搜
 for(int i=0;i<4;i++)
                        {
                                if(i==0)
                                {
                                        for(int j=1;j<10;j++)
                                {
                                        if(j==tmp.wei[i]) continue;
                                        else{
                                                int mid;
                                                mid=tmp.num+(j-tmp.wei[i])*pow(10,3-i);
                                                if((!flag[mid])&&(data[mid-1000].visit==0)) 
                                                 {
                                                        data[mid-1000].visit=1;
                                                        data[mid-1000].step=tmp.step+1;
                                                        data[mid-1000].num=mid;
                                                        list.push(data[mid-1000]);
                                                 }
                                            }
                                }
                                }
                                else{
                                for(int j=0;j<10;j++)
                                {
                                        if(j==tmp.wei[i]) continue;
                                        else{
                                                int mid;
                                                mid=tmp.num+(j-tmp.wei[i])*pow(10,3-i);
                                                if((!flag[mid])&&(data[mid-1000].visit==0)) 
                                                 {
                                                        data[mid-1000].visit=1;
                                                        data[mid-1000].step=tmp.step+1;
                                                        data[mid-1000].num=mid;
                                                        list.push(data[mid-1000]);
                                                 }
                                            }
                                }
                                    }
                                }
                                list.pop();
                        }
                
                if(f_ans==1) cout<<ans<<endl;
                
        }
        return 0;
}