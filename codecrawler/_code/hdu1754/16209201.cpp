/* THE PROGRAM IS MADE BY PYY */
/*----------------------------------------------------------------------------//
    Copyright (c) 2011 panyanyany All rights reserved.

    URL   : http://acm.hdu.edu.cn/showproblem.php?pid=1754
    Name  : 1754 I Hate It

    Date  : Wednesday, September 14, 2011
    Time Stage : half an hour and one hour

    Result: 
4602821    2011-09-14 22:09:08    Accepted    1754
484MS    7160K    2609 B
C++    pyy

4602802    2011-09-14 22:07:05    Output Limit Exceeded    1754
125MS    7136K    2660 B
C++    pyy

4602785    2011-09-14 22:05:30    Time Limit Exceeded    1754
3000MS    7132K    2646 B
C++    pyy

4602584    2011-09-14 21:45:47    Time Limit Exceeded    1754
3000MS    7132K    2525 B
C++    pyy

4602563    2011-09-14 21:43:53    Time Limit Exceeded    1754
3000MS    7132K    2531 B
C++    pyy

4602534    2011-09-14 21:40:48    Time Limit Exceeded    1754
3000MS    7132K    2531 B
C++    pyy


Test Data :

Review :
ä¸å¼å§è¶æ¶è¶å¾è«åå¶å¦ï¼è°è¦è°è¯ä¹ï¼åç°ä¸ä¸ªå¾è¯¡å¼çç°è±¡ï¼å°±æ¯
Update() ç«ç¶ä¼èªå¨æ§è¡å¤ä¸æ¬¡ï¼
ä¸å¼å§update() å½æ°çåæ°ç¬¬äºå¥æ¯è¿æ ·åçï¼
tree[root].max = max (update (2 * root, pos, val), update (2 * root + 1, pos, val)) ;

äºæ¯ä¸ºäºè§å¯å¶åé¨ç©¶ç«æ¯ä¸ºä½ä¼å¤æ§è¡ä¸æ¬¡ï¼å«å°å¶åç«å¼æ¥ï¼
    int a, b ;
    a = update (2 * root, pos, val) ;
    b =    update (2 * root + 1, pos, val) ;

    tree[root].max = max (a, b) ;
åç°å®ç«ç¶åæ­£å¸¸äºï¼æ­£å¨çº³é·ä¹éï¼çç¶çå°äºmax()å½æ°çå®ä¹ï¼ç«ç¶æ¯å®å®ä¹ï¼
#define max(x1, y1) ((x1) > (y1) ? (x1) : (y1))
äºæ¯ä¸åè±ç¶å¼æï¼å ä¸ºå®å®ä¹å¨å±å¼çæ¶åä¼è¿æ ·ï¼
max (update (2 * root, pos, val), update (2 * root + 1, pos, val)) ;
ç­åäºï¼
((update (2 * root, pos, val)) > (update (2 * root, pos, val)) ? (update (2 * root, pos, val)) : (update (2 * root, pos, val)))
äºæ¯ä¹æ¯æ¬¡éå°max()å±å¼ä¹åå°±ä¼åºç°åä¸ªupdate()å½æ°ï¼ç¸å½äºå¤äºææ°çº§çæ§è¡æ¬¡æ°ï¼
//----------------------------------------------------------------------------*/

#include <stdio.h>
#include <conio.h>
#include <string.h>

#define max(x1, y1) ((x1) > (y1) ? (x1) : (y1))
#define min(x1, y1) ((x1) < (y1) ? (x1) : (y1))

#define MAXSIZE 200002

typedef struct {
    int max ;
    int left, right ;
} NODE ;

int        n, m ;
int        num [MAXSIZE] ;
NODE    tree[MAXSIZE * 20] ;

// æå»ºçº¿æ®µæ 
int build (int root, int left, int right)
{
    int mid ;

    // å½åèç¹æè¡¨ç¤ºçåºé´
    tree[root].left        = left ;
    tree[root].right    = right ;

    // å·¦å³åºé´ç¸åï¼åæ­¤èç¹ä¸ºå¶å­ï¼max åºå¨å­å¯¹åºæä¸ªå­¦ççå¼
    if (left == right)
    {
        return tree[root].max = num[left] ;
    }
    mid = (left + right) / 2 ;

    // éå½å»ºç«å·¦å³å­æ ï¼å¹¶ä»å­æ ä¸­è·å¾æå¤§å¼
    int a, b ;
    a = build (2 * root, left, mid) ;
    b = build (2 * root + 1, mid + 1, right) ;

    return tree[root].max = max (a, b) ;
}

// ä»èç¹ root å¼å§ï¼æ¥æ¾ left å right ä¹é´çæå¤§å¼
int find (int root, int left, int right)
{
    int mid ;
    // è¥æ­¤åºé´ä¸ root æç®¡ççåºé´æ äº¤é
    if (tree[root].left > right || tree[root].right < left)
        return 0 ;
    // è¥æ­¤åºé´åå« root æç®¡ççåºé´
    if (left <= tree[root].left && tree[root].right <= right)
        return tree[root].max ;

    // è¥æ­¤åºé´ä¸ root æç®¡ççåºé´é¨åç¸äº¤

    int a, b ;    // ä¸è½è¿æ · max (find(...), find(...));
    a = find (2 * root, left, right) ;
    b = find (2 * root + 1, left, right) ;

    return max (a, b) ;
}

// æ´æ° pos ç¹çå¼
int update (int root, int pos, int val)
{
    // è¥ pos ä¸å­å¨äº root æç®¡ççåºé´å
    if (pos < tree[root].left || tree[root].right < pos)
        return tree[root].max ;

    // è¥ root æ­£å¥½æ¯ä¸ä¸ªç¬¦åæ¡ä»¶çå¶å­
    if (tree[root].left == pos && tree[root].right == pos)
        return tree[root].max = val ;

    // å¦åãããã

    int a, b ;    // ä¸è½è¿æ · max (find(...), find(...));
    a = update (2 * root, pos, val) ;
    b =    update (2 * root + 1, pos, val) ;

    tree[root].max = max (a, b) ;

    return tree[root].max ;
}

int main ()
{
    char c ;
    int i ;
    int x, y ;
    while (scanf ("%d%d", &n, &m) != EOF)
    {
        for (i = 1 ; i <= n ; ++i)
            scanf ("%d", &num[i]) ;
        build (1, 1, n) ;

        for (i = 1 ; i <= m ; ++i)
        {
            getchar () ;
            scanf ("%c%d%d", &c, &x, &y) ;
            if (c == 'Q')
            {
                printf ("%d\n", find (1, x, y)) ;
            }
            else
            {
                num[x] = y ;
                update (1, x, y) ;
            }
        }
    }
    return 0 ;
}
