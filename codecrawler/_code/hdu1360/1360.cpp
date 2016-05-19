#include <iostream>
#include <cctype>
using namespace std;
int main()
{
    int word=0,sentence=0,mistakes=0,c;   
    while( ( c=getchar() ) != EOF )
    {
        if(word==0)
        {
            if(isalpha(c))        // word头一个字母
                word=1;
        }
        else
        {
            if(isalpha(c))        // word中不是头一个字母
            {
                if(isupper(c))
                    mistakes++;
            }
            else
                word=0;
        }        
        if(sentence==0)
        {
            if(isalpha(c))        // 句首的第一个字母
            {
                sentence=1;
                if(islower(c))
                    mistakes++;
            }
        }
        else if(c=='.' || c=='?' || c=='!')    // 遇到结束标点 本句结束
  sentence=0;
    }  
    cout<<mistakes<<endl; 
    return 0;
}