program POJ1989;//by_poetshy
 const
     maxn=100000;
 var
     a                        :array[1..maxn]of longint;
     v                        :array[1..maxn]of boolean;
     i,n,k,j                    :longint;
     ans                        :longint;
 
 begin
     readln(n,k);
     for i:=1 to n do readln(a[i]);
     j:=0;
     fillchar(v,sizeof(v),0);
     for i:=1 to n do
         begin
             if not v[a[i]] then
                 begin    
                     v[a[i]]:=true;
                     inc(j);
                 end;
             if j=k then
                 begin
                     fillchar(v,sizeof(v),0);
                     j:=0;inc(ans);
                 end;
         end;
     writeln(ans+1);
 end.