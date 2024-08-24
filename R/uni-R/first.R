install.packages("magick")
library(magick)
image <- image_read("C:/Users/User/Pictures/wallpapers/photo-1438684498571-4908536446fd.jpg") # Load an image from a file
image_resized <- image_resize(image, "256x256") # Resize the image
image_rotated <- image_rotate(image, 45) # Rotate the image by 45 degrees
image_cropped <- image_crop(image, "200x200+0+0") # Crop the image to a 200x200 pixel area starting from the top-left corner (0,0)
image_flipped <- image_flop(image) # Flip the image horizontally
image_flipped_vertically <- image_flip(image) # Flip the image vertically
# image_adjusted <- image_modulate(image, brightness = 120, saturation = 120, hue = 150)
# Adjust brightness, saturation, and hue (brightness = 1.2, saturation = 1.2, hue = 1.5)
image_bordered <- image_border(image, color = "black", geometry = "10x10")
# Add a border of 10 pixels, color black
# image_sharpened <- image_sharpen(image, radius = 1, sigma = 1) # Sharpen the image
# image_rescaled <- image_scale(image, geometry = "50%") # Rescale the image to a range of [0, 1]
# image_blurred <- image_blur(image, 10, 3) # Apply Gaussian blur to the image (sigma = 3)
# image_edges <- image_edge(image, radius = 1) # Apply Sobel edge detection
# image_threshold <- image_threshold(image_gray, "50%") # Apply thresholding to create a binary image
print(image) # Display original image
print(image_resized) # Display processed images
image_write(image_flipped_vertically, "processed_image.jpg") # Save the processed image
browseURL("processed_image.jpg") # Open the saved image in the default web browser