#!/usr/bin/python

import sqlite3
import datetime

def createTable(conn):
	conn.execute('''CREATE TABLE if not exists SUMMARY_ATTENDANCE
		(ID INTEGER PRIMARY KEY AUTOINCREMENT,
		ROLL_NUMBER INTEGER NOT NULL,
		DT datetime default (datetime(current_timestamp,'LOCALTIME')),
		DURATION_HOURS FLOAT);''')

def displayDB():
	try:
		conn
	except:
		conn=sqlite3.connect("test.db")
	finally:
		cursor = conn.execute("SELECT ID,ROLL_NUMBER,DT,DURATION_HOURS from SUMMARY_ATTENDANCE")
		for row in cursor:
	   		print "ID=", row[0],
	   		print " ROLL_NUMBER=", row[1],
   			print " DT=", row[2],
   			print " DURATION_HOURS=",row[3]
   			
# NOTE IT IS ASSUMED THAT EVERYONE HAS MARKED EXIT, EXACTLY BEFORE 2:00AM.
# NOT MARKING JUST BEFORE 2:00 AM WOULD MARK HIM AS DEFAULTER.
# EVERY ENTRY AFTER 2:00 AM WOULD BE AN "INCOMING ENTRY" ONLY

def getSummary():
	Summary('NYO',8);
	Summary('RTE',2);

def Summary(filename,hours):
	conn=sqlite3.connect("test.db")
	list_students=open(filename,'r').readlines()
	for student in list_students:
		student=student.strip()
		prevdate=datetime.datetime.now()-datetime.timedelta(days=1)
		cursor=conn.execute("SELECT ID,ROLL_NUMBER,DT from ATTENDANCE where ROLL_NUMBER=? AND DT>?;",(int(student),str(prevdate)[:10]+" 02:00:00"))
		#print str(prevdate)[:10]+" 02:00:00"
		i=0;prev=None;
		summ=0.0
		for row in cursor:
			if i%2 == 0:
				prev=row[2]
				
			else:
				login=datetime.datetime.strptime(prev,"%Y-%m-%d %H:%M:%S")
				logout=datetime.datetime.strptime(row[2],"%Y-%m-%d %H:%M:%S")
				duration=logout-login
				
				if not duration.days == 0:
					summ=summ+24.0 - duration.seconds/3600.0
				else:
					summ=summ+duration.seconds/3600.0
			i=i+1
		createTable(conn)
		conn.execute("INSERT INTO SUMMARY_ATTENDANCE (ROLL_NUMBER,DURATION_HOURS) \
				VALUES (?,?)",(student,float("{0:.2f}".format(round(summ,2)))))
		if summ < hours :
			# MAKE A DEFAULTER API CALL HERE
			print student + " had less than "+str(hours)+" hours";
		if i%2==1:
			print student+" didn't marked exit. Evaluated till last exit."
	return

				
