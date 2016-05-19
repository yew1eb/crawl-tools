//不依赖大数 速度较快 DEBUG版时21位大概10秒左右

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
/**************************水仙花数**************************/
#define N 10

using namespace std;

void Narcissus(const int& n); //输出n位数中的水仙花数

int main(void)
{
     clock_t start , end;
     int n=1;
     start=clock();

    while(1)
     {
         std::cout<<"水仙花数位数:";
         cin>>n;
         start=clock();
         Narcissus(n);
         end=clock();
         std::cout<<"Times:"<<(double)(end-start)/CLK_TCK<<std::endl;
     }
     
     return 0;
}

static void StatNumber(int *num,int (&s)[N],const int& n)
{//统计num[]中 各数字出现的次数 结果放到S[]中
     memset(s,0x00,sizeof(int)*N);
     register int len=n;
     const int* ptr=num;
     while(len--)
     {
         ++s[*ptr++];
     }
}
static void Power_N(int *sum,const int& pow)
{   //对0~9的M次预处理将结果放入sum中,各数位拆解
     register int i;
     for(i = 1 ; i < N; i++)   //初始化sum
     {
         sum[i*pow]=i;
     }
     int tmp;
     for( i = 0 ;i < N; i++)   //对0~9的M次预处理
     {
        for( int j = 0 ; (j < pow -1);j ++)
         {
             tmp=i*pow;
             for( int n = 0 ; n < pow; n ++)
                sum[tmp+n]*=i;
             for(int m = 0 ; m < pow ; m ++)
             {
                 if(sum[tmp+m]>=10)
                 {
                     if(sum[tmp+m+1] == -1)
                        sum[tmp+m+1] = 0;
                     sum[tmp+m+1] += sum[tmp+m]/10;
                     sum[tmp+m] = sum[tmp+m]%10;
                 }
            }
        }
     }
}
static void Print(int *sum,const int& n)//输出水仙花数
{
     register int i = n-1;
         for(; i >= 0 ; i --)
         {
            std::cout<<sum[i];
         }
         std::cout<<std::endl;
}

static void add(int *addend,int *summend,const int& k,const int& pow )
{                               //加入k的pow次方
     register int i;
     const int j=k*pow;
     for( i = 0 ; i < pow; i ++)
        addend[i] += summend[j+i];

     for( i = 0 ; i < pow ; i ++)
     {
         if(addend[i]>=10)
         {
             if(addend[i+1] == -1)
                addend[i+1] = 0;
             addend[i+1] += addend[i]/10;
             addend[i] = addend[i]%10;
         }
     }
}

static void sub(int *a,int *b,const int& k,const int& pow )//从a中减去k的pow次方
{
     const int j=k*pow;
     for(register int i = 0 ; i < pow; i++)
     {
         if(a[i] < b[j+i])
         {
             a[i+1] -= 1;
             a[i]=a[i]+10-b[j+i];
         }
         else
         {
            a[i] -= b[j+i];
         }
     }
}
static bool cmp(int (&a)[N],int (&b)[N])//比较
{
     for(register int i = 0 ; i < N; i++)
         if(a[i]!=b[i])
            return false;
     return true;
}
void Narcissus(const int& n)
{
     if(n <= 0) return;

     int *sum=new int[n*N];     //0~9的n次方
     memset(sum,0,sizeof(int)*n*N);

     int stat1[N]={0};          //N次方和中各位数字出现的次数
     int stat2[N]={0};          //栈中数出现的次数
     int *gross=new int[n+1];   //栈中各数的n次方和 数字已拆分
     memset(gross,0x00,sizeof(int)*(n+1));

     int *stack=new int[n+1];     //栈
     memset(stack,0x00,sizeof(int)*(n+1));
     int* top=stack;            //栈顶指针
     const int *maxTop=stack+n; //

     Power_N(sum,n);            //求出0~9的n次方
     bool tab = false;
     register int k =9;         //动态组合的数字  从大到小组合

     while(1)
     {
         if(top < maxTop && gross[n]==0)
         {                    //栈中数字及N次方和均未达到N位
             add(gross,sum,k,n);
             stat2[k]++;      //记录栈中各数字出现次数
             *top++ = k;      //数字入栈 栈顶不会大于后面的数字777-776.即780不会有
         }                    //因无++K,只有--K.已出现过的组合后面不会再现 如731已现,无371/137/713/173

         if(gross[n]>0)       //组合数字的N次方和大于N位
         {
             sub(gross,sum,k,n);
             stat2[k]--;
             k=*--top - 1;    //退栈,组合数字为退出数减一,后面不会有比前面更大的组合数字
         }
         if(top == maxTop)    //栈满 即已有N位数字
         {
            if(gross[n-1]==0) //N次方和小于N位 若n为1,不能输出0,此处退出
                break;        //由于后面无比它更大的组合(见165-172行注释),退出
            StatNumber(gross,stat1,n);//求N次方和中各位数出现次数 存于sta1中
            if(cmp(stat1,stat2))      //若出现的数字及其次数完全相同,则为水仙花数
            {
                Print(gross,n);       //若栈中为7 3 1则输出371
            }
            if(*(top-1) != 0)         //若栈顶数字不为0
             {
                 sub(gross,sum,k,n);  //先从N次方和中减去此数字的N次方
                 --stat2[k];          //此数次数随即减少 此时栈顶指针未动
             }
             else
             {
                 while(*(top-1) == 0) //栈顶为0 循环后指向栈中紧跟的非0数字
                 {
                      --top;
                      --stat2[0];     //退0
                 }
                 //if(top-1<stack) break;
                 tab=true;
             }
             k=*--top;               //退栈 k接收退出的数字
             if(tab)
             {
                 sub(gross,sum,k,n); //
                 --stat2[k];
                 tab = false;
             }
             --k;       //后面的组合数字比原数更小 保证不出现 788
         }
         //if(*stack ==1)  break;
     }
     delete []sum;
     delete []gross;
     delete []stack;
}