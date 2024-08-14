import serial
import psutil
import time
from time import sleep
ser = serial.Serial()
ser.baudrate = 115200
ser.port = 'COM3'

while True:
	ser.open()
	usage = "Usage: " + str(psutil.cpu_percent()) + "%"
	ser.write(usage.encode())
	ser.close()
	sleep(1.5)


