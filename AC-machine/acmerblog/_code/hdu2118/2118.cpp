#include <iomanip>
#include <iostream>
#include <iterator>
#include <deque>
using namespace std;
struct POINT {int x; int y;};
struct RECT {POINT tl; POINT br;};
//判断点是否在矩形内
bool PointInRect(const POINT &pt, const RECT &rc) {
	return (pt.x >= rc.tl.x && pt.x <= rc.br.x &&
		pt.y >= rc.tl.y && pt.y <= rc.br.y);
}
//计算两点计距离的平方
int PointDistance(const POINT &pt1, const POINT &pt2) {
	POINT Vec = {pt2.x - pt1.x, pt2.y - pt1.y};
	return (Vec.x * Vec.x + Vec.y * Vec.y);
}
//主函数
int main(void) {
	deque<POINT> Icons, Clicks;
	deque<RECT> Rects;
	//循环读入每一组数据
	for (char Tag = 0; cin >> Tag && Tag != '#'; ) {
		RECT rc;
		switch (Tag) {
		case 'I': //输入图标数据
			cin >> rc.tl.x >> rc.tl.y;
			Icons.push_back(rc.tl);
			break;
		case 'R': //输入矩形数据
			cin >> rc.tl.x >> rc.tl.y >> rc.br.x >> rc.br.y;
			if (rc.br.x < rc.tl.x) *(int*)0 = 0;
			if (rc.br.y < rc.tl.y) *(int*)0 = 0;
			Rects.push_back(rc);
			if (Rects.size() > 26) *(int*)0 = 0;
			break;
		case 'M': //输入鼠标点击事件(坐标)
			cin >> rc.tl.x >> rc.tl.y;
			Clicks.push_back(rc.tl);
			break;
		}
	}
	deque<POINT>::iterator iIcon, iClick;
	deque<RECT>::iterator iRect;
	//检查是否存在图标被矩形覆盖
	for (iIcon = Icons.begin(); iIcon != Icons.end(); ++iIcon) {
		for (iRect = Rects.begin(); iRect != Rects.end(); ++iRect) {
			if (PointInRect(*iIcon, *iRect)) {
				iIcon->x = 10000; //将该图标移至无穷远处，即将其忽略
				iIcon->y = 10000; //不能删除，以免影响后面图标的编号
			}
		}
	}
	//处理每一次鼠标点击事件
	for (iClick = Clicks.begin(); iClick != Clicks.end(); ++iClick) {
		//按题目要求，从后向前检查是否点在某个矩形内
		deque<RECT>::reverse_iterator riRect;
		for (riRect = Rects.rbegin(); riRect != Rects.rend() &&
			!PointInRect(*iClick, *riRect); ++riRect);
		//如果找到点在某个矩型，输出该矩形
		if (riRect != Rects.rend()) {
			cout << (char)(distance(riRect, Rects.rend()) - 1 + 'A') << endl;
			continue;
		}
		//查找离鼠标位置距离最近的图标，存到动态数组SelIcons中
		deque<int> SelIcons(1, 1);
		deque<POINT>::iterator iNear = Icons.begin(), iIcon;
		int nNear = PointDistance(*iClick, *iNear);
		for (iIcon = iNear + 1; iIcon != Icons.end(); ++iIcon) {
			int nDist = PointDistance(*iClick, *iIcon); //计算距离
			if (nDist < nNear) {
				iNear = iIcon;
				nNear = nDist;
				SelIcons.clear(); //清空原先的数组，以新图标代替
				SelIcons.push_back(distance(Icons.begin(), iIcon) + 1);
			}
			else if (nDist == nNear) { //发现同为最短距离的图标则加入数组
				SelIcons.push_back(distance(Icons.begin(), iIcon) + 1);
			}
		}
		//按要求的格式输出图标的编号
		deque<int>::iterator iSel;
		for (iSel = SelIcons.begin(); iSel != SelIcons.end(); ++iSel) {
			cout << setw(3) << *iSel;
		}
		cout << endl;
	}
	return 0;
}