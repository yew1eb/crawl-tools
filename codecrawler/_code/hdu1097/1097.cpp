hdu 1097 A hard puzzle
好吧，这个题我承认我没有快速幂取模，我找的规律通过尾数的的规律你会发现，尾数为0,1,5,6的不管是多少次方尾数依然不变，而尾数为4和9的每2次循环，2,3,7,8为每4次循环，就是这么水过啦~~~~~！！！


#include<iostream>

using namespace std;

int ldigit[10][4]={{0},{1},{6,2,4,8},{1,3,9,7},{6,4},{5},{6},{1,7,9,3},{6,8,4,2},{1,9}};

int main()

{

 int a,b;

 int d;

 while(scanf("%d%d",&a,&b)!=EOF)

 {

 d=a;

 if(d==0||d==1||d==5||d==6)

 printf("%d\n",d);

 else if(d==4||d==9) 

cout<<ldigit[d][b%2]<<endl;

 else if(d==2||d==3||d==7||d==8)

 cout<<ldigit[d][b%4]<<endl;

 }

 return 0;

}