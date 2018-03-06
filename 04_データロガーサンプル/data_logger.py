# coding: utf-8
import xlwings as xw
import sys
import serial
import time

def run():
    com_port = xw.Range("I2").value
    com_port = "COM" + str(int(com_port))
    com_speed = xw.Range("J2").value
    com_speed = str(int(com_speed))
    
    ser = serial.Serial(com_port, com_speed, timeout = 2)

    time.sleep(2)

    # スタート信号送信
    
    xld = 999
    xld = str(int(xld)) + '\n'
    xld = xld.encode('utf-8')   # バイト列化

    ser.write(xld)

    # 受信
    
    line = int(ser.readline())
    xw.Range("A3").value = str(line)
        
    # パラメータ送信
    xld = xw.Range("B2").value
    xld = str(int(xld)) + '\n'
    xld = xld.encode('utf-8')
    ser.write(xld)

    # パラメータ受信
    line = int(ser.readline())
    xw.Range("B3").value = str(line)
        
    # パラメータ送信
    xld = xw.Range("C2").value
    xld = str(int(xld)) + '\n'
    xld = xld.encode('utf-8')
    ser.write(xld)

    # パラメータ受信
    line = int(ser.readline())
    xw.Range("C3").value = str(line)
        
    # パラメータ送信
    xld = xw.Range("D2").value
    xld = str(int(xld)) + '\n'
    xld = xld.encode('utf-8')
    ser.write(xld)

    # パラメータ受信
    line = int(ser.readline())
    xw.Range("D3").value = str(line)
        
    num_data = int(xw.Range("B2").value)

    for i in range(5, num_data + 5):        
        # 受信
        xw.Range("B" + str(i)).value = i - 4
        line = int(ser.readline())
        xw.Range("C" + str(i)).value = str(line)        
    ser.close()

