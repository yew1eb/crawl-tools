if(s[i]>='A'&&s[i]<='Z') {//如果是大写字母
                 on[i]=min(on[i-1],off[i-1]+1)+1;//从on状态转移到on状态不需要按任何键，直接按字母键即可，从off状态转移到on状态的最少步数是：先按Caps Lock键再按字母键，所以是off[i-1]+1+1;
                 off[i]=min(on[i-1]+1,off[i-1]+1)+1;//同理~~~
             }
             else {//如果是小写字母
                 on[i]=min(on[i-1]+1,off[i-1]+1)+1;//在这种情况下从on状态转移到on状态的最小步数是先按Shift键并按字母键，从off状态转移到on状态的最小步数是先按字母键再按Caps Lock键，所以是off[i-1]+1+1;
                 off[i]=min(on[i-1]+1,off[i-1])+1;
             }