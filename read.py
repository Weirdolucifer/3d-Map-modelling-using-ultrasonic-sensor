import serial #Import Serial Library
from serial import Serial
import numpy as np
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits.mplot3d.art3d import Poly3DCollection, Line3DCollection
import matplotlib.pyplot as plt
from matplotlib.path import Path
import matplotlib.patches as patches
import time
import math
from scipy.spatial import ConvexHull

ax1= []
ay1= []
bx1= []
by1= []
cx1= []
cy1= []
dx1= []
dy1= []
ax =[]
ay =[]
axx=[]
ayy=[]
arduino = serial.Serial('/dev/ttyACM0',9600) 


def makeFig():
    plt.plot(x,y,'ro-')
counter = 0
arduino.setDTR(False)
time.sleep(1)
arduino.flushInput()
arduino.setDTR(True)


with arduino:
    while (counter != 91):
        myData = arduino.readline()
        dataArray = myData.split(" ")
        x11=  float(dataArray[0])
        y11=  float(dataArray[1])
        x22=  float(dataArray[2])
        y22=  float(dataArray[3])
        h1=   int(dataArray[4])
        print(x11)
        print(y11)
        print(x22)
        print(y22)   
        if(h1 < 90):
        	h1 = 90-h1
        	r = math.radians(h1)
        	a = math.sin(r)
        	b = math.cos(r)
        	dx1.append(30+y22*a)
        	dy1.append(y22*b)
        	cx1.append(60-x22*b)
        	cy1.append(30+x22*a)
        	bx1.append(30-y11*a)
        	by1.append(60-y11*b)
        	ax1.append(x11*b)
        	ay1.append(30-x11*a)

        else:
        	h1 = h1-90
        	r = math.radians(h1)
        	a = math.sin(r)
        	b = math.cos(r)
        	dx1.append(30-y22*a)
        	dy1.append(y22*b)
        	cx1.append(60-x22*b)
        	cy1.append(30-x22*a)
        	bx1.append(30+y11*a)
        	by1.append(60-y11*b)
        	ax1.append(x11*b)
        	ay1.append(30+x11*a)
        counter = counter+1
     

    for i in range(len(ax1)):
    	if ax1[i] < 50 and ay1[i] < 50 and ay1[i] > 0 and ax1[i] > 0:
    		ax.append(tuple((ax1[i],ay1[i])))
    		axx.append(ax1[i])
    		ayy.append(ay1[i])

    for i in range(len(bx1)):
    	if bx1[i] < 50 and by1[i] < 50 and bx1[i] > 0 and by1[i] > 0:
    		ax.append(tuple((bx1[i],by1[i])))
    		axx.append(bx1[i])
    		ayy.append(by1[i])

    for i in range(len(cx1)):
    	if cx1[i] < 50 and cy1[i] < 50 and cx1[i] > 0 and cy1[i] > 0:
    		ax.append(tuple((cx1[i],cy1[i])))
    		axx.append(cx1[i])
    		ayy.append(cy1[i])

    for i in range(len(dx1)):
    	if dx1[i] < 50 and dy1[i] < 50 and dx1[i] > 0 and dy1[i] > 0:
    		ax.append(tuple((dx1[i],dy1[i])))
    		axx.append(dx1[i])
    		ayy.append(dy1[i])

    ay.append(Path.MOVETO)
    for i in range(1,len(ax)):
    	ay.append(Path.LINETO)
    sorted(ax, key=lambda element: (element[0], element[1]))
    path = Path(ax, ay)
    print(ax)
    # xy = np.hstack((axx[:,np.newaxis],ayy[:,np.newaxis]))
    # hull = ConvexHull(xy)
    # plt.scatter(x,y)
    # plt.plot(x[hull.vertices], y[hull.vertices])
    # plt.show()
    fig = plt.figure()
    axw = fig.add_subplot(111)
    patch = patches.PathPatch(path, facecolor='orange', lw=2)
    axw.add_patch(patch)
    axw.set_xlim(0,60)
    axw.set_ylim(0,60)
    plt.show()

    

          
