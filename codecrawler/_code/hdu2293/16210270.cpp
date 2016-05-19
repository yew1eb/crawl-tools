#include <iostream>
#include <cmath>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int test;
    int ahp, bhp, astr, bstr, aspd, bspd;
    string a,b;
    int alen , blen;
    cin>>test;
    while(test--)
    {
        ahp = 0, bhp = 0, astr = 1, bstr = 1, aspd = 0, bspd = 0;
        cin>>a>>b;
        alen = a.length();
        blen = b.length();
        for(int i = 0; i < alen; i++)
        {
            ahp = (ahp + (83 -a[i])*(83-a[i]))%97;
            astr = (astr * a[i])%79;
            for(int j = i + 1; j < alen; j++)
            {
                aspd = (aspd + a[i]*a[j])%11;
            }
        }
        for(int i = 0; i < blen; i++)
        {
            bhp = (bhp + (83 -b[i])*(83-b[i]))%97;
            bstr = (bstr * b[i])%79;
            for(int j = i + 1; j < blen; j++)
            {
                bspd = (bspd + b[i]*b[j])%11;
            }
        }
        ahp = 300 - ahp;
        bhp = 300 - bhp;
        astr += 22;
        bstr += 22;
        
        int aw = bhp/astr; //a win , b éè¦è¢«aæ»æå æ¬¡.
        if (bhp%astr != 0) //aæåä¸æ¬¡æ»å»æ¯å¦æ°å¥½ææ­»b, æä¸æ­»åæä¸æ¬¡.
            aw++;
        int bw = ahp/bstr;
        if (ahp%bstr != 0)
            bw++;
        aw *= (20 - aspd);
        bw *= (20 - bspd);
        if (aw == bw)
        {
            cout<<"tie"<<endl;
        }
        else
        if (aw < bw)
        {
            cout<<"win"<<endl;
        }
        else
        {
            cout<<"lose"<<endl;
        }
    }
}
