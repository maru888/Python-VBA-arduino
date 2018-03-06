# coding: utf-8
import xlwings as xw
import sys
import serial
import time

def run():    
    ser = serial.Serial('COM13',115200)
    time.sleep(2)

    for i in range(1,11):        
        # 送信        
        xld = xw.Range("A"+str(i)).value
        xld = int(xld)                      # 整数化
        in_data = str(xld)                  # 文字列化
        in_data = in_data + '\n'            # 改行コート付加
        in_data = in_data.encode('utf-8')   # バイト列化
    
        ser.write(in_data)

        # 受信        
        line = ser.readline()
        line = int(line)
        xw.Range("B"+str(i)).value = str(line)        
        #time.sleep(0.1)
    ser.close()

