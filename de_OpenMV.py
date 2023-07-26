'''
FilePath: de.py
'''
import time, sensor, image,pyb
from image import SEARCH_EX, SEARCH_DS
def judge(t,img,probability):
    if img.width()>=t.width() and img.height()>=t.height():
        r = img.find_template(t,probability, step=2, search=SEARCH_EX)
    else:
        r = 0
    return r
def detection(t1,t2,t3,t4,t5,t6,t7,t8,img):
    r1=judge(t1,img,0.75)
    r2=judge(t2,img,0.7)
    r3=judge(t3,img,0.7)
    r4=judge(t4,img,0.7)
    r5=judge(t5,img,0.65)
    r6=judge(t6,img,0.7)
    r7=judge(t7,img,0.7)
    r8=judge(t8,img,0.7)
    zx=[0,0,0,0,0,0,0,0]
    zm=[120,120,120,120,120,120,120,120]
    t=0x00
    if r1:
        if img.get_pixel(r1[0]+r1[2]-3,r1[1]+r1[3]-8)<=60:
            img.draw_rectangle(r1)
            t|=0x01
            zx[0]=r1[0]
            zm[0]=r1[0]
    if r2:
        img.draw_rectangle(r2)
        t|=0x02
        zx[1]=r2[0]
        zm[1]=r2[0]
    if r3:
        img.draw_rectangle(r3)
        t|=0x04
        zx[2]=r3[0]
        zm[2]=r3[0]
    if r4:
        img.draw_rectangle(r4)
        t|=0x08
        zx[3]=r4[0]
        zm[3]=r4[0]
    if r5:
        img.draw_rectangle(r5)
        t|=0x10
        zx[4]=r5[0]
        zm[4]=r5[0]
    if r6:
        img.draw_rectangle(r6)
        t|=0x20
        zx[5]=r6[0]
        zm[5]=r6[0]
    if r7:
        img.draw_rectangle(r7)
        t|=0x40
        zx[6]=r7[0]
        zm[6]=r7[0]
    if r8:
        img.draw_rectangle(r8)
        t|=0x80
        zx[7]=r8[0]
        zx[7]=r8[0]
    maxindex=zx.index(max(zx))
    minindex=zm.index(min(zm))
    return [t,maxindex,minindex]
def Switch_TaskMode(Received_Bytes):
    if Received_Bytes==0x09:
        return 1
    elif Received_Bytes<0x09:
        return 2
    elif Received_Bytes>0x09:
        return 3
def Detection_for_Stop(t_All,Img_Test):
    r=[0,0,0,0,0,0,0,0]
    rindex=[0,0,0,0,0,0,0,0]
    count=0
    r[0]=judge(t_All[0],Img_Test,0.7)
    r[1]=judge(t_All[1],Img_Test,0.7)
    r[2]=judge(t_All[2],Img_Test,0.7)
    r[3]=judge(t_All[3],Img_Test,0.7)
    r[4]=judge(t_All[4],Img_Test,0.7)
    r[5]=judge(t_All[5],Img_Test,0.7)
    r[6]=judge(t_All[6],Img_Test,0.7)
    r[7]=judge(t_All[7],Img_Test,0.7)#参数待更改
    for Content in r :
        if Content:
            count=count+1
            rindex[r.index(Content)]=r.index(Content)+1
        else:
            pass
    if r[0] and Img_Test.get_pixel(r[0][0]+r[0][2]-5,r[0][1]+r[0][3]-8)>60:
        count-=1
    if count==1:
        return (rindex.index(max(rindex))+1)
    else:
        return 0
def Detection_for_Selected(Received_Bytes,img,t):
    bf=judge(t[Received_Bytes-1],img,0.7)
    if bf:
        img.draw_rectangle(bf)
        return Received_Bytes
    else:
        return 0
def Detection_for_LR(Received_Bytes,img,t):
    bf= judge(t[Received_Bytes-1],img,0.7)
    if bf:
       q=bf[0]+bf[2]/2
       img.draw_rectangle(bf)
       if q<=80:
           return 1
       else:
           return 2
    else:
        return 0
