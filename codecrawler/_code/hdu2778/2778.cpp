//用STL里的priority_queue存储，剩下的就是模拟了。。
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <queue>
#define INF 0x7fffffff
using namespace std;

struct Process
{
    int id;
    int arr;    //到达时间
    int last;
    int prior;
};

struct cmp //按任务到达CPU的顺序进行存储
{
    bool operator()(const Process &t1,const Process &t2)
    {
        if(t1.arr!=t2.arr)return t1.arr>t2.arr; //arr小的放在上面。小顶堆
        return t1.prior<t2.prior;   //对于同时到达的，prior大的放在上面。大顶堆
    }
};
struct cmp2//按任务执行的顺序存储
{
    bool operator()(const Process &t1,const Process &t2)
    {
        if(t1.prior!=t2.prior)return t1.prior<t2.prior;
        return t1.arr>t2.arr; //prior相同时，arr小的放在上面。即遵循first arrive,first serve

    }
};
int main()
{
    int num;
    int cases=0;
    while(cin>>num)
    {
        Process temp;
        Process temp2;
        if(cases!=0)printf("\n");
        priority_queue<Process,vector<Process>,cmp> Q;   //所有待办任务的队列
        priority_queue<Process,vector<Process>,cmp2> ing; //所有等待中的任务的队列,prior大的放上面
        for(int i=0; i<num; i++)
        {
            cin>>temp.id>>temp.arr>>temp.last>>temp.prior;
            Q.push(temp);
        }
        printf("CASE #%d\n",++cases);
        int timer=0;
        temp=Q.top();
        Q.pop();

        ing.push(temp); //第一个任务进入ing队
        timer=temp.arr; //记录当前时间
        while(1) //注意结束条件不能是Q为空。Q空了之后，还要再运行一次。
        {
            //temp=ing.top();
            if(!Q.empty())
            {
                temp2=Q.top();
                Q.pop();
            }
            else
            {
                temp2.arr=INF; //永远不会到来
                temp2.last=0;
                temp2.prior=0;
                temp2.id=0;
            }
            bool flag=0;
            while(!ing.empty())
            {
                temp=ing.top();
                if(timer+temp.last<=temp2.arr)
                {
                    timer+=temp.last;
                    printf("%d %d\n",temp.id,timer);
                    ing.pop();
                }
                else
                {
                    flag=1;
                    break;
                }
            }
            if(temp2.arr==INF)      //Q空了后，再循环一次，在这儿终止。
            {
                break;
            }
            if(flag)   //如果被打断
            {
                //   temp.arr=timer;
                temp.last=temp.last-(temp2.arr-timer);//更新这个任务还需要的时间
                timer=temp2.arr;
                ing.pop();
                ing.push(temp); //更新ing最上面那个
                ing.push(temp2);
            }
            else if(!Q.empty())//没被打断，说明些时ing队列空了
            {
                timer=temp2.arr;
                ing.push(temp2);
            }
        }

    }
    return 0;
}