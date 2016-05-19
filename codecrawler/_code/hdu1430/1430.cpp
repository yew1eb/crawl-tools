#include <cstdio>
 #include <iostream>
 #include <algorithm>
 #include <cstring>
 #include <map>
 #include <stack>
 #include <string>
 
 using namespace std;
 
 char q[44444][10], op[44444], tmp[10];
 int qh, qt, last[44444];
 map<string, int> pos;
 
 void op1(char *s) { reverse(s, s + 8);}
 
 void op2(char *s, bool op) {
     if (op) {
         rotate(s, s + 3, s + 4);
         rotate(s + 4, s + 5, s + 8);
     } else {
         rotate(s, s + 1, s + 4);
         rotate(s + 4, s + 7, s + 8);
     }
 }
 
 void op3(char *s, bool op) {
     char t;
     if (op) {
         t = s[1];
         s[1] = s[6];
         s[6] = s[5];
         s[5] = s[2];
         s[2] = t;
     } else {
         t = s[1];
         s[1] = s[2];
         s[2] = s[5];
         s[5] = s[6];
         s[6] = t;
     }
 }
 
 void PRE() {
     for (int i = 0; i < 8; i++) tmp[i] = i + '0';
     tmp[8] = 0;
     pos.clear();
     qh = qt = 0;
 
     strcpy(q[qt], tmp);
     pos[tmp] = qt;
     last[qt] = -1;
     op[qt++] = 0;
     while (qh < qt) {
         strcpy(tmp, q[qh]);
         op1(tmp);
         if (pos.find(tmp) == pos.end()) {
             strcpy(q[qt], tmp);
             pos[tmp] = qt;
             last[qt] = qh;
             op[qt++] = 'A';
         }
 
         strcpy(tmp, q[qh]);
         op2(tmp, true);
         if (pos.find(tmp) == pos.end()) {
             strcpy(q[qt], tmp);
             pos[tmp] = qt;
             last[qt] = qh;
             op[qt++] = 'B';
         }
 
         strcpy(tmp, q[qh]);
         op3(tmp, true);
         if (pos.find(tmp) == pos.end()) {
             strcpy(q[qt], tmp);
             pos[tmp] = qt;
             last[qt] = qh;
             op[qt++] = 'C';
         }
 
         qh++;
     }
 }
 
 int main() {
 //    freopen("in", "r", stdin);
     PRE();
     char bg[10], ed[10], con[10];
     while (cin >> bg >> ed) {
         for (int i = 0; i < 8; i++) {
             int t = 0;
             while (bg[i] != ed[t]) t++;
             con[t] = i + '0';
         }
         con[8] = 0;
         int cur = pos[con];
         stack<char> path;
         while (!path.empty()) path.pop();
         while (cur) {
             path.push(op[cur]);
             cur = last[cur];
         }
         while (!path.empty()) {
             putchar(path.top());
             path.pop();
         }
         puts("");
     }
     return 0;
 }