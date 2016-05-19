/*
Date : 2015-09-06 15:23

Author : Dongao

Motto :

å¾ä¸ªä¹åµï¼
*/

#include<bits/stdc++.h>
using namespace std;
char str[1000];
struct node{
    char name[3000];
    int num;
    bool operator < (const node & rhs) const {
        if(num==rhs.num) return name>rhs.name;
        return num > rhs.num;
    }
}N[110];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        getchar();
        memset(N,0,sizeof(N));
        for(int i=0;i<n;i++){
            gets(str);
            int len=strlen(str);

            for(int j=len-1,k=0;j>=len-4;j--,k++){
                    N[i].num+= ( (str[j]-'0')*(int)floor( pow(10,k)+0.5 ) );
            }
//            printf("%d\n",N[i].num);
//            str[len-5]=0;
            strcpy(N[i].name,str);
            N[i].name[len-5]=0;
        }
        sort(N,N+n);
        for(int i=0;i<n;i++)
            printf("%s\n",N[i].name);

    }
    return 0;
}
//4,6,
