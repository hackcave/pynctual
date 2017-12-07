#!/usr/bin/env python

import sqlite3

def createdb():

    try:
        db = sqlite3.connect('db')

        cursor = db.cursor()
        cursor.execute('''CREATE TABLE IF NOT EXISTS person (id INTEGER PRIMARY KEY AUTOINCREMENT, rollno INTEGER NOT NULL, filename1 TEXT,filename2 TEXT,filename3 TEXT,filename4 TEXT,filename5 TEXT)''')

    except Exception as e:
        db.rollback()
        raise e 
    
    finally:
        db.close()


def updatedb(roll_no):
    roll_no = int(roll_no)

    try:
        global conn
        db = sqlite3.connect("db")
        _cursor = db.cursor()

        # Ensure that entry should not exist already
        for row in _cursor.execute("SELECT rollno FROM person"):
            if row[0] == roll_no:
                print("Entry already exist")
                return
            else:
                pass

        # Ensure xyt file of intern with "rollno: 000" is named as 000.xyt
        filename1 = str(roll_no)+'.xyt1'
        filename2 = str(roll_no)+'.xyt2'
        filename3 = str(roll_no)+'.xyt3'
        filename4 = str(roll_no)+'.xyt4'
        filename5 = str(roll_no)+'.xyt5'
        if(_cursor):
            _cursor.execute('''INSERT INTO person (rollno, filename1, filename2, filename3, filename4, filename5) VALUES(?,?,?,?,?,?)''', (roll_no, filename1, filename2, filename3, filename4, filename5))
        else:
            raise Exception("_cursor is NULL")

        db.commit()

    except Exception as e:
        db.rollback()
        raise e

    finally:
        db.close()


def displaydb():
    try:
        db = sqlite3.connect("db")
        _cursor = db.cursor()
        _rows = _cursor.execute("SELECT id, rollno, filename1, filename2, filename3, filename4, filename5 from person")

        for row in _rows:
            print('ID: {} ROLL-NO: {} FILENAME: {}'.format(row[0], row[1], row[2])) 

    except Exception as e:
        db.rollback()
        raise e
    
    finally:
        db.close()

