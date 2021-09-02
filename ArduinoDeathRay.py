#!/usr/bin/python3

import serial
import time
from pymouse import PyMouse

arduino = serial.Serial(port='/dev/ttyUSB0', baudrate=19200, timeout=.005)
def write(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.005)
    arduino.readline()

m = PyMouse()
screenW, screenH = m.screen_size()
write("360 11 11 1")

m.move(int(screenW/2), int(screenH/2));

while True:
    mx, my = m.position()
    Sx = int(mx/screenW * 180)
    Sy = 180 - int(my/screenH * 180)
    LED = 1
    LED = int(LED)+1;
    write(str(360) + " " +str(Sx) + " " + str(Sy) + " " + str(LED) + " " )
