from datetime import datetime

import speech_recognition as sr
import pyttsx3
from fuzzywuzzy import fuzz

import os

speak_engine = pyttsx3.init()
voices = speak_engine.getProperty('voices')
speak_engine.setProperty('voice', voices[1].id)

# Команди:
opts = {
    'name': ('ліліан', 'лілі', 'лі'),
    'user_command': ('скажи', 'покажи', 'як', 'знайди', 'що таке'),
    'cmds': {
        'ctime': ('котра година', 'який час', 'час', 'зараз година'),
        'paint': ('малювати', 'малюй', 'відкрий пейнт', 'пейнт'),
        'google': ('знайди', 'пошук гугл', 'гугл'),
        'youtube': ('відео', 'ютуб', 'музика'),
        'smart': ('розумний дім', 'увімкни світло', 'світло', 'дім', 'температура')
    }
}

def command():
    r = sr.Recognizer()

    with sr.Microphone(device_index=1) as source:  # за замовчуванням
        print("Скажіть щось...")
        r.pause_threshold = 1
        r.adjust_for_ambient_noise(source, duration=1)
        audio = r.listen(source)

    try:
        text = r.recognize_google(audio, language='uk-UA').lower()
    except sr.UnknownValueError:
        print("[Помилка] Не вдалося розпізнати голос")
        text = ""
    except sr.RequestError as e:
        print("[Помилка] Перевірте інтернет-з'єднання")
        text = ""
    except:
        text = command()

    return text

def speak(what):
    print(what)
    speak_engine.say(what)
    speak_engine.runAndWait()
    speak_engine.stop()

def callback(text):
    if text.startswith(opts['name']):
        cmd = text

        for x in opts['name']:
            cmd = cmd.replace(x, "").strip()

        for x in opts['user_command']:
            cmd = cmd.replace(x, "").strip()

        cmd = regornize_cmd()
        execute_cmd(cmd['cmds'])

def regornize_cmd(cmd):
    RC = {'cmd': '', 'percent': 0}
    for c, v in opts['cmds'].items():
        for x in v:
            vrt = fuzz.ratio(cmd, x)
            if vrt > RC['percent']:
                RC['cmd'] = c
                RC['percent'] = vrt
    return RC

def execute_cmd(cmd):
    if cmd == 'ctime':
        now = datetime.now()
        speak(f"Now, {now.hour} hour {now.minute} minute {now.second} second")

    elif cmd == 'paint':
        speak("Відкриваю Paint")
        os.system("mspaint")

    elif cmd == 'smart':
        speak("Welcome, to your smart home!")
        speak("Turning on the lights, and checking temperature.")
        speak("Lights are now on. Room temperature is 22 degrees Celsius.")

    elif cmd == 'google':
        speak("Open Google")
        os.system("start https://www.google.com")

    elif cmd == 'youtube':
        speak("Open YouTube")
        os.system("start https://www.youtube.com")

# Головна частина:
if __name__ == '__main__':
    voice_input = command()
    recognized = regornize_cmd(voice_input)
    execute_cmd(recognized['cmd'])
