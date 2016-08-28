#!/usr/bin/env python
# coding=utf-8

import jieba

file = open('blacklist.txt', mode='r+', encoding='utf-8')
blacklist = []
for line in file:
    words = line.strip().split(' ')
    for word in words:
        if len(word) > 1:
            blacklist.append(word.lower()+'\n')
blacklist.sort()
file = open('temp.txt', mode='w+', encoding='utf-8')
file.writelines(blacklist)
file.close()