#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 100015
#define inf 1<<29
#define LL long long
#define Key_value ch[ch[root][1]][0]
using namespace std;
int n,q,p[N],cnt,s[2*N],e[2*N],ope[N];
int node[2*N];
char str[N][10];
int root,tot,size[2*N],key[2*N],pre[2*N],ch[2*N][2],num[2*N];
//debug部分COPY自HH
void Treaval(int x) {  
    if(x) {  
        Treaval(ch[x][0]);  
        printf("结点%2d:左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d ,key = %2d   num= %2d \n",x,ch[x][0],ch[x][1],pre[x],size[x],key[x],num[x]);  
        Treaval(ch[x][1]);  
    }  
}  
void debug() {printf("%d\n",root);Treaval(root);}   
void Push_Up(int r){
	size[r]=size[ch[r][0]]+size[ch[r][1]]+num[r];
}
void NewNode(int &r,int father,int k){
	r=++tot;
	pre[r]=father;
	size[r]=e[k]-s[k]+1;
	num[r]=e[k]-s[k]+1;
	key[r]=k;
	node[k]=r;
	ch[r][0]=ch[r][1]=0;
}
void Bulid(int &x,int l,int r,int father){
	if(l>r)
		return;
	int mid=(l+r)/2;
	NewNode(x,father,mid);
	Bulid(ch[x][0],l,mid-1,x);
	Bulid(ch[x][1],mid+1,r,x);
	Push_Up(x);
}
void Rotate(int x,int kind){  
	int y=pre[x];    
	ch[y][!kind]=ch[x][kind];   
	pre[ch[x][kind]]=y;  
	if(pre[y])  
		ch[pre[y]][ch[pre[y]][1]==y]=x;  
	pre[x]=pre[y];  
	ch[x][kind]=y;  
	pre[y]=x;  
	Push_Up(y);  
}   
void Splay(int r,int goal){  
	while(pre[r]!=goal){  
		if(pre[pre[r]]==goal)  
			Rotate(r,ch[pre[r]][0]==r);  
		else{  
			int y=pre[r];  
			int kind=(ch[pre[y]][0]==y);  
			if(ch[y][kind]==r){  
				Rotate(r,!kind);  
				Rotate(r,kind);  
			}  
			else{  
				Rotate(y,kind);  
				Rotate(r,kind);  
			}  
		}  
	}  
	Push_Up(r);  
	if(goal==0) root=r;  
} 
int Bin(int x){   //离散化中，二分查找
	int low=0,high=cnt-1,mid;
	while(low<=high){
		mid=(low+high)>>1;
		if(s[mid]<=x&&e[mid]>=x)
			return mid;
		if(e[mid]<x)
			low=mid+1;
		else
			high=mid-1;
	}
}
int Get_Min(int r){
	while(ch[r][0]){
		r=ch[r][0];
	}
	return r;
}
void Delete(){
	int k=Get_Min(ch[root][1]);  //找到右孩子中最小的
	Splay(k,root);   //旋转过来，使得右子树没有左孩子
	ch[ch[root][1]][0]=ch[root][0];   //将原来的左孩子给右子树作为左孩子
	root=ch[root][1];   //让右孩子为根
	pre[ch[root][0]]=root;   
	pre[root]=0;
	Push_Up(root);
}
void Insert(int &r,int k,int father){
	if(r==0){
		NewNode(r,father,k);
		return;
	}
	Insert(ch[r][0],k,r);  //因为是插入到队首，担心一直往左子树找
	Push_Up(r);
}
void Top(int x){
	int k=Bin(x);
	int y=node[k];  //找到这个人所在区间的标号
	Splay(y,0);   //旋转至根部
	if(!ch[root][0]||!ch[root][1]){   //左右孩子不完整，直接将孩子拉到根部
		root=ch[root][0]+ch[root][1];
		pre[root]=0;
	}
	else
		Delete();  //删除节点
	Insert(root,k,0);  //再插入
	Splay(tot,0);   //旋转至根部,这步不加会TLE
}
int Get_Rank(int x){
	int k=Bin(x);
	int y=node[k];
	Splay(y,0);
	return size[ch[root][0]]+1;
}
int Get_Kth(int r,int k){
	int t=size[ch[r][0]];
	if(k<=t)
		return Get_Kth(ch[r][0],k);
	else if(k<=t+num[r])
		return s[key[r]]+(k-t)-1;
	else
		return Get_Kth(ch[r][1],k-t-num[r]);
}
void slove(){
	for(int i=0;i<q;i++){
		if(str[i][0]=='T')
			Top(ope[i]);
		else if(str[i][0]=='Q')
			printf("%d\n",Get_Rank(ope[i]));
		else
			printf("%d\n",Get_Kth(root,ope[i]));
	}
}
int main(){
	int t,cas=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&q);
		//将所有TOP和QUERY操作的点进行离散化，将中间不变的区间缩成点
		int total=0;
		p[total++]=0;
		for(int i=0;i<q;i++){
			scanf("%s%d",str[i],&ope[i]);
			if(str[i][0]=='T'||str[i][0]=='Q')
				p[total++]=ope[i];
		}
		p[total++]=n;
		sort(p,p+total);
		cnt=0;
		//进行离散化，s[i]表示区间起点，e[i]表示区间终点
		for(int i=1;i<total;i++)
			if(p[i]!=p[i-1]){
				if(p[i]-p[i-1]>1){   //中间的区间
					s[cnt]=p[i-1]+1;
					e[cnt]=p[i]-1;
					cnt++;
				}
				s[cnt]=p[i];   //端点
				e[cnt]=p[i];
				cnt++;
			}
		root=tot=0;	
		ch[root][0]=ch[root][1]=pre[root]=size[root]=num[root]=key[root]=0;
		Bulid(root,0,cnt-1,0);  //建树
		printf("Case %d:\n",++cas);
		slove();
	}
	return 0;
}