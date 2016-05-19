//å­å¸åºæ³çæå¨æå
#include <iostream>
#include <string>
using namespace std;
string input,s;

void perm(){
    int flag=1;
    if(input[0]!='0'){flag=0;cout<<input;}s=input;
    while(1){
        int index=-1;
        for(int i=input.size()-2;i>=0;i--) // ä»æå³å¼å§,æ¾å°ç¬¬ä¸ä¸ªæ¯å³è¾¹å°çæ°å­,èµå¼ç»index
        {
            if(input[i]<input[i+1]){
                index=i;
                break;
            }
        }
        if(index==-1)break; // æææåéåå®ï¼break while

        char M='9'; // Mä¸ºçè§å¨å¼ä¸´æ¶åé(for swap)
        int C; // Cä¸ºææ¾å°æ°å­çåºå·
        for(int i=index+1;i<=input.size()-1;i++){ // åä»æå³å¼å§,æ¾å°input[index]å³è¾¹æ¯input[index]å¤§çæ°å­
            if(input[i]<=input[index])continue;
            if(input[i]<=M){
                C=i;
                M=input[i];
            }
        } 
        input[C]=input[index];
        input[index]=M; // äº¤æ¢input[index]åinput[C]
        int len=input.size()-1-index;
        for(int i=1;i<=len/2;i++){ // å°indexåé¢çé¨ååç½®ï¼æ¯å¦7421,åç½®ä¸º1247ï¼åªéè¦å¯¹ç§°äº¤æ¢å³å¯
            char t=input[index+i];
            input[index+i]=input[input.size()-i];
            input[input.size()-i]=t;
        }
        if(input[0]=='0'){ s=input;continue; }
        if(s[0]==input[0]){ cout<<' '<<input;s=input;flag=0; }
        else { if(flag==0)cout<<endl<<input;else cout<<input; s=input; }
    }
    cout<<endl;
}

int main(){
    
    char str[5];
    int cnt=0;
    //freopen("hdu1716in.txt","r",stdin);
    //freopen("hdu1716out.txt","w",stdout);
    while(cin>>str[0]>>str[1]>>str[2]>>str[3])
    { 
        str[4]='\0';input=str;
        if(str[0]=='0'&&str[1]=='0'&&str[2]=='0'&&str[3]=='0')break;
        if(cnt)cout<<endl;cnt++;
        perm();
    }   
    //system("pause");
    //æ³¨æï¼æäºç³»ç»è½ç¶æ¯æ system("pause"); 
    //ä½æ¯å¦æå¾ªç¯ä¼ç»æï¼è¿è¡å°è¯¥å¥å°±ä¼ Wrong answer
    // è¿æ¯åºè¯¥æ³¨æçå°æ¹ã 
    return 0;
}
