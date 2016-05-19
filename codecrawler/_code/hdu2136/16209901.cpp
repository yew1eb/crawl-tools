#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX=1000001;

bool isPrime[MAX];//isPrime[i]=trueè¡¨ç¤ºæ¯ç´ æ°ï¼falseè¡¨ç¤ºä¸æ¯
int indexes[MAX]; //å­æ¾ç´ æ°å å­çåºå·

void eraosthenes()
{
    fill(isPrime,isPrime+MAX,true);//åè®¾0~MAXé½æ¯ç´ æ°
    isPrime[0]=isPrime[1]=false; //æ0,1ç­å»
    int n=sqrt((double)MAX);

    for(int i=2; i<=n; i++)
    {
        if (isPrime[i]==false) continue;

        for(int j=i*i; j<MAX; j+=i)
        {
            if (isPrime[j]==false) continue;
            isPrime[j]=false;
        }        
    }
}

void createIndexes()
{
    eraosthenes();
    int i,k=1;
    for(i=2; i<MAX; i++)
        if (isPrime[i]==true) indexes[i]=k++;
    
    int m=MAX/2;
    for(i=2; i<=m; i++)
    {
        if (isPrime[i]==true)
        {
            int pos=2*i;
            while(pos<MAX)
            {
                indexes[pos]=indexes[i];
                pos+=i;
            }
        }
    }
}

bool run()
{
    int n;
    if (scanf("%d",&n)==EOF) return false;
    printf("%d\n",indexes[n]);
    return true;
}

int main()
{
    createIndexes();
    while(run());
    return 0;
}

