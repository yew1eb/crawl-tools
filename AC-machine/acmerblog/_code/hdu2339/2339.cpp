int bfs()
{
int i,tot=0,tt,sg;
for (i=1;i<=h;++i)
   memset(vst[i],-1,(w+2)*sizeof(vst[i][0]));
for (i=m;i;)
{
   --i;
   if (vst[sts[i].x][sts[i].y]<0)
   {
    hd=0;
    tl=1;
    qx[hd]=sts[i].x;
    qy[hd]=sts[i].y;
    vst[sts[i].x][sts[i].y]=i;
    int ax,ay,bx,by,lb=sts[i].h-d,j;
    tt=0;
    sg=1;
    while (hd<tl)
    {
     ax=qx[hd];
     ay=qy[hd];
     ++hd;
     if (grids[ax][ay]==grids[sts[i].x][sts[i].y]) ++tt;
     for (j=0;j<4;++j)
     {
      bx=ax+cx[j];
      by=ay+cy[j];
      if (isvalid(bx,by)&&grids[bx][by]>lb)
      {
       if (vst[bx][by]>i) sg=0;
       if (vst[bx][by]<0)
       {
        vst[bx][by]=i;
        qx[tl]=bx;
        qy[tl]=by;
        ++tl;
       }
      }
     }
    }
    if (sg) tot+=tt;
   }
}
return tot;
}