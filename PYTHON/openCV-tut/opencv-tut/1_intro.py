import cv2

# img = cv2.imread("assets/Cat_November_2010-1a.jpg", cv2.IMREAD_GRAYSCALE)
# print(img.size) # shows the size of the image
# print(img.shape) # shows the shape of the image
# print(img[0, 0]) # shows the pixel value at the first row and first column

# to get the lightest possible pic
# iterate through the image and change the pixel value
# for i in range(img.shape[0]):
#   for j in range(img.shape[1]):
#     img[i, j] = max(254, img[i, j] * 2)


# img = img * 1 # increases the pixel value by 4


img = cv2.imread("assets/Cat_November_2010-1a.jpg", cv2.IMREAD_COLOR)
print(img.size) # shows the size of the image
print(img.shape) # shows the shape of the image
print(img[0,0]) # shows the pixel value at the first row and first column
rgb_img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
print(rgb_img[0,0]) # shows the pixel value at the first row and first column


# cv2.imshow("Cat", img)
# cv2.waitKey(0) # freezes the window until any key is pressed
# cv2.destroyAllWindows(0) # closes the window after pressing a key
