#include <stdio.h>
#include <string.h>

unsigned char Memory[32];
unsigned char Input[32][9];
unsigned char accu, pc;
unsigned char temp;

int main()
{
    int i, j;
    unsigned char mask;

    while(1){
        for(i = 0; i < 32; i++){
            if(gets(&Input[i][0]) == NULL) return 0;
            Memory[i] = 0;
            for(j = 0; j < 8; j++) Memory[i] = (Memory[i] << 1) + (Input[i][j] - '0');
        }
        pc = accu = 0;
        while(1){
            temp = Memory[pc++];
            if(pc > 0x1F) pc = 0;
            switch(temp >> 5){
            case 0:
                Memory[temp & 0x1F] = accu;
                break;
            case 1:
                accu = Memory[temp & 0x1F];
                break;
            case 2:
                if(accu == 0) pc = temp & 0x1F;
                break;
            case 3:
                break;
            case 4:
                accu--;
                break;
            case 5:
                accu++;
                break;
            case 6:
                pc = temp & 0x1F;
                break;
            case 7:
                break;
            }
            if((temp >> 5) == 7) break;
        }

        mask = 0x80;
        for(i = 0; i < 8; i++){
            putchar((accu & mask) ? '1' : '0');
            mask = mask >> 1;
        }
        putchar('/n');
    }
}