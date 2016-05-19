#include<iostream>
using namespace std;

typedef struct 
{
    double x;
    double y;
}Point;
Point p[1010];

int main()
{
    int n, i;
    while(cin >> n, n){
        bool flag = true;
        double sum = 0;
        for(i = 0; i < n; i++)
            cin >> p[i].x >> p[i].y;

        p[n].x = p[0].x, p[n].y = p[0].y;
        p[n + 1].y = p[1].x, p[n + 1].y = p[1].y;
        for(i = 0; i < n; i++)
        {
            sum = (p[i + 1].x  - p[i].x) * (p[i + 2].y - p[i].y) - ( p[i + 1].y - p[i].y) * (p[i + 2].x - p[i].x);
            if(sum < 0)
            {
                flag = false;
                break;
            }
        }
        if(flag)
            puts("convex");
        else
            puts("concave");
    }
    return 0;
}