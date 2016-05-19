#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;
char st[205];
int flag,x,y;
void move(int &x,int &y,int &flag,char dict){
    if(flag==0){
        if(dict=='A'){
            x=x+10;
            y=y;
            flag=1;
        }
        else{
            x=x-10;
            y=y;
            flag=3;
        }
    }
    else if(flag==1){
        if(dict=='A'){
            x=x;
            y=y-10;
            flag=2;
        }
        else{
            x=x;
            y=y+10;
            flag=0;
        }
    }
    else if(flag==2){
        if(dict=='A'){
            x=x-10;
            y=y;
            flag=3;
        }
        else{
            x=x+10;
            y=y;
            flag=1;
        }
    }
    else{
        if(dict=='A'){
            x=x;
            y=y+10;
            flag=0;
        }
        else{
            x=x;
            y=y-10;
            flag=2;
        }
    }
}
int main(){
    while(scanf("%s",&st)!=EOF){
        printf("300 420 moveto\n310 420 lineto\n");
        int len=strlen(st);
        flag=1;
        int i;
        x=310;y=420;
        for(i=0;i<len;i++){
            move(x,y,flag,st[i]);
            printf("%d %d lineto\n",x,y);
        }
        printf("stroke\nshowpage\n");
    }
    return 0;
}