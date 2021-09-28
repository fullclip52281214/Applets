import pyautogui
import keyboard as kb
from time import sleep

'''
Ctrl+Alt+l = Left click continuously
Ctrl+Alt+X = start continuous click
ESC = End automatic click
Ctrl+Alt+S = start switching button
Ctrl+Alt+T = change the period of click
Ctrl+Alt+E = program end

'''
pyautogui.PAUSE = 0.01
def SpeedChange():
    if(kb.is_pressed("ctrl")):
        if(kb.is_pressed("alt")):
            if(kb.is_pressed("T")):
                try:
                    pyautogui.PAUSE=float(input("Enter the click interval : "))
                    print("command received")
                except:
                    print("Wrong input value")
                    




def Clicking():
    print("Start clicking")
    while(True):
        pyautogui.click()
        if(kb.is_pressed("esc")):
            print("STOP!!")
            return



ContinuousClick=0
def LeftMouseDect():
    global ContinuousClick
    if(kb.is_pressed("ctrl")):
        if(kb.is_pressed("alt")):
            if(kb.is_pressed("l")):
                ContinuousClick=1
    if ContinuousClick == 1:
        if(not( kb.is_pressed("ctrl") or kb.is_pressed("alt") or kb.is_pressed("l"))):
            ContinuousClick=0
            Clicking()



def StartContinuousPress(key1):
    print("Start Pressing")
    while(True):
        pyautogui.press(key1)
        if(kb.is_pressed("esc")):
            print("STOP!!")
            return


def LoadingButton1():
    key1=kb.read_key()
    print(key1)
    StartContinuousPress(key1)


Continuous=0
def ContinuousPressDect():
    global Continuous
    if(kb.is_pressed("ctrl")):
        if(kb.is_pressed("alt")):
            if(kb.is_pressed("x")):
                Continuous=1
    if Continuous == 1:
        if(not( kb.is_pressed("ctrl") or kb.is_pressed("alt") or kb.is_pressed("c"))):
            Continuous=0
            print("reading 1 char")
            LoadingButton1()
            






def StartSwitching(key1,key2):
    print("StartSwitching")
    while(True):
        pyautogui.press(key1)
        pyautogui.press(key2)
        if(kb.is_pressed("esc")):
            print("STOP!!")
            return
            

def LoadingButton2():
    key1=kb.read_key()
    key2=kb.read_key()
    while(key1==key2):
        key2=kb.read_key()
    print(key1,key2)
    StartSwitching(key1,key2)
    
    
    
Switch=0
def Switchdect():
    global Switch
    if(kb.is_pressed("ctrl")):
        if(kb.is_pressed("alt")):
            if(kb.is_pressed("s")):
                Switch=1
    if Switch==1:
        if(not( kb.is_pressed("ctrl") or kb.is_pressed("alt") or kb.is_pressed("s"))):
            Switch=0
            print("reading 2 char")
            LoadingButton2()
    
    
def ProgramEndDect():
    if(kb.is_pressed("ctrl")):
        if(kb.is_pressed("alt")):
            if(kb.is_pressed("e")):
                return True
    return False



if __name__=="__main__":
    while(True):
        Switchdect()
        ContinuousPressDect()
        LeftMouseDect()
        SpeedChange()
        if ProgramEndDect():
            break
        sleep(pyautogui.PAUSE)