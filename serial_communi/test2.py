import serial
import time

print("Arduino")
time.sleep(0.5)

if __name__=='__main__':
    ser=serial.Serial('/dev/ttyACM0',9600,timeout=1)
    ser.flush()
    while True:
        if ser.in_waiting>0:
            line=ser.readline().decode('utf-8').rstrip()
            print(line)
