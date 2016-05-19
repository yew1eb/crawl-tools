#include<cstdio>
#include<cstring>
using namespace std;
struct node
{
    int value;
    int pre,next;
} num[1000005];
int l,ll,r,rr,cnt;
void MoveLefe()
{
    char ch[5];
    scanf("%s",ch);
    if(ch[0]=='L')
    {
        if(num[ll].pre==l)
        {
            l=ll;
            ll=num[ll].next;
        }
        else
        {
            l=ll;
            ll=num[ll].pre;
        }
    }
    else
    {
        if(num[r].pre==rr)
        {
            rr=r;
            r=num[r].next;
        }
        else
        {
            rr=r;
            r=num[r].pre;
        }
    }
}
void MoveRight()
{
    char ch[5];
    scanf("%s",ch);
    if(ch[0]=='L')
    {
        if(num[l].pre==ll)
        {
            ll=l;
            l=num[l].next;
        }
        else
        {
            ll=l;
            l=num[l].pre;
        }
    }
    else
    {
        if(num[rr].pre==r)
        {
            r=rr;
            rr=num[rr].next;
        }
        else
        {
            r=rr;
            rr=num[rr].pre;
        }
    }
}
void Insert()
{
    char ch[5];
    int value;
    scanf("%s%d",ch,&value);
    if(ch[0]=='L')
    {
        num[cnt].pre=ll;
        num[cnt].next=l;
        if(num[ll].pre==l) num[ll].pre=cnt;
        else               num[ll].next=cnt;
        if(num[l].pre==ll) num[l].pre=cnt;
        else               num[l].next=cnt;
        l=cnt++;
        num[l].value=value;
    }
    else
    {
        num[cnt].pre=rr;
        num[cnt].next=r;
        if(num[rr].pre==r) num[rr].pre=cnt;
        else               num[rr].next=cnt;
        if(num[r].pre==rr) num[r].pre=cnt;
        else               num[r].next=cnt;
        r=cnt++;
        num[r].value=value;
    }
}
void Delete()
{
    char ch[5];
    int next;
    scanf("%s",ch);
    if(ch[0]=='L')
    {
        if(num[l].pre==ll) next=num[l].next;
        else               next=num[l].pre;
        if(num[ll].pre==l)  num[ll].pre=next;
        else               num[ll].next=next;
        if(num[next].pre==l) num[next].pre=ll;
        else                 num[next].next=ll;
        l=next;
    }
    else
    {
        if(num[r].pre==rr) next=num[r].next;
        else               next=num[r].pre;
        if(num[rr].pre==r)  num[rr].pre=next;
        else               num[rr].next=next;
        if(num[next].pre==r) num[next].pre=rr;
        else                 num[next].next=rr;
        r=next;
    }
}
void Reverse()
{
    if(num[r].pre==rr) num[r].pre=ll;
    else               num[r].next=ll;
    if(num[l].pre==ll) num[l].pre=rr;
    else               num[l].next=rr;
    if(num[ll].pre==l) num[ll].pre=r;
    else               num[ll].next=r;
    if(num[rr].pre==r) num[rr].pre=l;
    else               num[rr].next=l;
    l=l^r;
    r=l^r;
    l=l^r;
}
void out(int n)
{
    bool first=true;
    int pre=0;
    for(int i=num[0].next;i!=n+1;)
    {
        if(first)
        {
            printf("%d",num[i].value);
            first=false;
        }
        else printf(" %d",num[i].value);
        if(num[i].next!=pre)
        {
            pre=i;
            i=num[i].next;
        }
        else
        {
            pre=i;
            i=num[i].pre;
        }
    }
    printf("\n");
}
int main()
{
    int cas,n,m;
    char s[20];
    scanf("%d",&cas);
    for(; cas--;)
    {
        scanf("%d",&n);
        cnt=n+2;
        for(int i=1; i<=n; ++i)
        {
            scanf("%d",&num[i].value);
            num[i].pre=i-1;
            num[i].next=i+1;
        }
        scanf("%d%d",&l,&r);
        num[0].pre=0;
        num[0].next=1;
        num[n+1].pre=n;
        ll=num[l].pre;
        rr=num[r].next;
        scanf("%d",&m);
        for(; m--;)
        {
            scanf("%s",s);
            if(strcmp(s,"MoveLeft")==0)
                MoveLefe();
            else if(strcmp(s,"MoveRight")==0)
                MoveRight();
            else if(strcmp(s,"Insert")==0)
                Insert();
            else if(strcmp(s,"Delete")==0)
                Delete();
            else if(strcmp(s,"Reverse")==0)
                Reverse();
        }
        out(n);
    }
    return 0;
}
