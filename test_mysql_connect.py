#!/usr/bin/env python
# -*- coding:utf-8 -*-

import pymysql

conn = pymysql.connect(
    host='127.0.0.1',
    port=3306,
    user='root',
    passwd='root',
    db='crawl_db',
    charset = 'utf8'
)

cursor = conn.cursor()

# cursor() 使用该连接创建并返回游标
# commit() 提交当前事务
# rollback() 回滚当前事务
# close() 关闭连接

'''
cursor 游标对象: 用于执行查询和获取结果

cursor对象支持的方法:
execute()           执行一条sql命令
fetchone()          取的结果集的下一行
fetchmany(size)     获取结果集的下几行
fetchall()          获取结果集中剩下的所有行
rowcount()          最近一次execute返回数据的行数或影响行数
close()             关闭游标对象
'''

'''
SELECT 语句用法
'''
sql = "SELECT * FROM user"
cursor.execute(sql)
print(cursor.rowcount)
rs = cursor.fetchall()
for row in rs:
    print("id=%s, username=%s " % row)

'''
事务: 访问和更新数据库的一个程序执行单元
- 原子性 : 事务中包括的诸操作要么都做,要么都不做
- 一致性 : 事务必须使数据库从一致性状态变到另一个一致性状态
- 隔离性 : 一个事务的执行不能被其他事务干扰
- 持久性 : 事务一旦提交, 它对数据库的改变就是永久性的

正常结束事务 : conn.commit()
异常结束事务 : conn.rollback()
'''

sql_insert = "insert into user(id, username) values(null, 'zhangsan')"
sql_update = "update user set username='yew1eb' where id = 1004"
sql_delete = "delete from user where id = 1003"

cursor.execute(sql_insert)
conn.commit()
cursor.execute(sql_update)
conn.commit()
cursor.execute(sql_delete)
conn.commit()

cursor.close()
conn.close()