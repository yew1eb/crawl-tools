#include <iostream>
#include <algorithm>
using namespace std;
const int M = 100005;
int a,b;
int father[M];       //è®°å½ç¶èç¹ 
bool circle;         //å¤æ­æ¯å¦å­å¨ç¯ 
bool visit[M];       //ç¨æ¥è®°å½é¡¶ç¹æ°  
int edgenum,vnum;    //åå«è¡¨ç¤ºè¾¹æ°ï¼é¡¶ç¹æ° 
void initial( )
{
     for( int i=0 ; i<M ; i++ )
          father[i] = i,visit[i]=false;
     circle = false;  
     edgenum = vnum = 0;      
}

int find(  int x )
{
    return x == father[x] ? x : father[x] = find(father[x]);     //æ¾ç¥åèç¹ + è·¯å¾åç¼© 
}

void merge( int a ,int b )
{
     if( a == b )
         circle = true;
     int x , y;
     x = find(a);
     y = find(b);
     if( x != y ){
         father[x] = y;
         edgenum++;       //å¼åºä¸æ¡è¾¹ 
     }
     else
         circle = true;   //x==yï¼è¯´æä»ä»¬æ¯åä¸ä¸ªç¥åï¼ä¸æ¦è¿éä¾¿ä¸ç¥å3èæç¯ 
}

int main()
{
    while( true ){
           initial( );
           scanf("%d%d",&a,&b);
           if( a==0 && b==0 ){     //ä¸ºç©ºæ  
               printf("Yes\n");       
               continue;
           }
           if( a==-1 && b==-1 )
               break;
           visit[a] = true;
           visit[b] = true;
           merge( a,b );
           while( true ){
                  scanf("%d%d",&a,&b);
                  if( a==0 && b==0 )
                      break;
                  visit[a] = true;
                  visit[b] = true;
                  merge( a , b );      
           }
           for( int i=0 ; i<M ; i++ )
                if( visit[i] )
                    vnum++;  
           if(  !circle && edgenum+1 == vnum )
               printf("Yes\n");
           else
               printf("No\n");
    }     
    return 0;
}
