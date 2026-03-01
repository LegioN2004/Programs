import numpy as np
import matplotlib.pyplot as plt
from skimage import measure, color


BW = np.zeros((8, 8), dtype=int)
BW[1:4, 1:3] = 1
BW[4:7, 3:5] = 1
BW[1, 5:8]   = 1
BW[2, 6:8]   = 1

print("Binary Matrix (BW):")
print(BW)


L4, num_4 = measure.label(BW, connectivity=1, return_num=True)
print(f"\n4-Connectivity Objects found: {num_4}")
print("Label Matrix (L4):")
print(L4)


L8, num_8 = measure.label(BW, connectivity=2, return_num=True)
print(f"\n8-Connectivity Objects found: {num_8}")
print("Label Matrix (L8):")
print(L8)

rgb_label4 = color.label2rgb(L4, bg_label=0, bg_color=(0, 0, 0))
rgb_label8 = color.label2rgb(L8, bg_label=0, bg_color=(0, 0, 0))

plt.figure(figsize=(12, 5))


plt.subplot(1, 2, 1)
plt.imshow(rgb_label4)
plt.title(f"Labeled Components (4-Conn)\nObjects found: {num_4}")


plt.subplot(1, 2, 2)
plt.imshow(rgb_label8)
plt.title(f"Labeled Components (8-Conn)\nObjects found: {num_8}")

plt.show()
