#!/usr/bin/env python

#To test the databse

import sqlite3

try:
    db = sqlite3.connect('db/intern_data')

    cursor = db.cursor()
    cursor.execute('''SELECT rollno,xyt FROM interns''')

    data = cursor.fetchall()

    #To check file names are correctly stored
    for row in data:
        print('{0} : {1}'.format(row[0],row[1]))

    db.commit()

except Exception as e:
    raise e

finally:
    db.close()
