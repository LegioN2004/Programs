# Sam Westby Tech tutorial OpenCV

## Introduction

This is a tutorial on OpenCV, a computer vision library. This tutorial will cover the basics of OpenCV, including how to install it, how to use it, and how to create a simple computer vision application.

## What is OpenCV?

OpenCV is an open-source computer vision library that was originally developed by Intel. It is now maintained by the OpenCV community. OpenCV provides a wide range of computer vision algorithms, including image processing, object detection, and machine learning.

## Installing OpenCV

To install OpenCV, you will need to have Python installed on your computer. You can install OpenCV using pip, the Python package manager. To install OpenCV using pip, run the following command:

```
pip install opencv-python
```

## Using OpenCV

Once you have installed OpenCV, you can start using it in your Python programs. Here is an example of how to load an image using OpenCV:

```python

import cv2

# Load an image
# image = cv2.imread('someFolder/image.jpg', params)
img = cv2.imread("assets/Cat_November_2010-1a.jpg", cv2.IMREAD_GRAYSCALE)
# IMREAD_COLOR shows coloured image, IMREAD_GRAYSCALE shows grayscale image

# Display the image
cv2.imshow('Image', image)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

This code will load an image from the file `image.jpg` and display it in a window. You can use the `cv2.imshow` function to display images, and the `cv2.waitKey` function to wait for a key press before closing the window.

- `print(img[0, 0])` shows the pixel value at the first row and first column. Between 0 and 255. The more near to 0, the darker the pixel is. The more near to 255, the lighter the pixel is.
- `img` stores the individual pixel values of the image in an array. eg: img[0, 0] will give the pixel value of the first row and first column.

Now if we do coloured image, we will get 3 values for each pixel. The first value is the blue value, the second value is the green value, and the third value is the red value. The values are between 0 and 255 for each of them. It goes backwards RGB i.e BGR. The array is like `[blue_value, green_value, red_value]`.