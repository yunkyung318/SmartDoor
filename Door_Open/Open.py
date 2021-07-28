import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(23,GPIO.OUT)
GPIO.setup(24,GPIO.OUT)

print ("Stop, Press Ctrl+C to quit")
try:
    while True:
        a=int(input())
        
        if a==1:
            GPIO.output(23,False)
            GPIO.output(24,True)
        elif a==0:
            GPIO.output(23,True)
            GPIO.output(24,False)

except KeyboardInterrupt:
        GPIO.cleanup()
        print ("End")
