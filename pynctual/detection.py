import scanFP as fp
import gray
import os
import glob
import sys
import warnings
import logging
import subprocess
from subprocess import call
import db
import sendNotification as sn
from datetime import datetime
warnings.filterwarnings("ignore")
def holmes():
	fp.scan()
	gray.grayscale()
	call(["./mindtct","-b","-m1","grayout.png","temp"])
	probe =  "temp.xyt"
	flag=0
	for file in glob.glob("./Gallery/*.xyt"):
		bozo = subprocess.check_output(["./bozorth3","-p", probe, file])
		if int(bozo)>=40:
			flag=1
			name = file[10:16]
			print name+" was here at "+ datetime.now().strftime('%Y-%m-%d %H:%M:%S')
		#	sn.send_notification(name +" was here at   "+ datetime.now().strftime('%Y-%m-%d %H:%M:%S'))
			break
	if (flag==0):
		print "Who the fuck are you..."