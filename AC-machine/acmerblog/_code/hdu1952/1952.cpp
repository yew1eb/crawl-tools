/*This Code is Submitted by billforum for Problem 1952 at 2012-06-08 15:39:09*/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <cstring>
#include <stdlib.h>
using namespace std;
const int Len=1000000;
int next[Len+5];
void getNext(int next[],char str[])
{
        int len=strlen(str);
        int i=0,j=-1;
        while(i<len)
        {
                if((j==-1)||(str[i]==str[j]))
                {
                        j++;
                        i++;
                        next[i]=j;
                }
                else j=next[j];
        }
        
        
        return;
}
void print(int next[],int len)
{
        for(int i=0;i<len;i++)
                printf("%d ",next[i]);
}
int cmp(char s1[],char s2[])
{
        int i=0,j=0;//i->s1,j->s2
        int len1=strlen(s1),len2=strlen(s2);
        int times=0;
        while(i<len1)
        {
                if((j==-1)||(s1[i]==s2[j]))
                {
                        i++;
                        j++;
                        if(j>=len2) 
                        {
                                