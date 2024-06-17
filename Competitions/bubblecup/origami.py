import numpy as np
import cv2


with open('test.txt') as f:
    n = int(f.readline())

    list = []
    for i in range(n):

        dot = f.readline().split(" ")
        list.append((int(dot[0]), int(dot[1])))

# print(cv2.convexHull(np.array(list)))

rect = cv2.minAreaRect(np.array(list, np.float32))
print("%.6f, %.6f, %d" % (rect[1][0], rect[1][1], round(rect[1][0] * rect[1][1])))
