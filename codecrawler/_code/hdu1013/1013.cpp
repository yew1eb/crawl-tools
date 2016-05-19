1 #include<cstdio>
 2 #include<cstring>
 3 int main() {
 4     int N,ans=0;
 5     char str[1000];
 6     while(scanf("%s",str)) {
 7         if(strlen(str)==1&&str[0]=='0')
 8         break;
 9         while(1) {
10             int len=strlen(str);
11             if(len==1) {
12                 printf("%s\n",str);
13                 break;
14             }
15             ans=0;
16             for(int i=0;i<len;++i)
17             ans+=str[i]-'0';
18             int z=0;
19             while(ans!=0) {
20                 str[z++]=(ans%10)+'0';
21                 ans/=10;
22             }
23             str[z]=NULL;
24         }
25     }
26     return 0;
27 }
28