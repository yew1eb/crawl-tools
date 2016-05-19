#include <iostream>
#include <algorithm>
using namespace std;
#define N 105

struct elem 
{
    char name[25];
    int tnum,xnum;
    char tname[N][25];
    char xname[N][25];
}stu[N];

struct trie 
{
    int end;
    int count;
    trie *next[26];
};

trie *root;
char add_str[N][25];
char del_str[N][25];
int len_add,len_del;

int cmp(elem a,elem b)
{
    return strcmp(a.name,b.name)<0?1:0;
}

trie* newtrie()   
{   
    trie *t;   
    t=(trie*)malloc(sizeof(struct trie));   
    memset(t,0,sizeof(struct trie));   
    return t;   
}

void insert(char *ch)   
{   
    int i;   
    trie *t,*s;   
    s=root;   
    for(i=0;ch[i];i++)   
    {   
        if(s->next[ch[i]-'a'])   
        {   
            s=s->next[ch[i]-'a'];   
            s->count=s->count+1;   
        }   
        else  
        {   
            t=newtrie();   
            s->next[ch[i]-'a']=t;   
            s=t;   
            s->count=1;   
        }   
    }   
	s->end = 1;
} 

int search(char *ch)   
{   
    int i;   
    trie *s=root;   
    if(ch[0]==0) return 0;   
    for(i=0;ch[i];i++)   
    {   
        if(s->next[ch[i]-'a'])      
            s=s->next[ch[i]-'a'];      
        else  
            break;   
    }  
    if(ch[i]==0 && s->end == 1) return s->count;   
    else return 0;   
} 

void Delete(char *ch)   
{   
    int i;   
    trie *s;   
    s=root;   
    for(i=0;ch[i];i++)   
    {   
        s=s->next[ch[i]-'a'];
        s->count=s->count-1;
    }   
	s->end = 0;
} 

int main()
{
    int n,m,k,i,j,ttt;
    char ch[25];
    while (scanf("%d %d",&n,&m)!=EOF)
    {
        root = newtrie();
        getchar();
        for(i=0;i<n;i++)
        {
            scanf("%s",stu[i].name);
            scanf("%d",&stu[i].tnum);
            getchar();
            for(j=0;j<stu[i].tnum;j++)
                scanf("%s",stu[i].tname[j]);
            scanf("%d",&stu[i].xnum);
            getchar();
            for (j=0;j<stu[i].xnum;j++)
                scanf("%s",stu[i].xname[j]);
        }
        scanf("%d",&k);
        getchar();
        for(i=0;i<k;i++)
        {
            scanf("%s",ch);
            insert(ch);
        }
        int flag1,flag2;
        while (m--)
        {
            len_add = 0;
            len_del = 0;
            for(i=0;i<n;i++)
            {
                for(j=0;j<stu[i].tnum;j++)
                {
                    flag1 = search(stu[i].tname[j]);
					if(flag1 !=0)
						break;
                }
                for (j=0;j<stu[i].xnum;j++)
                {
                    flag2 = search(stu[i].xname[j]);
					if(flag2 !=0)
						break;
                }
                if(flag1 !=0 && flag2 == 0)
                {
                    strcpy(add_str[len_add],stu[i].name);
                    len_add++;
                }
                else if(flag1 == 0 && flag2 != 0)
                {
                    strcpy(del_str[len_del],stu[i].name);
                    len_del++;
                }
            }
            for(i=0;i<len_add;i++)
            {
                if(search(add_str[i]) == 0)
                    insert(add_str[i]);
            }
            for(i=0;i<len_del;i++)
            {
                if(search(del_str[i]) != 0)
                    Delete(del_str[i]);
            }
        }
        sort(stu,stu+n,cmp);
        ttt=0;
        for(i=0;i<n;i++)
        {
            if(search(stu[i].name) != 0)
            {
                if(ttt>0)
                    printf(" ");
                ttt++;
                printf("%s",stu[i].name);
            }
        }
        if(ttt==0)
            printf("None");
        printf("/n");
    }
    return 0;
}