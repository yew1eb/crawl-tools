#include <iostream>
#include <string>
#include <list>
#include  <vector>
#include <set>
#include <algorithm>
#include <fstream>

struct passger
{
	friend bool operator<(const passger& l,const passger& r);
	std::string name;
	int rp;
};

bool operator<(const passger& l,const passger& r)
{
	if(l.rp<r.rp){
		return true;
	}else if(l.rp==r.rp){
		return l.name>r.name;
	}
	return false;
}

struct car
{
	std::vector<passger> pas;
	int num;
};

car unit;

std::list<car > train;
typedef std::list<car >::iterator tritr_t; 
typedef std::vector<passger>::iterator psitr_t;

tritr_t itr,itr2;
psitr_t psitr;
int n,m,xi;
std::string command;
passger tmp;
std::string nm;
int var1,var2;

bool pr_insert(std::vector<passger>& vec, passger& tmp)
{
	psitr_t psitr;
	if(tmp<vec[0]){
		itr->pas.insert(vec.begin(),tmp);
		return true;
	}else{
		for(psitr=vec.begin();psitr!=vec.end();psitr++){
			if(*psitr<tmp){
				continue;
			}else{
				vec.insert(psitr+1,tmp);
			}
		}
		if(psitr==vec.end()){
			vec.push_back(tmp);
		}
		return true;
	}
	return false;

}
   int main()
{
//	std::ifstream fi("1.txt"); 
	while (std::cin>>n>>m){
		for(int i=0;i!=n;i++){
			std::cin>>xi;
			for(int j=0;j!=xi;j++){
				std::cin>>tmp.name>>tmp.rp;
				unit.pas.push_back(tmp);
			}
			std::sort(unit.pas.begin(),unit.pas.end());
			unit.num=i;
			train.push_back(unit);
			unit.pas.clear();
		}

		for(int i=0;i!=m;i++){
			std::cin>>command;
			if(command=="GETON"){

				std::cin>>var1>>tmp.name>>tmp.rp;
				for(itr=train.begin();itr!=train.end();itr++){
					if(itr->num==var1-1){

				         pr_insert(itr->pas,tmp);
					}
				}
			}else if(command=="GETOUT"){

				std::cin>>var1;
				for(itr=train.begin();itr!=train.end();itr++){
					if(itr->num==var1-1){
						std::cout<<itr->pas[0].name<<std::endl;
						itr->pas.erase(itr->pas.begin());
						break;
					}
				}
			}else if(command=="JOIN"){

				std::cin>>var1>>var2;
				for(itr=train.begin();itr!=train.end();itr++){
					if(itr->num==var1-1){
						break;
					}
				}
				for(itr2=train.begin();itr2!=train.end();itr2++){
					if(itr2->num==var2-1){
						for(psitr=itr2->pas.begin();psitr!=itr2->pas.end();psitr++){
							pr_insert(itr->pas,*psitr);
						}
						train.erase(itr2);
						break;
					}
				}
			}
		}

		train.clear();
	}
}