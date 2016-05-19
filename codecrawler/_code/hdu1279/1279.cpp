#include<stdio.h>
#include<string.h>
int main(){       
	int T,i,sum;   
	int n;   
	scanf("%d",&T);
    while(T--)  
	{      
		scanf("%d",&n);
		sum=0;
		while(n!=1){
			if(n%2){
				sum++;
				if(sum==1)
					printf("%d",n);
				else
					printf(" %d",n);
				n=n*3+1;
			}
			else
				n/=2;
		}

		if(sum==0)
			printf("No number can be output !");
		printf("\n");
	}     
	return 0; 
}