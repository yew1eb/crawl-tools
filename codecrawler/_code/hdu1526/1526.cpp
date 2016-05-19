#include<stdio.h>
#include<string.h>

#define N 2050
inline int Max(int a,int b){return a>b?a:b;}

int num;
char s[N*2][26];
int idx(char *ss){
	for(int i = 1; i <num ;i++)
		if(strcmp(ss, s[i])==0)return i;
	strcpy(s[num], ss);
	return num++;
}

int yn, xn;
int x[N], y[N], map[N][N];

int lef[N];
bool T[N];
int match(int u){
	for(int i = 1; i <= yn; i++){
		if(map[ x[u] ][ y[i] ]==0 || T[ y[i] ])continue;
		T[ y[i] ] = 1;
		if(lef[ y[i] ] == -1 || match( lef[ y[i] ] ) )
		{
			lef[ y[i] ] = u;
			return 1;
		}
	}
	return 0;
}
int slove(){
	int ans = 0;
	memset(lef, -1, sizeof(lef));
	for(int i = 1; i <= xn; i++){
		memset(T,0,sizeof(T));
		ans += match(i);
	}
	return ans;
}

void Floyd(){
	for(int k = 1; k < num; k++)
		for(int i = 1; i < num; i++)
			if(map[i][k])
			for(int j = 1; j < num; j++)
			{
				if(map[k][j]) map[i][j] = 1;
			}
}

char temp[26];
void init(){
	int i, j;
	num = 1;
	memset(map, 0, sizeof(map));
	scanf("%d",&yn);
	for(i = 1; i <= yn; i++)
	{
		scanf("%s",temp); 
		y[i] = idx(temp);
		map[ y[i] ][ y[i] ] = 1;
	}
	scanf("%d",&xn);
	for(i = 1; i <= xn; i++){
		scanf("%s",temp); scanf("%s",&temp);
		x[i] = idx(temp);
	}
	
	int edge; scanf("%d",&edge);
	while(edge--){
		scanf("%s",temp); int a = idx(temp);
		scanf("%s",temp); int b = idx(temp);
		map[ a ][ b ] = 1;
	}
	Floyd();
}

