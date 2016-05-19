#include <iostream>
using namespace std;
char sev[10010];
int main()
{
  int h,a,p,y;  		
  while(gets(sev))
  {
  	h=a=p=y=0;
  	int k(0);
   for(int i=0;sev[i];i++)
    {
      if(sev[i]=='h') h++;
      if(sev[i]=='a'){
  	 	  if(h)  {a++,h--; } 
	    }
	  
	  if(sev[i]=='p'){
  	     if(a){ k++; if(k%2==0){p++;a--;} }	
        }
	 
 	  if(sev[i]=='y'){
 		 if(p){
 		    y++;p--;	
 		  }
 	    } 			
    }
	
	cout<<y<<endl;	
  }	
	return 0;
}