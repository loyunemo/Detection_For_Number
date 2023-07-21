'''
Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
Date: 2023-07-15 19:23:33
LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
LastEditTime: 2023-07-21 10:22:00
FilePath: \Communication.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import sensor, image, time,math,pyb
from pyb import UART,LED
import json
import ustruct

def packdata(flag,uart):

    data = ustruct.pack("<B",      #格式为俩个字符俩个短整型(2字节)
                   flag)
    uart.write(data)
def receivedata():
     if uart.any():                          #判断是否接收到数据
        a = uart.read(1)[0]         #uart.read()为一个字节串，加.decode() 变成字符串
        print(a)
