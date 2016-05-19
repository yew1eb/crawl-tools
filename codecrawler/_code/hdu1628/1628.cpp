#include <iostream>
#include <vector>
using namespace std;
int main(void) {
    //循环处理每一行输入的数据
    for (int n, k; cin >> n >> k && n * k != 0; ) {
        vector<int> Circle; //将动态数组中存入顺序的编号，从1起
        for (int i = 0; i < n; Circle.push_back(++i));
        //循环杀人，直到只有一个幸存者。m为被杀死人的编号
        for (int m = (k - 1) % Circle.size(), t; Circle.size() != 1; ) {
            //计算埋葬者在数组中的位置，人数按已杀死m号人后计算
            t = (m - 1 + k) % (Circle.size() - 1);
            //如果t在m的后面，则要加1(数组尺寸在此时并未改变)
            t = (t + (t >= m)) % Circle.size();
            Circle[m] = Circle[t]; //将埋葬者移动到被杀死人的位置上
            Circle.erase(Circle.begin() + t); //删除原埋葬者的位置
            //继续向后数k个人，做下一次循环
            m = (m - (t < m) + k) % Circle.size();
        } //换算后输出结果
        cout << (n - Circle.front() + 1) % n + 1 << endl;
    }
    return 0;
}