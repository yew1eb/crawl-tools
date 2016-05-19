#include<stack>
#include<map>
#include<queue>
#include<stdio.h>
#include<string.h>

using namespace std;

typedef struct L
{
    int x;
    friend bool operator < (L a ,L b)
    {
        return a.x < b.x;
    }
}L;

typedef struct R
{
    int x;
    friend bool operator < (R a ,R b)
    {
        return a.x > b.x;
    }
}R;

R xinr ,tour;
L xinl ,toul;
priority_queue<L>lq;
priority_queue<R>rq;
queue<int>qq;
map<int ,int>mark;


int main ()
{
    int n ,cas = 1 ,i ,a;
    char str[10];
    while(~scanf("%d" ,&n))
    {
        while(!lq.empty())lq.pop();
        while(!rq.empty())rq.pop();
        while(!qq.empty())qq.pop();
        mark.clear();
        int ls = 0 ,rs = 0;
        printf("Case #%d:\n" ,cas ++);
        while(n--)
        {
            scanf("%s" ,str);
            if(str[0] == 'i')
            {
                scanf("%d" ,&a);
                mark[a] = 1;
                qq.push(a);
                if(ls == rs)//å¾å³æ¾
                {
                    rs ++;
                    if(ls == 0)
                    {
                       xinr.x = a;
                       rq.push(xinr);
                    }
                    else
                    {
                        toul = lq.top();
                        xinr.x = a;
                        if(toul.x < a) rq.push(xinr);
                        else
                        {

                            lq.pop();
                            tour.x=toul.x;
                            rq.push(tour);

                            xinl.x=xinr.x;
                            lq.push(xinl);
                        }
                    }
                }
                else //å¾å·¦æ¾
                {
                    ls ++;
                    tour = rq.top();
                    xinl.x = a;
                    if(tour.x > a) lq.push(xinl);
                    else
                    {
                        rq.pop();
                        toul.x=tour.x;
                        lq.push(toul);
                        xinr.x=xinl.x;
                        rq.push(xinr);
                    }
                }
            }
            if(str[0] == 'o')
            {

                int tou = qq.front();
                qq.pop();
                if(tou >= rq.top().x) rs --;
                else ls --;
                mark[tou] = 0;
                if(ls > rs) //->
                {
                    ls -- ,rs ++;
                    xinr.x = lq.top().x;
                    lq.pop();
                    rq.push(xinr);
                }
                if(rs - ls == 2)
                {
                    ls ++ ,rs --;
                    xinl.x = rq.top().x;
                    rq.pop();
                    lq.push(xinl);
                }
            }
            if(str[0] == 'q')
            {
                printf("%d\n" ,rq.top().x);
            }
            while(!lq.empty())
            {
                if(!mark[lq.top().x])
                lq.pop();
                else break;
            }
            while(!rq.empty())
            {
                if(!mark[rq.top().x])
                rq.pop();
                else break;
            }
        }


    }
}






