/*
hdu 1107

http://acm.hdu.edu.cn/showproblem.php?pid=1107

Exe.Time	Exe.Memory		Code Len.	Language 
0MS			300K			4146 B		C++ 
Author:WonderCoder
Email:[email protected]/* <![CDATA[ */!function(t,e,r,n,c,a,p){try{t=document.currentScript||function(){for(t=document.getElementsByTagName('script'),e=t.length;e--;)if(t[e].getAttribute('data-cfhash'))return t[e]}();if(t&&(c=t.previousSibling)){p=t.parentNode;if(a=c.getAttribute('data-cfemail')){for(e='',r='0x'+a.substr(0,2)|0,n=2;a.length-n;n+=2)e+='%'+('0'+('0x'+a.substr(n,2)^r).toString(16)).slice(-2);p.replaceChild(document.createTextNode(decodeURIComponent(e)),c)}p.removeChild(t)}}catch(u){}}()/* ]]> */
*/
#include <iostream>
#include <fstream>
using namespace std;
int N,num,X[13][13];

struct persion
{
    char v;		//门派
    int x,y;	//坐标
    int MP;		//内功
    int DP;		//武力
    int HP;		//生命
	bool isF;	//是否格斗过
	int dir;	//方向1为正方向，0为反方向  少林的正方向是下 武当的正方向是右，峨眉的正方向是右下
}p[1000];

//显示格斗过后个门派的结果
void ShowRest()
{
    int ss,sw,se,hs,hw,he;
    ss = sw = se = hs = hw = he =0;
    for(int i=0;i<num;i++)
    {
        switch(p[i].v)
        {
		case 'S':
			if(p[i].HP>0)	//如果生命值为小于或等于0，说明死了
			{ss++; hs+=p[i].HP;}break;
		case 'W':
			if(p[i].HP>0)
			{sw++; hw+=p[i].HP;}break;
		case 'E': 
			if(p[i].HP>0)
			{se++; he+=p[i].HP;}break;
        }
    }
    cout<<ss<<" "<<hs<<endl;	//少林
    cout<<sw<<" "<<hw<<endl;	//武当
    cout<<se<<" "<<he<<endl;	//峨眉
    cout<<"***"<<endl;
}

//返回伤害值
int getDPS(int i)
{
	int DPS = 0;
	switch(p[i].v)
	{
	case 'S':DPS = (0.5*p[i].MP+0.5*p[i].DP)*(p[i].HP+10)/100;
				 break;
	case 'W':DPS = (0.8*p[i].MP + 0.2*p[i].DP)*(p[i].HP+10)/100;
		break;
	case 'E':DPS = (0.2*p[i].MP + 0.8*p[i].DP)*(p[i].HP+10)/100;
		break;
	}
	return DPS;
}

//移动
void move()
{
	int i;
	for(i=0;i<num;i++)
        {
			p[i].isF = false;
            X[p[i].y][p[i].x]--;					//当前位置的人数-1，因为这位大侠要走了。。
            switch(p[i].v)
            {
			case 'S':
				if(p[i].y >10) p[i].dir = 0;		//到底，向上运动了。。
				if(p[i].y <1) p[i].dir = 1;			//到顶了，改变方向
				if(!p[i].dir)		p[i].y--;
                else   		p[i].y++;
                break;
			case 'W':
				if(p[i].x >10) p[i].dir = 0;		//达到最右边，改变方向，向左运动
				if(p[i].x <1) p[i].dir = 1;			//达到最左边，有右运动
                if(!p[i].dir)   p[i].x--;			
                else    	p[i].x++;
                break;
			case 'E':
				if(p[i].y == 11||p[i].x == 11)		//到达右边或下边，向反向运动
					p[i].dir = 0;
				if(p[i].y == 0||p[i].x == 0)		//到达左边或上边，改变方向，向正方向运动
					p[i].dir = 1;
				if((p[i].y==0&&p[i].x==11)||(p[i].y==11&&p[i].x==0))
					break;
				else
				{
					if(!p[i].dir)
					{   p[i].y--;   p[i].x--;     }
					else
					{   p[i].y++;   p[i].x++;     }
				}
                break;
            }
            X[p[i].y][p[i].x]++;				//这位大侠来到了新的位置，在该位置的人数量加1
        }
}

//开始格斗
void fight()
{
    int i,j,DPS1,DPS2;
    while(N--)
    {
        for(i=0;i<num;i++)
        {
			DPS1 = DPS2 = 0;
            if(X[p[i].y][p[i].x]==2&&!p[i].isF&&p[i].HP>0)		//当前位置只有2个人。同时大侠i在本回合内没有格斗过，到然大侠i还不能死。。
            {
				
                for(j=0;j<num;j++)
                {
					if((p[i].y==p[j].y)&&(p[i].x==p[j].x)&&(p[i].v!=p[j].v)&&p[j].HP>0)		//寻找大侠i所在位置的其他武林人士（这位武林人士还没死哦）。门派不能和大侠i相同，
					{
						DPS1 = getDPS(i);		//计算伤害值
						DPS2 = getDPS(j);	
						p[i].HP -=DPS2;		//格斗了，战前生命力 - 对方攻击力
						p[j].HP -=DPS1;
						p[i].isF = true;	//标记本回合已经格斗过。
						p[j].isF = true;	
					}
                }
            }
        }
		//一回合过去了，各位武林高手开始移动。。
		move();
    }
}
int main()
{
    //ifstream cin("a.txt");
    int a;
    while(cin>>a)
    {
        while(a--)
        {
			//初始化地图。。。
            for(int i=0;i<12;i++)
            {
                for(int j=0;j<12;j++)
					X[i][j] = 0;
            }
            num = 0;
            cin>>N;
            while(cin>>p[num].v&&p[num].v!='0')
            {
                cin>>p[num].y>>p[num].x>>p[num].MP>>p[num].DP>>p[num].HP;
				p[num].y--;				//大侠的位置从0.0位置开始计算，所以X，Y都减1
				p[num].x--;
				p[num].isF = false;		//初始化，没有战斗过。
				p[num].dir = 1;			//初始化方向为正
                X[p[num].y][p[num].x]++;
				num++;
            }
			fight();
            ShowRest();
        }
    }
    return 0;
}