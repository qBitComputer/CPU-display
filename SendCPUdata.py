import serial
ser = serial.Serial()
ser.baudrate = 115200
ser.port = 'COM3'
ser.open()
ser.write(b'Hello world!')
ser.close()
