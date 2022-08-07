import writer

import os
from cv2 import imwrite,IMWRITE_JPEG_QUALITY,resize,INTER_NEAREST


jpg_quality=80 #jpg品質 0~100
WaterMarkLevel=2 #浮水印層0~7(越高越明顯，但抗噪能力更好，不容易在壓縮時被吃掉)
ImageResizeScale=2/3 #輸出的圖片尺寸(但依然是原尺寸計算,若有需要大量使用就要自行先用別的程式先跑一次)
WaterMarkScale=0.2 #0~1 浮水印所佔的比例(放在左上角)
if __name__=="__main__":
    cur_path=os.path.dirname(__file__)
    path=cur_path+"\\images"
    
    for dirname,subdir,files in os.walk(path): #讀取所有檔案
        i=1
        for file in files: #針對個檔案一一處理各
            print("("+str(i)+"/"+str(len(files))+") "+ file)
            i+=1
            OutputImage=writer.writer(WaterMarkLevel,"images\\"+file,"watermark.bmp",WaterMarkScale)
            OutputImage=resize(OutputImage,None,fx=ImageResizeScale,fy=ImageResizeScale,interpolation=INTER_NEAREST)
            imwrite("outputs\\"+file[0:len(file)-4]+".jpg",OutputImage, [IMWRITE_JPEG_QUALITY, jpg_quality]) 
            # warn! ! An error may occur if the source file is not in png format
            
    print("\nDONE!!")
        