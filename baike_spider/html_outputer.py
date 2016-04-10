#!/usr/bin/env python
# -*- coding:utf-8 -*-
class HtmlOutputer(object):

    def __init__(self):
        self.datas = []

    def collect_data(self, data):
        if data is None:
            return
        self.datas.append(data)

    def output_html(self):
        fout = open('output.html', 'w')
        fout.write('<htm>')
        fout.write('<head><meta http-equiv=Content-Type content="text/html;charset=utf-8"></head>')
        fout.write('<body>')
        fout.write('<table>')

        for data in self.datas:
            fout.write("<tr>")
            fout.write(("<td>%s</td>" % data['url']))
            fout.write(("<td>%s</td>" % data['title']))
            fout.write(("<td>%s</td>" % data['summary']))
            fout.write("</tr>")
        fout.write('</table>')
        fout.write('</body>')
        fout.write('</htm>')
