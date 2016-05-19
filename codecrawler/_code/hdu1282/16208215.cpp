#include<iostream>
#include<vector>
int n;
int rn;
int idx;
int tmp;
std::vector<int> trans;

int main()
{
    while (std::cin>>n){
        trans.push_back(n);
        while (true){
            tmp=n;
            while (tmp!=0){
                rn*=10;
                rn+=tmp%10;
                tmp/=10;
            }
            if(n==rn){
                break;
            }
            n+=rn;
            rn=0;
            trans.push_back(n);
            idx++;
        }

        std::cout<<idx<<std::endl;
        for(int i=0;i!=trans.size();i++){
            if(i!=trans.size()-1){
                std::cout<<trans[i]<<"--->";
            }else{
                std::cout<<trans[i]<<std::endl;
            }
        }

        n=rn=idx=0;
        trans.clear();
    }
}