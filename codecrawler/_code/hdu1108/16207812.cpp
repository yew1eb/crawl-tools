#include<iostream>
#include<algorithm>
int x,y;

int lcd(int x, int y)
{
    
    if(x<y){
        std::swap(x,y);
    }
    if(y==0){
        return  x;
    }
    lcd(y,x%y);
}

int  lcm(int x,int y)
{
    return (x*y)/lcd(x,y);
}


int main()
{
    while(std::cin>>x>>y){
        std::cout<<lcm(x,y)<<std::endl;
    }
}