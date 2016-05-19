        for(int j = 0; j < 20; j++) {
            for(int i = 0; i < 1<<20; i++) if(i>>j&1) {
                cnt[i^(1<<j)] += cnt[i];
            }
        }