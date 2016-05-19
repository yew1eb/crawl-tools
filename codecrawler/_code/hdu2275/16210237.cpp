#include<stdio.h>
#include<set>
using namespace std;
multiset<int>ss;
multiset<int>::iterator p,q;
int main(){
    int n,t; char c[5];
    while(~scanf("%d",&n)){
        ss.clear();
        while(n--){
            scanf("%s %d",c,&t);
            if(c[1]=='u')ss.insert(t);
            else {
                if(ss.size()==0 || *ss.begin() > t){printf("No Element!\n");continue;}
                ss.insert(t);
                q=ss.find(t);//è¿åç¬¬ä¸ä¸ªç­äºtçè¿­ä»£å¨
                p=q;    p++;
                if(p!=ss.end() && *p==t)t=*p;
                else {p--;p--;t=*p;}
                printf("%d\n",t);
                ss.erase(p); ss.erase(q);
            }
        }
        printf("\n");
    }
    return 0;
}
/*
7
Push 2
Push 5
Pop 2
Pop 3
Pop 4
Pop 5
Pop 6

*/