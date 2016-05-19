#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int main(void)
{
    int n;
    char c;
    int k,t,e,mark;
    int i,j,from,to;
    int dist[27];
    int mat[27][27];
    double max,value[27];
    queue<int> q;
    while( cin >> n )
    {
        getchar();
        for( i = 0; i <= 26; i++ )
            for( j = 0; j <= 26; j++ )
                mat[i][j] = 0;
        for( i = 0; i <= 26; i++ )
            dist[i] = value[i] = 0;  //以上为初始化
            
        for( i = 1; i <= n; i++ )
        {
            c = getchar();
            from = c - 'A';
            cin >> value[from];
            getchar();
            while( (c=getchar()) != '/n')
            {
                if( c == '*')  to = 26;
                else to = c- 'A';
                mat[from][to] = mat[to][from] = 1; 
            }
        }        //以上为图的输入过程
        dist[26] = 1;
        q.push(26);
        while( !q.empty() )
        {
            e = q.front();
            q.pop();
            for( j = 0; j < 26; j++)
            {
                k = mat[e][j];
                if( k == 1 && dist[j] == 0)
                {
                    dist[j] = dist[e] + 1;
                    q.push(j);
                }
            }
        }               //以上为bfs的过程 
        
        for( i = 0,max = -1; i < 26; i++ )
        {
            if( dist[i] > 2 )
            {
                t = dist[i] - 2;
                while( t--)
                    value[i] *= 0.95;
            } 
            else if( dist[i] != 2)
                value[i] = 0;
           
            if( value[i] > max )
                max = value[mark = i];
        }      
        cout << "Import from " << (char)(mark+'A') << endl;
        
    }
    return 0;
}