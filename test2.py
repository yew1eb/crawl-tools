#!/usr/bin/env python
# -*- coding:utf-8 -*-


maxSize = 1000
C = [0 for i in range(maxSize)]

def lowbit(x):
    return x&(-x)

def sum(x):
    ret = 0
    while(x):
        ret += C[x]
        x -= lowbit(x)
    return ret

def add(x, d):
    while(x < maxSize):
        C[x] += d
        x += lowbit(x)


file = open('144043123647536.txt')
maxNum = 0
answer = 0
for row in file.readlines():
    arr = row.split(' ')
    if arr[0]=='up':
        add(int(arr[2]), int(arr[1]))
    elif arr[0]=='down':
        add(int(arr[2]), -int(arr[1]))
    else:
        tmp = sum(int(arr[2])) - sum(int(arr[1])-1)
        print(tmp)
        answer += tmp

print("answer: ",answer)