1 #include <iostream>
 2 using namespace std;
 3 int n, m;
 4 int arr[1000];
 5 
 6 int gcd(int a, int b) //求出最大公约数
 7 {
 8     if(b)
 9         return gcd(b, a % b);
10     else 
11         return a;
12 }
13 int lcm(int a, int b)  //注意这里不能用a*b/gcd(a,b)，数据会溢出
14 {
15     return a  / gcd(a, b) * b;
16 }
17 int main()
18 {
19     while(scanf("%d", &n) != EOF)
20     {
21         while(n--){
22             scanf("%d", &m);
23             int first;
24             scanf("%d", &first);
25             for (int i = 1; i < m; i++)   //两两计算最小公倍数
26             {
27                 scanf("%d", &arr[i]);
28                 first = lcm(first, arr[i]);
29             }
30             printf("%d\n", first);
31         }
32     }
33 }