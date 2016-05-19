#include <stdio.h>

int n, s;

void print(char *str, int len)
{
    int i, j, k;
    //head
    for(i = len-1; i >= 0; i --){
        switch(str[i]){
        case '0':
        case '2':
        case '3':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            printf(" ");
            for(j = 0; j < s; j ++){
                printf("-");
            }
            printf(" ");
            break;
        case '1':
        case '4':
            for(j = 0; j < s+2; j ++){
                printf(" ");
            }
            break;
        }
        if(i!=0)printf(" ");
    }
    printf("\n");

    //top body
    for(i = 0; i < s; i ++){
        for(j = len-1; j >= 0; j --){
            switch(str[j]){
            case '1':
            case '2':
            case '3':
            case '7':
                for(k = 0; k < s+1; k ++){
                    printf(" ");
                }
                printf("|");
                break;
            case '5':
            case '6':
                printf("|");
                for(k = 0; k < s+1; k ++){
                    printf(" ");
                }
                break;
            case '0':
            case '4':
            case '8':
            case '9':
                printf("|");
                for(k = 0; k < s; k ++){
                    printf(" ");
                }
                printf("|");
                break;
            }//switch
            if(j!=0)printf(" ");
        }//for
        
        printf("\n");
    }//for

    //middle
    for(i = len-1; i >= 0; i --){
        switch(str[i]){
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '8':
        case '9':
            printf(" ");
            for(j = 0; j < s; j ++){
                printf("-");
            }
            printf(" ");
            break;
        case '0':
        case '1':
        case '7':
            for(j = 0; j < s+2; j ++){
                printf(" ");
            }
            break;
        }
        if(i!=0)printf(" ");
    }
    printf("\n");

    //low body
    for(i = 0; i < s; i ++){
        for(j = len-1; j >= 0; j --){
            switch(str[j]){
            case '1':
            case '3':
            case '4':
            case '5':
            case '7':
            case '9':
                for(k = 0; k < s+1; k ++){
                    printf(" ");
                }
                printf("|");
                break;
            case '2':
                printf("|");
                for(k = 0; k < s+1; k ++){
                    printf(" ");
                }
                break;
            case '0':
            case '6':
            case '8':
                printf("|");
                for(k = 0; k < s; k ++){
                    printf(" ");
                }
                printf("|");
                break;
            }//switch
            if(j!=0)printf(" ");
        }//for
        printf("\n");
    }//for

    //buttom
    for(i = len-1; i >= 0; i --){
        switch(str[i]){
        case '0':
        case '2':
        case '3':
        case '5':
        case '6':
        case '8':
        case '9':
            printf(" ");
            for(j = 0; j < s; j ++){
                printf("-");
            }
            printf(" ");
            break;
        case '1':
        case '4':
        case '7':
            for(j = 0; j < s+2; j ++){
                printf(" ");
            }
            break;
        }
        if(i!=0)printf(" ");
    }
    printf("\n\n");
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w+",stdout);
    char str[9];
    int len;
    while(scanf("%d%d", &s, &n)){
        if(n==0&&s==0)break;
        len = 0;
        if(n == 0)
            str[len++] = 0+'0';
        else{
            while(n!=0){
                str[len ++] = n%10 + '0';
                n /= 10;
            }
        }
        print(str, len);
    }
    return 0;
}