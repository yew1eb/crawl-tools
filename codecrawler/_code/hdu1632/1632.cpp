#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct POINTF {
    float x; float y;
};
//保证精度，两个淫点数之差小于0.0001的认为相等
bool Equal(float f1, float f2) {
    return (abs(f1 - f2) < 1e-4f);
}
//判断两点是否相等
bool operator==(const POINTF &p1, const POINTF &p2) {
    return (Equal(p1.x, p2.x) && Equal(p1.y, p2.y));
}
//比较两点坐标大小，先比较x坐标，若相同则比较y坐标
bool operator>(const POINTF &p1, const POINTF &p2) {
    return (p1.x > p2.x || (Equal(p1.x, p2.x) && p1.y > p2.y));
}
//计算两向量外积
float operator^(const POINTF &p1, const POINTF &p2) {
    return (p1.x * p2.y - p1.y * p2.x);
}

//判定两线段位置关系，并求出交点(如果存在)。
//有重合：完全重合(6)，1个端点重合且共线(5)，部分重合(4)
//无重合：两端点相交(3)，交于线上(2)，正交(1)，无交(0)，参数错误(-1)
int Intersection(POINTF p1, POINTF p2, POINTF p3, POINTF p4, POINTF &Int) {
    //保证参数p1!=p2，p3!=p4
    if (p1 == p2 || p3 == p4) {
        return -1; //返回-1代表至少有一条线段首尾重合，不能构成线段
    }
    //为方便运算，保证各线段的起点在前，终点在后。
    if (p1 > p2) {
        swap(p1, p2);
    }
    if (p3 > p4) {
        swap(p3, p4);
    }
    //求出两线段构成的向量
    POINTF v1 = {p2.x - p1.x, p2.y - p1.y}, v2 = {p4.x - p3.x, p4.y - p3.y};
    //求两向量外积，平行时外积为0
    float Corss = v1 ^ v2;
    //判定两线段是否完全重合
    if (p1 == p3 && p2 == p4) {
        return 6;
    }
    //如果起点重合
    if (p1 == p3) {
        Int = p1;
        //起点重合且共线(平行)返回5；不平行则交于端点，返回3
        return (Equal(Corss, 0) ? 5 : 3);
    }
    //如果终点重合
    if (p2 == p4) {
        Int = p2;
        //终点重合且共线(平行)返回5；不平行则交于端点，返回3
        return (Equal(Corss, 0) ? 5 : 3);
    }
    //如果两线端首尾相连
    if (p1 == p4) {
        Int = p1;
        return 3;
    }
    if (p2 == p3) {
        Int = p2;
        return 3;
    }//经过以上判断，首尾点相重的情况都被排除了
    //将线段按起点坐标排序。若线段1的起点较大，则将两线段交换
    if (p1 > p3) {
        swap(p1, p3);
        swap(p2, p4);
        //更新原先计算的向量及其外积
        swap(v1, v2);
        Corss = v1 ^ v2;
    }
    //处理两线段平行的情况
    if (Equal(Corss, 0)) {
        //做向量v1(p1, p2)和vs(p1,p3)的外积，判定是否共线
        POINTF vs = {p3.x - p1.x, p3.y - p1.y};
        //外积为0则两平行线段共线，下面判定是否有重合部分
        if (Equal(v1 ^ vs, 0)) {
            //前一条线的终点大于后一条线的起点，则判定存在重合
            if (p2 > p3) {
                Int = p3;
                return 4; //返回值4代表线段部分重合
            }
        }//若三点不共线，则这两条平行线段必不共线。
        //不共线或共线但无重合的平行线均无交点
        return 0;
    } //以下为不平行的情况，先进行快速排斥试验
    //x坐标已有序，可直接比较。y坐标要先求两线段的最大和最小值
    float ymax1 = p1.y, ymin1 = p2.y, ymax2 = p3.y, ymin2 = p4.y;
    if (ymax1 < ymin1) {
        swap(ymax1, ymin1);
    }
    if (ymax2 < ymin2) {
        swap(ymax2, ymin2);
    }
    //如果以两线段为对角线的矩形不相交，则无交点
    if (p1.x > p4.x || p2.x < p3.x || ymax1 < ymin2 || ymin1 > ymax2) {
        return 0;
    }//下面进行跨立试验
    POINTF vs1 = {p1.x - p3.x, p1.y - p3.y}, vs2 = {p2.x - p3.x, p2.y - p3.y};
    POINTF vt1 = {p3.x - p1.x, p3.y - p1.y}, vt2 = {p4.x - p1.x, p4.y - p1.y};
    float s1v2, s2v2, t1v1, t2v1;
    //根据外积结果判定否交于线上
    if (Equal(s1v2 = vs1 ^ v2, 0) && p4 > p1 && p1 > p3) {
        Int = p1;
        return 2;
    }
    if (Equal(s2v2 = vs2 ^ v2, 0) && p4 > p2 && p2 > p3) {
        Int = p2;
        return 2;
    }
    if (Equal(t1v1 = vt1 ^ v1, 0) && p2 > p3 && p3 > p1) {
        Int = p3;
        return 2;
    }
    if (Equal(t2v1 = vt2 ^ v1, 0) && p2 > p4 && p4 > p1) {
        Int = p4;
        return 2;
    } //未交于线上，则判定是否相交
    if(s1v2 * s2v2 > 0 || t1v1 * t2v1 > 0) {
        return 0;
    } //以下为相交的情况，算法详见文档
    //计算二阶行列式的两个常数项
    float ConA = p1.x * v1.y - p1.y * v1.x;
    float ConB = p3.x * v2.y - p3.y * v2.x;
    //计算行列式D1和D2的值，除以系数行列式的值，得到交点坐标
    Int.x = (ConB * v1.x - ConA * v2.x) / Corss;
    Int.y = (ConB * v1.y - ConA * v2.y) / Corss;
    //正交返回1
    return 1;
}
// 比较向量中哪个与x轴向量(1, 0)的夹角更大
bool CompareVector(const POINTF &pt1, const POINTF &pt2) {
    //求向量的模
    float m1 = sqrt(pt1.x * pt1.x + pt1.y * pt1.y);
    float m2 = sqrt(pt2.x * pt2.x + pt2.y * pt2.y);
    //两个向量分别与(1, 0)求内积
    float v1 = pt1.x / m1, v2 = pt2.x / m2;
    //如果向量夹角相等，则返回离基点较近的一个，保证有序
    return (v1 < v2 || v1 == v2 && m1 < m2);
}
//计算凸包
bool CalcConvexHull(vector<POINTF> &Src) {
    //点集中至少应有3个点，才能构成多边形
    if (Src.size() < 3) {
        return false;
    }
    //查找基点
    vector<POINTF>::iterator i;
    POINTF ptBase = Src.front(); //将第1个点预设为最小点
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
    //计算得到首尾依次相联的向量
    for (vector<POINTF>::reverse_iterator ri = Src.rbegin();
        ri != Src.rend() - 1; ++ri) {
        vector<POINTF>::reverse_iterator riNext = ri + 1;
        //向量三角形计算公式
        ri->x -= riNext->x, ri->y -= riNext->y;
    }
    //依次删除不在凸包上的向量
    for (i = Src.begin() + 1; i != Src.end(); ++i) {
        //回溯删除旋转方向相反的向量，使用外积判断旋转方向
        for (vector<POINTF>::iterator iLast = i - 1; iLast != Src.begin();) {
            float v1 = i->x * iLast->y, v2 = i->y * iLast->x;
            //如果叉积大于0，则没有逆向旋转
            //如果叉积等于0，还需用内积判断方向是否相逆
            if (v1 > v2 || (v1 == v2 && i->x * iLast->x > 0 &&
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
//计算凸多边形面积
float CalcArea(vector<POINTF> &Covex) {
    float fArea = 0;
    vector<POINTF>::iterator i, j;
    //遍例多边形每一个顶点
    for (i = Covex.begin(); i != Covex.end(); ++i) {
        //j为i的下一个顶点
        if ((j = i + 1) == Covex.end()) {
            j = Covex.begin();
        }
        //累加面积
        fArea += j->x * i->y - i->x * j->y;
    }
    return fArea / 2.0f;
}
//判定点是否在多边形内
bool PointInPolygon(POINTF pt, vector<POINTF> &Poly) {
    //遍例多边形每一个顶点
    for (int i = 0; i < (int)Poly.size(); ++i) {
        //j为i的下一个顶点
        int j = (i + 1) % (int)Poly.size();
        //构成由给定点到顶点的向量
        POINTF p1 = {pt.x - Poly[i].x, pt.y - Poly[i].y};
        //构成由当前顶点到下一顶点的向量
        POINTF p2 = {Poly[j].x - Poly[i].x, Poly[j].y - Poly[i].y};
        //根据外积作出判断
        float fCross = p1 ^ p2;
        if (fCross < 0) {
            return false;
        }
    }
    return true;
}

//主函数
int main(void) {
    vector<float> Result;
    //循环读入每一组多边形数据
    for (int nNum; cin >> nNum && nNum != 0; ++nNum) {
        vector<POINTF> Poly1, Poly2;
        for (POINTF pt; nNum-- > 0 && cin >> pt.x >> pt.y; Poly1.push_back(pt));
        cin >> nNum;
        for (POINTF pt; nNum-- > 0 && cin >> pt.x >> pt.y; Poly2.push_back(pt));
        //去掉每个多边形中，相临的重复点
        unique(Poly1.begin(), Poly1.end());
        unique(Poly2.begin(), Poly2.end());
        if (Poly1.size() < 3 || Poly2.size() < 3) {
            printf("%8.2f", 0.0f);
        }
        //计算两多边形的面积和
        float fAreaUnion = CalcArea(Poly1);
        fAreaUnion += CalcArea(Poly2);
        vector<POINTF> IntPoly;
        //添加多边形1在多边形2中的点到交集中
        for (int i = 0; i < (int)Poly1.size(); ++i) {
            if (PointInPolygon(Poly1[i], Poly2)) {
                IntPoly.push_back(Poly1[i]);
            }
        }
        //添加多边形2在多边形1中的点到交集中
        for (int i = 0; i < (int)Poly2.size(); ++i) {
            if (PointInPolygon(Poly2[i], Poly1)) {
                IntPoly.push_back(Poly2[i]);
            }
        }
        //求出两多边形所有的交点，含重合的顶点，添加到交集中
        for (int i = 0; i < (int)Poly1.size(); ++i) {
            for (int j = 0; j < (int)Poly2.size(); ++j) {
                POINTF Int;
                int nr = Intersection(
                    Poly1[i], Poly1[(i + 1) % (int)Poly1.size()],
                    Poly2[j], Poly2[(j + 1) % (int)Poly2.size()], Int);
                if (nr == 6) {
                    IntPoly.push_back(Poly1[i]);
                    IntPoly.push_back(Poly1[(i + 1) % (int)Poly1.size()]);
                }
                else if(nr > 0) {
                    IntPoly.push_back(Int);
                }
            }
        }
        //为交集求凸包，并计算面积
        float fIntArea = CalcConvexHull(IntPoly) ? CalcArea(IntPoly) * 2 : 0;
        //保存结果
        Result.push_back(fAreaUnion - fIntArea);
    }
    //按格式输出结果
    for (vector<float>::iterator i = Result.begin(); i != Result.end(); ++i) {
        printf("%8.2f", *i);
    }
    cout << endl;
    return 0;
}