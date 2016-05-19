/**
* url : http://acm.hdu.edu.cn/showproblem.php?pid=1930
* stratege : 解一元线性同余方程组， 扩展欧几里得
* Author: johnsondu
* Status: johnsondu 0MS 284K 2207B C++ 2012-08-19 13:13:15 
* Trick: There will be no blank in the end of the text 
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

const int N = 2005 ;
int key[N], num, n ;
int str[N] ;
int res[N] ;
int r[N] ; 

void input ()
{
    int i ;
    scanf  ("%d", &n) ;
	memset (res, 0, sizeof (res)) ;
	memset (str, 0, sizeof (str)) ;
	memset (r, 0, sizeof (r)) ;
	memset (key, 0, sizeof (key)) ;
	num = 0 ;
    for (i = 0; i < 4; i ++)  // key
        scanf ("%d", &key[i]) ;
    for (i = 0; i < n; i ++)  // the set of remainder
        scanf ("%d", &str[i]) ;
	
	
}

void exGcd (int a, int b, int &d, int &x, int &y)  // Extended_Euclid
{
    if (b == 0)
    {
        d = a ;
        x = 1 ;
        y = 0 ;
        return ;
    }
    exGcd (b, a%b, d, x, y) ;
    int tmp = x ;
    x = y ;
    y = tmp - (a/b)*y ;
}

void getNum ()
{
    int i, j ;
    int a, b, c, d, x, y ;
    for (i = 0; i < n; i ++)
    {
        r[3] = str[i] % 100 ;        //transform the set of remainder into the 
        r[2] = (str[i]%10000)/100 ;  //single remainder of the key
        r[1] = (str[i]%1000000)/ 10000 ;
        r[0] = str[i]/1000000; 

		int ta = key[0] ;
		int tr = r[0] ;
									//mission: x = r1 (mod a1), x = r2 (mod a2), ..., find x ;
        for (j = 1; j < 4; j ++)    //a1, a2, ... are key[i], r1, r2, ... are r[i] 
        {							//find the str[i]'s value 
            a = ta, b = key[j] ;
			c = r[j] - tr ;
            exGcd (a, b, d, x, y) ;
			
			int t = b/d ;
			x = (x*(c/d)%t + t) % t ;
			tr = ta*x + tr ;
			ta = ta * (key[j]/d) ;
        }
        res[i] = tr ;
    }
}

void output ()
{
	int i ;
	int a, b, c ;
	char destr [10005] ;
	int len = 0 ;
	for (i = 0; i < n; i ++)
	{
		a = res[i] / 10000 ;
		b = (res[i] % 10000) / 100 ;
		c = res[i] % 100 ;
		
		if (a != 27)
			destr[len++] = 'A' + a - 1 ;
		else destr[len++] = ' ' ;
		if (b != 27)
			destr[len++] = 'A' + b - 1 ;
		else destr[len ++] = ' ' ;
		if (c != 27)
			destr[len++] = 'A' + c - 1 ;
		else destr[len ++] = ' ' ;
	}
	while (destr[len-1] == ' ')  //ignore the blank in the end of text.
	{
		len -- ;
	}
	for (i = 0; i < len; i ++)
		printf ("%c", destr[i]) ;
	printf ("\n") ;
}

int main ()
{
    int tcase ;
    scanf ("%d", &tcase)  ;
    while (tcase --)
    {
        input () ;
        getNum () ;
		output () ;
    }
    return 0 ;
}