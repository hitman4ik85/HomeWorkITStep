from PIL import ImageGrab, ImageOps
import pyautogui
from numpy import *
import time

class DinoBot:
    def __init__(self, replaybtn, dino):
        self.replaybtn = replaybtn
        self.dino = dino
        self.last_action_time = 0
        self.reaction_delay = 0.1
        self.cactus_threshold = 6330  # поріг для виявлення перешкоди

    def restartgame(self):
        pyautogui.click(self.replaybtn)

    def jump(self):
        pyautogui.keyDown("space")
        pyautogui.keyUp("space")

    def down(self):
        pyautogui.keyDown("down")
        pyautogui.keyUp("down")

    def crouch(self):
        pyautogui.keyDown("down")
        time.sleep(0.1)
        pyautogui.keyUp("down")

    def detect_cactus(self):
        box = (self.dino[0] + 35, self.dino[1], self.dino[0] + 180, self.dino[1] + 35)
        image = ImageGrab.grab(box)
        grayImage = ImageOps.grayscale(image)
        a = array(grayImage.getcolors())
        return a.sum()

    def detect_bird(self):
        box = (self.dino[0] + 80, self.dino[1] - 40, self.dino[0] + 150, self.dino[1] - 10)
        image = ImageGrab.grab(box)
        grayImage = ImageOps.grayscale(image)
        pixels = list(grayImage.getdata())
        dark_pixels = [p for p in pixels if p < 100]
        return len(dark_pixels)

    def start(self):
        self.restartgame()
        time.sleep(1)

        while True:
            current_time = time.time()
            cactus_value = self.detect_cactus()
            bird_dark_pixels = self.detect_bird()
            # print(cactus_value, bird_dark_pixels)

            if cactus_value > self.cactus_threshold and (current_time - self.last_action_time > self.reaction_delay):
                self.jump()
                time.sleep(0.07)
                self.down()
                self.last_action_time = current_time

            elif bird_dark_pixels > 10 and (current_time - self.last_action_time > self.reaction_delay):
                self.crouch()
                self.last_action_time = current_time

def main():
    bot = DinoBot((393, 400), (104, 407))
    bot.start()

if __name__ == '__main__':
    main()