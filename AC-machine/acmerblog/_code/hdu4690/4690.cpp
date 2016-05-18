#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn = 10000005;

struct sss
{
      char s[50];
};
sss ss[16][16]=
{
"NUL"    ,"SOH","STX","ETX"," ","HT"," ","DEL",    " ",    " ",    " "    ,"VT"    ,"FF",    "CR",    "SO"    ,"SI",
"DLE",    "DC1"    ,"DC2",    "DC3",    " ",    " ",    "BS",    " ",    "CAN"    ,"EM",    " " ,    " ",    "IFS",    "IGS"    ,"IRS",    "IUS ITB",
" ",    " ",    " "    ," ",    " ",    "LF",    "ETB"    ,"ESC",    " ",    " ",    " ",    " ",    " ",    "ENQ","ACK"    ,"BEL",
" "," ",    "SYN",    " " ,    " ",    " ",    " ",    "EOT"    ," ",    " ",    " ",    " ",    "DC4" ,"NAK",    " "    ,"SUB",
"SP",    " ",    " ",    " ",    " "    ," ",    " ",    " ",    " ",    " ",    " "    ,"."    ,"<",    "(",    "+",    "|",
"&",      " ",    " ",   " "    ," ",    " "    ," "    ," ",    " ",    " ",    "!",    "$",    "*",    ")",    ";"    ," ",
"-",    "/"    ," ",    " ",    " ",    " "," ",    " ",    " ",    " ",    " ",    ",",    "%%",    "_",    ">",    "?",
" ",    " "," ",    " "    ," "    ," " ,     " ",    " "    ," ",    "`"    ,":"    ,"#",    "@",    "'",    "=",    "\"",
" ",    "a",    "b",    "c"    ,"d",    "e"    ,"f",    "g",    "h",    "i",   " ",    " ",    " "    ," ",    " ",    " "    ,
" ",    "j",    "k",    "l",    "m",    "n"    ,"o"    ,"p"    ,"q",    "r" ,  " ",   " ",    " "    ," "    ," ",    " "    ,
" ",    "~",    "s",    "t",    "u",    "v",    "w",    "x",    "y"    ,"z" ,  " " ,  " " ,  " " ,  " " ,  " "  , " ",
"^"   ," "  , " ",   " " ,  " " ,  " "  , " " ,  " ",   " " , " ", "["  , "]",     " ",    " ",    " ",    " "    ,
"{"    ,"A",    "B"    ,"C",    "D",    "E"    ,"F"    ,"G",    "H"    ,"I" ,  " "    ," "    ," "    ," ",    " ",    " "    ,
"}",    "J",    "K",    "L",    "M",    "N",    "O",    "P"    ,"Q"    ,"R"  , " ",    " ",    " ",    " ",    " ",    " ",
"\\",    " ",    "S",    "T",    "U",    "V",    "W",    "X",    "Y",    "Z" ,  " ",    " "    ," "    ," ",    " ",    " ",
"0",    "1",    "2",    "3"    ,"4",    "5",    "6",    "7",    "8",    "9", " ", " ", " ", " ", " ", " "
};
sss tt[8][16] =
{
"NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL", "BS",  "HT",  "LF",  "VT",  "FF",  "CR",  "SO",  "SI",
"DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB", "CAN", "EM",  "SUB", "ESC", "IFS", "IGS", "IRS", "IUS ITB",
"SP",  "!",   "\"",  "#",   "$",   "%%",   "&",   "'",   "(",   ")",   "*",   "+",   ",",   "-",   ".",   "/",
"0",   "1",   "2",   "3",   "4",   "5",   "6",   "7",   "8",   "9",   ":",   ";",   "<",   "=",   ">",   "?",
"@",   "A",   "B",   "C",   "D",   "E",   "F",   "G",   "H",   "I",   "J",   "K",   "L",   "M",   "N",   "O",
"P",   "Q",   "R",   "S",   "T",   "U",   "V",   "W",   "X",   "Y",   "Z",   "[",   "\\",   "]",  "^",   "_",
"`",   "a",   "b",   "c",   "d",   "e",   "f",   "g",   "h",   "i",   "j",   "k",   "l",   "m",   "n",   "o",
"p",   "q",   "r",   "s",   "t",   "u",   "v",   "w",   "x",   "y",   "z",   "{",   "|",   "}",   "~",   "DEL"
};
struct daan
{
      char a,b;
}ans[20][20];
void init()
{
      for (int i=0;i<16;i++)
            for (int j=0;j<16;j++)
                  if (strcmp(ss[i][j].s," ") != 0)
            {
                  for (int a=0;a<8;a++)
                  for (int b=0;b<16;b++)
                        if (strcmp(ss[i][j].s , tt[a][b].s) == 0)
                  {
                        char ch1 , ch2 ;
                        ch1 = '0' + a;
                        if (b >= 10)ch2 = (char)(b - 10 + 'A');
                        else ch2 = (char)(b + '0');
                        ans[i][j].a = ch1;
                        ans[i][j].b = ch2;
                  }
            }
}
char temp[10000006];
void show()
{
      for (int i=0;i<=15;i++)
      {
            for (int j=0;j<=15;j++)
                  printf("%c%c ",ans[i][j].a,ans[i][j].b);
            printf("\n");
      }
}
int main()
{
      init();
 //     show();
      gets(temp);
            int len = strlen(temp);
            for (int i=0;i<len;i+=2)
            {
                  char a = temp[i];
                  char b = temp[i+1];
                  int t1 , t2;
                  if (a >= 'A' && a <= 'Z')t1 = 10 + a - 'A';
                  else t1 = a - '0';
                  if (b >= 'A' && b <= 'Z')t2 = 10 + b - 'A';
                  else t2 = b - '0';
                  printf("%c%c",ans[t1][t2].a,ans[t1][t2].b);
            }
            printf("\n");
      return 0;
}