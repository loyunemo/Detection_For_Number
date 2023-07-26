import sensor, image, time,pyb
from de import detection
import de
from de import Switch_TaskMode,Detection_for_Selected
import time, sensor, image,pyb,Communication
from image import SEARCH_EX, SEARCH_DS
from de import detection,Detection_for_LR,Detection_for_Stop
from pyb import UART
from communication import packdata
global uartx
uart=UART(3,115200)
led = pyb.LED(3)
ledG =pyb.LED(2)
ledR=pyb.LED(1)
# Set sensor settings
sensor.set_contrast(1)
sensor.set_gainceiling(16)

sensor.reset()
sensor.set_framesize(sensor.QQVGA)
sensor.set_pixformat(sensor.GRAYSCALE)
sensor.skip_frames(time = 2000)

threshold = (120,255)

t1 = image.Image("./1.pgm").to_grayscale()#.binary([threshold])
t2 = image.Image("./2.pgm").to_grayscale()#.binary([threshold])
t3 = image.Image("./3.pgm").to_grayscale()#.binary([threshold])
t4 = image.Image("./4.pgm").to_grayscale()#.binary([threshold])
t5 = image.Image("./5.pgm").to_grayscale()#.binary([threshold])
t6 = image.Image("./6.pgm").to_grayscale()#.binary([threshold])
t7 = image.Image("./7.pgm").to_grayscale()#.binary([threshold])
t8 = image.Image("./8.pgm").to_grayscale()#.binary([threshold])
t_All=[t1,t2,t3,t4,t5,t6,t7,t8]
global Task_Mode_Flag
global a
a=0x05
global b
clock = time.clock()
global state_stopsending
state_stopsending=0
while(True):
    flag=0
    debug_flag = 0
    if uart.any():
        a = int(uart.read(1)[0])
        led.on()
        state_stopsending=1
        b=0
    else:
        pass
    Task_Mode_Flag=Switch_TaskMode(a)
    Task_Mode_Flag=2
    clock.tick()
    z = sensor.snapshot().lens_corr(strength = 1.8, zoom = 1.0).\
        replace(hmirror=True,vflip=True,transpose=False).\
        rotation_corr(corners=[(36,0),(124,0),(160,120),(0,120)])

    if Task_Mode_Flag==1:
        data=Detection_for_Stop(t_All,z)
    elif Task_Mode_Flag==2:
        data=Detection_for_Selected(a,z,t_All)

        ledR.on()
    elif Task_Mode_Flag==3:
        data=Detection_for_LR(a-16,z,t_All)

    else:
        data=0
    #a=0x00
    #[a,detectR,detectL]=detection(t1,t2,t3,t4,t5,t6,t7,t8,z)
    #LR=Detection_for_LR(a-16,z,t_All)
    if state_stopsending and data and data!=0:
        flag=data
        packdata(data,uart)
        #data=0
        state_stopsending=0
        ledG.on()
    print("state:",state_stopsending,"flag:",Task_Mode_Flag,"data:",data,clock.fps())
