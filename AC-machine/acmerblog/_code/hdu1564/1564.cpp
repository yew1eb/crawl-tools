//============================================================================
// Name        : hdu.cpp
// Author      : lanjiangzhou
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstdio>

using namespace std;

int main() {
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        if(n%2==0) printf("8600\n");
        else printf("ailyanlu\n");
    }
    return 0;
}