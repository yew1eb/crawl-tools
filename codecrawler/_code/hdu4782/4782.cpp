#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int n,i,j,cnt = 0,cas = 1;
    string last,ans,tmp;
    scanf("%d",&n);
    while(cnt++<n)
    {
        ans = "";
        while(1)
        {
            getline(cin,tmp,'\n');
            tmp = last+tmp;
            ans = ans+' '+tmp;
            int l = tmp.length();
            int fl = ans.length();
            bool f = true;
            for(i = 0; i<=l-7; i++)
            {
                if(tmp.substr(i,7) == "</html>")
                {
                    last = tmp.substr(i+7,l-(i+7));
                    ans = ans.substr(0,fl-(l-(i+7)));
                    f = false;
                    break;
                }
            }
            if(!f)break;
        }
        int l = ans.length(),dep = 0;
        printf("Case #%d:\n",cas++);
        for(i = 0;i<l;)
        {
            if(ans[i] == '<')
            {
                if(ans[i+1]!='/')dep++;
                while(ans[i]!='>'&&i<l)printf("%c",ans[i]),i++;
                if(ans[i-1] == '/')dep--;
                printf("%c\n",ans[i++]);
                while(ans[i] == ' ')i++;
                if(ans[i] == '<'&&ans[i+1] == '/')dep--;
                for(j = 0; j<dep; j++)printf(" ");
            }
            else
            {
                bool fs = false;
                int pre = 1;
                while(ans[i]!='<'&&i<l)
                {
                    if(ans[i] == '\t')ans[i] = ' ';
                    if(ans[i] == ' ')
                    {
                        while(ans[i] == ' ')
                        {
                            i++;
                            if(ans[i] == '\t')ans[i] = ' ';
                        }
                        i--;
                    }
                    if(ans[i] == ' '&&(ans[i+1]=='<'||pre))
                    {
                        i++;
                        continue;
                    }
                    pre = 0;
                    printf("%c",ans[i]);
                    fs = true;
                    i++;
                }
                if(fs)printf("\n");
                if(ans[i] == '<'&&ans[i+1] == '/')dep--;
                if(fs)for(int j = 0; j<dep; j++)printf(" ");
            }
        }
    }
    return 0;
}