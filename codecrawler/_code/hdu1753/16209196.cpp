/*ä»»å¡ï¼é«ç²¾åº¦ï¼è®¡ç®å¤§æ°å å¤§æ° 
*
*åæ°ï¼ä¹æ³å½æ°mulåæ°ä¸º è¢«å æ°a[]ï¼å æ°b[]ï¼ä¿å­æç»ç»æçansæ°ç»
*ç»æï¼ansæ°ç»ä¸­ans[0]ä¸ºæé«ä½ï¼ä»¥æ­¤ç±»æ¨  
*/ 
#include <iostream>
#include <string.h>
#define MAX 10000
using namespace std;
int max(int a,int b){
    if(a>b)return a;
    else return b;
}
void delete_point(char*a){
    int len=strlen(a);
    int i;
    for(i=0;i<len;i++){
        if(a[i]=='.') break;
    }
    if(i<len-1){
        for(int j=i;j<len-1;j++)
            a[j]=a[j+1];
        a[len-1]=0;    
    }
    
}
int add(char a[],char b[],char ans[]) {
         int i,j,s,len,c=0;
         int temp_a[MAX],temp_b[MAX],temp_ans[MAX];
         memset(ans,0,sizeof(ans));
         memset(temp_a,0,sizeof(temp_a));
         memset(temp_b,0,sizeof(temp_b));
         memset(temp_ans,0,sizeof(temp_ans));
         len=max(strlen(a),strlen(b)); 
         for (i=0;i<strlen(a);i++)         
             temp_a[strlen(a)-i-1]=a[i]-'0';
          for (i=0;i<strlen(b);i++)         
             temp_b[strlen(b)-i-1]=b[i]-'0';
         
         for(j=0;j<len;j++){
            s=temp_a[j]+temp_b[j]+c;
            temp_ans[j]=s%10;
            c=s/10;
         }
         if(c) temp_ans[len++]=c;         
         for (i=0;i<len;i++)
            ans[len-1-i]=temp_ans[i]+'0';
         ans[len]='\0';      
         return len;
        }
int main()
{
    char a[MAX],b[MAX],ans[MAX];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    while(cin>>a>>b){
        int len_a=strlen(a);
        int len_b=strlen(b);
        int len_a_1=0,len_a_2=0;
        int len_b_1=0,len_b_2=0;
        for(int i=0;i<len_a;i++){
            if(a[i]!='.') len_a_1++;
            else {
                len_a_2=len_a-len_a_1-1;
                break;
            }
        }
        for(int i=0;i<len_b;i++){
            if(b[i]!='.') len_b_1++;
            else {
                len_b_2=len_b-len_b_1-1;
                break;
            }
        }
        //cout<<"å·®"<<abs(len_b_2-len_a_2)<<endl;
        if(len_b_2>len_a_2){
            for(int i=len_a;i<len_a+len_b_2-len_a_2;i++)
                a[i]='0';
            len_a+=len_b_2-len_a_2;
        }
        else if(len_b_2<len_a_2){
            for(int i=len_b;i<len_b+len_a_2-len_b_2;i++)
                b[i]='0';
            len_b+=len_a_2-len_b_2;
        }
        //cout<<a<<endl;
        //cout<<b<<endl;
        //å»é¤å°æ°ç¹
        delete_point(a);
        delete_point(b);
        //cout<<a<<endl;
        //cout<<b<<endl;
        int len_ans=add(a,b,ans);
        //cout<<ans<<endl;
        int flag_point=len_ans-max(len_a_2,len_b_2);
        int flag_int=1;  //æ å¿æ¯å¦æ¯æ´æ° ï¼1ä»£è¡¨æ´æ° 
        int flag_zero_front=1;  //å¿½ç¥åå¯¼é¶æ¶ä½¿ç¨ ï¼1è¡¨ç¤ºå¨é¨ä¸º0ï¼0è¡¨ç¤ºæç»ç»æä¸æ¯é¶ 
        int flag_zero_behand;//å¿½ç¥åå¯¼é¶æ¶ä½¿ç¨ ï¼1è¡¨ç¤ºåé¢å¨é¨ä¸º0ï¼0è¡¨ç¤ºåé¢ä¸å¨æ¯0 
        int flag_zero_all=1;
        for(int i=flag_point;i<len_ans;i++)
            if(ans[i]!='0') flag_int=0;
        for(int i=0;i<len_ans;i++)
                if(ans[i]!='0') flag_zero_all=0;
        if(flag_zero_all==1) {
            cout<<"0"<<endl;
            continue;
        }
        for(int i=0;i<len_ans;i++){
            flag_zero_behand=1;
            if(i==flag_point-1) flag_zero_front=0;
            if(i==flag_point&&flag_int==1)break; 
            if(i==flag_point) cout<<'.';            
            if(flag_zero_front==0||ans[i]!='0'){
                for(int j=i;j>=flag_point&&j<len_ans;j++){
                    if(ans[j]!='0') flag_zero_behand=0; 
                }
                if(i>=flag_point&&flag_zero_behand==1) break;
                cout<<ans[i];
                flag_zero_front=0;
            }
        }
        
        cout<<endl;        
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
    }
    return 0;
}