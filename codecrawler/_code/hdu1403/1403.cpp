#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define maxn 200100
char s[maxn];
int h2,ans,len1,B[maxn];//B某个桶空余空间尾部的索引
int *S1,*S2,* R,*R2;
int mem[4][maxn],height[maxn];
void CreateSuffixArray(char* szText,int L)
{
    int i,h;
	S1=mem[0]; //h阶后缀数组
	S2=mem[1]; //2h阶后缀数组
	R=mem[2];  //h阶Rank数组
	R2=mem[3]; //2h阶Rank数组
	
	//花O(n)的时间对h=1进行基数排序
    for(i=0;i<L;i++) B[szText[i]]++;
    for(i=1;i<256;i++) B[i]+=B[i-1];
    for(i=L-1;i>=0;i--) S1[--B[szText[i]]]=i;
	//计算Rank(1),因为仅仅是1阶的Rank，所以有并列的
    for(R[S1[0]]=0,i=1;i<L;i++)
    {
        if(szText[S1[i]]==szText[S1[i-1]])
            R[S1[i]]=R[S1[i-1]];
        else
            R[S1[i]]=R[S1[i-1]]+1;
    }
	
	//log(n)趟O(n)的倍增排序
	//SA(h)=>Rank(h)=>SA(2h)=>Rank(2h)=>...
    for(h=1;h<L&&R[S1[L-1]]<L-1;h*=2)                                                                
    {
		//计算Rank(h)相同的后缀形成的h桶尾部的索引
		//即有多少个后缀的h前缀相同，他们被放在一个桶中
        for(i=0;i<L;i++) B[R[S1[i]]]=i;
		
		//求SA(2h)
		//在同一个h桶中，所有的后缀的h前缀肯定相同，
		//那么比较他们的2h前缀，只要比较其2h前缀的后半的
		//长度为h的串即可，而这个串恰恰是后面某个后缀的
		//h前缀，所以我们逆向遍历有序的SA(h),
		//将S1-h号前缀放到他所在桶的最后一个空位置，
		//同时，桶尾前进一个位置，这样即形成了2h桶排序
        for(i=L-1;i>=0;i--)
            if(h<=S1[i])
                S2[B[R[S1[i]-h]]--]=S1[i]-h;
				
		//对于长度不超过h的最后几个后缀，由于在h阶段
		//他们实际上都已经独立分桶了(长度为h的也是)
		//而且他们的桶中有且仅有一个元素，
		//所以只要直接复制他们h阶段的SA值就可以了
		//同时，由于采用滚动数组，所以最终我们只需复制h/2个数据
        for(i=L-h,h2=L-(h>>1);i<h2;i++)
            S2[B[R[i]]]=i;
		
		//计算Rank(2h)
		//2h阶段是否要分桶只需看相邻两个2h前缀的后半
		//h前缀是否全部h阶相等
        for(R2[S2[0]],i=1;i<L;i++)
        {
			//这里不用考虑S1[i]+h会越界
			//如果i达到S1[i]+h越界的数值，
			//那么前面一个条件显然不会满足了
			//因为此时i前缀肯定已经独立分桶了
            if(R[S2[i]]!=R[S2[i-1]]||R[S2[i]+h]!=R[S2[i-1]+h])
                R2[S2[i]]=R2[S2[i-1]]+1;
            else
                R2[S2[i]]=R2[S2[i-1]];
        }
		swap(S1,S2);
        swap(R,R2);
    }
}
//求height[i]=suffix(sa[i-1])和suffix(sa[i])的最长公共前缀，
//也就是排名相邻的两个后缀的最长公共前缀
//有height[i]>=h[i-1]-1(证明见NOI论文《后缀数组--处理字符串的有力工具》作者：罗穗骞)  
void calheight(char* r,int L)
{
    int i, j, k;
    for(i=0,k=0;i<L;i++)
    {
		if(R[i]==L-1) height[R[i]]=k=0;
		else
        {
			if (k>0)k--;
			j=S1[R[i]+1];
			for(;r[i+k]==r[j+k];k++);
			height[R[i]]=k;
		}
    }
}
int main()
{
    int i,n;
    while (scanf("%s",s)!=EOF)
    {
        ans=0;
		memset(height,0,sizeof(height));
		memset(B,0,sizeof(B));
        memset(mem,0,sizeof(mem));
		len1=strlen(s);
		s[len1++]='#';
        scanf("%s",s+len1);
        n=strlen(s);
		s[n++]=0;
        CreateSuffixArray(s,n);
        calheight(s,n);
		
		//判断两个两个后缀是否在同一个串里
		//求height[]的最大值
		for (i=0;i<n-1;i++)
			if ((S1[i]-len1)*(S1[i+1]-len1)<1&&height[i]>ans)
				ans=height[i];
        printf("%d/n",ans);
    }
    return 0;
}