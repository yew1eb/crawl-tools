#include<iostream>
#include<iomanip>
using namespace std;

double judge_score(int tem)  //åæ°å¯¹åºçç¹æ°ï¼é¢ç®ç»åºçåªæ¯æ´æ°ï¼æä»¥è°ç¨æ¶è¦å¼ºå¶ç±»åè½¬å
{
    if(tem>=90 && tem<=100)
        return 4.0;
    else if(tem>=80 && tem<=89)
        return 3.0;
    else if(tem>=70 && tem<=79)
        return 2.0;
    else if(tem>=60 && tem<=69)
        return 1.0;
    return 0.0;
}

int main()
{
    int t,i;
    double credit,score;

    while(cin>>t)
    {
        double all_score=0.0,all_credit=0.0;
        for(i=0;i<t;i++)
        {
            cin>>credit>>score;
            
            if(score!=-1)  //åæ°ä¸º-1ï¼ä¸è®¡ç®
            {
                all_score+=judge_score(int(score))*credit; //åæ°çå¼ºå¶ç±»åè½¬åï¼åºè¯¥å¾éè¦ï¼æ²¡åè¿ä¸ªï¼ç»æWAäº8æ¬¡
                all_credit+=credit;
            }
        }

        if(all_credit==0.0 || all_score==0.0)  //GPAä¸å­å¨
        {
            cout<<-1<<endl;
            continue;
        }

        double GPA=all_score*1.0/all_credit;
        cout<<setiosflags(ios::fixed)<<setprecision(2)<<GPA<<endl;
    }
    return 0;
}
