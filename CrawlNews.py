#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Import smtplib for the actual sending function
import smtplib
# Import the email modules we'll need
from email.mime.text import MIMEText

import urllib2, re, codecs
import sys,os,time,atexit,fcntl,string
from signal import SIGTERM

class Daemon(): 
    def __init__(self,pidfile,stdin='/dev/null',stdout='/dev/null',stderr='/dev/null'):
        self.stdin=stdin
        self.stdout=stdout
        self.stderr=stderr
        self.pidfile=pidfile
 
    def daemonize(self):
        try:
            pid=os.fork()
            if pid > 0:
                sys.exit(0)
        except OSError,e:
            sys.stderr.write("fork fist faild:%d (%s)\n" % (e.errno,e.strerror))
            sys.exit(1)
            
        os.chdir('./')
        os.setsid()
        os.umask(0)
        try:
            pid=os.fork()
            if pid > 0:
                sys.exit(0)
        except OSError,e:
            sys.stderr.write("fork second faild:%d (%s)\n" % (e.errno,e.strerror))
            sys.exit(1)
 
 
        sys.stdout.flush()
        sys.stderr.flush()
 
        si=file(self.stdin,'r')
        so=file(self.stdout,'a+')
        se=file(self.stderr,'a+',0)
        os.dup2(si.fileno(),sys.stdin.fileno())
        os.dup2(so.fileno(),sys.stdout.fileno())
        os.dup2(se.fileno(),sys.stderr.fileno())
 

        atexit.register(self.delpid)
        pid=str(os.getpid())
        file(self.pidfile,'w+').write("%s\n" % pid)
 
 
    def delpid(self):
        os.remove(self.pidfile)
 
 
    def start(self):
        try:
            pf=open(self.pidfile,'r')
            pid=int(pf.read().strip())
            pf.close()
        except IOError:
            pid=None
 
        if pid:
            ms="pidfile %s already exist,daemon already running\n"
            sys.stderr.write(ms % self.pidfile)
            sys.exit(1)
        self.daemonize()
        self.run()
 
 
    def stop(self):
        try:
            pf=open(self.pidfile,'r')
            pid=int(pf.read().strip())
            pf.close()
        except IOError:
            pid=None
 
        if not pid:
            ms="pidfile %s does not exit,daemon not running\n"
            sys.stderr.write(ms % self.pidfile)
            return
 
        try:
            while True:
                os.kill(pid,SIGTERM)
                time.sleep(0.1)
                os.remove(self.pidfile)
        except OSError,err:
            err=str(err)
            if err.find('No sush process') > 0:
                if os.path.exists(self.pidfile):
                    os.remove(self.pidfile)
                else:
                    print str(err)
                    sys.exit(1)
 
 
    def restart(self):
        self.stop()
        self.start()


    def run(self):
		pass
         
class MssagePush(Daemon):
    
    send_dict = {
        'rece_list':["873554484@qq.com"],                       #收件人列表
        'send_host':"smtp.qq.com",                              #设置服务器
        'sender':"949020892@qq.com",                            #用户名
        'passwd':"haige6769107"                                 #口令
    }
    
    last_time = time.strftime('%Y-%m-%d', time.localtime(time.time()))
    
    def send_mail(self, subject, content):
        sender = self.send_dict['sender']
        passwd = self.send_dict['passwd']
        send_host = self.send_dict['send_host']
        rece_list = self.send_dict['rece_list']
        
        msg = MIMEText(content, _subtype='html', _charset='utf-8')  
        msg['Subject'] = subject
        msg['From'] = sender
        msg['To'] = ";".join(rece_list)  
        try:  
            server = smtplib.SMTP()  
            server.connect(send_host)  
            server.login(sender, passwd)  
            server.sendmail(sender, rece_list, msg.as_string())  
            server.close()  
            return True  
        except Exception, e:  
            print str(e)  
            return False
    
    
    def get_news(self):
        src_url = 'http://jwc.jsu.edu.cn/tongzhigonggao/'
        req = urllib2.Request(src_url)
        page = urllib2.urlopen(req).read()
        p = re.compile(r'<li><span class="article_publish_date" style="padding-right:2px;">(.*?)</span><a href="(.*?)" title="(.*?)">')
        items = p.findall(page)
        news = []
        for item in items:
            if item[0] >= self.last_time: 
                news.append( [item[0], item[1], item[2]])
        return news
    
    
    def make_text(self):
        news = self.get_news()
        if not news:
            return None
        content = '吉首大学最新教务通知公告:<br><br>'
        for new in news:
            content += new[0]
            content += '    '
            content += '<a href="http://jwc.jsu.edu.cn'+new[1]+'" target="_blank">'
            content += new[2].decode('gb2312')
            content += '</a>'
            content += '<br>'
        content += '<br><br> 推送服务由<a href="http://blog.csdn.net/yew1eb" target="_blank">yew1eb</a>提供. 代码托管在<a href="https://github.com/yew1eb/CrawlNews" target="_blank">Github</a>上.'

        return content


    def run(self):
        fp = open('./last_update_time', 'r')
        self.last_time = fp.read()
        fp.close()
        
        cur_date = time.strftime('%Y-%m-%d', time.localtime(time.time()))
        subject = '吉首大学教务处最新通知公告推送（by  yew1eb）' + cur_date
        while True:
            try:
                content = self.make_text()
                if content == None:
                    time.sleep(3600*2)
                    continue 
                if self.send_mail(subject, content):
                    time.sleep(3600*3)
                    self.last_time = time.strftime('%Y-%m-%d', time.localtime(time.time()))
                    fp = open('./last_update_time', 'w+')
                    fp.write(self.last_time)
                    fp.close()
                    sys.stderr.write("Send success %s\n" % time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(time.time())))
                    
                else:
                    time.sleep(600)
                    sys.stderr.write("Failed to send %s\n" % time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(time.time())))
            except:
                pass 
            time.sleep(3600)


if __name__ == '__main__':
    reload(sys)
    sys.setdefaultencoding('utf-8')  
    mssagePush = MssagePush('./pidfile', stderr='./error_log')
    if len(sys.argv) == 2:
        if 'start' == sys.argv[1]:
            mssagePush.start()
        elif 'stop' == sys.argv[1]:
            mssagePush.stop()
        elif 'restart' == sys.argv[1]:
            mssagePush.restart()
        else:
            print 'unkonow command'
            sys.exit(2)
        sys.exit(0)
    else:
        print "usage:%s start|stop|restart" % sys.argv[0]
        sys.exit(2)

