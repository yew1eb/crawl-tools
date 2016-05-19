//贡献了一次WA，原因是忽略了下面这句话：“Note that classmate number 1 initially has the ball and tosses it to classmate k. 
//Thus, number 1 has not yet been tossed the ball and so does not switch the direction he is thinking. ” 意思是说，虽然球是在同学1的
//手中，但是他是否被传过球，记为false的！要注意啊！还有一个需要注意的就是“she throws it back across the circle one place to the left 
//(from her perspective) of the person who threw her the ball” 要注意括号里面的句子，好重要，即是说：这个方向是你看一个人的左与右的方向，
//而不是一个人自己本身的左与右的方向！
#include <iostream>
#include <string>
using namespace std;

struct Info//储存同学的信息的 
{
    int num;//同学的序号 
    char direction;//想象中的方向 
    bool flag;//是否有接过球，即是话有没有同学传过球给他 
    int leftnum;//在其他同学眼中，他左边的数字！ 
    int rightnum;//在其他同学眼中，他右边的数字！
    int left;//就他自己本身来说，他左边的数字！ 
    int right;//就他自己本身；来说，他右边的数字！ 
}info[35];

int main()
{
    int n, k, i, pre, c, tmp;
    char temp;
    bool ff;
    while (cin >> n && n)
    {
          cin >> k;
          for (i = 1; i <= n; i++)//信息的输入 
          {
              cin >> temp;
              info[i].num = i;
              info[i].direction = temp;
              info[i].flag = false;
          } 
          //对他左右边数的赋值 
          info[1].rightnum = 2;
          info[1].left = 2;
          info[1].leftnum = n;
          info[1].right = n;
          info[n].rightnum = 1;
          info[n].left = 1;
          info[n].leftnum = n-1;
          info[n].right = n-1;
          for (i = 2; i < n; i++)
          {
              info[i].rightnum = i+1;
              info[i].left = i+1;
              info[i].leftnum = i-1;
              info[i].right = i-1;
          }
          
          pre = 1;
          c = 1;
          ff = false;
          while (1)
          {
                for (i = 1; i <= n; i++)
                {
                    if (!info[i].flag)
                    {
                        ff = true;
                        break;
                    }
                }
                //分情况讨论其中的四种情况！ 
                if (ff)
                {
                    if (info[k].direction == 'L')
                    {
                        info[k].flag = true;
                        if (pre == info[k].left)
                        {
                            info[k].direction = 'R';
                            tmp = info[k].right;
                        }
                        else 
                        {
                            info[k].direction = 'R';
                            tmp = info[pre].leftnum;
                        }
                    }
                    else if (info[k].direction == 'R')
                    {
                        info[k].flag = true;
                        if (pre == info[k].right)
                        {
                             info[k].direction = 'L';
                             tmp = info[k].left;
                        }
                        else 
                        {
                             info[k].direction = 'L';
                             tmp = info[pre].rightnum;
                        }
                    }
                    pre = k;
                    k = tmp;
                    ff = false;
                    c++;
                }
                else  break;
          }
          
          cout << "Classmate " << pre << " got the ball last after " << c-1 << " tosses." << endl;;
    }
    
    system("pause");
}
