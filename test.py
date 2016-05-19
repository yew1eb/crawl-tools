#!/usr/bin/env python
# -*- coding:utf-8 -*-
import re
from lxml import etree
from bs4 import BeautifulSoup

html = '''
<html><head><meta content="HDOJ ACM ICPC OJ C C++ Pascal Java" name="keywords"/><meta content="text/html;charset=utf-8" http-equiv="Content-Type"/><link href="/images/global.css" media="all" rel="stylesheet" type="text/css"/><link href="/css/diyinhead.css" media="all" rel="stylesheet" type="text/css"/><link href="/css/webinhead.css" media="all" rel="stylesheet" type="text/css"/><script src="/js/global.js" type="text/javascript"></script><script src="/js/register.js" type="text/javascript"></script><script src="/js/MathJax/MathJax/MathJax.js?config=TeX-AMS-MML_HTMLorMML" type="text/javascript"></script><title>User Login</title></head><body>
<a name="top"></a>
<table align="center" border="0" cellpadding="0" cellspacing="0" style="word-wrap:break-word" width="980">
<tr>
<td align="center" style="border:#1A5CC8 1px solid" width="100%">
<a href="/">
<img border="0" height="116" src="/images/banner.jpg" width="100%"/>
</a>
</td>
</tr>
<tr>
<td style="border:#1A5CC8 1px solid">
<table cellpadding="1" cellspacing="0" width="979px">
<tr align="center" bgcolor="#1A5CC8" class="banner" height="25">
<td>Online Judge</td>
<td>Online Exercise</td>
<td>Online Teaching</td>
<td>Online Contests</td>
<td>Exercise Author</td>
</tr>
<tr align="center" style="font-size:16px">
<td valign="top" width="20%">
<a href="/faq.php" style="text-decoration: none">F.A.Q</a><br/>
<a href="/friends" style="text-decoration: none">Hand In Hand</a><br/>
<a href="/onlineuser.php" style="text-decoration: none">Online Acmers</a> <br/>
<!-- /onlineuser.php-->
<a href="/forum" style="text-decoration: none">Forum | </a><a href="/discuss/public/list.php" style="text-decoration: none">Discuss</a><br/>
<a href="/statistic/submit_graph.php" style="text-decoration: none">Statistical Charts</a><br/>
</td>
<td valign="top" width="20%">
<form action="/search.php" method="get">
<a href="/listproblem.php?vol=1" style="text-decoration: none">Problem Archive</a><br/>
<!--<a href="http://feeds.feedburner.com/Hdoj-problemset"><img src="/images/rss1.jpg" alt="problemset" style="vertical-align:text-bottom;"width=20 height=20></a><br>-->
<!--
			 <a href="/submit.php">Submit Solution</a><br>
		-->
<a href="/status.php" style="text-decoration: none">Realtime Judge Status</a><br/>
<a href="/ranklist.php" style="text-decoration: none">Authors Ranklist</a><br/>
<input name="field" type="hidden" value="author"/><input class="text60" name="key"/> <input class="button40" type="submit" value="Search"/>
<!--
			<input name=field value=problem type=hidden><input class=text60 name=key>&nbsp;<input class=button40 type=submit value=Search>
		-->
</form>
</td>
<td valign="top" width="20%">
<form action="/search.php" method="get">
		     <a href="http://code.hdu.edu.cn/" style="text-decoration: none">C/C++/Java Exams     </a><br/>
<a href="/game" style="text-decoration: none">ACM Steps</a><br/>
<a href="/ITJobs/">Go to Job</a><br/>
<a href="/livecast" style="text-decoration: none">Contest LiveCast</a><br/>
<a href="/region" style="text-decoration: none">ICPC@China</a><br/>
<!-- <a href="/register.php">Register New Author</a><br> -->
<!-- <a href="/modifyuser.php">Update Your Information</a><br> -->
</form>
</td>
<td valign="top" width="20%">
<a href="http://bestcoder.hdu.edu.cn" style="text-decoration: none; color: red; font-weight: bold;">Best Coder <sup style="color: gray;">beta</sup></a><br/><a href="/vip/contest_list.php" style="text-decoration: none">VIP</a> | <a href="/contests/contest_list.php" style="text-decoration: none">STD Contests</a><br/><a href="http://code.hdu.edu.cn/vcontest" style="text-decoration: none">Virtual Contests </a><br/>  <a href="/diy/contest_list.php" style="text-decoration: none">  DIY | </a><a href="/webcontest" style="text-decoration: none"><font color="">Web-DIY</font> <font color="gray" size="1"><sup>beta</sup></font></a><br/><a href="/recentcontest" style="text-decoration: none">Recent Contests</a><br/> </td>
<td width="20%">
<form action="/userloginex.php?action=login" method="post">
<table align="center" border="0" cellspacing="0" width="168">
<tr><td align="center" colspan="2"><a href="/qqlogin/oauth/login.php"><img border="0" src="/qqlogin/images/qqlogin.png"/></a></td></tr>
<tr><td width="68">Author ID </td><td align="right"><input class="text90" maxlength="20" name="username" type="text"/></td></tr>
<tr><td>Password </td><td align="right"><input class="text90" maxlength="20" name="userpass" type="password"/></td></tr>
</table>
<input class="button40" name="login" type="submit" value="Sign In"/> <a href="http://bestcoder.hdu.edu.cn/register.php?url=acm.hdu.edu.cn/userloginex.php?action=login" style="text-decoration: none">Register new ID</a>
</form>
</td>
</tr>
</table>
</td>
</tr>
<tr>
<td>
<div align="center" id="rollword"><marquee onmouseout="javascript:this.start();" onmouseover="javascript:this.stop();" scrollamount="2" scrolldelay="30" width="600"><b style="margin-right:20px"><a href="http://acm.hdu.edu.cn/ITJobs/index.php" style="color:red" target="_blank">Hot~~ÕÐÆ¸¡ª¡ª°Í¿¨Ë¹£¨º¼ÖÝ£©£¬ÑÇÐÅ¿Æ¼¼£¬Ò¼³¿ÇªÑô(º¼ÖÝ)</a>
<br/>
</b></marquee></div> </td>
</tr>
<tr>
<td><br/>
<table border="0" cellpadding="0" cellspacing="0" width="100%">
<tbody>
<tr>
<td width="100"> </td>
<td>
<h1 align="center" style="COLOR: #1A5CC8">Sign In Your Account</h1> <form action="userloginex.php?action=login&amp;cid=0&amp;notice=0" method="post" name="formlogin">
<table align="center" border="0" cellspacing="0" style="font-size:14px" width="168">
<tr>
<td width="68">Author ID </td>
<td align="right">
<input class="text90" id="username" maxlength="20" name="username" type="text"/>
</td>
</tr>
<tr>
<td>Password </td>
<td align="right">
<input class="text90" id="userpass" maxlength="20" name="userpass" type="password"/>
</td>
</tr>
<tr>
<td align="center" colspan="2" height="43"><input class="button40" id="login" name="login" type="submit" value="Sign In"/>
				   <a href="http://bestcoder.hdu.edu.cn/register.php?url=acm.hdu.edu.cn/userloginex.php?action=login">Register new ID!</a></td>
</tr>
</table>
</form>
</td>
<td width="100"> </td>
</tr>
</tbody>
</table>
</td>
</tr>
<tr>
<td>
<table cellpadding="1" cellspacing="0" style="border:#1A5CC8 1px solid; font-size:14px" width="100%">
<tr align="center">
<td class="footer_link" height="45"><a href="/">Home</a> | <a href="#top">Top</a></td>
<td style="padding:6px">
			Hangzhou Dianzi University Online Judge 3.0<br/>
			Copyright © 2005-2016 <a href="mailto:acm@hdu.edu.cn">HDU ACM Team</a>. All Rights Reserved.<br/>
<a href="../about_us/developer.php">Designer &amp; Developer </a>: <a>Wang Rongtao</a>&amp;nbsp<a>LinLe</a>&amp;nbsp<a href="mailto:gjavac@gmail.com">GaoJie</a>&amp;nbsp<a href="mailto:gl8997@gmail.com">GanLu</a><br/>
<span class="pagerunstatus">Total 0.000000(s) query 0, Server time : 2016-05-19 19:36:02, Gzip enabled</span> </td>
<td class="footer_link">
<!-- <a href="javascript:history.go(-1);">Back</a> | <a href="javascript:history.forward();">Forward</a>-->
<a href="/admin">Administration</a>
</td>
</tr>
</table>
</td>
</tr>
</table>
<script type="text/javascript">
	var cnzz_protocol = (("https:" == document.location.protocol) ? " https://" : " http://");
	document.write(unescape("%3Cspan id='cnzz_stat_icon_1254072405'%3E%3C/span%3E%3Cscript src='" + cnzz_protocol + "s11.cnzz.com/z_stat.php%3Fid%3D1254072405%26show%3Dpic' type='text/javascript'%3E%3C/script%3E"));
	document.getElementById('cnzz_stat_icon_1254072405').style.display = 'none';
</script>
</body></html>
'''

soup = BeautifulSoup(html, 'lxml')
print(soup)
table = soup.find(id='usercode')
print(table.text)
