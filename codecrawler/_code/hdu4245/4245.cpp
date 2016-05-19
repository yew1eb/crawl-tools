#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,string>m;
void ini()
{
	m["A"]="";
	m["A#"]="Bb";
	m["Bb"]="A#";
	m["B"]="";
	m["C"]="";
	m["C#"]="Db";
	m["Db"]="C#";
	m["D"]="";
	m["D#"]="Eb";
	m["Eb"]="D#";
	m["E"]="";
	m["F"]="";
	m["F#"]="Gb";
	m["Gb"]="F#";
	m["G"]="";
	m["G#"]="Ab";
	m["Ab"]="G#";
}
int main()
{
	int i=1;;
	string s,ss,sss;
	ini();
	while(cin>>s>>ss)
	{
		sss=m[s];
		if(sss.size()==0)
			cout<<"Case "<<i++<<": UNIQUE"<<endl;
		else cout<<"Case "<<i++<<": "<<sss<<" "<<ss<<endl;
	}
	return 0;
}