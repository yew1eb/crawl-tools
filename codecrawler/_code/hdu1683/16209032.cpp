#include <stdio.h>
#include <string.h>
int main(){
    int t,len1,len2,len3,i,flag,n;
    scanf("%d",&t);
    while(t--){
        char a[105],b[105],c[105];
        scanf("%s%s%s",a,b,c);
        len1=strlen(a);
        len2=strlen(b);
        len3=strlen(c);
        n=flag=0;
        for(i=0;i<len2;i++){
            if(b[i]=='*'||c[i]=='*')
                n++;
            else if(a[n]==b[i]||a[n]==c[i])
                n++;
            if(n==len1){
                flag=1;
                break;
            }
        }
        if(flag)
            printf("win\n");
        else
            printf("lose\n");
    }
    return 0;
}