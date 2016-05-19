//思路简单：只需要建树就行，判断是否为同一颗树。
//用数组建一颗树。
#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,t,c;
    char s[22];
    int tree[1111];
    int tree1[1111];
    while(~scanf("%d",&t)&&t!=0)
    {
        scanf("%s",s);    
       memset(tree,-1,sizeof(tree));
        for(i=0;s[i]!='\0';i++)
        {
             c=s[i]-'0';
             j=1;
             while(tree[j]!=-1)
             {
             if(c<=tree[j]) j=j*2;
                else  j=j*2+1;
             }
             tree[j]=c;
        }//数组建树。
        while(t--)
        {
            scanf("%s",s);    
       memset(tree1,-1,sizeof(tree1));
        for(i=0;s[i]!='\0';i++)
        {
             c=s[i]-'0';
             j=1;
             while(tree1[j]!=-1)
             {
             if(c<=tree1[j]) j=j*2;
                else  j=j*2+1;
             }
             tree1[j]=c;
        }
        for(i=0;i<=1024&&tree[i]==tree1[i];i++);//判断是否为同一颗树。
    if(i>1024)
        puts("YES");
    else
        puts("NO");
        }
    }
return 0;
}



                  
        