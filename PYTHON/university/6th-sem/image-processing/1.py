import numpy as np
import matplotlib.pyplot as plt
from skimage import measure, color

BW = np.array(
    [
        [0, 0, 0, 0, 0, 0, 0, 0],
        [0, 1, 1, 0, 0, 1, 1, 1],
        [0, 1, 1, 0, 0, 1, 1, 1],
        [0, 1, 1, 0, 0, 0, 0, 0],
        [0, 0, 0, 1, 1, 0, 0, 0],
        [0, 0, 0, 1, 1, 0, 0, 0],
    ]
)

print("Original Binary Image:")
print(BW)

labeled_4 = measure.label(BW, connectivity=1)
labeled_8 = measure.label(BW, connectivity=2)

print("\nLabeled 4-Connected Components:")
print(labeled_4)

print("\nLabeled 8-Connected Components:")
print(labeled_8)

image_label_overlay = color.label2rgb(labeled_4, image=BW, bg_label=0)

plt.figure(figsize=(6, 6))
plt.imshow(image_label_overlay)
plt.title("Labeled Components (label2rgb equivalent)")
plt.axis("off")
plt.show()

props = measure.regionprops(labeled_4)

print("\nMeasured Properties (Area):")
for i, prop in enumerate(props):
    print(f"Object Label {prop.label}: Area = {prop.area} pixels")

isolated_object = (labeled_4 == 2).astype(int)
print("\nIsolated Object 2:")
print(isolated_object)
