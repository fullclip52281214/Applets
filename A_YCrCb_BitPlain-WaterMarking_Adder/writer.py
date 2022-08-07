import cv2
import numpy as np
import math

def writer(level,file,watermark,MarkScale=1):  # 進行浮水印製作的起點

    Y,Cr,Cb,Yfree = split(level,file)  #分解圖片

    Yfull = write(level,Yfree,watermark,MarkScale) #製作浮水印
    image = merge(Yfull,Yfree,Cr,Cb)  #將浮水印層與圖片混合
    
    return image
    
def split(level,file):
    image=cv2.imread(file)
    
    image=cv2.cvtColor(image,cv2.COLOR_BGR2YCrCb)  # YCrCb space
    Y,Cr,Cb=cv2.split(image)
    #cv2.imshow("ori Y",Y)
    
   
    mask=np.ones(Y.shape,dtype=np.uint8)*(256- 2**(level+1)) # 增強在色彩空間轉換與進行有損壓縮時，圖片的容錯能力(可亮可暗)(先抽掉，等下再用無償提升稍微補一部份回來)
    # 大於第二層的浮水印有最強的抗噪能力，但也蠻明顯的
    # 等於1時，無法承受變暗雜訊
    # 等於0時，無法承受雜訊
    
    Yfree=cv2.bitwise_and(Y,mask) #被抽出來的層
    if level>=2:
        mask=np.ones(Y.shape,dtype=np.uint8)*2**level
        LostPlain=cv2.bitwise_and(Y,mask) #其實意義不大，但反正有空位就拿來補一下缺的亮度
        Yfree=Yfree+(LostPlain>>level)
        Yfree+=2**(level-1)-1 #無償提升對付變暗雜訊
    #cv2.imshow("Other Level",Yfree)

    return Y,Cr,Cb,Yfree
  
def write(level,Yfree,watermark,MarkScale):
    watermark=cv2.imread(watermark,0)
    t,watermark=cv2.threshold(watermark,2**level,1,cv2.THRESH_TRUNC) #調整浮水印亮度
        
    scale0=Yfree.shape[0]/watermark.shape[0]  #預設把浮水印做得跟原圖一樣大
    scale1=Yfree.shape[1]/watermark.shape[1]
    if scale0 < scale1:
        watermark=cv2.resize(watermark,(math.floor(watermark.shape[1]*scale0*MarkScale),math.floor(Yfree.shape[0]*MarkScale)),interpolation=cv2.INTER_NEAREST)
    else:
        watermark=cv2.resize(watermark,(math.floor(Yfree.shape[1]*MarkScale),math.floor(watermark.shape[0]*scale1*MarkScale)),interpolation=cv2.INTER_NEAREST)
    
    Yfull=np.zeros((Yfree.shape),dtype=np.uint8)
    Yfull[0:watermark.shape[0],0:watermark.shape[1]]=watermark
    
    #cv2.imshow("Yfull",Yfull)
    return Yfull
    
    
    
def merge(Yfull,Yfree,Cr,Cb):
    Y=cv2.add(Yfull,Yfree)
    image=cv2.merge([Y,Cr,Cb])
    image=cv2.cvtColor(image,cv2.COLOR_YCrCb2BGR)
    
    return image




if __name__=="__main__":
    image=writer(2,"images\\2022-06-26 23_58_40-Greenshot.png","watermark.bmp",1)
    cv2.imshow("Output",image)
    cv2.imwrite("Output.png",image)
    cv2.waitKey()
    cv2.destroyAllWindows()