import cv2
image=cv2.imread("Output.png",-1)
cv2.imshow("text",image)
import numpy as np
r,c,d=image.shape
b=np.zeros((r,c,8),dtype=np.uint8)
color=["blue","green","red"]
for i in range(8):
    b[:,:,i]=2**i
result=np.zeros((r,c,8),dtype=np.uint8)
for j in range(3):
    for i in range(8):
        result=cv2.bitwise_and(image[:,:,j],b[:,:,i])
        mask=result>0#looking for 3-30
        result[mask]=255
        cv2.imshow(color[j]+"level"+str(i),result)

cv2.waitKey()
cv2.destroyAllWindows()