int main(){
	int t; scanf("%d",&t);
	while(t--){
	init();
	printf("%d\n",xn - slove());
	if(t)printf("\n");
	}
	return 0;
}
/*
99

4
A
B
C
D
6
a 0
b 1
c 2
d 3
e 4
f 5
9
0 A
0 D
1 A
1 B
2 B
2 C
3 C
4 A
5 A

5
A
B
C
D
E
5
a 0
b 1
c 2
d 3
e 4
9
0 A
0 D
1 A
1 B
2 B
2 C
2 E
3 C
4 B

5
A
B
C
D
E
6
a C
b C
c C
d C
e A
f A
4
C E
E D
E B
B A

5
A
B
C
D
E
4
a W
b X
c Y
d Z
4
W X
X Y
Y Z
Z Q

30
r0
r1
r2
r3
r4
r5
r6
r7
r8
r9
r10
r11
r12
r13
r14
r15
r16
r17
r18
r19
r20
r21
r22
r23
r24
r25
r26
r27
r28
r29
30
d0 p0
d1 p1
d2 p2
d3 p3
d4 p4
d5 p5
d6 p6
d7 p7
d8 p8
d9 p9
d10 p10
d11 p11
d12 p12
d13 p13
d14 p14
d15 p15
d16 p16
d17 p17
d18 p18
d19 p19
d20 p20
d21 p21
d22 p22
d23 p23
d24 p24
d25 p25
d26 p26
d27 p27
d28 p28
d29 p29
100
p15 r19
p12 r21
p12 r11
p7 r2
p10 r16
p29 r4
p3 r17
p23 r28
p27 r1
p18 r2
p3 r29
p5 r8
p14 r9
p23 r0
p29 r0
p18 r14
p19 r22
p27 r24
p3 r5
p18 r5
p21 r10
p10 r17
p27 r25
p15 r16
p27 r4
p18 r22
p25 r15
p0 r9
p25 r23
p1 r16
p16 r11
p0 r27
p3 r19
p13 r29
p24 r2
p4 r8
p4 r6
p2 r2
p9 r21
p28 r19
p13 r24
p4 r14
p3 r21
p29 r27
p7 r15
p8 r29
p13 r12
p19 r18
p20 r7
p5 r16
p6 r22
p9 r8
p25 r18
p29 r15
p9 r4
p18 r13
p2 r25
p25 r10
p24 r0
p14 r5
p19 r17
p3 r1
p17 r8
p18 r15
p23 r27
p23 r10
p8 r14
p25 r7
p10 r21
p17 r12
p16 r4
p14 r10
p5 r21
p8 r24
p0 r11
p17 r17
p11 r5
p2 r26
p25 r17
p6 r25
p23 r24
p24 r12
p29 r28
p11 r1
p19 r20
p5 r5
p24 r19
p7 r21
p10 r7
p7 r11
p10 r25
p20 r22
p22 r15
p18 r17
p24 r17
p4 r18
p11 r29
p22 r2
p3 r8
p15 r0

100
r0
r1
r2
r3
r4
r5
r6
r7
r8
r9
r10
r11
r12
r13
r14
r15
r16
r17
r18
r19
r20
r21
r22
r23
r24
r25
r26
r27
r28
r29
r30
r31
r32
r33
r34
r35
r36
r37
r38
r39
r40
r41
r42
r43
r44
r45
r46
r47
r48
r49
r50
r51
r52
r53
r54
r55
r56
r57
r58
r59
r60
r61
r62
r63
r64
r65
r66
r67
r68
r69
r70
r71
r72
r73
r74
r75
r76
r77
r78
r79
r80
r81
r82
r83
r84
r85
r86
r87
r88
r89
r90
r91
r92
r93
r94
r95
r96
r97
r98
r99
100
d0 p0
d1 p1
d2 p2
d3 p3
d4 p4
d5 p5
d6 p6
d7 p7
d8 p8
d9 p9
d10 p10
d11 p11
d12 p12
d13 p13
d14 p14
d15 p15
d16 p16
d17 p17
d18 p18
d19 p19
d20 p20
d21 p21
d22 p22
d23 p23
d24 p24
d25 p25
d26 p26
d27 p27
d28 p28
d29 p29
d30 p30
d31 p31
d32 p32
d33 p33
d34 p34
d35 p35
d36 p36
d37 p37
d38 p38
d39 p39
d40 p40
d41 p41
d42 p42
d43 p43
d44 p44
d45 p45
d46 p46
d47 p47
d48 p48
d49 p49
d50 p50
d51 p51
d52 p52
d53 p53
d54 p54
d55 p55
d56 p56
d57 p57
d58 p58
d59 p59
d60 p60
d61 p61
d62 p62
d63 p63
d64 p64
d65 p65
d66 p66
d67 p67
d68 p68
d69 p69
d70 p70
d71 p71
d72 p72
d73 p73
d74 p74
d75 p75
d76 p76
d77 p77
d78 p78
d79 p79
d80 p80
d81 p81
d82 p82
d83 p83
d84 p84
d85 p85
d86 p86
d87 p87
d88 p88
d89 p89
d90 p90
d91 p91
d92 p92
d93 p93
d94 p94
d95 p95
d96 p96
d97 p97
d98 p98
d99 p99
100
p95 r21
p44 r99
p52 r5
p53 r24
p92 r32
p89 r20
p85 r45
p33 r32
p89 r45
p14 r38
p27 r77
p47 r32
p8 r99
p3 r50
p77 r78
p0 r72
p99 r96
p23 r4
p1 r29
p80 r45
p61 r70
p66 r99
p67 r99
p83 r8
p97 r98
p46 r76
p75 r93
p8 r35
p93 r11
p85 r70
p90 r37
p94 r41
p33 r69
p45 r87
p98 r26
p32 r12
p96 r98
p63 r15
p50 r46
p23 r99
p44 r69
p75 r20
p14 r84
p7 r7
p47 r45
p29 r37
p82 r23
p31 r68
p45 r76
p55 r43
p54 r87
p7 r2
p38 r22
p17 r40
p69 r40
p39 r65
p61 r66
p37 r76
p2 r45
p83 r50
p90 r65
p39 r24
p88 r70
p92 r33
p99 r47
p29 r53
p35 r88
p56 r25
p11 r73
p65 r32
p66 r56
p97 r27
p22 r87
p55 r25
p32 r91
p27 r74
p56 r66
p98 r96
p89 r91
p82 r88
p38 r11
p93 r25
p51 r49
p50 r14
p75 r67
p98 r41
p23 r48
p20 r98
p35 r28
p23 r67
p19 r2
p41 r75
p68 r91
p71 r9
p82 r53
p97 r73
p16 r91
p98 r20
p92 r1
p86 r67

20
r0
r1
r2
r3
r4
r5
r6
r7
r8
r9
r10
r11
r12
r13
r14
r15
r16
r17
r18
r19
20
d0 p0
d1 p1
d2 p2
d3 p3
d4 p4
d5 p5
d6 p6
d7 p7
d8 p8
d9 p9
d10 p10
d11 p11
d12 p12
d13 p13
d14 p14
d15 p15
d16 p16
d17 p17
d18 p18
d19 p19
20
p10 r7
p5 r1
p6 r10
p15 r2
p17 r9
p10 r3
p6 r3
p6 r14
p4 r16
p3 r5
p6 r17
p9 r4
p2 r19
p19 r0
p3 r1
p7 r0
p2 r6
p10 r10
p8 r19
p19 r19

3
A
B
C
5
a a
b b
c c
x p99
d d
100
p1 p0
p2 p1
p3 p2
p4 p3
p5 p4
p6 p5
p7 p6
p8 p7
p9 p8
p10 p9
p11 p10
p12 p11
p13 p12
p14 p13
p15 p14
p16 p15
p17 p16
p18 p17
p19 p18
p20 p19
p21 p20
p22 p21
p23 p22
p24 p23
p25 p24
p26 p25
p27 p26
p28 p27
p29 p28
p30 p29
p31 p30
p32 p31
p33 p32
p34 p33
p35 p34
p36 p35
p37 p36
p38 p37
p39 p38
p40 p39
p41 p40
p42 p41
p43 p42
p44 p43
p45 p44
p46 p45
p47 p46
p48 p47
p49 p48
p50 p49
p51 p50
p52 p51
p53 p52
p54 p53
p55 p54
p56 p55
p57 p56
p58 p57
p59 p58
p60 p59
p61 p60
p62 p61
p63 p62
p64 p63
p65 p64
p66 p65
p67 p66
p68 p67
p69 p68
p70 p69
p71 p70
p72 p71
p73 p72
p74 p73
p75 p74
p76 p75
p77 p76
p78 p77
p79 p78
p80 p79
p81 p80
p82 p81
p83 p82
p84 p83
p85 p84
p86 p85
p87 p86
p88 p87
p89 p88
p90 p89
p91 p90
p92 p91
p93 p92
p94 p93
p95 p94
p96 p95
p97 p96
p98 p97
p99 p98
p0 A

ans:
2
2
0
1
4
2
49
9
4


*/