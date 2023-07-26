'''
Author: loyunemo 3210100968@zju.edu.cn
Date: 2023-07-24 15:21:31
LastEditors: loyunemo 3210100968@zju.edu.cn
LastEditTime: 2023-07-24 16:59:10
FilePath: \undefinedd:\learning\project_for_electronic\识别字模\Yolov\boot.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import sensor
import image
import lcd
import KPU as kpu
from machine import UART
from Maix import GPIO
from fpioa_manager import fm
import utime
import ustruct
#FUNCTION MODULE AREA
def packdata(flag,uart):

    data = ustruct.pack("<B",      #格式为俩个字符俩个短整型(2字节)
                   flag)
    uart.write(data)
def Switch_TaskMode(Received_Bytes):
    if Received_Bytes==0x09:
        return 1
    elif Received_Bytes<0x09:
        return 2
    elif Received_Bytes>0x09:
        return 3

#---
fm.register(8,fm.fpioa.UART2_TX)
fm.register(6,fm.fpioa.UART2_RX)
fm.register(28, fm.fpioa.GPIO0)
uart_A = UART(UART.UART2, 115200, 8, None, 1, timeout=1000, read_buf_len=4096)
write_str = 'get dat\r\n'
lcd.init()
sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.set_windowing((224, 224))
sensor.set_hmirror(1)
sensor.set_vflip(1)
sensor.run(1)
task = kpu.load("/sd/yolov2.kmodel")
f=open("anchors.txt","r")
anchor_txt=f.read()
L=[]
for i in anchor_txt.split(","):
    L.append(float(i))
anchor=tuple(L)
f.close()
a = kpu.init_yolo2(task, 0.6, 0.3, 5, anchor)
f=open("lable.txt","r")
labels_txt=f.read()
labels = labels_txt.split(",")
f.close()
while(True):
    img = sensor.snapshot()
    img=img.replace(hmirror=False,vflip=False,transpose=False)
    code = kpu.run_yolo2(task, img)
    taskMode=uart_A.read(1)
    if taskMode:
        a =taskMode[0]
    else:
        taskMode=9
    if code:
        count=0
        print("a")
        for t in code:
            count=count+1
        for i in code:
            a=img.draw_rectangle(i.rect(),(0,255,0),2)
            print(labels[i.classid()])
            a = lcd.display(img)
            lcd.draw_string(i.x()+45, i.y()-5, labels[i.classid()]+" "+'%.2f'%i.value(), lcd.WHITE,lcd.GREEN)
            b=str(labels[i.classid()])
            uart_A.write(b)
        uart_A.write("f")
    else:
        a = lcd.display(img)
a = kpu.deinit(task)
