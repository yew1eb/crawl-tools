#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double h1,r1,x1,y1,z1;
        double h2,r2,x2,y2,z2,x3,y3,z3;
        scanf("%lf%lf%lf%lf%lf",&h1,&r1,&x1,&y1,&z1);
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&h2,&r2,&x2,&y2,&z2,&x3,&y3,&z3);
        double k1=z1+h1-r1;//åªå¾çå¤´é¨ä¸­ç¹ä½ç½®
        double k2=z2+0.9*h2-r2;//è­¦å¯å¤´é¨ä¸­ç¹ä½ç½®
        double a=x1-x2,b=y1-y2,c=k1-k2;//åªå¾å¤´é¨ä¸­ç¹ä¸è­¦å¯å¤´é¨ä¸­ç¹çè¿çº¿åé
        double a1=b*z3-y3*c,b1=a*z3-x3*c,c1=a*y3-b*x3;//æªçåéä¸åªå¾ãè­¦å¯çå¤´é¨åéçåä¹
        double dis=(a1*a1+b1*b1+c1*c1)/(x3*x3+y3*y3+z3*z3);//æªçè·ç¦»ä¸åªå¾çè·ç¦»çå¹³æ¹
        if(dis<=r1*r1&&(a*x3+b*y3+c*z3>0))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
