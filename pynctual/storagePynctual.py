import scanFP as fp
import gray
import os
import time
import sys
from subprocess import call
import db
import sendNotification as sn

db.createdb()
# for i in range(5):
print "Place your next finger..."
roll_no = str(sys.argv[1])
name = "./Gallery/" + roll_no
fp.scan()
gray.grayscale()
call(["./mindtct","-b","-m1","grayout.png",name])
db.updatedb(sys.argv[1])
	# time.sleep(3)
db.displaydb()
