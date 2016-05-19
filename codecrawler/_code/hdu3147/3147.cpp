#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<algorithm>
#include<list>
#include<cstdio>
#include<stack>
#include<cstring>
#include<cmath>
#include<string>
#include<sstream>
#include<map>
#include <bitset>
#include <set> 

using namespace std ;

#define			pii			pair < int , int >
#define			MP			make_pair

map < char , pii > table ;
map < pii , char > table2 ;
bool visit[100] ;

int main()
{
	//freopen("a.in","r",stdin);
	int t , R , C ;
	string key , text ;
	cin >> t ;
	getline ( cin , text ) ;
	while ( t-- ){
		table.clear() , table2.clear() ;
		memset ( visit , 0 , sizeof visit ) ;
		visit['q'-'a'] = 1 ;
		getline ( cin , key ) ;
		getline ( cin , text ) ;
		R = C = 0 ;
		for ( int i = 0 ; i < key.size() ; i++ ){
			if ( key[i] >= 'a' && key[i] <= 'z' && !visit[key[i]-'a'] ){
				visit[key[i]-'a'] = 1 ;
				table[key[i]] = MP ( R , C ) ; 
				table2[MP(R,C)] = key[i] ;
				C++ ;
				if ( C == 5 ){
					R++ ;
					C = 0 ;
				}
			}
		}
		for ( int i = 'a' ; i <= 'z' ; i++ ){
			if ( !visit[i-'a'] ){
				table[(char)(i)] = MP ( R , C ) ; 
				table2[MP(R,C)] = (char)(i) ;
				C++ ;
				if ( C == 5 ){
					R++ ;
					C = 0 ;
				}
			}
		}
		for ( int i = 0 ; i < text.size() ; i++ ){
			if ( text[i] == ' ' ){
				text.erase ( text.begin() + i ) ;
				i-- ;
			}
		}
		for ( int i = 0 ; i < text.size()-1 ; i+=2 ){
			if ( text[i] == text[i+1] )
				text.insert ( text.begin() + i + 1 , 'x' ) ;
		}
		if ( (int)(text.size())%2 )
			text.push_back ( 'x' ) ;
		char ch1 , ch2 ;
		int x_ch1 , y_ch1 , x_ch2 , y_ch2 , new_x , new_y ;
		for ( int i = 0 ; i < (int)(text.size())-1 ; i+=2 ){
			ch1 = text[i] , ch2 = text[i+1] ;
			if ( ch1 == ch2 ) ch2 = 'x' ;
			x_ch1 = table[ch1].first ;
			y_ch1 = table[ch1].second ;
			x_ch2 = table[ch2].first ;
			y_ch2 = table[ch2].second ;
			if ( x_ch1 == x_ch2 ){
				new_y = (y_ch1+1)%5 ;
				cout << (char)(table2[MP(x_ch1,new_y)]-32);
				new_y = (y_ch2+1)%5 ;
				cout << (char)(table2[MP(x_ch2,new_y)]-32) ;
			}
			else if ( y_ch1 == y_ch2 ){
				new_x = (x_ch1+1)%5 ;
				cout << (char)(table2[MP(new_x,y_ch1)]-32) ;
				new_x = (x_ch2+1)%5 ;
				cout << (char)(table2[MP(new_x,y_ch2)]-32) ;
			}
			else{
				new_y = abs ( y_ch1 - y_ch2 ) ;
				if ( y_ch1 < y_ch2 ){
					y_ch1 += new_y ;
					y_ch2 -= new_y ;
				}
				else if ( y_ch1 > y_ch2 ){
					y_ch1 -= new_y ;
					y_ch2 += new_y ;
				}
				cout << (char)(table2[MP(x_ch1,y_ch1)]-32) ;
				cout << (char)(table2[MP(x_ch2,y_ch2)]-32) ;
			}
		}
		cout << endl ;
	}
	return 0;
}