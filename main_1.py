# Untitled - By: Nemo - 周日 7月 16 2023

import sensor, image, time
from de import detection
from de import Switch_TaskMode,Detection_for_Selected
import time, sensor, image,pyb,Communication
from image import SEARCH_EX, SEARCH_DS
from de import detection,Detection_for_LR,Detection_for_Stop
from pyb import UART
from communication import packdata
global uartx
uart=UART(3,115200)
# Set sensor settings
sensor.set_contrast(1)
sensor.set_gainceiling(16)

sensor.reset()
sensor.set_framesize(sensor.QQVGA)
sensor.set_pixformat(sensor.GRAYSCALE)
sensor.skip_frames(time = 2000)
t1 = image.Image("./1_s.pgm").to_grayscale()
t2 = image.Image("./2_s.pgm").to_grayscale()
t3 = image.Image("./3_s.pgm").to_grayscale()
t4 = image.Image("./4_f.pgm").to_grayscale()
t5 = image.Image("./5_f.pgm").to_grayscale()
t6 = image.Image("./6_f.pgm").to_grayscale()
t7 = image.Image("./7_f.pgm").to_grayscale()
t8 = image.Image("./8_f.pgm").to_grayscale()
t_All=[t1,t2,t3,t4,t5,t6,t7,t8]
global Task_Mode_Flag
global a
clock = time.clock()

while(True):
    if uart.any():
        a = int(uart.read(1)[0])
    else:
        a=100
    Task_Mode_Flag=Switch_TaskMode(a)
    Task_Mode_Flag=1
    clock.tick()
    z = sensor.snapshot().lens_corr(strength = 1.8, zoom = 1.0).replace(hmirror=True,vflip=True,transpose=False).rotation_corr(corners=[(59,0),(125,0),(160,90),(0,90)])
    if Task_Mode_Flag==1:
        flag=Detection_for_Stop(t_All,z)
    elif Task_Mode_Flag==2:
        flag=Detection_for_Selected(a,z,t_All)
    else:
        flag=Detection_for_LR(a-16,z,t_All)
    #a=0x00
    #[a,detectR,detectL]=detection(t1,t2,t3,t4,t5,t6,t7,t8,z)
    #LR=Detection_for_LR(a-16,z,t_All)
    packdata(flag,uart)
    print(Task_Mode_Flag,flag,clock.fps())
