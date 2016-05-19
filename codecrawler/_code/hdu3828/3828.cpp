#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define mod 1000000009LL
#define ll __int64
#define maxn 2000
ll next[maxn];
void GetNext(char str[])
{
 ll i = 1, len = strlen(str + 1);
 next[1] = 0;
 ll j = 0;
 while(i <= len)
 {
 if (j == 0 || str[i] == str[j])
 {
 i++;
 j++;
 next[i] = j;
 }
 else
 j = next[j];
 }
}
//-1 include 0 no x len
ll kmp(char str[], char str2[])
{
 ll i = 1, j = 1, len1 = strlen(str + 1), len2 = strlen(str2 + 1);
 while(i <= len1 && j <= len2)
 {
 if (j == 0 || str[i] == str2[j])
 {
 i++;
 j++;
 }
 else j = next[j];
 }
 if (j > len2) return -1;
 if (i > len1) return j - 1;
}
ll n, ca;
char str[20][100];
ll share[20][20], len[20];
ll dp[85536][20];
ll pre[85536][20][2];
char strtmp[maxn], strtmp2[maxn];
void getans(ll i, ll j, ll from)
{
 if (from == -1) strcpy(strtmp, str[j] + 1);
 else strcat(strtmp, str[j] + 1 + share[from][j]);
 if (pre[i][j][0] != -1 && pre[i][j][1] != -1)
 getans(pre[i][j][0], pre[i][j][1], j);
}
ll getInt(char strtmp2[])
{
 ll ans = 0;
 for(ll i = 0; i <strlen(strtmp2); i++)
 {
 if (strtmp2[i] == '1')ans=(ans<<1)+1;
 else ans=ans<<1;
 if (ans >= mod) ans %= mod;
 }
 return ans;
}
bool vst[20];
char cat[20][20][300];
int main()
{
 ca = 1;
 while(scanf("%I64d", &n) != EOF)
 {
 for(ll i = 0; i < n; i++)
 {
 unsigned ll a;
 scanf("%I64u", &a);
 char tmp[maxn], ccnt = 0;
 while(a)
 {
 if (a & 1LL) tmp[ccnt++] = '1';
 else tmp[ccnt++] = '0';
 a >>= 1LL;
 }
 for(ll j = 0, k = ccnt - 1; j < ccnt; j++, k--)
 str[i][j + 1] = tmp[k];
 str[i][1 + ccnt] = '\0';
 }
 memset(share, 0, sizeof(share));
 memset(vst, 0, sizeof(vst));
 for(ll i = 0; i < n; i++)
 for(ll j = 0; j < n; j++)
 {
 GetNext(str[i]);
 if (i != j && !vst[j] && kmp(str[j], str[i]) == -1)//i��j����
 {
 vst[i] = 1;
 break;
 }
 }
 ll cnt = 0;
 for(ll i = 0; i < n; i++)
 if (!vst[i]) strcpy(str[cnt++] + 1, str[i] + 1);
 n = cnt;
 for(ll i = 0; i < n; i++)
 {
 len[i] = strlen(str[i] + 1);
 for(ll j = 0; j < n; j++)
 {
 GetNext(str[j]);
 if(i==j)continue;
 share[i][j] = kmp(str[i], str[j]);
 if(share[j][j]==-1)share[i][j]=strlen(str[j]+1);
 }
 }
 for(ll i = 0; i < n; i++)
 for(ll j = 0; j < n; j++)
 {
 strcpy(cat[i][j], str[i] + 1);
 strcat(cat[i][j], str[j] + 1 + share[i][j]);
 }
 memset(dp, -1, sizeof(dp));
 memset(pre, -1, sizeof(pre));
 for(ll i = 0; i < n; i++)
 {
 dp[1 << i][i] = len[i];
 pre[1 << i][i][0] = -1;
 }
 for(ll i = 1; i < (1 << n); i++)
 {
 for(ll j = 0; j < n; j++)
 {
 if (dp[i][j] != -1)
 {
 for(ll k = 0; k < n; k++)
 {
 if (!(i>>k&1))
 {
 ll st = (i | (1 << k));
 ll val = dp[i][j] + len[k] - share[k][j];
 if (dp[st][k] == -1 || val < dp[st][k])
 {
 dp[st][k] = val;
 pre[st][k][0] = i;
 pre[st][k][1] = j;
 }
 else if (val == dp[st][k])
 {
 if (strcmp(cat[k][j], cat[k][pre[st][k][1]]) < 0)
 {
 pre[st][k][0] = i;
 pre[st][k][1] = j;
 }
 }
 }
 }
 }
 }
 }
 ll id = -1, mmax = 100000;
 for(ll i = 0, k = (1 << n) - 1; i < n; i++)
 {
 if (dp[k][i] < mmax)
 {
 mmax = dp[k][i];
 id = i;
 }
 else if (dp[k][i] == mmax && strcmp(str[i] + 1, str[id] + 1) < 0)
 {
 id = i;
 }
 }
 getans((1 << n) - 1, id, -1);
 printf("%I64d\n", getInt(strtmp));
 }
 return 0;
}