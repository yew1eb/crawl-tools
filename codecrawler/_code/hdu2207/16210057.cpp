#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(int argc, char *argv[])
{
    int j, pos, num, t;
    while( cin>>t )
    {
        //å ä¸ºæå¨0åå¨1çæ¯ç¹æ®çä¸è½ç¨ 
        t+=2;
        pos=num=0;
        //ç¡®å®tçäºè¿å¶çä½æ° 
        while( t ) t>>=1, ++pos;
        //æ»å±32ä½ï¼æä»¥ä»31å¼å§ï¼0ç»æï¼æ¯åçï¼ 
        for(j=31; j>=0; --j)
        {
            //jä¹å°±æ¯ä½æ°å¤§äºtçä½æ°æ¯è¦ä¸º1çï¼è¿éå°±æ¯ç¡®å®
            //äºè¿å¶çä½æ°ä¸çé£ä½æ°ä¸º1 
            if( j>=pos ) num+=1<<(j%8);
            //è¿éæ¯ä¸ºäºå«ä½ä¸ä¸ªè¾åº 
            if( j==0 || j%8==0 )
            {
                cout<<num;
                //è¿éçææä¹å¥½çè§£ 
                num=0;
                //å°±æ¯æåä¸æ¬¡ä¸éè¦è¾åº"."ï¼æä»¥å¤æ­å°±å¯ä»¥äº 
                if( j>0 ) cout<<".";
            }
        } 
        cout<<endl;
    } 
    return 0;
}
