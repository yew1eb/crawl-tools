#!/usr/bin/env python
# -*- coding:utf-8 -*-

from PIL import Image
img_list = ['birthday', 'email', 'introducer','password','phone',
            're_password','sex','username']
for img in img_list:
    img_path = 'simple-img/'+img+'.png'
    image_file = Image.open(img_path)
    image_file = image_file.convert('1')
    image_file.save(img+'.png')