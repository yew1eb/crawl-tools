import java.util.*;


public class Main{
	static long mod=1000000007;
	static TreeMap<Integer,Long> tree=new TreeMap<Integer,Long>();
	static int n,k;
	static long to4(int a)
	{
		int[] z=new int[100];
		for(int q=0;q<100;q++)
		{
			z[q]=a&3;
			a>>=2;
		}
		long s=0;
		for(int q=99;q>=0;q--)
		{
			s*=10;
			s+=z[q];
		}
		return s;
	}
	static void init(int idx,int st,long num)
	{
		int[] z=new int[10];
		int[] x=new int[10];
		int s=st;
		int max=-1;
		for(int q=1;q<=k;q++)
		{
			z[q]=s&3;
			s>>=2;
			x[q]=s&3;
			s>>=2;
			if(x[q]>max)
				max=x[q];
		}
		int[] c=z.clone();
		int[] v=x.clone();
		for(int q=-1;q<=max;q++)
			for(int w=-1;w<=max;w++)
			{
				z=c.clone();
				x=v.clone();
				if(!(q==w&&q>=0&&w>=0))
				{
					if(q==-1&&w==-1)
					{
						z[idx]=3;
						x[idx]=max+1;
					}
					if(q>=0&&w>=0)
					{
						z[idx]=0;
						x[idx]=q;
						boolean t=false,y=false;
						for(int e=1;e<idx;e++)
							if(x[e]==q&&(z[e]==1||z[e]==3))
							{
								z[e]-=1;
								t=true;
							}
						for(int e=1;e<idx;e++)
							if(x[e]==w&&(z[e]==2||z[e]==3))
							{
								z[e]-=2;
								y=true;
							}
						for(int e=1;e<idx;e++)
							if(x[e]==w)
								x[e]=q;
					}
					if(q==-1&&w>=0)
					{
						z[idx]=2;
						x[idx]=w;
						boolean t=false;
						for(int e=1;e<idx;e++)
							if(x[e]==w&&(z[e]==2||z[e]==3))
							{
								z[e]-=2;
								t=true;
							}
						if(!t)
							continue;
					}
					if(q>=0&&w==-1)
					{
						z[idx]=1;
						x[idx]=q;
						boolean t=false;
						for(int e=1;e<idx;e++)
							if(x[e]==q&&(z[e]==1||z[e]==3))
							{
								t=true;
								z[e]-=1;
							}
						if(!t)
							continue;
					}
					int ma=-1;
					for(int e=1;e<=idx;e++)
						x[e]+=10;
					for(int e=1;e<=idx;e++)
					{
						if(x[e]==ma+1)
							ma++;
						if(x[e]>ma+1)
						{
							for(int r=e+1;r<=idx;r++)
								if(x[r]==x[e])
								x[r]=ma+1;
							x[e]=ma+1;
							ma++;
						}
					}
		st=0;
		for(int e=idx;e>=1;e--)
		{
			st<<=2;
			st|=x[e];
			st<<=2;
			st|=z[e];
		}
		if(tree.containsKey(st))
			tree.put(st,num+tree.get(st));
		else
			tree.put(st,num);
				}
			}
	}
	static void work(int st,long num)
	{
		int[] z=new int[10];
		int[] x=new int[10];
		int s=st;
		int max=0;
		for(int q=1;q<=k;q++)
		{
			z[q]=s&3;
			s>>=2;
			x[q]=s&3;
			s>>=2;
			if(x[q]>max)
				max=x[q];
		}
		s=st;
		int[] c=z.clone();
		int[] v=x.clone();
		for(int q=-1;q<=max;q++)
			for(int w=-1;w<=max;w++)
			{
				z=c.clone();
				x=v.clone();
				if(!(q==w&&q>=0&&w>=0))
				{
					if(q==-1&&w==-1)
					{
						z[k+1]=3;
						x[k+1]=max+1;
					}
					if(q>=0&&w>=0)
					{
						z[k+1]=0;
						x[k+1]=q;
						boolean t=false,y=false;
						for(int e=1;e<k+1;e++)
							if(x[e]==q&&(z[e]==1||z[e]==3))
							{
								z[e]-=1;
								t=true;
							}
						for(int e=1;e<k+1;e++)
							if(x[e]==w&&(z[e]==2||z[e]==3))
							{
								z[e]-=2;
								y=true;
							}
						for(int e=1;e<k+1;e++)
							if(x[e]==w)
								x[e]=q;
						if(t==false||y==false)
							continue;
					}
					if(q==-1&&w>=0)
					{
						z[k+1]=2;
						x[k+1]=w;
						boolean t=false;
						for(int e=1;e<k+1;e++)
							if(x[e]==w&&(z[e]==2||z[e]==3))
							{
								z[e]-=2;
								t=true;
							}
						if(!t)
							continue;
					}
					if(q>=0&&w==-1)
					{
						z[k+1]=1;
						x[k+1]=q;
						boolean t=false;
						for(int e=1;e<k+1;e++)
							if(x[e]==q&&(z[e]==1||z[e]==3))
							{
								t=true;
								z[e]-=1;
							}
						if(!t)
							continue;
					}
					boolean t=false;
					for(int e=2;e<=k+1;e++)
						if(x[e]==x[1])
							t=true;
					if(!t)
						continue;
					
					
					
					
					for(int e=1;e<=k;e++)
					{
						x[e]=10+x[e+1];
						z[e]=z[e+1];
					}
					int ma=-1;
					for(int e=1;e<=k;e++)
					{
						if(x[e]==ma+1)
							ma++;
						if(x[e]>ma+1)
						{
							for(int r=e+1;r<=k;r++)
								if(x[r]==x[e])
								x[r]=ma+1;
							x[e]=ma+1;
							ma++;
						}
					}
					st=0;
					for(int e=k;e>=1;e--)
					{
						st<<=2;
						st|=x[e];
						st<<=2;
						st|=z[e];
					}
					if(tree.containsKey(st))
						tree.put(st,(num+tree.get(st))%mod);
					else
						tree.put(st,num);
				}
			}
	}
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		for(;scan.hasNext();)
		{
		n=scan.nextInt();
		k=scan.nextInt();
		if(k>n-1)
			k=n-1;
		if(k==0)
		{
			System.out.println(0);
			continue;
		}
		if(k==1)
		{
			System.out.println(2);
			continue;
		}
		tree.clear();
		tree.put(3,1l);
		int[] z=new int[10000];
		long[] x=new long[10000];
		int num=0;
		for(int q=2;q<=k;q++)
		{
			num=0;
			int a=-1;
			for(;a!=tree.lastKey();)
			{
				a=tree.higherKey(a);
				z[num]=a;
				x[num]=tree.get(a);
				num++;
			}
			tree.clear();
			for(int w=0;w<num;w++)
				init(q,z[w],x[w]);
		}
		for(int p=k+1;p<=n;p++)
		{
			num=0;
			int a=-1;
			for(;a!=tree.lastKey();)
			{
				a=tree.higherKey(a);
				z[num]=a;
				x[num]=tree.get(a);
				num++;
			}
			tree.clear();
			for(int q=0;q<num;q++)
				work(z[q],x[q]);
		}
		num=0;
		long sum=0;
		int a=-1;
		int[] c=new int[10];
		for(;a!=tree.lastKey();)
		{
			a=tree.higherKey(a);
			z[num]=a;
			x[num]=tree.get(a);
			int u=z[num];
			boolean i=true;
			for(int q=0;q<k;q++)
			{
				u>>=2;
				c[q]=u&3;
				u>>=2;
				if(c[q]!=0)
					i=false;
			}
			if(i)
			{
				sum+=x[num];
				sum%=mod;
			}
			num++;
		}
		System.out.println(sum);
		}
	}

}