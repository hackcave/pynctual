 #!/usr/bin/env python

import sqlite3
import datetime

def createTable(conn):
	conn_cursor=conn.cursor()
	conn_cursor.execute('''CREATE TABLE IF NOT EXISTS SUMMARY_ATTENDANCE
		(id INTEGER PRIMARY KEY AUTOINCREMENT,
		roll_number INTEGER NOT NULL,
		dt datetime default (datetime(current_timestamp,'LOCALTIME')),
		duration_hours FLOAT);''')

def displayDB():
	try:
		conn
	except:
		conn=sqlite3.connect("test.db")
	finally:
		conn_cursor=conn.cursor()
		cursor = conn_cursor.execute("SELECT id,roll_number,dt,duration_hours from SUMMARY_ATTENDANCE")
		for row in cursor:
			print 'Id={} RollNumber={} Date/Time={} DurationHours={}'.format(row[0],row[1],row[2],row[3]);
   			
# NOTE IT IS ASSUMED THAT EVERYONE HAS MARKED EXIT, EXACTLY BEFORE 2:00AM.
# NOT MARKING JUST BEFORE 2:00 AM WOULD MARK HIM AS DEFAULTER.
# EVERY FIRST ENTRY AFTER 2:00 AM WOULD BE AN "INCOMING ENTRY" ONLY

def getSummary():
	Summary('nyo',8);
	Summary('rte',2);

def Summary(filename,hours):
	conn=sqlite3.connect("test.db")
	conn_cursor=conn.cursor()
	list_students=open(filename,'r').readlines()
	for student in list_students:
		student=student.strip()
		prevdate=datetime.datetime.now()-datetime.timedelta(days=1)
		cursor=conn_cursor.execute("SELECT id,roll_number,dt from ATTENDANCE where roll_number=? AND dt>?;",(int(student),str(prevdate)[:10]+" 02:00:00"))
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
		conn_cursor.execute("INSERT INTO SUMMARY_ATTENDANCE (roll_number,duration_hours) VALUES (?,?)",(student,float("{0:.2f}".format(round(summ,2)))))
		if summ < hours :
			# MAKE A DEFAULTER API CALL HERE
			print '{} had less than {} hours'.format(student,str(hours));
		if i%2==1:
			print "{} didn't marked exit. Evaluated till last exit.".format(student);
			
	return

				
