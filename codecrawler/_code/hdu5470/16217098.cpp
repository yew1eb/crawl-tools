#include <bits/stdc++.h>
using namespace std ;

typedef long long LL ;

#define clr( a , x ) memset ( a , x , sizeof a )

const int MAXN = 100005 ;
const int N = 26 ;

namespace Suffix_Automation {

    struct Node {
        Node* nxt[N] ;
        Node* fail ;
        int l ;
        int c ;

        void newnode ( int _l , int _c ) {
            clr ( nxt , 0 ) ;
            fail = NULL ;
            l = _l ;
            c = _c ;
        }
    } ;

    Node node[MAXN << 1] ;
    Node* last ;
    Node* root ;
    Node* cur ;
    Node* point ;

    void init () {
        point = root = last = cur = node ;
        cur->newnode ( 0 , -1 ) ;
    }

    void create ( Node* p , Node* np , int c ) {
        Node *q = p->nxt[c] , *nq = ++ cur ;
        *nq = *q ;
        nq->l = p->l + 1 ;
        q->fail = nq ;
        if ( point == q ) point = nq ;
        if ( np != NULL ) np->fail = nq ;
        for ( ; p && p->nxt[c] == q ; p = p->fail ) p->nxt[c] = nq ;
    }

    void add ( int c ) {
        Node *p = last , *np = last = ++ cur ;
        np->newnode ( p->l + 1 , c ) ;
        for ( ; p && p->nxt[c] == NULL ; p = p->fail ) p->nxt[c] = np ;
        if ( p == NULL ) np->fail = root ;
        else if ( p->l + 1 == p->nxt[c]->l ) np->fail = p->nxt[c] ;
        else create ( p , np , c ) ;
    }
} ;

using namespace Suffix_Automation ;
char s[MAXN] ;
int c[N] ;
LL dp[MAXN] , A , B ;
pair < LL , int > Q[MAXN] ;
int head , tail ;
int n ;

void solve () {
    scanf ( "%s" , s + 1 ) ;
    n = strlen ( s + 1 ) ;
    for ( int i = 0 ; i < N ; ++ i ) scanf ( "%d" , &c[i] ) ;
    scanf ( "%lld%lld" , &A , &B ) ;
    init () ;
    head = tail = 0 ;
    int l = 0 ;
    for ( int i = 1 , j = 0 ; i <= n ; ++ i ) {
        s[i] -= 'a' ;
        dp[i] = dp[i - 1] + c[s[i]] ;
        while ( j + 1 < i && !point->nxt[s[i]] ) {
            add ( s[++ j] ) ;
            if ( point != root && -- l == point->fail->l ) point = point->fail ;
        }
        if ( point->nxt[s[i]] ) point = point->nxt[s[i]] , ++ l ;
        else add ( s[++ j] ) , point = root , head = tail = 0 ;
        while ( head != tail && j > Q[head].second ) ++ head ;
        if ( head != tail ) dp[i] = min ( dp[i] , Q[head].first + i * A + B + B ) ;
        Q[tail ++] = make_pair ( dp[i] - i * A , i ) ;
        while ( head + 1 != tail && Q[tail - 1].first <= Q[tail - 2].first ) {
            -- tail ;
            Q[tail - 1] = Q[tail] ;
        }
    }
    printf ( "%lld\n" , dp[n] ) ;
}

int main () {
    int T ;
    scanf ( "%d" , &T ) ;
    for ( int i = 1 ; i <= T ; ++ i ) {
        printf ( "Case #%d: " , i ) ;
        solve () ;
    }
    return 0 ;
}