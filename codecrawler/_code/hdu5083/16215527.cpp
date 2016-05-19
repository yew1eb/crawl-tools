#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int ord,o1,o2,o3;
char str[520];
char l1[20],l2[20],l3[20];
char s1[10],s2[10],s3[10];
char ming[7][11]= {{"ss"},{"ADD"},{"SUB"},{"DIV"},{"MUL"},{"MOVE"},{"SET"}};
int getnum(char s[])
{
    int sum=0,cnt=0;
    for(int i=0;i<strlen(s);i++)
    {
        sum+=pow(2,cnt++)*(s[i]-'0');
    }
    //cout<<"è¿ä¸²å­ç¬¦ä¸²è½¬åä¸ºæ°å­="<<sum<<endl;
    return sum;
}
void gain1(char s[])
{
    int len=strlen(s);
    int sum=0,cnt=0;
    for(int i=len-1;i>=0;i--)
    sum+=(int)pow(10,cnt++)*(s[i]-'0');
    cnt=0;
    while(sum!=0)
    {
        l1[cnt++]=(sum%2)+'0';
        sum/=2;
    }
    l1[cnt]='\0';
}
void gain2(char s[])
{
    int len=strlen(s);
    int sum=0,cnt=0;
    for(int i=len-1;i>=0;i--)
    sum+=(int)pow(10,cnt++)*(s[i]-'0');
    cnt=0;
    while(sum!=0)
    {
        l2[cnt++]=sum%2+'0';
        sum/=2;
    }
    l2[cnt]='\0';
}
void gain3(int sum)
{
    int cnt=0;
    while(sum!=0)
    {
        l3[cnt++]=sum%2+'0';
        sum/=2;
    }
    l3[cnt]='\0';
}
void output()
{
    for(int i=6;i>strlen(l3);i--)
    cout<<0;
    for(int i=strlen(l3)-1;i>=0;i--)
    cout<<l3[i];
    for(int i=5;i>strlen(l2);i--)
    cout<<0;
    for(int i=strlen(l2)-1;i>=0;i--)
    cout<<l2[i];
    for(int i=5;i>strlen(l1);i--)
    cout<<0;
    for(int i=strlen(l1)-1;i>=0;i--)
    cout<<l1[i];
    cout<<endl;
}
void getans()
{
    if(o3>=1&&o3<=6)
        if(o2>=1&&o2<=31)
            if(o1>=0&&o1<=31)
            {
                if(o1==0&&o3==6)
                    printf("SET R%d\n",o2);
                else if(o1!=0&&o3==6)
                    printf("Error!\n");
                else if(o1==0&&o3!=6)
                    printf("Error!\n");
                else
                    printf("%s R%d,R%d\n",ming[o3],o2,o1);
                return ;
            }
    printf("Error!\n");
    return ;
}
int main()
{
    while(scanf("%d",&ord)!=EOF)
    {
        getchar();
        memset(s1,'\0',sizeof(s1));
        memset(s2,'\0',sizeof(s2));
        memset(s3,'\0',sizeof(s3));
        gets(str);//è¾å¥æ è¯¯ï¼
        int len=strlen(str);
        if(!ord)//å°16ä½äºè¿å¶ç¿»è¯ä¸ºæä½æ¯è¯­ï¼
        {
            for(int i=5;i>=0;i--)
            s3[5-i]=str[i];
            s3[6]='\0';
            for(int i=10;i>=6;i--)
            s2[10-i]=str[i];
            s2[5]='\0';
            for(int i=len-1;i>10;i--)
            s1[15-i]=str[i];
            s1[5]='\0';
            o1=getnum(s1);
            o2=getnum(s2);
            o3=getnum(s3);
            getans();//æ­¤å¤æ è¯¯ï¼
        }
        else
        {
            bool have_last=false;
            int num=0;

            int cnt=0,pos=0;
            for(int i=0;str[i]!=' ';i++)
            s3[cnt++]=str[i],pos=i;
            s3[cnt]='\0';

            pos+=3;//ç§»å¨å­ç¬¦ï¼
            cnt=0;
            while(str[pos]>='0'&&str[pos]<='9'&&pos<len)
            {
                s2[cnt++]=str[pos++];
            }
            num=1;//è¡¨ç¤ºç°å¨æ1ä¸ªæ´æ°ï¼
            s2[cnt]='\0';

            cnt=0;
            pos+=2;//æçæ¯åºè¯¥ç§»å°äºä¸ä¸ä¸ªæ´æ°çæé«ä½ï¼

            while(str[pos]>='0'&&str[pos]<='9'&&pos<len)
            {
                have_last=true;
                s1[cnt++]=str[pos++];
            }
            if(have_last)
                num++;//ä¸¤ä¸ªæ°å­ï¼
            s1[cnt]='\0';

            if(num==2)
            gain1(s1);
            else
            strcpy(l1,"00000");
            gain2(s2);
            for(int i=1;i<=6;i++)
            if(!strcmp(ming[i],s3))
            pos=i;
            gain3(pos);
            output();
        }
    }
    return 0;
}
