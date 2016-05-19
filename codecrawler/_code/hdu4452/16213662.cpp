#include<stdio.h>
char turn(char c){
    switch(c){
        case 'W':return 'S';
        case 'E':return 'N';
        case 'N':return 'W';
        case 'S':return 'E';
    }
}
void go(char &d,int v,int &x,int &y,int n){
    switch(d){
        case 'W':x-=v;break;
        case 'E':x+=v;break;
        case 'N':y-=v;break;
        case 'S':y+=v;break;
    }
    if(x<1){x=2-x;d='E';}
    if(x>n){x=2*n-x;d='W';}
    if(y<1){y=2-y;d='S';}
    if(y>n){y=2*n-y;d='N';}
}
int main(){
    char d1,d2,c;
    int n,t,time;
    int x1,y1,x2,y2,v1,v2,r1,r2;
    while(scanf("%d",&n),n){
        getchar();
        scanf("%c %d %d",&d1,&v1,&r1);
        getchar();
        scanf("%c %d %d",&d2,&v2,&r2);
        scanf("%d",&time);
        x1=y1=1;x2=y2=n;
        for(t=1;t<=time;t++){
            go(d1,v1,y1,x1,n);
            go(d2,v2,y2,x2,n);
            if(x1==x2&&y1==y2){c=d1;d1=d2;d2=c;}
            else{
                if(t%r1==0)
                    d1=turn(d1);
                if(t%r2==0)
                    d2=turn(d2);
            }
        }
        printf("%d %d\n%d %d\n",x1,y1,x2,y2);
    }
    return 0;
}
