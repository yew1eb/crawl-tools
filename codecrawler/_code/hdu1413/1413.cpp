#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct wenjian
{
	char name[25]; //当前文件夹名 
	char Fname[1005][25]; //当前文件夹下所有的文件。 
	wenjian *next[1005];//当前文件夹下所包含的文件夹 
	int sum; // 当前文件夹下的文件夹个数 
	int Fsum;// 当前文件夹下的文件个数 
	wenjian *father; //当前文件夹的根 
}*p; 
int main(int argc, char *argv[])
{
	char order[15],content[25]; int i,j,flag,id; 
	char note[6][50]={"success","no such directory","directory already exist",
	"can not delete the directory","file already exist","no such file"}; //输出数组
	p=new wenjian; wenjian *r=p;  //用r保存根
	strcpy(p->name,"\\"); p->sum=p->Fsum=0; p->father=p; //对根赋值 
	while(scanf("%s%s",order,content)!=EOF)
	{
		if(strcmp(order,"CD")==0) //CD切换 
		{
			flag=1;  //默认找不到 
			if(p->sum>0) //有文件夹 
			{
				for(i=0;i<p->sum;i++)
				if(strcmp(p->next[i]->name,content)==0) {flag=0; p=p->next[i]; break; } //找到了,进入下一级 
			}
			if(strcmp(content,"..")==0) //退回上一级目录 
			{
				p=p->father; flag=0;
			}
			if(strcmp(content,"\\")==0) //退回根目录 
			{
				p=r; flag=0;
			}
			printf("%s\n",note[flag]); 
			
		}
		else  if(strcmp(order,"MD")==0) //在当前目录下建立名为[directory name]的子目录 
		{
			flag=0; //默认找不到 
			if(p->sum>0)
			{
				for(i=0;i<p->sum;i++)
				if(strcmp(p->next[i]->name,content)==0){flag=2; break;}//有同名
				 
			}
			if(strcmp(content,"..")==0||strcmp(content,"\\")==0) flag=2; //不允许创建..和\子目录 
			printf("%s\n",note[flag]);
			if(flag==0) //创建子目录成功 ，更新当前目录所包含的文件夹 
			{
				wenjian *pp=new wenjian;
				strcpy(pp->name,content);
				pp->sum=pp->Fsum=0; pp->father=p;
				p->next[p->sum]=pp;
				(p->sum)++;
			} 	
		} 
		else if(strcmp(order,"RD")==0) //删除当前目录下名为[directory name]的子目录 
		{
			flag=0; //默认可以成功删除
			if(p->sum>0) //当前目录下有文件夹
			{
				for(i=0;i<p->sum;i++)
				if(strcmp(p->next[i]->name,content)==0) //找到了,看它是不是一个空文件夹 
				{
					if(p->next[i]->sum||p->next[i]->Fsum) {flag=3;break;} //不是空的 
					else { id=i; break;	} 
				} 
				if(i==p->sum) flag=3; //没有找到这个文件夹 	 
			}
			else flag=3; //没有文件夹
			printf("%s\n",note[flag]);
			if(flag==0) // 删除子目录成功，更新当前目录 
			{
				for(;i<(p->sum)-1;i++)
				{
					p->next[i]=p->next[i+1];
				}
				(p->sum)--;
			}	
		}
		else  if(strcmp(order,"CREATE")==0) //在当前目录下创建名为[file name]的文件
		{
			flag=0; //默认找不到 
			if(p->Fsum>0)
			{
				for(i=0;i<p->Fsum;i++)
				if(strcmp(p->Fname[i],content)==0){flag=4; break;}//有同名
				 
			}
			printf("%s\n",note[flag]);
			if(flag==0) //创建文件成功,更新文件 
			{
				strcpy(p->Fname[p->Fsum],content); (p->Fsum)+=1; 
			} 
		}
		else //删除当前目录下名为[file name]的文件 
		{
			flag=5;//默认没有这个文件
			if(p->Fsum>0)
			{
				for(i=0;i<p->Fsum;i++)
				{
					if(strcmp(p->Fname[i],content)==0) { flag=0; id=i;break;}
				}
			}
			printf("%s\n",note[flag]); 
			if(flag==0)  //删除文件成功，更新文件
			{
				for(;i<(p->Fsum)-1;i++)
				strcpy(p->Fname[i],p->Fname[i+1]);
				p->Fsum=(p->Fsum)-1;
			} 
		} 
	} 
	return 0;
}