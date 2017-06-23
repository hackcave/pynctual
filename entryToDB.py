#!/usr/bin/python

import sqlite3


# updateDB(RollNumber) is called for making an entry in test.db database

def createTable(conn):
	conn.execute('''CREATE TABLE if not exists ATTENDANCE
		(ID INTEGER PRIMARY KEY AUTOINCREMENT,
		ROLL_NUMBER INTEGER NOT NULL,
		DT datetime default (datetime(current_timestamp,'LOCALTIME')));''')
	
def updateDB(RollNumber):
	RollNumber=int(RollNumber)
	global conn
	conn=sqlite3.connect("test.db")
	createTable(conn)
	
	conn.execute("INSERT INTO ATTENDANCE (ROLL_NUMBER) \
      			VALUES (?)",(RollNumber,));
	conn.commit()
	conn.close()



def displayDB():
	try:
		conn
	except:
		conn=sqlite3.connect("test.db")
	finally:
		cursor = conn.execute("SELECT ID,ROLL_NUMBER,DT from ATTENDANCE")
		for row in cursor:
	   		print "ID = ", row[0],
	   		print "     ROLL_NUMBER = ", row[1],
   			print "     DT = ", row[2]
