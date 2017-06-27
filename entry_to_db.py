 #!/usr/bin/env python

import sqlite3


# updateDB(RollNumber) is called for making an entry in test.db database

def createTable(conn):
	conn_cursor=conn.cursor()
	conn_cursor.execute('''CREATE TABLE IF NOT EXISTS ATTENDANCE
		(id INTEGER PRIMARY KEY AUTOINCREMENT,
		roll_number INTEGER NOT NULL,
		dt datetime default (datetime(current_timestamp,'LOCALTIME')));''')
	
def updateDB(RollNumber):
	RollNumber=int(RollNumber)
	global conn
	conn=sqlite3.connect("test.db")
	createTable(conn)
	conn_cursor=conn.cursor()
	conn_cursor.execute("INSERT INTO ATTENDANCE (roll_number) VALUES (?)",(RollNumber,));
	conn.commit()
	conn.close()



def displayDB():
	try:
		conn
	except:
		conn=sqlite3.connect("test.db")
	finally:
		conn_cursor=conn.cursor()
		cursor = conn_cursor.execute("SELECT id,roll_number,dt from ATTENDANCE")
		for row in cursor:
			print 'Id={} RollNumber={} Date/Time={}'.format(row[0],row[1],row[2]);
