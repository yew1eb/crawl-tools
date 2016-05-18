#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int main()
{
    int a,b,c,ta[3],h,min,ti,diners,res;
    int  i;
    priority_queue<int,vector<int>,greater<int> > table[3];
    char s[7];
    while(scanf("%d%d%d",&a,&b,&c)==3&&a)
    {
        ta[0]=ta[1]=ta[2]=res=0;
        while(scanf("%s",s)==1&&s[0]!='#')
        {
            ti=0;
            scanf("%d",&diners);
            for(i=0;s[i]!=':';++i)
                ti=s[i]-'0'+ti*10;
            ti*=60;
            min=0;
            for(++i;s[i];++i)
                min=min*10+s[i]-'0';
            ti+=min;
            if(diners==1||diners==2)
            {
                while(!table[0].empty()&&table[0].top()<=ti)
                {
                    ta[0]--;
                    table[0].pop();
                }
                if(ta[0]<a)
                {
                    ++ta[0];
                    res+=diners;
                    table[0].push(ti+30);
                }
                else if(ti+30<=table[0].top())
                {
                    table[0].push(table[0].top()+30);
                    ++ta[0];
                    res+=diners;
                }
            }
            else if(diners==3||diners==4)
            {
                while(!table[1].empty()&&table[1].top()<=ti)
                {
                    ta[1]--;
                    table[1].pop();
                }
                if(ta[1]<b)
                {
                    ++ta[1];
                    res+=diners;
                    table[1].push(ti+30);
                }
                else if(ti+30<=table[1].top())
                {
                    table[1].push(table[1].top()+30);
                    ++ta[1];
                    res+=diners;
                }
            }
            else
            {
                while(!table[2].empty()&&table[2].top()<=ti)
                {
                    ta[2]--;
                    table[2].pop();
                }
                if(ta[2]<c)
                {
                    ++ta[2];
                    res+=diners;
                    table[2].push(ti+30);
                }
                else if(ti+30<=table[2].top())
                {
                    table[2].push(table[2].top()+30);
                    ++ta[2];
                    res+=diners;
                }
            }
        }
        printf("%d\n",res);
        for(i=0;i<3;++i)
            while(!table[i].empty())
                table[i].pop();
    }

    return 0;
}