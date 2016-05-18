#include<iostream>
 #include<cstring>
 #include<algorithm>
 using namespace std;
 
 struct stick{
     int length;  //长度
     int mark;  //标记是否被使用过
 };
 stick sticks[64];
 int n,num,sum;
 
 int cmp(const stick &s1,const stick &s2){
     return s1.length>s2.length;
 }
 //len当前的长度，count当前长度为len的木棒的根数
 int dfs(int len,int l,int count,int pos){
     if(len==sum)return 1;//如果当期的长度就是所有木棒的总长
     if(count==num)return 1;
     for(int i=pos;i<n;i++){
         if(sticks[i].mark)continue;
         //没有被标记过的
         if(len==(sticks[i].length+l)){
             sticks[i].mark=1;
             if(dfs(len,0,count+1,0))//长度相等时，还是要从第一根开始搜
                 return 1;
             sticks[i].mark=0;
             return 0;
         }else if(len>(sticks[i].length+l)){
             sticks[i].mark=1;
             l+=sticks[i].length;
             if(dfs(len,l,count,i+1))
                 return 1;
             l-=sticks[i].length;//如果不成功，就要恢复
             sticks[i].mark=0;
             if(l==0)return 0;//当前搜索，如果前面的l为0，但第一根没有用上，那么这根木棒就要舍弃
             while(sticks[i].length==sticks[i+1].length)i++;//这根不成功的话，则相连的长度相同的不要
         }
     }
     return 0;
 }
 
 int main(){
     while(scanf("%d",&n)!=EOF){
         if(n==0)break;
         sum=0;
         for(int i=0;i<n;i++){
             scanf("%d",&sticks[i].length);
             sticks[i].mark=0;
             sum+=sticks[i].length;
         }
         sort(sticks,sticks+n,cmp);
         for(int len=sticks[0].length;len<=sum;len++){
             if(sum%len)continue; 
             num=sum/len; //原来长度为len的木棒的根数
             if(dfs(len,0,0,0)){
                 printf("%d\n",len);
                 break;
             }
         }
     }
     return 0;
 }