import sensor
import image
import lcd
import KPU as kpu
from machine import UART
from Maix import GPIO
from fpioa_manager import fm
import utime
import ustruct
from board import board_info
print(dir(board_info.all()))
#FUNCTION MODULE AREA
def packdata(flag,uart):
    flag=int(flag)
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
def Detection_for_Stop(a,code,Img_Test):
    count=0
    if code:
        for Content in code :
            count+=1
            a = Img_Test.draw_rectangle(Content.rect(),(0,255,0),2)
            lcd.draw_string(Content.x()+45, Content.y()-5, labels[Content.classid()]+" "+'%.2f'%Content.value(), lcd.WHITE,lcd.GREEN)
            a = lcd.display(img)
    else:
        a = lcd.display(img)
        return 0
    if count==1:
        return labels[Content.classid()]
    else:
        return 0
def Detection_for_Selected(a,Received_Bytes,img,code):
    if code:
        for Content in code :
            if Received_Bytes==labels[Content.classid()]:
                a = img.draw_rectangle(Content.rect(),(0,255,0),2)
                lcd.draw_string(Content.x()+45, Content.y()-5, labels[Content.classid()]+" "+'%.2f'%Content.value(), lcd.WHITE,lcd.GREEN)
                a = lcd.display(img)

                return Received_Bytes
    else:
        a = lcd.display(img)
        return 0
def Detection_for_LR(a,Received_Bytes,img,t):
    if code:
        for Content in code :
            if Received_Bytes==labels[Content.classid()]:
                a = img.draw_rectangle(Content.rect(),(0,255,0),2)
                a = lcd.display(img)
                lcd.draw_string(Content.x()+45, Content.y()-5, labels[Content.classid()]+" "+'%.2f'%Content.value(), lcd.WHITE,lcd.GREEN)
                if Content.x()+Content.w()/2<=160:
                    return 1
                else:
                    return 2
    else:
        a = lcd.display(img)
        return 0
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
    code = kpu.run_yolo2(task, img)
    Read_Buffer=uart_A.read(1)

    if Read_Buffer:
        print(Read_Buffer[0])
        TaskMode =Switch_TaskMode(Read_Buffer[0])
    else:
        TaskMode=Switch_TaskMode(9)
        print("No Input!")
    if TaskMode==1:
        flag=Detection_for_Stop(a,code,img)
    elif TaskMode==2:
        flag=Detection_for_Selected(a,Read_Buffer[0],img,code)
    else:
        flag=Detection_for_LR(a,Read_Buffer[0]-16,img,code)
    packdata(flag,uart_A)
a = kpu.deinit(task)
