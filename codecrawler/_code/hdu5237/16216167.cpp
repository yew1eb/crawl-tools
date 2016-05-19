#include <stdio.h>                                                                                                        
#include <string.h>                                                                                                       
char map[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";                                          
char s[10005];                                                                                                           
char encoded[10005];                                                                                                     
void base64()                                                                                                             
{                                                                                                                         
    long long t, slen, p, i, flag;                                                                                           
    p = 0;                                                                                                                   
    slen = strlen(s);                                                                                                        
    flag = slen % 3;                                                                                                         
    for(i = 0;i < slen;i += 3)                                                                                               
    {                                                                                                                        
        t = (s[i]<<16) + (s[i + 1]<<8) + s[i + 2];                                                                              
        encoded[p++] = map[(t&((1<<6) - 1)<<18)>>18];                                                                          
        //t>>6;                                                                                                                 
        encoded[p++] = map[(t&((1<<6) - 1)<<12)>>12];                                                                           
        //t>>6;                                                                                                                 
        encoded[p++] = map[(t&((1<<6) - 1)<<6)>>6];                                                                             
        //t>>6;                                                                                                                 
        encoded[p++] = map[t&((1<<6) - 1)];                                                                                     
    }                                                                                                                        
    if(flag == 1)                                                                                                            
    {                                                                                                                        
      encoded[p - 1] = '=';                                                                                                  
      encoded[p - 2] = '=';                                                                                                  
    }                                                                                                                        
    else if(flag == 2)                                                                                                       
        encoded[p - 1] = '=';  
    encoded[p] = '\0';                                                                                                 
    //printf("%d\n", p);                                                                                                     
}                                                                                                                         
int main()                                                                                                                
{                                                                                                                         
    int t, k, m, i;                                                                                                          
    scanf("%d", &t);                                                                                                         
    m = 1;                                                                                                                   
    while(t--)                                                                                                               
    {                                                                                                                        
        scanf("%d %s", &k, s);                                                                                                  
        while(k--)                                                                                                              
        {                                                                                                                       
            base64();                                                                                                              
            strcpy(s, encoded);                                                                                                    
        }                                                                                                                       
        printf("Case #%d: ", m++);                                                                                              
        for(i = 0;i < strlen(encoded);i++)                                                                                      
            printf("%c", encoded[i]);                                                                                              
        printf("\n");                                                                                                           
    }                                                                                                                        
    return 0;                                                                                                                
}                                          
