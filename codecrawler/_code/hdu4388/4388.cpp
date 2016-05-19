#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int main()
{
	int _;
	scanf("%d",&_);
	for (int ______=1;______<=_;______++)
	{
		printf("Case %d: ",______);
		int __,_____,____=0;
		scanf("%d",&__);
		for (int ___=1;___<=__;___++)
		{
			scanf("%d",&_____);
			while (_____)
			{
				if (_____&1) ____++;
				_____>>=1;
			}
		}
		if ((____-__)&1) puts("Yes");
		else puts("No");
	}
	return 0;
}