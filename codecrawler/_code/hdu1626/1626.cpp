#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
int main(void) {
    typedef unsigned short word;
    char Bits[1032]; //存储输入的字符串
    cin.sync_with_stdio(false); //输入的数据量很大，关闭同步以加速
    cout << setbase(16) << setiosflags(ios::uppercase) << setfill('0');
    //循环处理输入的每一行字符串
    for (string Line; getline(cin, Line) && Line[0] != '#'; cout << endl) {
        word nGen = 34943, nLen = Line.length(), *pBit = (word*)Bits;
        //将字符串转存到静态数组中。x86的CPU字节序为little-endian，
        reverse_copy(Line.begin(), Line.end(), Bits); //反转为正字节序
        *(word*)(&Bits[nLen]) = 0; //将结尾后面的一些位都清零
        nLen = nLen / 2 + (nLen % 2 != 0); //计算作为int数组的长度
        long nRem = 0;//nRem表示余数
        //循环除所有的位，累加进位的余数，生成CRC码
        for (int i = nLen - 1; i >= 0; --i) {
            nRem = ((nRem << 16) + pBit[i]) % nGen;
        }
        if (nRem != 0) { //如果余数不为0，则需构造CRC码，算法见文档
            nRem = nGen - (nRem << 16) % nGen;
        } //下面按要求的格式输出CRC码
        unsigned char* pByte = (unsigned char*)&nRem;
        cout << setw(2) << (int)pByte[1] << ' ' << setw(2) << (int)pByte[0];
    }
    return 0;
}