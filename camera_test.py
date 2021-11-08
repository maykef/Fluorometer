import numpy as np
import cv2
import sys
import csv
from datetime import datetime
import os
import glob

cap = cv2.VideoCapture(1 + cv2.CAP_V4L)

cap2 = cv2.VideoCapture(0 + cv2.CAP_V4L)

i=0

# CU51 has the following possible resolution settings
# 640 x 480
# 1280 x 720
# 1920 x 1080
# 2592 x 1944

rows = 640
cols = 480

# Set parameters for the camera
cap.set(cv2.CAP_PROP_FRAME_WIDTH, cols)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, rows)
cap.set(cv2.CAP_PROP_CONVERT_RGB, 0) # turn off RGB conversion
cap.set(cv2.CAP_PROP_BRIGHTNESS, 8)
cap.set(cv2.CAP_PROP_EXPOSURE, 10) #Not Supported
cap.set(cv2.CAP_PROP_FPS, 30)
cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter.fourcc(*'Y16 '))

# Create the mask
# Gray out both binaries and enable _, binary in order to create the mask.
# after the mask has been obtained, gray out _, binary and enable both binary to
# retrieve the mask.
binary = cv2.imread('Masked_Image.png')
binary = binary[:,:,1]
print('Width = ', cap.get(3),' Height = ', cap.get(4),' fps = ', cap.get(5))


# Save the orint text to the original standard output
original_stdout = sys.stdout


while True:
    dt = datetime.now().strftime("%M_%S.%f")[:-3]
    _, frame = cap.read()
    _, frame2 = cap2.read()
    bf8 = np.array(frame//16, dtype = np.uint8)
    im3 = cv2.bitwise_and(bf8,binary)
    im3[binary==0] = 0
    # Normalize the image
    bf8_2_color = cv2.applyColorMap(im3, cv2.COLORMAP_PARULA)
    bf8_3_color = cv2.applyColorMap(frame2, cv2.COLORMAP_VIRIDIS)
    # Display the image, print image size and fps and save each frame
    cv2.imshow('Masked_Image', im3)
    cv2.imshow("lepton", cv2.resize(bf8_3_color, (640, 480)))
    cv2.imshow("Opencv Video See3Cam_CU51 Color", bf8_2_color)
    Mean = cv2.mean(bf8, im3)[:1]
    cv2.imshow('Opencv Binary Image', binary)
    cv2.imwrite('Frame'+str(i)+'.jpg',im3)
    i += 1
    print('Pixels =', cv2.countNonZero(im3))
    print('Mean =', Mean[:1])
    print('Standard Deviation =', cv2.meanStdDev(im3, im3)[:1])
    with open('results.csv', 'a') as csvfile:
        fieldnames = ['Mean']
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        writer.writerow({'Mean': Mean})
    # detect waitkey of q to quit
    key = cv2.waitKey(1) & 0xFF
    if key == ord("q"):
        break
