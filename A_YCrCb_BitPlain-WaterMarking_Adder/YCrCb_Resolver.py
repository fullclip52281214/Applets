import cv2
import numpy as np
image=cv2.imread("output.png",-1)
image=cv2.cvtColor(image,cv2.COLOR_BGR2YCrCb)
Y,Cr,Cb=cv2.split(image)

cv2.imshow("text",Y)

r,c=Y.shape
b=np.zeros((r,c,8),dtype=np.uint8)

for i in range(8):
    b[:,:,i]=2**i
result=np.zeros((r,c,8),dtype=np.uint8)
for i in range(8):
    result=cv2.bitwise_and(Y,b[:,:,i])
    mask=result>0#可參照3-30
    result[mask]=255
    cv2.imshow(str(i),result)

cv2.waitKey()
cv2.destroyAllWindows()