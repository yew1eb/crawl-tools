#include <iostream>  
#include <set>  
#include <string>  
#include <sstream>// ä¸è¦å¿è®°äº 

using namespace std;  

int main() {  
    string art;  
    while(getline(cin,art) && art != "#"){  
        istringstream stream(art);  
        string word;  
        set<string> map;  
        while(stream >>word){  
            map.insert(word);  
        }  
        cout <<map.size() <<endl;  
    }  
    return 0;  
}