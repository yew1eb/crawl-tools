#include<iostream>
#include<cstdio>
#include<string>
#include<cctype>
#include<sstream>
using namespace std;
#define MAXN 110
#define INF (1 << 30)
int d[MAXN], u[MAXN * MAXN], v[MAXN * MAXN], w[MAXN * MAXN];
int e, n, vMin, num[4];
int ballman_ford()
{
    for(int i = 0; i <= n; d[i++] = INF);
    d[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < e; j++){
            if(d[v[j]] > d[u[j]] + w[j])
                d[v[j]] = d[u[j]] + w[j];
        }
    }
    for(int i = 0; i < e; i++)
        if(d[v[i]] > d[u[i]] + w[i])
            return 0;
    vMin = (1 << 30);
    for(int i = 1; i <= n; i++)
        if(vMin > d[i]) vMin = d[i];
    return 1;
}
int main()
{
    string input, s;
    int i, j, k, l, m, flag;
    //freopen("input.txt", "r", stdin);
    while(scanf("%d", &n)){
        if(!n) break;
        scanf("%d", &m);
        cin.ignore();
        e = 0;
        for(i = 0; i < m; i++){
            getline(cin, input);
            istringstream in (input);
            //cout<<input<<endl;
            num[0] = num[1] = num[2] = 0;
            for(j = 0, l = 0; in>>s; j++){
                if(isdigit(s[0])){
                    for(k = 0; k < s.size(); k++)
                        num[l] = num[l] * 10 + s[k] - '0';
                    l++;
                }
                if(j == 3){
                    if(s == "at") flag = 1;
                    else flag = 0;
                }
            }
            if(flag){
                u[e] = num[0]; v[e] = num[2]; w[e++] = -num[1];
            }else {
                u[e] = num[0]; v[e] = num[2]; w[e++] = 0;
                u[e] = num[2]; v[e] = num[0]; w[e++] = num[1];
            }
        }
        for(i = 1; i <= n; e++, i++){
            u[e] = 0; v[e] = i; w[e] = 0;
        if(ballman_ford()){
            for(i = 1; i <= n; i++)
                printf("%d%c", d[i] - vMin + 1, i == n ? '/n' : ' ');
        }else printf("Impossible./n");
    }
    return 0;
}
 

版权声明：本文为博主原创文章，未经博主允许不得转载。

参考：http://blog.csdn.net/zhaofukai/article/details/6279471
						                        





(adsbygoogle = window.adsbygoogle || []).push({});

 


window._bd_share_config={"common":{"bdSnsKey":{},"bdText":"","bdMini":"2","bdMiniList":false,"bdPic":"","bdStyle":"0","bdSize":"24"},"share":{}};with(document)0[(getElementsByTagName('head')[0]||body).appendChild(createElement('script')).src='http://bdimg.share.baidu.com/static/api/js/share.js?v=89860593.js?cdnversion='+~(-new Date()/36e5)];

					