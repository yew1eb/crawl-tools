
#include <stdio.h>
#include <queue>
using namespace std;
int trans(char c) {
    if(c >= '0' && c <= '9')
        return c-'0';
    if(c == 'A')    return 1;
    if(c == 'T')    return 10;
    if(c == 'J')    return 11;
    if(c == 'Q')    return 12;
    if(c == 'K')    return 13;
}
int main() {
    char s[50];
    int card[52];
    int i;
    while(true) {
        for(i = 0; i < 52; i++) {
            scanf("%s", s);
            if(s[0] == '#') return 0;
            card[i] = trans(s[1]);
        }
        queue<int> A, B;
        for(i = 51; i >= 0; i--) {
            if(i%2) A.push(card[i]);
            else    B.push(card[i]);
        }
        int turn = 1;//0 A, 1 B
        int judge = -1;
        queue<int> H;//heap
        while(true) {
            if(turn == 0 && A.empty()) {
                judge = 0;
                break;
            }
            if(turn == 1 && B.empty()) {
                judge = 1;
                break;
            }
            int CARD;
            if(turn == 0)
                CARD = A.front(), A.pop();
            else
                CARD = B.front(), B.pop();
            //printf("%d - %c %d %d\n", CARD, turn+'A', A.size(), B.size());
            H.push(CARD);
            turn = 1-turn;
            int ended = 1;
            while(CARD >= 11 || CARD == 1) {
                ended = 0;
                int paid;
                if(CARD == 1)   paid = 4;
                else if(CARD == 11)   paid = 1;
                else if(CARD == 12)   paid = 2;
                else if(CARD == 13)   paid = 3;
                for(i = 0; i < paid; i++) {
                    if(turn == 0 && A.empty()) {
                        judge = 0;
                        break;
                    }
                    if(turn == 1 && B.empty()) {
                        judge = 1;
                        break;
                    }
                    if(turn == 0)
                        CARD = A.front(), A.pop();
                    else
                        CARD = B.front(), B.pop();
                    H.push(CARD);
                    //printf("%d - %c\n", CARD, turn+'A');
                    if(CARD == 1 || CARD >= 11)//change
                        break;
                }
                if(judge >= 0)  break;
                turn = 1-turn;
            }
            if(judge >= 0)  break;
            if(ended == 0) {
                if(turn == 0) {
                    while(!H.empty()) {
                        A.push(H.front());
                        H.pop();
                    }
                } else {
                    while(!H.empty()) {
                        B.push(H.front());
                        H.pop();
                    }
                }
            }
        }
        printf("%d%3d\n", 2-judge, judge ? A.size() : B.size());
    }
    return 0;
}