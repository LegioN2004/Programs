install.packages("magick")
library(magick)
img <- image_read("C:/Users/User/Pictures/Screenshots/nothing.png")
img_resized <- image_resize(img, "224x224")
image_write(img_resized, "C:/Users/User/Pictures/processed_image.jpg")
browseURL("C:/Users/User/Pictures/processed_image.jpg")

img_gray <- image_convert(img_resized, colorspace = "gray")
image_write(img_resized, "C:/Users/User/Pictures/processed_image.jpg")
browseURL("C:/Users/User/Pictures/processed_image.jpg")

img_normalized <- image_modulate(img_gray, brightness = 100, saturation = 100, hue = 100)
image_write(img_normalized, "C:/Users/User/Pictures/processed_image.jpg")
browseURL("C:/Users/User/Pictures/processed_image.jpg")

img_blurred <- image_blur(img_normalized, radius = 5)
image_write(img_blurred, "C:/Users/User/Pictures/processed_image.jpg")
browseURL("C:/Users/User/Pictures/processed_image.jpg")

img_equalized <- image_equalize(img_blurred)
image_write(img_equalized, "C:/Users/User/Pictures/processed_image.jpg")
browseURL("C:/Users/User/Pictures/processed_image.jpg")

img_flipped <- image_flip(img_equalized)
image_write(img_flipped, "C:/Users/User/Pictures/processed_image.jpg")
browseURL("C:/Users/User/Pictures/processed_image.jpg")

img_rotated <- image_rotate(img_flipped, 45)
image_write(img_rotated, "C:/Users/User/Pictures/processed_image.jpg")
browseURL("C:/Users/User/Pictures/processed_image.jpg")

img_cropped <- image_crop(img_rotated, "150x150+25+25")
image_write(img_cropped, "C:/Users/User/Pictures/processed_image.jpg")
browseURL("C:/Users/User/Pictures/processed_image.jpg")

img_padded <- image_border(img_cropped, "white", "10x10")
image_write(img_padded, "C:/Users/User/Pictures/processed_image.jpg")
browseURL("C:/Users/User/Pictures/processed_image.jpg")

img_channel <- image_channel(img_padded, "red")
image_write(img_channel, "C:/Users/User/Pictures/processed_image.jpg")
browseURL("C:/Users/User/Pictures/processed_image.jpg")

img_binary <- image_threshold(img_channel, threshold = "50%")
print(img_binary)
image_write(img_binary, "C:/Users/User/Pictures/processed_image.jpg")
browseURL("C:/Users/User/Pictures/processed_image.jpg")
