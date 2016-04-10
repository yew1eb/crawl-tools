#!/usr/bin/env python
# -*- coding:utf-8 -*-

import pymysql
import urllib.request

def db_connect():
    conn = pymysql.connect(
        host='127.0.0.1',
        port=3306,
        user='root',
        passwd='root',
        db='crawl_db',
        charset='utf8'
    )
    return conn


def get_email_address(fetch_limit):
    select_sql = 'SELECT id,address FROM email163 WHERE status=0 LIMIT %d' % fetch_limit
    rs = []
    try:
        conn = db_connect()
        cursor = conn.cursor()
        cursor.execute(select_sql)
        print("Get need process records count : %d" % cursor.rowcount)
        rs = cursor.fetchall()
    except Exception as e:
        print(e)
    finally:
        return rs


def send_request(email):
    query = 'https://163password.download/s?e=%s' % email
    response = urllib.request.urlopen(query)
    if response.getcode() != 200:
        return False,""
    result = str(response.read())
    print("   " + result)
    if result == b'\xe6\x9c\xaa\xe6\x89\xbe\xe5\x88\xb0':
        print(result.strip())
    return False, "****"


def insert_table_email(items):
    if None == items:
        return
    try:
        conn = db_connect()
        cursor = conn.cursor()
        for item in items:
            ins_sql = 'INSERT INTO email(id,username,suffix,passwd) ' \
                      'VALUES(null,\'' + item['username'] + '\',\'' + '163.com' + '\',\'' + item['username'] + '\')'
            print(ins_sql)
            cursor.execute(ins_sql)
            upd_sql = 'UPDATE email163 SET status=1 WHERE id = %d' % item['id']
            print(upd_sql)
            cursor.execute(upd_sql)
        conn.commit()
    except Exception as e:
        print(e)
    finally:
        cursor.close()
        conn.close()


def main():
    emails = get_email_address(fetch_limit=5)
    items = []
    for email in emails:
        exist, result = send_request(email[1])
        if False == exist:
            continue
        temp = {'username': email[1].split('@')[0],
                'passwd': result,
                'id': email[0]}
        items.append(temp)

    insert_table_email(items)


if __name__ == '__main__':
    main()
