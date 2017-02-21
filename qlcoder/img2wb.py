#!/usr/bin/env python
# -*- coding:utf-8 -*-

from PIL import Image


image_file = Image.open('lenna.png')
pix = image_file.load()
width = image_file.size[0]
height = image_file.size[1]
img = Image.new("RGB",(width,height))
for x in range(width):
    for y in range(height):
        r, g, b = pix[x, y]
        if r&1:
            img.putpixel((x,y),(0,255,0))
        else:
            img.putpixel((x,y),(0,0,0))
img.show()
