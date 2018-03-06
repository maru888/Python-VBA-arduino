# coding: utf-8
import xlwings as xw
import sys
import serial
import time
import datetime

def run():
    
    ser = serial.Serial('COM13',9600)

    time.sleep(1)

    for i in range(1,11):
        line = ser.readline()
        line = int(line)
        xw.Range("A"+str(i)).value = i
        xw.Range("B"+str(i)).value = str(line)
        time.sleep(0.1)

    sp.close()

