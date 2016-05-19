//1160
#include <iostream>
#include <algorithm>
using namespace std;

struct mouse
{
    int id;
    int weight;
    int speed;
    int pos;
    int pre;
}s[10005];
bool cmp(mouse a,mouse b)
{
    return(a.weight<b.weight||(a.weight==b.weight&&a.speed<b.speed));
}

int main()
{
    int count=0;
    while(scanf("%d %d",&s[count].weight,&s[count].speed)!=EOF)
    {
        s[count].id=count+1;
        count++;
    }
    sort(s,s+count,cmp);
/*********************************************************************************/
//æé¿éå¢å­åºåé¨å
    int ans[10005]={0};
    s[0].pos=1;
    int i,j,max=1,maxi=0;
    //è®°å½æ¯ä¸ªç¹çåºåä½ç½®
    for(i=1;i<count;i++)
    {
        j=max;
        while(j)
        {
            if(s[i].weight>s[ans[j]].weight&&s[i].speed<s[ans[j]].speed)
            {
                s[i].pos=j+1;
                ans[j+1]=i;
                s[i].pre=ans[j];
                break;
            }
            j--;
        }
        //ç¬¬ä¸ä¸ªç¹
        if(j==0)
        {
            s[i].pos=1;
            ans[1]=i;
        }
        //ç®åä¸ºæ­¢æé¿çç¹
        if(s[i].pos>max)
        {
            max=s[i].pos;
            maxi=i;
        }
    }
/*    
    for(int cc=0;cc<count;cc++)
        cout<<cc<<' '<<s[cc].id<<' '<<s[cc].weight<<' '<<s[cc].speed<<' '<<s[cc].pos<<' '<<s[cc].pre<<endl;
*/

    cout<<max<<endl;
    //è¾åºæé¿åºå
    int temp[10005];
    for(i=1;i<=max;i++)
    {
        temp[i]=s[maxi].id;
        maxi=s[maxi].pre;
    }
    for(i=max;i>0;i--)
        cout<<temp[i]<<endl;
/*********************************************************************************/

    return 0;
}