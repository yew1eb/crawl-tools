1 #include<cstdio>
 2 #include<cstring>
 3 int visit[100005];
 4 int main() {
 5     int step,mod,front;
 6     while(scanf("%d%d",&step,&mod)!=EOF) {
 7         memset(visit,0,sizeof(visit));
 8         visit[0]=1;
 9         front=0;
10         int i;
11         for(i=1;i<mod;++i) {
12             front=(front+step)%mod;
13             if(visit[front])
14             break;
15             visit[front]=1;
16         }
17         if(i==mod)
18         printf("%10d%10d    Good Choice\n\n",step,mod);
19         else
20         printf("%10d%10d    Bad Choice\n\n",step,mod);
21     }
22     return 0;
23 }