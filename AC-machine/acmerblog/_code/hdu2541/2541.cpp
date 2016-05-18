/*
*Time: 93ms
*题目大意：
*        求i+(i+1)+(i+2)的结果对于有没有进位，没有进位的称为Simple Addition Expression
*        给定一个n,求i < n有多少个数可以称为simple Addition Expression.
*解题思路：
*        总共有786432个符合要求的数据。所以可以用暴力。
*        求出所有的满足的simple Addition Expression的数。之后用二分查找位置即可。
*/