#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

typedef unsigned long ulong;
typedef unsigned short ushort;

// 用于存储profile中的阈值和转成数字序列的关键词组合
struct PROFILE
{
	size_t nThreshold;
	std::vector<ushort> nArray;
};

// 用于存储profile中的阈值和profile的编号，title中的包含的两个关键字之间的距离和title的编号
struct INFO
{
	size_t nDist;
	size_t nIdx;
};

typedef std::vector<std::string> VECSTR;
typedef std::vector<ushort> ARRAY;
typedef std::vector<ARRAY> MATRIX;
typedef std::map<ulong, std::vector<INFO> > MAPINFO;
typedef std::pair<size_t, size_t> PAIR;

// 将keywords对中的两个单词用数字序列表示，用一个unsigned short数据类型存储
ulong MakeWordPair(ushort w1, ushort w2)
{
	return (w1 > w2)? (w1 | (w2 << 16)) : (w2 | (w1 << 16));
}

// 排序过程，重载“<”运算符
bool operator < (const INFO &f1, const INFO &f2)
{
	return (f1.nDist < f2.nDist || (f1.nDist == f2.nDist && f1.nIdx < f2.nIdx));
}

// 去重过程，重载“==”运算符
bool operator == (const INFO &f1, const INFO &f2)
{
	return (f1.nDist == f2.nDist && f1.nIdx == f2.nIdx);
}

