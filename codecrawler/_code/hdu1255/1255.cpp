#include<iostream>
 #include<string>
 #include<stdlib.h>
 using namespace std;
 
 typedef struct
 {
     double x;
     double y_up;
     double y_down;
     int l_r;
 }LINE;
 
 typedef struct
 {
     double x;
     double y_up;
     double y_down;
     int cover;
     bool has_child;
 }TREE;
 
 int cmp(const void *a,const void *b)
 {
     return *(double *)a>*(double *)b? 1: -1;
 }
 
 TREE tree[1000*1001];
 LINE line[2002];
 int n,index;
 double x1,y1,x2,y2;
 double y[2002];
 
 void build(int i,int l,int r)
 {
     tree[i].cover=0;
     tree[i].x=-1;
     tree[i].has_child=true;
     tree[i].y_up=y[r];
     tree[i].y_down=y[l];
     if(l+1==r)
     {
         tree[i].has_child=false;
         return;
     }
     int mid=(l+r)>>1;
     build(2*i,l,mid);
     build(2*i+1,mid,r);
 }
 
 double insert(int i,double l,double r,double x,int l_r)
 {
     if(tree[i].y_up<=l || tree[i].y_down>=r)
         return 0;
     if(!tree[i].has_child)
     {
         if(tree[i].cover>1)
         {
             double ans=(x-tree[i].x)*(tree[i].y_up-tree[i].y_down);
             tree[i].x=x;
             tree[i].cover+=l_r;
             return ans;
         }
         else
         {
             tree[i].cover+=l_r;
             tree[i].x=x;
             return 0;
         }
     }
     else
         return insert(2*i,l,r,x,l_r)+insert(2*i+1,l,r,x,l_r);
 }
 
 int main()
 {
     int t,i;
     //freopen("D:\\in.txt","r",stdin);
     cin>>t;
     while(t--)
     {
         cin>>n;
         index=1;
         for(i=1;i<=n;i++)
         {
             scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2); 
             line[index].x=x1;
             line[index].l_r=1;
             line[index].y_up=y2;
             line[index].y_down=y1;
             y[index]=y1;
             index++;
 
             line[index].x=x2;
             line[index].l_r=-1;
             line[index].y_up=y2;
             line[index].y_down=y1;
             y[index]=y2;
             index++;
         }
         qsort(y+1,2*n,sizeof(y[0]),cmp);
         qsort(line+1,2*n,sizeof(line[0]),cmp);
         build(1,1,index-1);
         double ans=0;
         for(i=1;i<index;i++)
         {
             ans+=insert(1,line[i].y_down,line[i].y_up,line[i].x,line[i].l_r);
         }
         printf("%.2lf\n",ans);
     }
     return 0;
 }