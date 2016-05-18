#include <stdio.h>
#include <math.h>

//注意精度，1e-8直接WA了一次
#define EPS 1e-6
#define PI acos(-1.0)

double dist[3],angle[3];
double point[3][2];

double cal_dist(int i,int j)
{
    return sqrt((point[i][0] - point[j][0]) * (point[i][0] - point[j][0]) + (point[i][1] - point[j][1]) * (point[i][1] - point[j][1]));
}
///求圆周角
double cal_angle(int i,int j,int k)
{
    return acos((dist[i] * dist[i] + dist[j] * dist[j] - dist[k] * dist[k])/(2.0 * dist[i] * dist[j]));
}
///判断是否为整数，记得加0.05，注意 1 可能被表示成0.99999999999
bool ok(double x)
{
    return fabs(x - int(x + 0.05)) < EPS;
}
int main()
{
    int i;
    while(scanf("%lf%lf",&point[0][0],&point[0][1]) == 2)
    {
        scanf("%lf%lf%lf%lf",&point[1][0],&point[1][1],&point[2][0],&point[2][1]);
        dist[0] = cal_dist(0,1);
        dist[1] = cal_dist(1,2);
        dist[2] = cal_dist(0,2);

        angle[0] = cal_angle(0,1,2) / PI;
        angle[1] = cal_angle(1,2,0) / PI;
        angle[2] = cal_angle(2,0,1) / PI;

        for(i = 3; i <= 1000; ++i)
            if(ok(angle[0] * i) && ok(angle[1] * i) && ok(angle[2] * i))
                break;
        printf("%d\n",i);
    }
    return 0;
}
