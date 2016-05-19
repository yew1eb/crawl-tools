#include <iostream>
#include <cstdio>
#include <memory.h>
#include <string.h>
#include <algorithm>
#define MAX(a , b) ((a) > (b) ? (a) : (b))
using namespace std;
const int maxn = 22;
const int maxm = 8;
struct node
{
    char name[maxn];
    int price;
}th[maxn],consume[maxn];
struct thing
{
    char name[maxn];
    int need,cnt;
    char dic[maxm][maxn];
    int num[maxm];
}com[maxn];
struct SS
{
    char name[maxn];
    int num,price;
    bool valid;
    bool operator < (const SS &other) const
    {
        return strcmp(name , other.name) <= 0;
    }
}bag[maxm];
char str[1000];
int m,n1,n2,n3,top,cas = 0;

int change(char *s)
{
    int res = 0;
    for(int i=0;s[i] != '\0';i++)
    {
        res *= 10;
        res += s[i] - '0';
    }
    return res;
}

void read()
{
    printf("Case %d:\n",++cas);
    for(int i=0;i<n1;i++)
    {
        getchar();
        scanf("%s %d",th[i].name,&th[i].price);
    }
    scanf("%d",&n2);
    getchar();
    for(int i=0;i<n2;i++)
    {
        gets(str);
        char *g = NULL;
        g = strtok(str , ",: \t");
        strcpy(com[i].name , g);
        g = strtok(NULL , ",: \t");
        com[i].need = change(g);
        com[i].cnt = 0;
        g = strtok(NULL , ",: \t");
        while(g != NULL)
        {
            strcpy(com[i].dic[com[i].cnt] , g);
            g = strtok(NULL , ",: \t");
            com[i].num[com[i].cnt++] = change(g);
            g = strtok(NULL , ",: \t");
        }
    }
    scanf("%d",&n3);
    for(int i=0;i<n3;i++)
    {
        getchar();
        scanf("%s %d",consume[i].name,&consume[i].price);
    }
    return;
}

void update()
{
    int j = 0;
    for(int i=0;i<6;i++)
    {
        while(j < 6 && bag[j].valid)
        {
            j++;
        }
        if(bag[i].valid == false) continue;
        if(i > j)
        {
            bag[j] = bag[i];
            bag[i].valid = false;
            bag[j++].valid = true;
        }
    }
    top = j;
    return;
}

void solve()
{
    scanf("%d",&m);
    getchar();
    int money = 0;
    top = 0;
    for(int i=0;i<6;i++)
    {
        bag[i].valid = bag[i].num = 0;
    }
    while(m--)
    {
        char c = getchar();
        gets(str);
        if(str[0] >= '0' && str[0] <= '9')
        {
            money += change(str);
        }
        else
        {
            if(c == '+')
            {
                bool flag = false;
                for(int i=0;i<n1;i++)
                {
                    if(strcmp(th[i].name , str) == 0)
                    {
                        flag = true;
                        if(money >= th[i].price)
                        {
                            if(top == 6) break;
                            strcpy(bag[top].name , str);
                            bag[top].num = 1;
                            bag[top].price = th[i].price;
                            bag[top].valid = true;
                            top++;
                            money -= th[i].price;
                        }
                        break;
                    }
                }
                if(flag) continue;
                for(int i=0;i<n2;i++)
                {
                    if(strcmp(com[i].name , str) == 0)
                    {
                        flag = true;
                        if(com[i].need > money) break;
                        bool have = true;
                        int c = 0;
                        for(int j=0;j<com[i].cnt;j++)
                        {
                            c += com[i].num[j];
                            int t = 0;
                            for(int k=0;k<top;k++)
                            {
                                if(strcmp(bag[k].name , com[i].dic[j]) == 0)
                                {
                                    t++;
                                }
                            }
                            if(t < com[i].num[j])
                            {
                                have = false;
                                break;
                            }
                        }
                        if(have && (top < 6 || c > 0))
                        {
                            money -= com[i].need;
                            int tot = com[i].need;
                            for(int j=0;j<com[i].cnt;j++)
                            {
                                int t = 0;
                                for(int k=0;k<top;k++)
                                {
                                    if(strcmp(bag[k].name , com[i].dic[j]) == 0 && bag[k].valid)
                                    {
                                        bag[k].valid = false;
                                        tot += bag[k].price;
                                        if(++t == com[i].num[j])
                                        {
                                            break;
                                        }
                                    }
                                }
                            }
                            for(int j=0;j<=top;j++)
                            {
                                if(bag[j].valid == false)
                                {
                                    bag[j].valid = true;
                                    bag[j].num = 1;
                                    strcpy(bag[j].name , com[i].name);
                                    bag[j].price = tot;
                                    if(j == top) top++;
                                    break;
                                }
                            }
                            update();
                        }
                        break;
                    }
                }
                if(flag) continue;
                for(int i=0;i<n3;i++)
                {
                    if(strcmp(consume[i].name , str) == 0)
                    {
                        flag = true;
                        if(money >= consume[i].price)
                        {
                            if(top == 6) break;
                            money -= consume[i].price;
                            bool have = false;
                            for(int j=0;j<top;j++)
                            {
                                if(strcmp(bag[j].name , str) == 0)
                                {
                                    have = true;
                                    bag[j].num++;
                                    bag[j].price += consume[i].price;
                                    break;
                                }
                            }
                            if(have == false)
                            {
                                strcpy(bag[top].name , str);
                                bag[top].num = 1;
                                bag[top].price = consume[i].price;
                                bag[top++].valid = true;
                            }
                        }
                        break;
                    }
                }
            }
            else
            {
                for(int i=0;i<top;i++)
                {
                    if(strcmp(bag[i].name , str) == 0)
                    {
                        bag[i].valid = false;
                        money += bag[i].price;
                        update();
                        break;
                    }
                }
            }
        }
    }
    sort(bag , bag + top);
    printf("%d\n%d\n",money,top);
    for(int i=0;i<top;i++)
    {
        printf("%s: %d\n",bag[i].name,bag[i].num);
    }
    puts("");
    return;
}

int main()
{
    while(~scanf("%d",&n1))
    {
        read();
        solve();
    }
    return 0;
}
