#include<iostream>
#include<string>
#include<fstream>
int ar[27][2];
int m,n;
std::string str;
//int depth;
int dfs(int n,int r,int d)
{
	d++;
	if(n==27||n==0){
		return 0;
	}
	if(ar[n][0]==r||ar[n][1]==r){
		return d;
	}
	int res;
    if((res=dfs(ar[n][0],r,d))!=0){
		return res;
	};
    if((res=dfs(ar[n][1],r,d))!=0){
		return res;
	};
	return 0;
}
int main()
{
	//std::fstream fin("1.txt");
	while (std::cin>>m>>n&&m&&n){
		for(int i=0;i!=m;i++){
			std::cin>>str;
			for(int i=1;i!=3;i++){
				if(str[i]=='-'){
					ar[str[0]-'A'+1][i-1]=27;
				}else{
					ar[str[0]-'A'+1][i-1]=str[i]-'A'+1;
				}
			}
		}

		int res,r;
		bool flag=false;
		for(int i=0;i!=n;i++){
			std::cin>>str;
			if((res=dfs((str[0]-'A'+1),str[1]-'A'+1,0))!=0){
				if(res==1){
					std::cout<<"child"<<std::endl;
				}else if(res==2){
					std::cout<<"grandchild"<<std::endl;
				}else{
					for(int i=0;i!=res-2;i++){
						std::cout<<"great-";
					}
					std::cout<<"grandchild"<<std::endl;
				}
			}else if((res=dfs(str[1]-'A'+1,str[0]-'A'+1,0))!=0){
				if(res==1){
					std::cout<<"parent"<<std::endl;
				}else if(res==2){
					std::cout<<"grandparent"<<std::endl;
				}else{
					for(int i=0;i!=res-2;i++){
						std::cout<<"great-";
					}
					std::cout<<"grandparent"<<std::endl;
				}
			}else{
				std::cout<<"-"<<std::endl;
			}

		}

		memset(ar,0,sizeof(ar));
	}
}