from PIL import Image
import cv2
import os

def grayscale():
	name="grayout.png"
	frame=cv2.imread("./out.bmp")
	#code block for adaptive thresholding
	grayscaled = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
	cv2.imwrite(name,grayscaled)
	os.remove('out.bmp')