#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
struct strCmp
{
bool operator()(const char s1 ,const char s2) const
{
   return s1 < s2;
}
};

int main()
{
//   freopen("in.txt","r",stdin);
string start;
string end;
string mess;
map< char , char> rule;
rule['A'] = 'V';
rule['B'] = 'W';
rule['C'] = 'X';
rule['D'] = 'Y';
rule['E'] = 'Z';
rule['F'] = 'A';
rule['G'] = 'B';
rule['H'] = 'C';
rule['I'] = 'D';
rule['J'] = 'E';
rule['K'] = 'F';
rule['L'] = 'G';
rule['M'] = 'H';
rule['N'] = 'I';
rule['O'] = 'J';
rule['P'] = 'K';
rule['Q'] = 'L';
rule['R'] = 'M';
rule['S'] = 'N';
rule['T'] = 'O';
rule['U'] = 'P';
rule['V'] = 'Q';
rule['W'] = 'R';
rule['X'] = 'S';
rule['Y'] = 'T';
rule['Z'] = 'U';
while(cin >> start)
{
     if(start == "ENDOFINPUT" )
    break;
   while(1)
   {
   getline(cin,mess);
   if(mess.length() != 0)
   break;
   }

        for(int i=0 ;i<mess.length() ;i++)
        if(mess[i] >= 'A' && mess[i] <= 'Z')
   cout << rule[mess[i]];
   else
   cout << mess[i];
   cout << endl;
   cin >> end;

}
}