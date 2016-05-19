//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <iostream>
//#include <iomanip>
//#include <stack>
//using namespace std;
//string str;
//stack<double> s;
//stack<int> op;
//double calc(char k)
//{
//    int oth;
//    double t1, t2, t;
//    if(s.size()<2||op.empty())
//    {
//        op.push(k);
//        continue;
//    }
//    t1 = s.top(); s.pop();
//    t2 = s.top(); s.pop();
//    oth = op.top();
//    if()
//}
//
//int main()
//{
//    int i, tmp;
//    char ch;
//    freopen("in.txt","r",stdin);
//    while(getline(cin,str))
//    {
//        if(str[0]=='0') break;
//        i=0;
//        while(!s.empty()) s.pop();
//        while(!op.empty()) op.pop();
//        while(i<str.size())
//        {
//            tmp = 0;
//            while(i<str.size()&&str[i]==' ') i++;
//            while(i<str.size()&&str[i]>='0'&&str[i]<='9')
//                    tmp =tmp*10 + str[i++]-'0';
//            if(tmp!=0) s.push((double)tmp);
//            cout<<tmp<<endl;
//            i++;
//            k = -1;
//            while(i<str.size()&& str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
//            {
//                if(str[i]=='+') k=0;
//                else if(str[i]=='-') k=1;
//                else if(str[i]=='*') k=2;
//                else if(str[i]=='/') k=3;
//
//            }
//            if(!op.empty())
//            {
//
//            }
//            i++;
//
//        }
//        cout<<fixed<<setprecision(4)<<s.top()<<endl;
//    }
//    return 0;
//}
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    double num[205];
    int i;
    double s;
    char f;
    double sum;
    while(cin>>s)
    {
        memset(num,'\0', sizeof(num));
        num[0] = s;
        i = 0;
        f = getchar();
        if(f=='\n'&&s==0) break;
        while(1)
        {
            cin>>f>>s;
            if(f=='*') num[i]*=s;
            else if(f=='/') num[i] /= s;
            else if(f=='+') num[++i] = s;
            else
            {
                num[++i]=-s;
            }
            if(getchar()=='\n') break;
        }
        sum = 0;
        for(i; i>=0; i--)
            sum +=num[i];
        printf("%.2lf\n",sum);
    }
    return 0;
}
