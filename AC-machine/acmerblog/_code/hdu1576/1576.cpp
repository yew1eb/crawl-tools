pair<LL,LL> ex_gcd(LL a,LL b){
  if(b == 0) return make_pair(1,0);
  pair<LL,LL> t = ex_gcd(b,a%b);
  return make_pair(t.second , t.first - (a / b) * t.second);
}
int main()
{
    int T,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        pair<LL,LL> p = ex_gcd(k,9973);
        LL  q = p.first % 9973 + 9973;
        LL ans = (q * n) % 9973;
        cout<<ans<<endl;
    }
    return 0;
}