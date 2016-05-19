#include<stdio.h>
int a[100010];
int main(){
    int case_number,k=0,i,number,position1,end,thissum,maxsum,begin;
    scanf("%d",&case_number);
    while(case_number--){
        k++;
        scanf("%d",&number);
        for(i=0;i<number;i++)
            scanf("%d",&a[i]);
        position1=begin=end=0;
        maxsum=thissum=a[0];
        for(i=1;i<number;i++){
            if(thissum+a[i]<a[i]){             //å¦æå½åå¼æ¯a[i]å°çè¯åæ¹ä¸ºa[i]
                thissum=a[i];
                position1=i;                  //è®°å½ä¸æ¹çä½ç½®
            }
            else{
                thissum=thissum+a[i];          
            }
            if(thissum>maxsum){                //å½åå¼æ¯æå¤§å¼å¤§ï¼åå¤´å°¾é½è¦æ¹
                maxsum=thissum;
                begin=position1;
                end=i;
            }
        }
        printf("Case %d:\n%d %d %d\n",k,maxsum,begin+1,end+1);
        if(case_number)                        //æµè¯æ°æ®ä¹åæç©ºè¡ï¼ä¸å¼å§ä¹æ²¡çè§ï¼ä¹WRäºã
            printf("\n");
    }
    return 0;
}