int main(void)
{
	VECSTR profileStrs, titleStrs;
	for (std::string str; getline(std::cin, str) && str[0] != '#'; ) {
		// 读入数据，若以“P：”开头，则表示profile，若以“T：”开头，则表示title，若以空格或者tab开头，则承接上一个title。
		switch(str[0]) {
		case 'P':
			profileStrs.push_back(std::string(str.begin() + 2, str.end()));
			break;
		case 'T':
			titleStrs.push_back(std::string(str.begin() + 2, str.end()));
			break;
		case ' ':
		case '\t':
			titleStrs.back() += str;
			break;
		}
	}
	std::map<std::string, ushort> wordTbl;	     // 用于给每一个keywords编号，keywords与编号的映射关系存入wordTbl中
	std::vector<PROFILE> arrProfile;	         // 将每个profile中的keywords序列转化为相应的keywords编号序列
	for (VECSTR::iterator i = profileStrs.begin(); i != profileStrs.end(); ++i) {
		i->push_back(' ');
		std::string::iterator iBeg = i->begin();
		// 由于profile由阈值和keywords串组成，遍历profile字符串，找到阈值的起始位置
		for (; iBeg != i->end() && !isdigit(*iBeg); ++iBeg);
		// 找到阈值的结束位置，读取阈值
		std::string strThre;
		std::string::iterator iEnd = iBeg;
		for (; iEnd != i->end() && isdigit(*iEnd); ++iEnd)
			strThre.push_back(*iEnd);
		// 保存每一个profile的阈值和由keywords的编号组成的序列
		arrProfile.push_back(PROFILE());
		PROFILE &cur = arrProfile.back();
		// 将阈值由文本形式转为数值形式
		cur.nThreshold = atoi(strThre.c_str()); 
		//用于存储keywords中读取的单词
		std::string word;   
		for (std::string::iterator j = iEnd; j != i->end(); ++j) {
			if (*j != ' ' && *j != '\t')
				word.push_back(*j);
			else if (!word.empty()) {
				// 更新keywords与编号的映射表
				ushort &wordIdx = wordTbl[word];
				if (wordIdx == 0)
					wordIdx = wordTbl.size();
				// 存储keywords编号序列
				cur.nArray.push_back(wordIdx); 
				word.clear();
			}
		}
	}
	// 原输入为一个profile对应一组keywords pair，将其转变为一个keywords pair对应一个profile编号组，建立映射关系
	MAPINFO profileTbl;
	for (std::vector<PROFILE>::iterator i = arrProfile.begin(); i != arrProfile.end(); ++i)	{
		// 所有的keywords两两组合作为一个keywords pair
		for (ARRAY::iterator j = i->nArray.begin(); j != i->nArray.end() - 1; ++j) {
			for (ARRAY::iterator k = j + 1; k != i->nArray.end(); ++k) {
				INFO info = {i->nThreshold, i - arrProfile.begin()};
				profileTbl[MakeWordPair(*j, *k)].push_back(info);
			}
		}
	}

	MATRIX titleAry;
	for (VECSTR::iterator i = titleStrs.begin(); i != titleStrs.end(); ++i) {
		(*i)[i->size() - 1] = ' ';
		titleAry.push_back(ARRAY());
		std::string word;
		// 按题中要求处理title，去掉非字母的符号。再将title序列转化为编号序列，若某一个单词为keyword，则标记为相应的编号，若不是，则标记为-1
		for (std::string::iterator j = i->begin(); j != i->end(); ++j) {
			char cTmp = tolower(*j);
			if (cTmp != ' ' && cTmp != '\t') {
				if (isalpha(cTmp))
					word.push_back(cTmp);
			}
			else if (!word.empty()) {
				std::map<std::string, ushort>::iterator idx = wordTbl.find(word);
				titleAry.back().push_back(idx != wordTbl.end() ? idx->second : -1);
				word.clear();
			}
		}
	}
	// 每一个title中包含多个keywords pair，计算并存储每对keywords的距离
	MAPINFO titleTbl;
	for (MATRIX::iterator i = titleAry.begin(); i != titleAry.end(); ++i) {
		// 对当前title建立keywords pair，每对keywords的距离以及title编号的映射表
		std::map<ulong, ushort> curWordmap;
		for (ARRAY::iterator j = i->begin(); j != i->end() - 1; ++j) {
			if (*j != ushort(-1)) {
				for (ARRAY::iterator k = j + 1; k != i->end(); ++k) {
					if (*k != ushort(-1)) {
						// 若存在关键字对，则计算两个关键字间的距离，保留最小值
						ushort nDist = k - j;
						ushort &nWord = curWordmap[MakeWordPair(*j, *k)];
						if (nWord == 0 || nDist < nWord)
							nWord = nDist;
					}
				}
			}
		}
		// 将title处理为一个keywords pair对应一组title编号和距离
		for (std::map<ulong, ushort>::iterator j = curWordmap.begin(); j != curWordmap.end(); ++j) {
			INFO info = {j->second, i - titleAry.begin()};
			titleTbl[j->first].push_back(info);
		}
	}
	// 比较profile和title，确定哪些title属于相应的profile
	std::vector<PAIR> result;
	for (MAPINFO::iterator i = profileTbl.begin(); i != profileTbl.end(); ++i) {
		std::vector<INFO> &curP = i->second;
		std::vector<INFO> &curT = titleTbl[i->first];
		// 判断title中是否有该keywords pair
		if (!curT.empty()) {
			// 当profile和title包含相同的keywords时，将当前的profile编号排序去重
			std::sort(curP.begin(), curP.end());
			curP.erase(std::unique(curP.begin(), curP.end()), curP.end());
			std::sort(curT.begin(), curT.end());    // 将当前的title编号排序
			for (std::vector<INFO>::iterator icurP = curP.begin(), icurT = curT.begin(); 
				icurP != curP.end() && icurT != curT.end();) {
					// 若当前title中关键字的距离小于当前profile中阈值，则该title的编号必定属于当前之后的所有profile（包含当前profile）
					// 若大于当前阈值，则去下一个profile的阈值
				if (icurT->nDist - 1 <= icurP->nDist) {
					for (std::vector<INFO>::iterator j = icurP; j != curP.end(); ++j)
						result.push_back(std::make_pair(j->nIdx + 1, icurT->nIdx + 1));
					++icurT;
				}
				else
					++icurP;
			}
		}
		else
			result.push_back(std::make_pair(curP.front().nIdx + 1, 0));
	}
	// 对结果排序并输出
	std::sort(result.begin(), result.end());
	int nProfIdx = 0;
	for (std::vector<PAIR>::iterator i = result.begin(); i != result.end(); ++i) {
		if (i->first != nProfIdx) {
			nProfIdx = i->first;
			if (i != result.begin())
				std::cout << std::endl;
			std::cout << nProfIdx << ": ";
			if (i->second != 0)
				std::cout << i->second;
		}
		else if (i->second != 0)
				std::cout << ',' << i->second;
		}
	}
	std::cout << std::endl;
	return 0;
}