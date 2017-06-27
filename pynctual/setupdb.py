#!/usr/bin/env python

import sqlite3

try:
    db = sqlite3.connect('db/intern_data')

    cursor = db.cursor()
    cursor.execute('''CREATE TABLE interns(id INTEGER PRIMARY KEY,rollno INTEGER,xyt TEXT)''')

    #Ensure xyt file of intern with "rollno: 000" is named as 000.xyt
    rollnos = []
    with open('db/Roll_No') as f:
        for line in f:
            rollnos.append((int(line),line.rstrip() + '.xyt'))

    cursor.executemany('''INSERT INTO interns(rollno,xyt) VALUES(?,?)''',rollnos)

    db.commit()

except Exception as e:
    db.rollback()
    raise e

finally:
    db.close()
