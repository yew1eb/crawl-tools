#include<cstdio>
 #include<cstring>
 
 int main(){
     int _case;
     scanf("%d",&_case);
     getchar();
     while(_case--){
         char str[110];
         gets(str);
         int cnt1,cnt2,p,len=strlen(str);
         cnt1=cnt2=p=0;
         bool flag=true;
         for(int i=0;i<len;i++){
             if((str[i]<'0'||str[i]>'9')&&str[i]!='.'&&str[i]!='E'&&str[i]!='-'){
                 flag=false;break;
             }else if(str[i]=='E'){
                 cnt1++;
                 if(i==0||(i+1)==len||cnt1>1){
                     flag=false;break;
                 }
             }else if(str[i]=='-'){
                 cnt2++;
                 if(i==0||str[i-1]!='E'||(i+1)==len||cnt2>1){
                     flag=false;break;
                 }
             }else if(str[i]=='.'){
                 p++;
                 if((i+1)==len||i==0||p>1||cnt1>0){
                     flag=false;break;
                 }
             }
         }
         flag?puts("YES"):puts("NO");
     }
     return 0;
 }