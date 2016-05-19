HDU ACM 1222 Wolf and Rabbit
##原题描述
###Problem Description
There is a hill with n holes around. The holes are signed from 0 to n-1.

![image](http://acm.hdu.edu.cn/data/images/C9-1004-1.jpg)

A rabbit must hide in one of the holes. A wolf searches the rabbit in anticlockwise order. The first hole he get into is the one signed with 0. Then he will get into the hole every m holes. For example, m=2 and n=6, the wolf will get into the holes which are signed 0,2,4,0. If the rabbit hides in the hole which signed 1,3 or 5, she will survive. So we call these holes the safe holes.
###Input
The input starts with a positive integer P which indicates the number of test cases. Then on the following P lines,each line consists 2 positive integer m and n(0&lt;m,n&lt;2147483648).
###Output
For each input m n, if safe holes exist, you should output "YES", else output "NO" in a single line.
###Sample Input
2
1 2
2 2
###Sample Output
NO
YES

##解题思路

##参考代码
```C++
```