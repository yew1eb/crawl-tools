int n;
char in[20][20];

int main()
{
	int cs=0;
	while(scanf("%d",&n),n){
		int a[20];
		rep(i,n)scanf("%s",in[i]);
		int ten=1, i;
		for(i=strlen(in[0])-1;i>=0;i--){
			if(in[0][i]=='.')break;
			ten*=10;
		}
		if(i<0)ten=1;
		
		rep(i,n){
			double t;
			sscanf(in[i],"%lf",&t);
			a[i]=int(t*ten+0.5);
		}
		int total=100*ten, m=1;
		for(;m<=9999;m++){
			int MX=0,MN=0;
			bool ok=1;
			rep(i,n){
				int mn=(int)ceil(m*(a[i]-0.5)/100/ten-EPS);
				int mx=(int)(m*(a[i]+0.5)/100/ten-EPS);
				if(mn>mx)ok=0;
				MX+=mx; MN+=mn;
			}
			if(ok&&MN<=m&&m<=MX)break;
		}
		printf("Case %d: ",++cs);
		if(m>9999)puts("error");
		else printf("%d\n",m);
	}
	return 0;
}
