#include <iostream>
    #include <cstdio>
    #include <cstring>
    #include <algorithm>
    #include <queue>

    #define PRIME 455809
    using namespace std;

    struct node
    {
        node(unsigned int t)
        {
            s=t;
            next=NULL;
        }
        unsigned int s;
        int step;
        node *next;
    };
    node *hashtable[460000][2];
    struct State
    {
        int map[10];
        int pos;
        int step;
    } states,statee;

    void hinsert(State s,bool ty)
    {
        unsigned int i,st=0;
        for(i=1; i<=9; i++)
            st=st*10+s.map[i];
        node *f=new node(st);
        f->step=s.step;
        f->next=hashtable[st%PRIME][ty];
        hashtable[st%PRIME][ty]=f;
    }
    bool exist(State s,bool ty,int &res)
    {
        unsigned int i,st=0;
        for(i=1; i<=9; i++)
            st=st*10+s.map[i];
        node *f=hashtable[st%PRIME][ty];
        while(f)
        {
            if(f->s==st)
            {
                res=f->step;
                return true;
            }
            f=f->next;
        }
        return false;
    }
    int transfer(State t,queue <State>&Q,bool ty)
    {
        State s;
        int res;
        s=t;
        if((s.pos-3)>0)
        {
            swap(s.map[s.pos],s.map[s.pos-3]);
            s.step++;
            s.pos-=3;
            if(exist(s,!ty,res))
            {
                return (s.step+res);
            }
            if(!exist(s,ty,res))
            {
                Q.push(s);
                hinsert(s,ty);
            }
        }
        s=t;
        if(s.pos+3<10)
        {
            swap(s.map[s.pos],s.map[s.pos+3]);
            s.step++;
            s.pos+=3;
            if(exist(s,!ty,res))
            {
                return (s.step+res);
            }
            if(!exist(s,ty,res))
            {
                Q.push(s);
                hinsert(s,ty);
            }
        }
        s=t;
        if((s.pos+1)%3!=1)
        {
            swap(s.map[s.pos],s.map[s.pos+1]);
            s.step++;
            s.pos+=1;
            if(exist(s,!ty,res))
            {
                return (s.step+res);
            }
            if(!exist(s,ty,res))
            {
                Q.push(s);
                hinsert(s,ty);
            }
        }
        s=t;
        if((s.pos-1)%3!=0)
        {
            swap(s.map[s.pos],s.map[s.pos-1]);
            s.step++;
            s.pos-=1;
            if(exist(s,!ty,res))
            {
                return (s.step+res);
            }
            if(!exist(s,ty,res))
            {
                Q.push(s);
                hinsert(s,ty);
            }
        }
        return 0;
    }

    queue<State>Qs;
    queue<State>Qe;
    int reversenum(State a)
    {
        int res=0;
        for(int i=1; i<=9; i++)
        {
            if(a.map[i]==0)continue;
            for(int j=i-1; j>=1; j--)
            {
                if(a.map[j]>a.map[i])res++;
            }
        }
        return res;
    }
    bool prejudge(State a,State b)
    {
        int t1=reversenum(states);
        int t2=reversenum(statee);
        if((t1+t2)%2!=0)
        {
            printf("-1\n");
            return true;
        }
        bool tflag=0;
        for(int i=1; i<=9; i++)
        {
            if(a.map[i]!=b.map[i])
            {
                tflag=1;
                break;
            }
        }
        if(!tflag)
        {
            printf("0\n");
            return true;
        }
        else return false;
    }
    int main()
    {
        int tcases;
        scanf("%d",&tcases);
        while(tcases--)
        {
            memset(hashtable,0,sizeof(hashtable));
            for(int i=1; i<=9; i++)
            {
                scanf("%d",&states.map[i]);
                if(states.map[i]==0)states.pos=i;
            }
            statee.step=0;
            for(int i=1; i<=9; i++)
            {
                scanf("%d",&statee.map[i]);
                if(statee.map[i]==0)statee.pos=i;
            }
            states.step=0;

            hinsert(states,0);
            hinsert(statee,1);
            if(prejudge(states,statee))continue;

            bool endflag=0;
            while(!Qs.empty())Qs.pop();
            while(!Qe.empty())Qe.pop();
            Qs.push(states);
            Qe.push(statee);
            while(!Qs.empty()||!Qe.empty())
            {
                int ns=Qs.size(); //这个是处于同一层的状态的数量
                int ne=Qe.size();
                if(ns<ne||ne==0) //选择元素个数较少的队列进行扩展
                {
                    for(int i=0; i<ns; i++)//扩展s队列。一次扩展一层，这是双广正确性(得到最优解)的重要保证
                    {
                        State cur;
                        cur=Qs.front();
                        Qs.pop();
                        int res=transfer(cur,Qs,0);
                        if(res)
                        {
                            printf("%d\n",res);
                            endflag=1;
                            break;
                        }
                    }
                }
                else
                {
                    for(int i=0; i<ne; i++)
                    {
                        State cur;
                        cur=Qe.front();
                        Qe.pop();
                        int res=transfer(cur,Qe,1);
                        if(res)
                        {
                            printf("%d\n",res);
                            endflag=1;
                            break;
                        }
                    }
                }
                if(endflag)break;
            }
        }
        return 0;
    }