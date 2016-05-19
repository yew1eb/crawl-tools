/* 
 * File:   main.cpp
 * Author: Kevin
 *
 * Created on 2013年10月27日, 下午2:06
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;
int p[105][105][2];
bool flag[105];
int a[105];
  int n,m;
bool jude(int m){
   for(int i=0;i<n;i++){
       if(p[m][i][0]>a[i])return false;
   }   
   return true;
}
bool solve(){
    for(int i=0;i<m;i++){
        if(flag[i]==false&&jude(i)){
            flag[i]=true;
            for(int j=0;j<n;j++){
                a[j]+=p[i][j][1];  
            }
            i=-1;
        }
    }
    for(int i=0;i<m;i++)if(flag[i]