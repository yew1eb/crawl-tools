#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int n,cont;
    char ch1[100];
    char ch2[100];
    scanf("%d",&n);
    while(n--){
        cont=0;
        scanf("%s",ch1);
        int len=strlen(ch1);
        for(int i=len-1;i>=0;i--)
           ch2[len-1-i]=ch1[i];
          for(int i=0;i<len;i++)
              if(ch1[i]==ch2[i]) cont++;
              else break;
        if(cont==len) printf("yes\n");
        else  printf("no\n");
    }
}
