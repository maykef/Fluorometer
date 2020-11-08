import numpy as np
import cv2
import matplotlib.pyplot as plt
import os


def process(filename, key):
    # Write some Text
    font                   = cv2.FONT_HERSHEY_SIMPLEX
    bottomLeftCornerOfText = (900,100)
    fontScale              = 3
    fontColor              = (255,255,255)
    lineType               = 2
    im = cv2.imread(filename)
    #im = np.array(im//16, dtype = np.uint8)
    im2 = cv2.cvtColor(im, cv2.COLOR_BGR2GRAY);
    colormap = plt.get_cmap('inferno')
    # create a binary thresholded image
    _, binary = cv2.threshold(im2, 20, 255, cv2.THRESH_BINARY)
    im3 = cv2.bitwise_and(im2,binary)
    im3[binary==0] = 0
    cv2.imshow('Masked_Image', im3)
    heatmap = (colormap(im3) * 2**16).astype(np.uint16)[:,:,:3]
    heatmap = cv2.cvtColor(heatmap, cv2.COLOR_RGB2BGR)
    im3_color = cv2.applyColorMap(im3,cv2.COLORMAP_JET)
    cv2.putText(im3,filename,
    bottomLeftCornerOfText,
    font,
    fontScale,
    fontColor,
    lineType)
    cv2.imwrite('binary_'+filename.format(key),im3)
    cv2.imwrite('cmap'+filename.format(key),im3_color)

def normalize(filename, key):
    im = cv2.imread(filename)
    A = np.double(im)
    out = np.zeros(A.shape, np.double)
    normalized = cv2.normalize(A, out, alpha=0, beta=1, norm_type=cv2.NORM_MINMAX)
    cv2.imwrite('normalized_'+filename.format(key),normalized)
