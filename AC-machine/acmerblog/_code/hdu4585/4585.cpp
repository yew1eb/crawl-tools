#include<iostream>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<cstdio>
using namespace std;
struct Node
{
    Node* son[2];
    int rank;
    int size;
    int key;
    bool operator<(const Node &a)const
    {
        return rank<a.rank;   //重载小于好，用于维护堆的性质
    }
    int cmp(int x)const
    {
        if(x==key) return -1;    //比较函数，用于确定寻找的值的位置，0表示左儿子，1表示右儿子，-1代表当前节点
        return x<key?0:1;
    }
    void maintain()//这里仅仅需要维护size
    {
        size = 1 + son[0]->size + son[1]->size;
    }
};
struct Treap
{
    Node * root;
    Node *null = new Node();//定义空结点，可以有效避免NULL带来的问题
    //初始化Treap
    void initial()
    {
        srand(time(NULL));
        root = null;
    }
    //旋转操作，d=0时代表左旋，d=1时代表右旋
    void rotate(Node* &o,int d)
    {
        Node*  k = o->son[d^1];
        o->son[d^1] = k -> son[d];
        k->son[d] = o;
        o->maintain();//注意，必须先维护o再维护k，因为o是子节点，不优先维护，会导致父节点出错
        k->maintain();
        o = k;
    }
    void ins(Node*  &o,int x)
    {
        if(o==null)
        {
            o = new Node();
            o->son[0] = o->son[1] = null;
            o->rank = rand();
            o->key = x;
            o->size = 1;
        }
        else
        {
            int d = o->cmp(x);
            ins(o->son[d],x);
            o->maintain();
            if(o < o->son[d])
                rotate(o,d^1);//当位于左儿子时，需要进行的是右旋，当位于右儿子时应当进行左旋，因此通项为rotate(o,d^1)
        }
    }
    void del(Node* &o,int x)
    {
        int d = o->cmp(x);
        if(d==-1)//已经找到待删除节点，将会有两种情况
        {
            if(o->son[0] == null) o = o->son[1];//左儿子为空，直接连接父节点和右儿子
            else if(o->son[1] == null) o= o->son[0];//右儿子为空，同上
            else
            {
                d = o->son[0] < o->son[1] ? 0:1;//在子节点中找到一个rank大的节点，将其旋转到当前节点，那么当前节点应当位于相反的子节点
                rotate(o,d);
                del(o->son[d],x);
            }
        }
        else
            del(o->son[d],x);
        if(o!=null) o->maintain();//删除节点后，需要对size进行维护。需要注意的是，如果节点为空时，就不需要维护了
    }
    int kth(Node* o,int k)//寻找第k大数
    {
        if(o == null || k<=0 || k>o->size) return -1;//k过大或者过小都不能找到，Treap中没有节点也无需找
        int s = (o->son[1] == null?0:o->son[1]->size);//获得右儿子的size
        if(k == s+1) return o->key;//当k为 s + 1时，说明当前节点就是答案
        else
            if(k<=s) return kth(o->son[1],k);//当k<s时，说明第k大数在右子树，k值无需更改
        else
            return kth(o->son[0],k-s-1);//当k>s+1时，第k大数在左子树，需要减去右子树的值和节点本身
    }
    int find(Node* o,int k)//返回该数是第几大
    {
        if(o == null) return -1;
        int d = o->cmp(k);
        if(d == -1) return 1 + o->son[1]->size;
        else if(d == 1) return find(o->son[d],k);
        else
        {
            int tmp = find(o->son[d],k);
            if(tmp == -1) return -1;
            else
                return tmp + 1 + o->son[1]->size;
        }
    }
} treap;
int id[5000005];
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        treap.initial();
        int x,y;
        scanf("%d%d",&x,&y);
        treap.ins(treap.root,y);
        id[y] = x;
        printf("%d %d\n",x,1);
        for(int i =2;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            id[y] = x;
            treap.ins(treap.root,y);
            int t = treap.find(treap.root,y);
            int ans1,ans2,ans;
            ans1 = treap.kth(treap.root,t-1);
            ans2 = treap.kth(treap.root,t+1);
            if(ans1 != -1)
                {
                    if(ans2==-1) ans = ans1;
                    else
                        if(ans1 - y >= y-ans2) ans = ans2; else ans = ans1;
                }
            else
                ans =ans2;
            printf("%d %d\n",x,id[ans]);
        }
    }
    return 0;
}
