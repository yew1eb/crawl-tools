#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
struct POINT {int x; int y;};
//判断两点是否相等
bool operator==(const POINT &p1, const POINT &p2) {
    return (p1.x == p2.x && p1.y == p2.y);
}
//比较两点坐标大小，先比较x坐标，若相同则比较y坐标
bool operator>(const POINT &p1, const POINT &p2) {
    return (p1.x > p2.x || (p1.x == p2.x && p1.y > p2.y));
}
//计算两向量外积
int operator^(const POINT &p1, const POINT &p2) {
    return (p1.x * p2.y - p1.y * p2.x);
}
//计算两向量内积
int operator*(const POINT &p1, const POINT &p2) {
    return (p1.x * p2.x + p1.y * p2.y);
}
// 比较向量中哪个与x轴向量(1, 0)的夹角更大
bool CompareVector(const POINT &pt1, const POINT &pt2) {
    //求向量的模
    float m1 = sqrt((float)(pt1.x * pt1.x + pt1.y * pt1.y));
    float m2 = sqrt((float)(pt2.x * pt2.x + pt2.y * pt2.y));
    //两个向量分别与(1, 0)求内积
    float v1 = pt1.x / m1, v2 = pt2.x / m2;
    //如果向量夹角相等，则返回离基点较近的一个，保证有序
    return (v1 > v2 || v1 == v2 && m1 < m2);
}
//计算凸包
bool CalcConvexHull(vector<POINT> &Src) {
    //点集中至少应有3个点，才能构成多边形
    if (Src.size() < 3) {
        return false;
    }
    //查找基点
    vector<POINT>::iterator i;
    POINT ptBase = Src.front(); //将第1个点预设为最小点
    for (i = Src.begin() + 1; i != Src.end(); ++i) {
        //如果当前点的y值小于最小点，或y值相等，x值较小
        if (i->y < ptBase.y || (i->y == ptBase.y && i->x > ptBase.x)) {
            //将当前点作为最小点
            ptBase = *i;
        }
    }
    //计算出各点与基点构成的向量
    for (i = Src.begin(); i != Src.end();) {
        //排除与基点相同的点，避免后面的排序计算中出现除0错误
        if (*i == ptBase) {
            i = Src.erase(i);
        }
        else {
            //方向由基点到目标点
            i->x -= ptBase.x, i->y -= ptBase.y;
            ++i;
        }
    }
    //按各向量与横坐标之间的夹角排序
    sort(Src.begin(), Src.end(), &CompareVector);
    //删除相同的向量
    Src.erase(unique(Src.begin(), Src.end()), Src.end());
    //点集中至少还剩2个点，加上基点才能构成多边形
    if (Src.size() < 2) {
        return false;
    }
    //计算得到首尾依次相连的向量
    for (vector<POINT>::reverse_iterator ri = Src.rbegin();
        ri != Src.rend() - 1; ++ri) {
        vector<POINT>::reverse_iterator riNext = ri + 1;
        //向量三角形计算公式
        ri->x -= riNext->x, ri->y -= riNext->y;
    }
    //依次删除不在凸包上的向量
    for (i = Src.begin() + 1; i != Src.end(); ++i) {
        //回溯删除旋转方向相反的向量，使用外积判断旋转方向
        for (vector<POINT>::iterator iLast = i - 1; iLast != Src.begin();) {
            int nCross = *i ^ *iLast;
            //如果叉积小于0，则没有逆向旋转
            //如果叉积等于0，还需用内积判断方向是否相逆
            if (nCross < 0 || (nCross == 0 && i->x * iLast->x > 0 &&
                i->y * iLast->y > 0)) {
                    break;
            }
            //删除前一个向量后，需更新当前向量，与前面的向量首尾相连
            //向量三角形计算公式
            i->x += iLast->x, i->y += iLast->y;
            iLast = (i = Src.erase(iLast)) - 1;
        }
    }
    //将所有首尾相连的向量依次累加，换算成坐标
    Src.front().x += ptBase.x, Src.front().y += ptBase.y;
    for (i = Src.begin() + 1; i != Src.end(); ++i) {
        i->x += (i - 1)->x, i->y += (i - 1)->y;
    }
    //添加基点，全部的凸包计算完成
    Src.push_back(ptBase);
    return (Src.size() >= 3);
}

//主函数
int main(void) {
    while (true) {
        string Name;
        while (Name.empty()) {
            getline(cin, Name);
        }
        if (Name[0] == '#') {
            break;
        }
        POINT Mass;
        cin >> Mass.x >> Mass.y;
        vector<POINT> Poly, Convex;
        for(POINT pt; cin >> pt.x >> pt.y && pt.x != 0 && pt.y != 0;) {
            Poly.push_back(pt);
        }
        Convex = Poly;
        if (!CalcConvexHull(Convex)) *(int*)0 = 0;
        //删除删除凸包边上多余的点
        for (int i = 0; i < (int)Convex.size(); ++i) {
            int j = (i + 1) % Convex.size();
            int k = (j + 1) % Convex.size();
            POINT v1 = {Convex[j].x - Convex[i].x, Convex[j].y - Convex[i].y};
            POINT v2 = {Convex[k].x - Convex[j].x, Convex[k].y - Convex[j].y};
            //外积为0表示共线，可以删除
            if ((v1 ^ v2) == 0) {
                //删除中间的点
                Convex.erase(Convex.begin() + j);
                --i; //这一次先不将i递增
            }
        }
        int nMin = Poly.size();
        //遍例凸包的每一条边
        for (int i = 0; i < (int)Convex.size(); ++i) {
            int j = (i + 1) % (int)Convex.size();
            //构造重心到该边两个顶点的向量
            POINT v1 = {Mass.x - Convex[i].x, Mass.y - Convex[i].y};
            POINT v2 = {Mass.x - Convex[j].x, Mass.y - Convex[j].y};
            POINT s1 = {Convex[j].x - Convex[i].x, Convex[j].y - Convex[i].y};
            POINT s2 = {Convex[i].x - Convex[j].x, Convex[i].y - Convex[j].y};
            //先作外积，判断重心是否在内侧
            //再作内积，判断重心是否在两端点之间
            if ((s1 ^ v1) >= 0 && v1 * s1 >= 0 && v2 * s2 >= 0) {
                int nMax = 0;
                //查找原多边形中在该边上的点
                for (int k = 0; k < (int)Poly.size(); ++k) {
                    //利用外积判断是否点在线上
                    s2.x = Poly[k].x - Convex[i].x;
                    s2.y = Poly[k].y - Convex[i].y;
                    if ((s2 ^ s1) == 0) {
                        //找出该边的编号(边上所有点编号的最大值)
                        nMax = max(k, nMax);
                    }
                }
                //找出编号最小的边
                nMin = min(nMin, nMax);
            }
        }
        //输出结果，编号从1开始
        cout << Name << ' ' << nMin + 1 << endl;
    }
    return 0;
}