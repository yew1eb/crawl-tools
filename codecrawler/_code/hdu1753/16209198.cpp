#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::find;
using std::reverse;

string sA, sB,sR, sApoint, sBpoint, sRpoint, sRinteger;
int iPointA = 0, iPointB = 0, iCarry = 0; 

void AddPoint()
{
    sRpoint.clear();
    if (sApoint.size() == 0 && sBpoint.size() == 0) return;
    if (sApoint.size() == 0){
        sRpoint += sBpoint;
        return;
    }
    if (sBpoint.size() == 0){
        sRpoint += sApoint;
        return;
    }

    if (sApoint.size() != sBpoint.size()){
        if (sApoint.size() > sBpoint.size()){
            for (int i = sBpoint.size() - 1; i >= 0; --i){
                char c = sBpoint[i] + sApoint[i] + iCarry - '0';
                if (c > '9'){
                    c -= 10;
                    iCarry = 1;
                } else iCarry = 0;
                sRpoint += c;
            }//for_i
            reverse(sRpoint.begin(), sRpoint.end());
            sRpoint += sApoint.substr(sBpoint.size(), sApoint.size() - sBpoint.size());
        }//if_sApoint
        else{
            for (int i = sApoint.size() - 1; i >= 0; --i){
                char c = sBpoint[i] + sApoint[i] + iCarry - '0';
                if (c > '9'){
                    c -= 10;
                    iCarry = 1;
                } else iCarry = 0;
                sRpoint += c;
            }//for_i
            reverse(sRpoint.begin(), sRpoint.end());
            sRpoint += sBpoint.substr(sApoint.size(), sBpoint.size() - sApoint.size());
        }
    }//if_sAp
    else{
        for (int i = sApoint.size() - 1; i >= 0; --i){
            char c = sBpoint[i] + sApoint[i] + iCarry - '0';
            if (c > '9'){
                c -= 10;
                iCarry = 1;
            } else iCarry = 0;
            sRpoint += c;
        }//for_i
        reverse(sRpoint.begin(), sRpoint.end());
    }//else
}

void AddInteger()
{
    sRinteger.clear();
    reverse(sA.begin(), sA.end());
    reverse(sB.begin(), sB.end());

    size_t i = 0;
    for (; i < sA.size() && i < sB.size(); ++i){
        sRinteger += sA[i] + sB[i] + iCarry - '0';
        if (sRinteger[i] > '9'){
            sRinteger[i] -= 10;
            iCarry = 1;
        } else iCarry = 0;
    }//for

    for (; i < sA.size(); ++i){
        sRinteger += sA[i] + iCarry;
        if (sRinteger[i] > '9'){
            sRinteger[i] -= 10;
            iCarry = 1;
        } else iCarry = 0;
    }

    for (; i < sB.size(); ++i){
        sRinteger += sB[i] + iCarry;
        if (sRinteger[i] > '9'){
            sRinteger[i] -= 10;
            iCarry = 1;
        } else iCarry = 0;
    }

    if (iCarry == 1) sRinteger += '1';//sRinteger += '1';
    
    reverse(sRinteger.begin(), sRinteger.end());
    int iLen = 0;
    while (sRinteger[iLen] == '0' && sRinteger.size() != 1) {
        iLen++;
        if (iLen == sRinteger.size()) break;
      }

    if (iLen == sRinteger.size()) iLen--;
    sRinteger = sRinteger.substr(iLen, sRinteger.size() - iLen + 1);
}

int main(void)
{
    while (cin >> sA >>sB){
        sR.clear();
        sApoint.clear(), sBpoint.clear();
        iPointA = 0, iPointB = 0, iCarry = 0;
        iPointA = sA.find('.', 0);
        if (iPointA != -1) sApoint += sA.substr(iPointA + 1, sA.size() - iPointA - 1);
        iPointB = sB.find('.', 0);
        if (iPointB != -1) sBpoint += sB.substr(iPointB + 1, sB.size() - iPointB - 1);
        sA = sA.substr(0, iPointA);
        sB = sB.substr(0, iPointB);

        AddPoint();
        AddInteger();
        sR.clear();
        sR += sRinteger;
        int iLen = sRpoint.size() - 1;
        if (iLen >= 0)
        while (sRpoint[iLen] == '0') {
            iLen--;
            if (iLen < 0) break;
        }

        if (iLen >= 0) {
            sR += '.';
            sR += sRpoint.substr(0, iLen + 1);
        }
        cout << sR << '\n';
    }
    return 0;
}