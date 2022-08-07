import os
import cv2
import numpy as np

level=2

if __name__=="__main__":
    cur_path=os.path.dirname(__file__)
    path=cur_path+"\\outputs"
    
    YTargetLayer=np.zeros((720,1280),dtype=np.float64)
    for dirname,subdir,files in os.walk(path): 
        for file in files: 
            image=cv2.imread("outputs\\"+file,-1)
            Y,Cr,Cb=cv2.split(image)
            mask=np.ones(Y.shape,dtype=np.uint8)*(256- 2**(level+1))
            YTargetLayer+=cv2.bitwise_and(Y,mask)*1.0
            
            
    YTargetLayer/=(98*128)
    cv2.imshow("image",YTargetLayer)
            
            
            
            

    cv2.waitKey()
    cv2.destroyAllWindows()

    
            

        