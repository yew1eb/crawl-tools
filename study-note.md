
Python开发简单爬虫<http://www.imooc.com/learn/563> 学习笔记

## 1. 简单爬虫架构
![简单爬虫架构](http://img.mukewang.com/568282d100013adb12800720.jpg)

爬虫调度端：启动、停止爬虫、见识爬虫的运行情况。

### 爬虫程序的模块
    URL管理器：对将要爬取和将要爬取的URL进行管理。可以再次去初一的待爬取的URL将其传给网页下载器；
    网页下载器：将URL指定的网页下载下来存储成一个字符串，传送给网页解析器；
    网页解析器：解析出有价值的数据，每一个网页都有很多只想其他网页的URL，北街洗出来之后可以补充进URL管理器
    只要有相关联的URL，爬虫就会一直运行下去。

![运行流程](http://img.mukewang.com/5682a3e00001535c12800720.jpg)

## 2. URL管理器
URL管理器：放置待抓取URL和已抓取URL，防止对URL反复、循环抓取
![URL管理器](http://img.mukewang.com/5682a47a00010f0412800720.jpg)
URL管理器实现方式
![URL管理器实现方式](http://img.mukewang.com/56828413000127d112800720.jpg)

## 3. 网页下载器
![...](http://img.mukewang.com/5682846700012cfc12800720.jpg)

![.](http://img.mukewang.com/5674b79000018cf312800720.jpg)
![..](http://img.mukewang.com/5674b81c0001983212800720.jpg)
![...](http://img.mukewang.com/5674b86b0001c8f712800720.jpg)
![....](http://img.mukewang.com/5674b8b200012bbe12800720.jpg)

## 4. 网页解析器
网页解析器:从网页中提取有价值数据的工具  
![...](http://img.mukewang.com/5674baff0001051312800720.jpg)
结构化解析 - DOM(Document Object Model)树
![...](http://img.mukewang.com/567a903a0001bbad12800720.jpg)
Beautiful Soup
    * Python第三方库, 用于从HTML或XML中提取数据
    * 官方文档:https://www.crummy.com/software/BeautifulSoup/bs4/doc/index.zh.html
   
![...](http://img.mukewang.com/568298f9000185ee12800720.jpg)
```
#创建bs4对象
from bs4 import BeautifulSoup

#根据html网页字符串创建bs对象
soup = BeautifulSoup(
    html_doc, #html文档字符串
    'html.parser' #html解析器
    from_encoding='utf8' #html文档的编码
)

#搜索节点find_all, find
#方法:find_all(name, attrs, string)

#查找所有标签为a的节点
soup.find_all('a')

#查找所有标签为a，链接符合/view/123.html形式的节点
soup.find_all('a', href='/view/123.html')
soup.find_all('a', href=re.compile(r'/view/\d+\.html'))

#查找所有标签为a，class为abc，文字为python的节点
soup.find_all('div', class_='abc', string='python')


#访问节点信息
#获取节点标签名称
node.name
#链接
node['href']
#文字
node.get_text()
```