#coding:utf-8

#シリアル通信で文字をArduino側に送受信
#aが押されたら通信を中止するプログラム

import serial
import time

ser = serial.Serial('COM13',115200)
time.sleep(1.5)

print(" OK ! ")

while True:
    
    #キーボードからの入力
    
    flag=bytes(input(),'utf-8')

    #シリアル通信で文字を送信する際は, byte文字列に変換する
    #input()する際の文字列はutf-8

    #送信
    
    ser.write(flag)

    #print(flag)


    if(flag==bytes('a','utf-8')):
        break;

    
    #受信
    
    line = ser.readline()
    line = int(line)
    print(line)    

ser.close()

