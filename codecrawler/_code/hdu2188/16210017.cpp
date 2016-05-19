#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,m,T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        if(n%(m+1)==0)cout<<"Rabbit"<<endl;
        else cout<<"Grass"<<endl;
    }
    return 0;
}
/*
    ç®ååå¼ï¼ä¸ä¸ªææ¬¾aï¼ä»¤ä¸ä¸ªäººé½è½ææ¬¾bï¼ä½¿å¾a+b=m-1ï¼
    å¦ænæ¯m+1çåæ°ï¼åæ¯æ¬¡å¾éæçæ°å ä¸æéæçæ°é½æ¯m+1ï¼åæåå¿å®å¾éèã
    å¦ænä¸æ¯m+1çåæ°ï¼åæéæä¸å®çé±ä½¿å¾næ¯m+1çåæ°ï¼é£ä¹å°±è·ä¸è¿°æåµç¸åï¼æéå¿èã
*/
