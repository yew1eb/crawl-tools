#include <stdio.h>
#define P 3.1415927
#define toFeet(x) x/12.0
#define toMiles(x) x/5280.0

int main(){
    double diameter;//ç´å¾
    int revolutions;//è½¬æ°
    double time;//æ¶é´
    double s;
    int count=1;
    while(scanf("%lf%d%lf",&diameter,&revolutions,&time),revolutions){
        time/=3600;
        diameter/=63360;
        s=diameter*P*revolutions;
        printf("Trip #%d: %.2lf %.2lf\n",count++,s,s/time);
    }
}
