#include<cstdio>
#include<cstring>
#include<cstdlib>
char le[2],ri[2],op[16],str[16];

void fun(int n)
{
    for(int i=4;i>=0;i--)
    {
        if(n&(1<<i))  printf("1");
        else printf("0");
    }
}


int main()
{
    int Op,pd,cnt,ok,l,r,mul;
    ind:while(~scanf("%d",&Op))
    {
        if(Op==1)
        {
            ok=0;
            scanf("%s%s",op,str);
            if(strcmp(op,"ADD")==0)
                printf("000001");
            else if(strcmp(op,"SUB")==0)
                printf("000010");
            else if(strcmp(op,"DIV")==0)
                printf("000011");
            else if(strcmp(op,"MUL")==0)
                printf("000100");
            else if(strcmp(op,"MOVE")==0)
                printf("000101");
            else
                {
                    printf("000110");
                    ok=1;
                }
            for(int i=0;i<strlen(str);i++)
            {
                if(str[i]==',')
                {
                    pd=i;
                    break;
                }
            }
            cnt=0;
            for(int i=1;i<pd;i++)
            {
                le[cnt]=str[i];
                cnt++;
            }
            le[cnt]='\0';
            l=atoi(le);
            cnt=0;
            for(int i=pd+2;i<strlen(str);i++)
            {
                ri[cnt]=str[i];
                cnt++;
            }
            ri[cnt]='\0';
            r=atoi(ri);
            fun(l);
            if(ok)
                printf("00000\n");
            else
                {
                    fun(r);
                    printf("\n");
                }
        }
        else
        {
            scanf("%s",str);
            ok=cnt=0;
            for(int i=0;i<=5;i++)
            {
                op[cnt]=str[i];
                cnt++;
            }
            if(strcmp(op,"000110")==0)
              ok=1;
            l=0,mul=1;
            for(int i=10;i>=6;i--)
            {
                 l+=(str[i]-'0')*mul;
                 mul*=2;
            }
            r=0,mul=1;
            for(int i=15;i>=11;i--)
            {
                r+=(str[i]-'0')*mul;
                mul*=2;
            }
            if(ok)
            {
                if(l==0||r!=0)
                {
                    printf("Error!\n");
                    goto ind;
                }
                else
                    printf("SET R%d\n",l);
            }
            else
            {
                if(l==0||r==0)
                {
                    printf("Error!\n");
                    goto ind;
                }
                if(strcmp(op,"000001")==0)
                    printf("ADD ");
                else if(strcmp(op,"000010")==0)
                    printf("SUB ");
                else if(strcmp(op,"000011")==0)
                    printf("DIV ");
                else if(strcmp(op,"000100")==0)
                    printf("MUL ");
                else if(strcmp(op,"000101")==0)
                    printf("MOVE ");
                else
                {
                    if(!ok)
                    {
                        printf("Error!\n");
                        goto ind;
                    }
                }
                printf("R%d,R%d\n",l,r);
            }
        }
    }
    return 0;
}
/*
1
ADD R12,R2
*/
