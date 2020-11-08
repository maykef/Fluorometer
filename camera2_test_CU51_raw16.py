import numpy as np
import cv2
from datetime import datetime

print(datetime.now())

cap = cv2.VideoCapture(0 + cv2.CAP_V4L)

# CU51 has the following possible resolution settings
# 640 x 480
# 1280 x 720
# 1920 x 1080
# 2592 x 1944

rows = 1920
cols = 1080

# Set parameters for the camera
cap.set(cv2.CAP_PROP_FRAME_WIDTH, cols)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, rows)
cap.set(cv2.CAP_PROP_CONVERT_RGB, False) # turn off RGB conversion
fps = cap.get(cv2.CAP_PROP_FPS)
timestamp = cap.get(cv2.CAP_PROP_POS_MSEC) # always 40
#cap.set(cv2.CAP_PROP_BRIGHTNESS, 10)

i=0
print('Width = ', cap.get(3),' Height = ', cap.get(4),' fps = ', cap.get(5))

while True:
    #grab capture value (into null) and frame
    _, frame = cap.read()

    # Write some Text
    font                   = cv2.FONT_HERSHEY_SIMPLEX
    location               = (900,100)
    fontScale              = 3
    fontColor              = (255,255,255)
    lineType               = 2

    # CU51 camera
    # convert from 12 bit (4096 levels) to 8 bit (256 levels) 255/4096 = 0.06226
    bf8 = np.array(frame//16, dtype = np.uint8)
    #bf8 = cv2.convertScaleAbs(frame, 0.06226)

 dt = str(datetime.now())

    # Write timestamp
    cv2.putText(bf8,dt,
    location,
    font,
    fontScale,
    fontColor,
    lineType)

    # Display the image
    cv2.imshow('BF8', bf8)

    cv2.imwrite("frame1_{:04d}.png".format(i),bf8)
    print('Timestamp',timestamp)
    i+=1
# detect waitkey of q to quit
    key = cv2.waitKey(1) & 0xFF
    if key == ord("q"):
        break

