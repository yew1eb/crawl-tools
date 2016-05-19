#include<stdio.h>
#include<string.h>
int main(){
    int n;
    char ch[100];
    scanf("%d",&n);
    getchar();
    int num_a,num_e,num_i,num_o,num_u;
    while(n--){
        gets(ch);
        num_a=0;
        num_e=0;
        num_i=0;
        num_o=0;
        num_u=0;
        int len=strlen(ch);
        for(int i=0;i<len;i++){
            switch(ch[i]){
                case 'a': num_a++; break;
                case 'e': num_e++; break;
                case 'i': num_i++; break;
                case 'o': num_o++; break;
                case 'u': num_u++; break;
            }
        }
        printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",num_a,num_e,num_i,num_o,num_u);
        if(n) printf("\n");
    }
}