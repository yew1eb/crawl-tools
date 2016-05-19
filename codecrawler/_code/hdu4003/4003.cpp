/*
棰樻剰锛氫竴妫垫湁鏉冩爲锛屼粠鏍圭粨鐐逛腑鏀惧叆K涓満鍣ㄤ汉锛屾眰鐢ㄨ繖K涓満鍣ㄤ汉閬嶅巻鎵�鏈夌殑缁撶偣鏈�灏戠殑鏉冨�煎拰
鍒嗘瀽锛歞p[i][j]琛ㄧず瀵逛簬浠缁撶偣涓烘牴缁撶偣鐨勫瓙鏍戯紝鏀緅涓満鍣ㄤ汉鎵�闇�瑕佺殑鏉冨�煎拰銆�
      褰搄=0鏃惰〃绀烘斁浜嗕竴涓満鍣ㄤ汉涓嬪幓锛岄亶鍘嗗畬缁撶偣鍚庡張鍥炲埌i缁撶偣浜嗐�傜姸鎬佽浆绉绘柟绋嬬被浼艰儗鍖�
  濡傛灉鏈�缁堢殑鐘舵�佷腑浠涓烘牴缁撶偣鐨勬爲涓湁j(j>0)涓満鍣ㄤ汉锛岄偅涔堜笉鍙兘鏈夊埆鐨勬満鍣ㄤ汉r鍒颁簡杩欐５鏍戝悗鍙堣窇鍒板埆鐨勬爲涓幓
  鍥犱负閭ｆ牱鐨勮瘽锛屼竴瀹氫細姣攋涓殑鏌愪竴涓埌杈緄鍚庤窇涓巖鐩稿悓鐨勮矾寰勫啀鍥炲埌i锛屽啀鎺ョ潃璺戝畠鐨勮矾寰勮宸�(澶氫簡涓�鏉鍥炲幓鐨勮竟)
  杩欐牱鐨勮瘽锛屽鏋滄渶鍚庝互i涓烘牴缁撶偣鐨勬爲涓病鏈夋満鍣ㄤ汉锛岄偅涔堝彧鍙兘鏄淳涓�涓満鍣ㄤ汉涓嬪幓閬嶅巻瀹屽悗鍐嶅洖鏉�
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

const __int64 maxn=11000;
const __int64 maxm=21000;
struct edge
{
	__int64 u,v,w,next;
}e[maxm];
__int64 edgeNum,first[maxn],dp[maxn][15];

void Addedge(__int64 u,__int64 v,__int64 w)
{
	e[edgeNum].u=u,e[edgeNum].v=v,e[edgeNum].w=w,e[edgeNum].next=first[u],first[u]=edgeNum++;
	e[edgeNum].u=v,e[edgeNum].v=u,e[edgeNum].w=w,e[edgeNum].next=first[v],first[v]=edgeNum++;
}

void DFS(__int64 t,__int64 p)
{
	__int64 ii,i,j,k;
	for(k=first[t];k!=-1;k=e[k].next)
	{
		i=e[k].v;
		if(i==p) continue;
		DFS(i,t);
	}
   /* 璧嬪垵鍊�0鏃讹紝鍙笉鐢ㄧ鍙跺瓙缁撶偣浜�
   //first[t]=-1鏃惰鏄庢爲涓彧鏈変竴涓粨鐐�
	if(first[t]==-1||(e[first[t]].next==-1&&p!=-1))//鍙跺瓙缁撶偣,娉ㄦ剰涓�瀹氳鎶婃牴缁撶偣鎺掗櫎銆�
	{
		for(i=0;i<=10;i++)
			dp[t][i]=0;
		return;
	}*/
	for(k=first[t];k!=-1;k=e[k].next)
	{
		i=e[k].v;
		if(i==p) continue;
		for(j=10;j>=0;j--)//璺�01鑳屽寘绫讳技锛屾柟鍚戜笉鑳芥崲銆�
		{//姝ゆ椂鐨刣p[i][j]琛ㄧず浠涓烘牴缁撶偣鐨勫瓙鏍戜腑鍓嶉潰鐨勫瓙鏍�(鍖呮嫭杩欐５瀛愭爲)鎬诲垎閰嶄簡j涓満鍣ㄤ汉鐨勬渶灏戞潈鍊煎拰
			/*if(!dp[t][j])//绗竴妫靛瓙鏍�
			{
				if(j) 
				{//鏈�澶氭斁j涓湪璇ュ瓙鏍戜腑锛屼笉涓�瀹氳鍏ㄩ儴鍒拌瀛愭爲涓�(鏈変竴浜涙満鍣ㄤ汉灏卞仠鍦ㄨ繖涓粨鐐逛笂)銆傚綋鐒朵竴涓笉鏀捐偗瀹氫笉鏄渶濂界殑
					for(ii=1;ii<=j;ii++)
						if(dp[t][j]==0||dp[t][j]>dp[i][ii]+ii*e[k].w)
							dp[t][j]=dp[i][ii]+ii*e[k].w;
				}
				else dp[t][0]=dp[i][0]+2*e[k].w;//鏀句笅涓�涓張閫�鍥炴潵
				continue;
			}
			else//鍚﹀垯锛岃嫢璇ュ瓙鏍戞斁0涓満鍣ㄤ汉*///杩欎竴娈典篃鍙互涓嶈
				dp[t][j]+=dp[i][0]+2*e[k].w;
			for(ii=1;ii<=j;ii++)//璇ュ瓙鏍戞斁[1,j]涓満鍣ㄤ汉
			{
				if(dp[t][j]>dp[t][j-ii]+dp[i][ii]+ii*e[k].w)
					dp[t][j]=dp[t][j-ii]+dp[i][ii]+ii*e[k].w;
			}
		}
	}
}
int main()
{
	__int64 n,s,k,i,u,v,w;
	while(scanf("%I64d%I64d%I64d",&n,&s,&k)!=EOF)
	{
		memset(first,-1,sizeof(first));
		for(edgeNum=0,i=1;i<n;i++)
		{
			scanf("%I64d%I64d%I64d",&u,&v,&w);
			Addedge(u,v,w);
		}
		memset(dp,0,sizeof(dp));
		DFS(s,-1);
		printf("%I64d\n",dp[s][k]);
	}
	return 0;
}