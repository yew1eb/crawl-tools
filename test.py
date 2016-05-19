#!/usr/bin/env python
# -*- coding:utf-8 -*-

count = 0
for i in range(1, 1000000):
    if i % 2 == 0 or i % 3==0:
        count = count + 1;
    if count == 2333:
        print(i)
        break