#include<iostream>
#include<string>
using namespace std;

string irrwords1[23];
string irrwords2[23];
int L,N;

int Find(string s)
{
    int i;
    for(i=0;i<L;i++)
    {
        if(irrwords1[i].compare(s)==0)
            return i;
    }
    return -1;
}
int main()
{
    int i;
    string strcin;

    while(cin>>L>>N)
    {        
        for(i=0;i<L;i++)
            cin>>irrwords1[i]>>irrwords2[i];

        for(i=0;i<N;i++)
        {
            cin>>strcin;
            if(Find(strcin)!=-1)  //irregulate words
            {
                cout<<irrwords2[Find(strcin)]<<endl;
            }
            else 
            {
                if(strcin[strcin.length()-1]=='y'&&strcin[strcin.length()-2]!='a'
                    &&strcin[strcin.length()-2]!='e'&&strcin[strcin.length()-2]!='i'
                    &&strcin[strcin.length()-2]!='o'&&strcin[strcin.length()-2]!='u')
                {  // in a consonant followed by "y"
                    strcin=strcin.substr(0,strcin.length()-1);
                    strcin=strcin+"ies";
                }
                else if(strcin[strcin.length()-1]=='o'||strcin[strcin.length()-1]=='s'
                    ||strcin[strcin.length()-1]=='x')
                {
                    strcin=strcin+"es";
                }
                else if(strcin[strcin.length()-1]=='h'&&(strcin[strcin.length()-2]=='c'||strcin[strcin.length()-2]=='s'))
                {
                    strcin=strcin+"es";
                }
                else 
                    strcin=strcin+"s";

                cout<<strcin<<endl;
            }    
        }

        for(i=0;i<23;i++)
        {
            irrwords1[i]="";
            irrwords2[i]="";
        }
    }

    return 0;
}