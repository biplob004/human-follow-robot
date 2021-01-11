#!/usr/bin/env python3
import serial
import time

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
ser.flush()


def forward():
    ser.write(b"forward\n")
    
def stop():
    ser.write(b"stop\n")

def left():
    ser.write(b"left\n")

def right():
    ser.write(b"right\n")


