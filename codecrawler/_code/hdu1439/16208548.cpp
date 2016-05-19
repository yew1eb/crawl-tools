# include "stdio.h"
# include "string.h"

int Key[210], ChangeNum[210];
char Ch[210], AnsCh[210];
int main()
{
    int n, k;
    while(~scanf("%d",&n) && n!=0)
    {
        memset(Key,0,sizeof(Key));
        memset(ChangeNum,0,sizeof(ChangeNum));
        for(int i = 1; i <= n; i++)
            scanf("%d",&Key[i]);
        for(int i = 1; i <= n; i++)
        {
            int num = 1;
            int t = Key[Key[i]];
            while(t!=Key[i])
            {
                num++;
                t = Key[t];
            }
            ChangeNum[i] = num;
        }
        while(scanf("%d",&k) && k!=0)
        {
            getchar();
            memset(Ch,0,sizeof(Ch));
            memset(AnsCh,0,sizeof(AnsCh));
            gets(Ch+1);
            int len = strlen(Ch+1);
            for(int i = len+1; i <= n; i++)
            {
                Ch[i] = ' ';
            }
            Ch[n+1] = '\0';
            for(int i = 1; i <= n; i++)
            {
                int pos = i;
                for(int j = 0; j < k % ChangeNum[i]; j++)
                {
                    pos = Key[pos];
                }
                AnsCh[pos] = Ch[i];
            }
            AnsCh[n+1] = '\0';
            puts(AnsCh+1);
        }
        printf("\n");
    }
    return 0;
}

