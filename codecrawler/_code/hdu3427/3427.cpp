#include<stdio.h>
#include<string.h>
#define NN 155 
char str[NN];
int mark[NN][NN];
int num[NN];
char cha[NN];

int dfs(int l, int r)
{
    int i, t;
    if (l == r){   /*如果就剩一种字符，直接判断是相连的个数是否大于1*/
        if (num[l] > 1)
            return 1;
        else
            return 0;
    }
    if (mark[l][r]>= 0)
        return mark[l][r];
    /*当前字符和后面的任一个相同字符合并，前提是夹在他们中间的
    字符串是合法的 
    */ 
    char ch = cha[l];
    for (i = l + 1; i <= r; i++){
        if (cha[i] == ch){
            if (mark[l + 1][i - 1] = dfs(l + 1, i - 1)){
                t = mark[i][r];
                mark[i][r] = -1;
                num[i] += num[l];
                mark[i][r] = dfs(i, r);
                num[i] -= num[l];
                if (mark[i][r] == 1)
                {
                    mark[i][r] = t;
                    return 1;
                }
                mark[i][r] = t;
            }
        }
    }
    /*当前字符是合法的，直接判断后一部分是否合法
      即如果x，y都合法，则xy也合法 
    */
    if (num[l] > 1 && (mark[l + 1][r] = dfs(l + 1, r)))
        return 1;
    return 0;
}
int main()
{
    int len, time, index, i;
    while (scanf("%s", str) != EOF){
        len = strlen(str);
        if (len == 0){
            puts("solvable");
            continue;
        }
        
        /*将字符串缩减成两个数组，一个存出现过的字符，另一个存这个字符出现的次数
            例ABBBAACC        缩成ABAC 和 1322
        */
        time = 1;
        index = 0;
        for (i = 1; i <= len; i++){
            if (str[i] != str[i - 1]){
                cha[index] = str[i - 1];
                num[index] = time;
                time = 1;
                index++;
            }
            else
                time++;
        }    
        memset(mark, -1, sizeof(mark));
        if (dfs(0, index - 1))
            puts("solvable");
        else
            puts("unsolvable");
    }
    return 0;
}