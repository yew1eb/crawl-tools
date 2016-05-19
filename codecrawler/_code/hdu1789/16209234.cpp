#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=1001;
bool mark[MAX];
int* *s=NULL;

void define_array(){//å®ä¹æ°ç» 
    s=new int*[MAX];//å®ä¹äºç»´æ°ç»ç¬¬1ç»´çå¤§å° 
    for(int i=0;i<MAX;++i)s[i]=new int[2];//å®ä¹ç¬¬äºç»´çå¤§å° 
}

bool cmp(int *a,int *b){//å¯¹äºç»´æ°ç»è¿è¡æåº 
    if(a[1] == b[1])return a[0]>b[0];
    return a[1]>b[1];
}

int main(){
    define_array();
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;++i)cin>>s[i][0];
        for(int i=0;i<n;++i)cin>>s[i][1];
        sort(s,s+n,cmp);
        memset(mark,false,sizeof mark);
        int sum=0,j;
        //æè·¯:æ¯æ¬¡é½éæ©åæ°æå¤§ç,å¤æ­è¿é¨åè¯¾ä»å®éå¶çé£å¤©å¼å§(éå¶3å¤©åä»ç¬¬ä¸å¤©å¼å§)å¾åæ¨çè½ä¸è½å¨ææçä¸å¤©å®æ 
        for(int i=0;i<n;++i){
            for(j=s[i][0];j>0;--j){
                if(!mark[j]){mark[j]=true;break;}//è¯¥åè¯¾å¯ä»¥å®æ 
            }
            if(j == 0)sum+=s[i][1];
        }
        cout<<sum<<endl;
    }
    return 0;
}