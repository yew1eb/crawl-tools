
const
  maxn=2000;
var
  f,v:array[0..maxn]of longint;
  t,i:longint;
function find(x:longint):longint;
var
  k:longint;
begin
  if f[x]=x then exit(x);
  k:=f[x];
  f[x]:=find(f[x]);
  v[x]:=(v[x]+v[k])and 1;
  exit(f[x]);
end;
procedure work;
var
  n,m,i,j,k,x,y:longint;
begin
  fillchar(f,sizeof(f),0);
  fillchar(v,sizeof(v),0);
  readln(n,m);
  for i:=1 to n do
    f[i]:=i;
  for i:=1 to m do
    begin
      readln(x,y);
      if find(x)=find(y) then
      if (v[x]+v[y])and 1<>1 then
      begin
        writeln('Suspicious bugs found!');
        for j:=i+1 to m do
          readln;
        exit;
      end;
      k:=v[x];
      x:=f[x];
      f[x]:=f[y];
      v[x]:=((k+v[y])+1)and 1;
    end;
  writeln('No suspicious bugs found!');
end;
begin
  readln(t);
  for i:=1 to t do
    begin
      writeln('Scenario #',i,':');
      work;
      writeln;
    end;
end.
