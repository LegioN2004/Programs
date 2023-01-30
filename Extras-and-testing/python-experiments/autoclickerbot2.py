import  time
import  pyautogui

while True:
    letter = "e"
    pyautogui.press(letter)
    print(pyautogui.position())
    pyautogui.click(1313,73)
    time.sleep(0.001)

