#include<stdio.h>
#include<string.h>
int d[10];
int set(int num){
    while(num){
        d[num%10]++;
        num /= 10;
    }
    return 0;
}
int make(int first, int last, int inter){
    if(inter < 0){
        first ^= last;
        last ^= first;
        first ^= last;
        inter = 0 - inter;
    }
    while(first <= last){
        set(first);
        first += inter;
    }
    return 0;
}
int main(){
    int n, f, l, inter, sum, i, j;
    char name[51], addr[20], s[10], ch;
    scanf("%d", &n);    
    while(n--){
        memset(d, 0, sizeof(d));
        getchar();
        gets(name);        
        scanf("%d%s", &sum, addr);       
        j = sum;
        do{
            scanf("%s", s);
            if(s[0] == '+' || s[0] == '-'){
                scanf("%d%d%d", &f, &l, &inter);
                if(s[0] == '-') inter *= -1;
                sum -= (l-f)/inter + 1;
                make(f, l, inter);
            }
            else{
                i = 0;
                while(s[i] != '\0'){
                    d[s[i++]-'0']++;
                }
                sum--;
            }
        }while(sum);
        printf("%s\n", name);
        printf("%d %s\n", j, addr);
        j = 0;
        for(i=0; i<10; i++){
            j += d[i];
            printf("Make %d digit %d\n", d[i], i);
        }
        printf("In total %d digit", j);
        if(j > 1) printf("s");
        printf("\n");
    }
    return 0;
}