import csv
import time
import serial

# Define the path to your CSV file
csv_file_path = "csv_files/new.csv"
ser = serial.Serial('COM13', 9600)  # Change 'COM10' to the appropriate serial port
ser.close()
